<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'name' => t('Group description'),
  'access callback' => 'og_migrate_7000_access',
  'dependencies' => array('og_7000_group'),
);


/**
 * OG Migrate callback; Upgrade "group" nodes.
 */
function og_7000_group_description(&$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['last'] = 0;

    // Calculate max items.
    $query = db_select('node_revision', 'nr');
    $query->innerJoin('node', 'n', 'n.vid = nr.vid');
    $query->innerJoin('d6_og', 'og', 'n.nid = og.nid');
    $context['sandbox']['max'] = $query
      ->countQuery()
      ->execute()
      ->fetchField();

    if (!$context['sandbox']['max']) {
      // No data to process, so return.
      $context['finished'] = 1;
      return;
    }
  }

  // Operate on every revision of every node, in batches.
  $batch_size = variable_get('og_batch_size', 200);
  $query = db_select('node_revision', 'nr');
  $query->innerJoin('node', 'n', 'n.vid = nr.vid');
  $query->innerJoin('d6_og', 'og', 'n.nid = og.nid');
  $query
    ->fields('nr', array('nid', 'vid'))
    ->fields('n', array('type', 'created'))
    ->fields('og', array('upgrade_id', 'og_description'))
    ->condition('og.upgrade_id', $context['sandbox']['last'], '>')
    ->orderBy('og.upgrade_id', 'ASC')
    ->range(0, $batch_size);
  $revisions = $query->execute();

  foreach ($revisions as $revision) {
    if (!empty($revision->og_description)) {
      $node = node_load($revision->nid, $revision->vid);
      $wrapper = entity_metadata_wrapper('node', $node);
      $wrapper->og_description->set($revision->og_description);
      $wrapper->save();
    }

    $context['sandbox']['last'] = $revision->upgrade_id;
    $context['sandbox']['progress']++;
  }

  if ($context['sandbox']['progress'] < $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}
