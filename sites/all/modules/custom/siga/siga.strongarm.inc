<?php
/**
 * @file
 * siga.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function siga_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clean_url';
  $strongarm->value = 1;
  $export['clean_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings';
  $strongarm->value = array(
    'file' => array(
      'default' => array(
        'view_modes' => array(),
        'extra_fields' => array(
          'form' => array(),
          'display' => array(
            'file' => array(
              'media_small' => array(
                'weight' => 0,
                'visible' => FALSE,
              ),
            ),
          ),
        ),
      ),
      'image' => array(
        'view_modes' => array(),
        'extra_fields' => array(
          'form' => array(),
          'display' => array(
            'file' => array(
              'media_small' => array(
                'weight' => 0,
                'visible' => FALSE,
              ),
            ),
          ),
        ),
      ),
      'audio' => array(
        'view_modes' => array(),
        'extra_fields' => array(
          'form' => array(),
          'display' => array(
            'file' => array(
              'media_small' => array(
                'weight' => 0,
                'visible' => FALSE,
              ),
            ),
          ),
        ),
      ),
      'video' => array(
        'view_modes' => array(),
        'extra_fields' => array(
          'form' => array(),
          'display' => array(
            'file' => array(
              'media_small' => array(
                'weight' => 0,
                'visible' => FALSE,
              ),
            ),
          ),
        ),
      ),
    ),
    'node' => array(
      'blog' => array(
        'view_modes' => array(),
        'extra_fields' => array(
          'form' => array(),
          'display' => array(),
        ),
      ),
      'event' => array(
        'view_modes' => array(
          'teaser' => array(
            'custom_settings' => TRUE,
          ),
          'sidebar_teaser' => array(
            'custom_settings' => TRUE,
          ),
          'full' => array(
            'custom_settings' => FALSE,
          ),
          'rss' => array(
            'custom_settings' => FALSE,
          ),
          'search_index' => array(
            'custom_settings' => FALSE,
          ),
          'search_result' => array(
            'custom_settings' => FALSE,
          ),
          'token' => array(
            'custom_settings' => FALSE,
          ),
        ),
        'extra_fields' => array(
          'form' => array(),
          'display' => array(),
        ),
      ),
    ),
  );
  $export['field_bundle_settings'] = $strongarm;

  return $export;
}
