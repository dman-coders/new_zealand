<?php

/**
 * Implementation of hook_feeds_importer_default().
 */
function new_zealand_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'locations_terms';
  $feeds_importer->config = array(
    'name' => 'Locations',
    'description' => 'Imports terms from the supplied list of locations. Supports geolocation fields.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => 'features_locations',
        'update_existing' => 0,
        'mappings' => array(
          '0' => array(
            'source' => 'name',
            'target' => 'name',
            'unique' => 1,
          ),
          '1' => array(
            'source' => 'lat',
            'target' => 'lat',
            'unique' => FALSE,
          ),
          '2' => array(
            'source' => 'lon',
            'target' => 'lon',
            'unique' => FALSE,
          ),
          '3' => array(
            'source' => 'top',
            'target' => 'bound_top',
            'unique' => FALSE,
          ),
          '4' => array(
            'source' => 'right',
            'target' => 'bound_right',
            'unique' => FALSE,
          ),
          '5' => array(
            'source' => 'bottom',
            'target' => 'bound_bottom',
            'unique' => FALSE,
          ),
          '6' => array(
            'source' => 'left',
            'target' => 'bound_left',
            'unique' => FALSE,
          ),
          '7' => array(
            'source' => 'parent',
            'target' => 'parent_name',
            'unique' => FALSE,
          ),
          '8' => array(
            'source' => 'id',
            'target' => 'external_id',
            'unique' => FALSE,
          ),
          '9' => array(
            'source' => 'parent_id',
            'target' => 'parent_external_id',
            'unique' => FALSE,
          ),
        ),
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_on_create' => 1,
    'import_period' => '-1',
  );

  $export['locations_terms'] = $feeds_importer;
  return $export;
}
