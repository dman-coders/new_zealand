<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function new_zealand_taxonomy_default_vocabularies() {
  return array(
    'locations' => array(
      'name' => 'Location',
      'description' => '',
      'help' => 'Area within New Zealand.',
      'relations' => '1',
      'hierarchy' => '1',
      'multiple' => '0',
      'required' => '1',
      'tags' => '0',
      'module' => 'features_locations',
      'weight' => '0',
      'nodes' => array(
        'feed' => 'feed',
        'channel' => 'channel',
      ),
    ),
  );
}
