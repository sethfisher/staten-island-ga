<?php
/**
 * @file
 * siga.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function siga_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clean_url';
  $strongarm->value = 1;
  $export['clean_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_notify_available_alerts';
  $strongarm->value = array(
    1 => '1',
    2 => '2',
  );
  $export['comment_notify_available_alerts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_notify_comment_notify_default_mailtext';
  $strongarm->value = 'Hi [comment-subscribed:author],

[comment:author] has commented on: "[comment:node:title]"

----
[comment:title]
[comment:body]
----

You can view the comment at the following url
[comment:url]

You can stop receiving emails when someone replies to this post,
by going to [comment-subscribed:unsubscribe-url]

You can set up auto-following feature for all future posts
by creating your own user with a few clicks here [site:login-url]

-- [site:name] team
[site:url]';
  $export['comment_notify_comment_notify_default_mailtext'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_notify_default_anon_mailalert';
  $strongarm->value = '1';
  $export['comment_notify_default_anon_mailalert'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_notify_default_registered_mailalert';
  $strongarm->value = '1';
  $export['comment_notify_default_registered_mailalert'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_notify_node_notify_default_mailalert';
  $strongarm->value = 1;
  $export['comment_notify_node_notify_default_mailalert'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_notify_node_notify_default_mailtext';
  $strongarm->value = 'Hi [comment:node:author],

You have received a comment on: "[comment:node:title]"

----
[comment:title]
[comment:body]
----

You can view the comment at the following url
[comment:url]

You will receive emails like this for all replies to your posts. You can
disable this by logging in and changing the settings on your user account at
[comment:node:author:edit-url].

-- [site:name] team
[site:url]';
  $export['comment_notify_node_notify_default_mailtext'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_notify_node_types';
  $strongarm->value = array(
    'blog' => 'blog',
    'event' => 'event',
    'article' => 0,
    'page' => 0,
  );
  $export['comment_notify_node_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'drupalchat_polling_method';
  $strongarm->value = '0';
  $export['drupalchat_polling_method'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_user_alert';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_user_alert'] = $strongarm;

  return $export;
}
