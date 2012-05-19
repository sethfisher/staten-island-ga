<?php
/**
 * @file
 * siga.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function siga_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'mini_teaser';
  $ds_view_mode->label = 'Mini Teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'user' => 'user',
  );
  $export['mini_teaser'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'teaser';
  $ds_view_mode->label = 'Teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'user' => 'user',
  );
  $export['teaser'] = $ds_view_mode;

  return $export;
}
