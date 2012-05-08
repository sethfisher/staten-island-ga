<?php
/**
 * @file
 * siga_profile.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function siga_profile_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'gravatar_default';
  $strongarm->value = 'mm';
  $export['gravatar_default'] = $strongarm;

  return $export;
}
