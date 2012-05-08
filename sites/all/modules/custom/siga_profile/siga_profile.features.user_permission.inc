<?php
/**
 * @file
 * siga_profile.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function siga_profile_user_default_permissions() {
  $permissions = array();

  // Exported permission: disable own gravatar.
  $permissions['disable own gravatar'] = array(
    'name' => 'disable own gravatar',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'gravatar',
  );

  // Exported permission: use gravatar.
  $permissions['use gravatar'] = array(
    'name' => 'use gravatar',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'gravatar',
  );

  return $permissions;
}
