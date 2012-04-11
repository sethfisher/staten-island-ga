<?php
/**
 * @file
 * siga.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function siga_user_default_permissions() {
  $permissions = array();

  // Exported permission: add media from remote sources
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      0 => 'administrator',
      1 => 'authenticated user',
    ),
    'module' => 'media_internet',
  );

  return $permissions;
}
