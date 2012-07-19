<?php
/**
 * @file
 * siga_flyer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function siga_flyer_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function siga_flyer_node_info() {
  $items = array(
    'flyer' => array(
      'name' => t('Flyer'),
      'base' => 'node_content',
      'description' => t('Upload a flyer for upcoming events, organizational information, or both.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
