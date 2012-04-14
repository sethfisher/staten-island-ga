<?php
/**
 * @file
 * siga_profile.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function siga_profile_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|blog_user_profile';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'blog_user_profile';
  $ds_fieldsetting->settings = array(
    'ds_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_picture_thumbnail',
    ),
  );
  $export['user|user|blog_user_profile'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function siga_profile_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|blog_user_profile';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'blog_user_profile';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'ds_user_picture',
        1 => 'field_about_me',
        2 => 'field_links',
      ),
    ),
    'fields' => array(
      'ds_user_picture' => 'ds_content',
      'field_about_me' => 'ds_content',
      'field_links' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['user|user|blog_user_profile'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function siga_profile_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'blog_user_profile';
  $ds_view_mode->label = 'Blog User Profile';
  $ds_view_mode->entities = array(
    'user' => 'user',
  );
  $export['blog_user_profile'] = $ds_view_mode;

  return $export;
}
