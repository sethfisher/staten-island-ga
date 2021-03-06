<?php


/**
 * @file
 * Page callbacks for Organic groups module.
 */

/**
 * Subscribe the current user to a group.
 *
 * @param $node
 *   The group node entity.
 * @param $uid
 *   Optional; The user ID of the subscribing user. If empty the current user
 *   will be used.
 */
function og_ui_subscribe($entity_type, $etid, $field_name = NULL) {
  global $user;
  $entity_info = entity_get_info($entity_type);
  if (!$entity_type || !$entity_info) {
    // Not a valid entity type.
    drupal_not_found();
    return;
  }
  $entity = entity_load_single($entity_type, $etid);
  if (!$entity || !og_is_group($entity_type, $entity)) {
    // Not a valid entity, or not a group.
    drupal_not_found();
    return;
  }

  list($id, $vid, $bundle) = entity_extract_ids($entity_type, $entity);

  if (empty($field_name)) {
    $field_name = og_get_best_group_audience_field('user', $user->uid, $entity_type, $entity);
    if (empty($field_name)) {
      // User entity has no group audience field.
      drupal_not_found();
      return;
    }
  }

  $wrapper = entity_metadata_wrapper('user', $user->uid);

  $field_info = field_info_field($field_name);
  if (empty($field_info) || empty($wrapper->{$field_name}) || !$wrapper->{$field_name}->access('view')) {
    // Field name given is incorrect, or user doesn't have access to the field.
    drupal_not_found();
    return;
  }

  if (!$user->uid) {
    // Anonymous user can't request membership.
    $dest = drupal_get_destination();
    if (variable_get('user_register', 1)) {
      drupal_set_message(t('In order to join any group, you must <a href="!login">login</a>. After you have successfully done so, you will need to request membership again.', array('!login' => url("user/login", array('query' => $dest)))));
    }
    else {
      drupal_set_message(t('In order to join any group, you must <a href="!login">login</a> or <a href="!register">register</a> a new account. After you have successfully done so, you will need to request membership again.', array('!register' => url("user/register", array('query' => $dest)), '!login' => url("user/login", array('query' => $dest)))));
    }
    drupal_goto('user');
  }

  $redirect = FALSE;

  $params = array();
  $params['@user'] = format_username($user);
  // Show the group name only if user has access to it.
  $params['@group'] = entity_access('view', $entity_type, $entity) ?  entity_label($entity_type, $entity) : t('Private group');

  if (og_is_member($entity_type, $id, 'user', $user, array(OG_STATE_BLOCKED))) {
    // User is blocked, access denied.
    drupal_access_denied();
    return;
  }
  if (og_is_member($entity_type, $id, 'user', $user, array(OG_STATE_PENDING))) {
    // User is pending, return them back.
    $message = $user->uid == $user->uid ? t('You already have a pending membership for the group @group.', $params) : t('@user already has a pending membership for the  the group @group.', $params);
    $redirect = TRUE;
  }

  if (og_is_member($entity_type, $id, 'user', $user, array(OG_STATE_ACTIVE))) {
    // User is already a member, return them back.
    $message = $user->uid == $user->uid ? t('You are already a member of the group @group.', $params) : t('@user is already a member of the group @group.', $params);
    $redirect = TRUE;
  }

  if ($redirect) {
    drupal_set_message($message);
    $url = entity_uri($entity_type, $entity);
    drupal_goto($url['path'], $url['options']);
  }

  if (og_user_access($entity_type, $id, 'subscribe', $user) || og_user_access($entity_type, $id, 'subscribe without approval', $user)) {
    // Show the user a subscription confirmation.
    return drupal_get_form('og_ui_confirm_subscribe', $entity_type, $id, $user, $field_name);
  }
}

/**
 * Confirm subscribe form.
 */
