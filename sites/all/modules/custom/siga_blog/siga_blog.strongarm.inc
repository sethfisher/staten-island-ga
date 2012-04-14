<?php
/**
 * @file
 * siga_blog.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function siga_blog_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_blog_pattern';
  $strongarm->value = 'blogs/[node:author]/[node:created:custom:n]/[node:created:custom:j]/[node:created:custom:Y]/[node:title]';
  $export['pathauto_node_blog_pattern'] = $strongarm;

  return $export;
}
