<?php
/**
 * @file
 * md_portfolio_core_demo.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function md_portfolio_core_demo_image_default_styles() {
  $styles = array();

  // Exported image style: md_portfolio_400x300.
  $styles['md_portfolio_400x300'] = array(
    'name' => 'md_portfolio_400x300',
    'label' => 'MD Portfolio(400x300)',
    'effects' => array(
      2 => array(
        'label' => 'Crop',
        'help' => 'Cropping will remove portions of an image to make it the specified dimensions.',
        'effect callback' => 'image_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_crop_form',
        'summary theme' => 'image_crop_summary',
        'module' => 'image',
        'name' => 'image_crop',
        'data' => array(
          'width' => 400,
          'height' => 300,
          'anchor' => 'center-center',
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function md_portfolio_core_demo_node_info() {
  $items = array(
    'md_portfolio' => array(
      'name' => t('MD Portfolio'),
      'base' => 'node_content',
      'description' => t('MD Portfolio Demo'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
