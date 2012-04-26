<?php
/**
 * @file
 * siga_events.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function siga_events_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|sidebar_teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'sidebar_teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|event|sidebar_teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function siga_events_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|sidebar_teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'sidebar_teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_date',
        2 => 'field_location',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_date' => 'ds_content',
      'field_location' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|event|sidebar_teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function siga_events_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'sidebar_teaser';
  $ds_view_mode->label = 'Sidebar Teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['sidebar_teaser'] = $ds_view_mode;

  return $export;
}
