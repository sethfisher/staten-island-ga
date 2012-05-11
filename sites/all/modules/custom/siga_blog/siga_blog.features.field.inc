<?php
/**
 * @file
 * siga_blog.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function siga_blog_field_default_fields() {
  $fields = array();

  // Exported field: 'node-blog-field_add_this'
  $fields['node-blog-field_add_this'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_add_this',
      'foreign keys' => array(),
      'indexes' => array(),
      'module' => 'addthis',
      'settings' => array(
        'max_length' => 255,
      ),
      'translatable' => '0',
      'type' => 'addthis',
    ),
    'field_instance' => array(
      'bundle' => 'blog',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'addthis_displays',
          'settings' => array(
            'buttons_size' => 'addthis_32x32_style',
            'counter_orientation' => 'horizontal',
            'extra_css' => '',
            'share_services' => 'facebook,twitter,google_plusone_share',
          ),
          'type' => 'addthis_basic_toolbox',
          'weight' => '1',
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'addthis_displays',
          'settings' => array(
            'buttons_size' => 'addthis_32x32_style',
            'counter_orientation' => 'horizontal',
            'extra_css' => '',
            'share_services' => 'facebook,twitter,google_plusone_share',
          ),
          'type' => 'addthis_basic_toolbox',
          'weight' => '1',
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_add_this',
      'label' => 'Add this',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'addthis',
        'settings' => array(),
        'type' => 'addthis_button_widget',
        'weight' => '31',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add this');

  return $fields;
}
