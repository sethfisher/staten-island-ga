<?php
/**
 * @file
 * siga_voting.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function siga_voting_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rate_widgets';
  $strongarm->value = array(
    1 => (object) array(
      'name' => 'up_or_down_thumbs',
      'tag' => 'vote',
      'title' => 'Up or Down Thumbs',
      'node_types' => array(
        0 => 'blog',
      ),
      'comment_types' => array(
        0 => 'blog',
      ),
      'options' => array(
        0 => array(
          0 => 1,
          1 => 'up',
        ),
        1 => array(
          0 => -1,
          1 => 'down',
        ),
      ),
      'template' => 'thumbs_up_down',
      'node_display' => '2',
      'teaser_display' => TRUE,
      'comment_display' => '2',
      'node_display_mode' => '1',
      'teaser_display_mode' => '1',
      'comment_display_mode' => '1',
      'roles' => array(
        2 => '2',
        3 => 0,
        1 => 0,
      ),
      'allow_voting_by_author' => 0,
      'noperm_behaviour' => '1',
      'displayed' => '1',
      'displayed_just_voted' => '2',
      'description' => '',
      'description_in_compact' => TRUE,
      'value_type' => 'points',
      'theme' => 'rate_template_thumbs_up_down',
      'css' => 'sites/all/modules/contrib/rate/templates/thumbs-up-down/thumbs-up-down.css',
      'translate' => TRUE,
    ),
  );
  $export['rate_widgets'] = $strongarm;

  return $export;
}
