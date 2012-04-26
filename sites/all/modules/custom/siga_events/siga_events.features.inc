<?php
/**
 * @file
 * siga_events.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function siga_events_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function siga_events_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function siga_events_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('An event happening at a certain time at a certain location.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