function og_ui_confirm_subscribe($form, &$form_state, $group_type, $gid, $account, $field_name) {
  $values = array('state' => og_user_access($group_type, $gid, 'subscribe without approval') ? OG_STATE_ACTIVE : OG_STATE_PENDING);

  // Add group membership form.
  $og_membership = og_membership_create($group_type, $gid, 'user', $account->uid, $field_name, $values);
  $form_state['og_membership'] = $og_membership;
  field_attach_form('og_membership', $og_membership, $form, $form_state);

  if (og_user_access($group_type, $gid, 'subscribe without approval')) {
    // Hide the user request field.
    if (!empty($form[OG_MEMBERSHIP_REQUEST_FIELD])) {
      $form[OG_MEMBERSHIP_REQUEST_FIELD]['#access'] = FALSE;
    }
  }

  $wrapper = entity_metadata_wrapper($group_type, $gid);
  $label = $wrapper->access('view') ? $wrapper->label() : t('Private group');

  $form['group_type'] = array('#type' => 'value', '#value' => $group_type);
  $form['gid'] = array('#type' => 'value', '#value' => $gid);
  $form['field_name'] = array('#type' => 'value', '#value' => $field_name);

  return confirm_form($form, t('Are you sure you want to join the group %title?', array('%title' => $label)), $wrapper->url->value(), ' ', t('Join'), t('Cancel'));
}

/**
 * Validate handler; Confirm OG membership.
 */
function og_ui_confirm_subscribe_validate($form, &$form_state) {
  // @see entity_form_field_validate().
  $og_membership = $form_state['og_membership'];
  field_attach_form_validate('og_membership', $og_membership, $form, $form_state);
}

/**
 * Submit handler; Confirm OG membership.
 */
function og_ui_confirm_subscribe_submit($form, &$form_state) {
  global $user;
  $og_membership = $form_state['og_membership'];
  field_attach_submit('og_membership', $og_membership, $form, $form_state);
  $og_membership->save();

  $group_type = $form_state['values']['group_type'];
  $gid = $form_state['values']['gid'];
  $group = entity_load_single($group_type, $gid);

  $form_state['redirect'] = entity_uri($group_type, $group);
}


/**
 * Confirm OG unsubscription form.
 *
 * The unsubscribing user is always the acting user - like this we make sure
 * no malicious user will unsubscribe another user. Administrators can reject or
 * ban another group member from the "people" page.
 */
function og_ui_unsubscribe($group_type, $gid) {
  global $user;
  $account = clone $user;
  $group = entity_load_single($group_type, $gid);
  if (!$group || !og_is_group($group_type, $group)) {
    // Not a valid entity, or not a group.
    drupal_not_found();
    return;
  }

  // Check the user isn't the manager of the group.
  if ($group->uid != $user->uid) {
    if (og_is_member($group_type, $gid, 'user', $account, array(OG_STATE_ACTIVE, OG_STATE_PENDING))) {
      // Show the user a subscription confirmation.
      return drupal_get_form('og_ui_confirm_unsubscribe', $group_type, $group);
    }
    drupal_access_denied();
    return;
  }
  else {
    $label = entity_label($group_type, $group);
    drupal_set_message(t('As the manager of %group, you can not leave the group.', array('%group' => $label)));
    drupal_goto(entity_uri($group_type, $group));
  }
}

/**
 * Confirm unsubscribe form.
 */
function og_ui_confirm_unsubscribe($form, &$form_state, $group_type, $group) {
  $form['group_type'] = array('#type' => 'value', '#value' => $group_type);
  $form['group'] = array('#type' => 'value', '#value' => $group);

  $label = entity_label($group_type, $group);
  $url = entity_uri($group_type, $group);
  return confirm_form($form, t('Are you sure you want to unsubscribe from the group %title?', array('%title' => $label)), $url, NULL, t('Remove'), t('Cancel'));
}

/**
 * Submit handler; Confirm OG unsubscription.
 */
function og_ui_confirm_unsubscribe_submit($form, &$form_state) {
  $group_type = $form_state['values']['group_type'];
  $group = $form_state['values']['group'];

  og_ungroup($group_type, $group);

  if (entity_access('view', $group_type, $group)) {
    $form_state['redirect'] = entity_uri($group_type, $group);
  }
}