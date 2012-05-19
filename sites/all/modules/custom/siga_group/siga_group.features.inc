<?php
/**
 * @file
 * siga_group.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function siga_group_ctools_plugin_api() {
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
function siga_group_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function siga_group_node_info() {
  $items = array(
    'group' => array(
      'name' => t('Group'),
      'base' => 'node_content',
      'description' => t('A group is a collection of people sharing a goal, interest, neighborhood, or anything else that people identify in common with.'),
      'has_title' => '1',
      'title_label' => t('Group Name'),
      'help' => '',
    ),
  );
  return $items;
}
