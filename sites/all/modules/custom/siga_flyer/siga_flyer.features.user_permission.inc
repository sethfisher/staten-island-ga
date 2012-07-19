<?php
/**
 * @file
 * siga_flyer.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function siga_flyer_user_default_permissions() {
  $permissions = array();

  // Exported permission: create flyer content.
  $permissions['create flyer content'] = array(
    'name' => 'create flyer content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own flyer content.
  $permissions['delete own flyer content'] = array(
    'name' => 'delete own flyer content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own flyer content.
  $permissions['edit own flyer content'] = array(
    'name' => 'edit own flyer content',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
