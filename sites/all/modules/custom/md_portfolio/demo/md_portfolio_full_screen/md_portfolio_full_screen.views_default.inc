<?php
/**
 * @file
 * md_portfolio_full_screen.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function md_portfolio_full_screen_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'md_portfolio_full_screen';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'MD Portfolio Full Screen';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'MD Portfolio Full Screen';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'md_load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '9';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['wle_page_check'] = '1';
  $handler->display->display_options['style_plugin'] = 'md_portfolio_mdp_plugin_style';
  $handler->display->display_options['style_options']['md_style_flag'] = '1';
  $handler->display->display_options['style_options']['md_style_view'] = array(
    'vid' => '12',
    'vname' => 'md_portfolio_full_screen',
    'display_id' => 'page',
    'filter_tax_id_field_name' => 'md_taxonomy_portfolio/field_mdp_categories',
    'filter_default_tax_id' => '4',
    'filter_default_tax_mname' => 'md_taxonomy_portfolio',
    'filter_default_field' => 'field_mdp_categories',
    'filter_div_id' => 'mdp-filter-12',
    'grid_div_id' => 'mdp-grid-12',
  );
  $handler->display->display_options['style_options']['md_style_filter_count'] = array(
    'flag_check' => 0,
    'options' => array(
      'count_type' => 'cbp-count-default',
      'field_prefix' => '',
      'field_suffix' => ' / ',
    ),
  );
  $handler->display->display_options['style_options']['md_style_item_width'] = '400';
  $handler->display->display_options['style_options']['md_style_item_width_unit'] = 'px';
  $handler->display->display_options['style_options']['md_style_item_height'] = '300';
  $handler->display->display_options['style_options']['md_style_item_level_height'] = array(
    'height1' => '300',
    'height2' => '300',
  );
  $handler->display->display_options['style_options']['md_style_container_type'] = 'cbp-l-grid-fullScreen';
  $handler->display->display_options['style_options']['md_style_animationType'] = 'fadeOutTop';
  $handler->display->display_options['style_options']['md_style_caption'] = 'zoom';
  $handler->display->display_options['style_options']['md_style_displayType'] = 'lazyLoading';
  $handler->display->display_options['style_options']['md_style_gridAdjustment'] = 'responsive';
  $handler->display->display_options['style_options']['md_style_gapHorizontal'] = '0';
  $handler->display->display_options['style_options']['md_style_gapVertical'] = '0';
  $handler->display->display_options['style_options']['md_style_view_node'] = 'mdp_full_popup';
  $handler->display->display_options['row_plugin'] = 'md_portfolio_mdp_plugin_rows';
  $handler->display->display_options['row_options']['md_rows'] = array(
    'field_mdp_images' => array(
      'field' => '',
      'flag' => 'caption',
      'caption' => array(
        'class_link' => 'cbp-singlePage',
        'text' => '',
        'field_display' => array(
          'title' => 1,
          'name' => 1,
        ),
      ),
      'more' => array(
        'caption_flag' => 0,
        'caption_text' => 'View Image',
        'full_page_flag' => 0,
        'full_page_text' => 'View Content',
        'inline_page_flag' => 0,
        'inline_page_text' => 'View Content',
        'field_display' => array(
          'title' => 0,
          'name' => 0,
        ),
      ),
    ),
    'title' => array(
      'field' => 'title',
      'flag' => '0',
    ),
    'name' => array(
      'field' => 'name',
      'flag' => '0',
    ),
  );
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_mdp_images']['id'] = 'field_mdp_images';
  $handler->display->display_options['fields']['field_mdp_images']['table'] = 'field_data_field_mdp_images';
  $handler->display->display_options['fields']['field_mdp_images']['field'] = 'field_mdp_images';
  $handler->display->display_options['fields']['field_mdp_images']['label'] = '';
  $handler->display->display_options['fields']['field_mdp_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mdp_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_mdp_images']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_mdp_images']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'cbp-l-caption-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '<div class="cbp-l-caption-desc">by [name]</div>';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'md_portfolio' => 'md_portfolio',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'md-portfolio-full-screen';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'MD Portfolio Full Screen ';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['md_portfolio_full_screen'] = $view;

  return $export;
}
