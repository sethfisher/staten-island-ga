<?php
/**
 * @file
 * siga_blog.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function siga_blog_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blog';
  $context->description = 'The context when on a user\'s blog.';
  $context->tag = 'blog';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'blogs/*' => 'blogs/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-blog_user_profile-block' => array(
          'module' => 'views',
          'delta' => 'blog_user_profile-block',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('The context when on a user\'s blog.');
  t('blog');
  $export['blog'] = $context;

  return $export;
}
