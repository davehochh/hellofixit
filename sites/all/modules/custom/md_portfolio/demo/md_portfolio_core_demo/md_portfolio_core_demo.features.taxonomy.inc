<?php
/**
 * @file
 * md_portfolio_core_demo.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function md_portfolio_core_demo_taxonomy_default_vocabularies() {
  return array(
    'md_taxonomy_portfolio' => array(
      'name' => 'MD Portfolio Taxonomy',
      'machine_name' => 'md_taxonomy_portfolio',
      'description' => 'MD Portfolio Taxonomy',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
