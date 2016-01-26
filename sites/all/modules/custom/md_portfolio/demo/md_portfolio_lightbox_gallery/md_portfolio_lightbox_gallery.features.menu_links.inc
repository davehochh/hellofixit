<?php
/**
 * @file
 * md_portfolio_lightbox_gallery.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function md_portfolio_lightbox_gallery_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_md-portfolio-lightbox-gallery:md-portfolio-lightbox-gallery
  $menu_links['main-menu_md-portfolio-lightbox-gallery:md-portfolio-lightbox-gallery'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'md-portfolio-lightbox-gallery',
    'router_path' => 'md-portfolio-lightbox-gallery',
    'link_title' => 'MD portfolio Lightbox Gallery',
    'options' => array(
      'identifier' => 'main-menu_md-portfolio-lightbox-gallery:md-portfolio-lightbox-gallery',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('MD portfolio Lightbox Gallery');


  return $menu_links;
}
