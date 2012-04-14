<?php
/**
 * @file
 * siga_profile.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function siga_profile_ctools_plugin_api() {
  return array("version" => "1");
}

/**
 * Implements hook_views_api().
 */
function siga_profile_views_api() {
  return array("version" => "3.0");
}
