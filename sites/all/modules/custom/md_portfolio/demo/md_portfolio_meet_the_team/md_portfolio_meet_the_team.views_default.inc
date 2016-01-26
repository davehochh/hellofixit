<?php
/**
 * @file
 * md_portfolio_meet_the_team.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function md_portfolio_meet_the_team_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'md_portfolio_meet_the_team';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'MD portfolio Meet The Team';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'MD portfolio Meet The Team';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'md_load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['wle_page_check'] = '1';
  $handler->display->display_options['style_plugin'] = 'md_portfolio_mdp_plugin_style';
  $handler->display->display_options['style_options']['md_style_flag'] = '1';
  $handler->display->display_options['style_options']['md_style_view'] = array(
    'vid' => '15',
    'vname' => 'md_portfolio_meet_the_team',
    'display_id' => 'page',
    'filter_tax_id_field_name' => 'md_taxonomy_portfolio/field_mdp_categories',
    'filter_default_tax_id' => '4',
    'filter_default_tax_mname' => 'md_taxonomy_portfolio',
    'filter_default_field' => 'field_mdp_categories',
    'filter_div_id' => 'mdp-filter-15',
    'grid_div_id' => 'mdp-grid-15',
  );
  $handler->display->display_options['style_options']['md_style_filter_count'] = array(
    'flag_check' => 1,
    'options' => array(
      'count_type' => 'cbp-count-tooltip',
      'field_prefix' => '(',
      'field_suffix' => ')',
    ),
  );
  $handler->display->display_options['style_options']['md_style_filter_type'] = 'cbp-l-filters-button';
  $handler->display->display_options['style_options']['md_style_item_width'] = '400';
  $handler->display->display_options['style_options']['md_style_item_width_unit'] = 'px';
  $handler->display->display_options['style_options']['md_style_item_height'] = '300';
  $handler->display->display_options['style_options']['md_style_item_level_height'] = array(
    'height1' => '300',
    'height2' => '300',
  );
  $handler->display->display_options['style_options']['md_style_animationType'] = 'sequentially';
  $handler->display->display_options['style_options']['md_style_caption'] = 'fadeIn';
  $handler->display->display_options['style_options']['md_style_displayType'] = 'lazyLoading';
  $handler->display->display_options['style_options']['md_style_gridAdjustment'] = 'responsive';
  $handler->display->display_options['style_options']['md_style_gapHorizontal'] = '50';
  $handler->display->display_options['style_options']['md_style_gapVertical'] = '40';
  $handler->display->display_options['style_options']['md_style_view_node'] = 'mdp_full_popup';
  $handler->display->display_options['row_plugin'] = 'md_portfolio_mdp_plugin_rows';
  $handler->display->display_options['row_options']['md_rows'] = array(
    'field_mdp_images' => array(
      'field' => '',
      'flag' => 'caption',
      'caption' => array(
        'class_link' => 'cbp-singlePage',
        'text' => 'Mega Drupal',
        'field_display' => array(
          'title' => 0,
          'field_mdp_categories' => 0,
        ),
      ),
      'more' => array(
        'caption_flag' => 1,
        'caption_text' => 'View Image',
        'full_page_flag' => 0,
        'full_page_text' => 'View Content',
        'inline_page_flag' => 1,
        'inline_page_text' => 'View Content',
        'field_display' => array(
          'title' => 1,
          'field_mdp_categories' => 1,
        ),
      ),
    ),
    'title' => array(
      'field' => 'title',
      'flag' => '1',
    ),
    'field_mdp_categories' => array(
      'field' => 'field_mdp_categories',
      'flag' => '1',
    ),
  );
  /* Field: Content: Images */
  $handler->display->display_options['fields']['field_mdp_images']['id'] = 'field_mdp_images';
  $handler->display->display_options['fields']['field_mdp_images']['table'] = 'field_data_field_mdp_images';
  $handler->display->display_options['fields']['field_mdp_images']['field'] = 'field_mdp_images';
  $handler->display->display_options['fields']['field_mdp_images']['label'] = '';
  $handler->display->display_options['fields']['field_mdp_images']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_mdp_images']['alter']['text'] = '[field_mdp_images]';
  $handler->display->display_options['fields']['field_mdp_images']['element_type'] = '0';
  $handler->display->display_options['fields']['field_mdp_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mdp_images']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mdp_images']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_mdp_images']['settings'] = array(
    'image_style' => 'md_portfolio_400x300',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_mdp_images']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['title']['element_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_class'] = 'cbp-l-grid-team-name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_mdp_categories']['id'] = 'field_mdp_categories';
  $handler->display->display_options['fields']['field_mdp_categories']['table'] = 'field_data_field_mdp_categories';
  $handler->display->display_options['fields']['field_mdp_categories']['field'] = 'field_mdp_categories';
  $handler->display->display_options['fields']['field_mdp_categories']['label'] = '';
  $handler->display->display_options['fields']['field_mdp_categories']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_mdp_categories']['element_class'] = 'cbp-l-grid-team-position';
  $handler->display->display_options['fields']['field_mdp_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_mdp_categories']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_mdp_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_mdp_categories']['delta_limit'] = '1';
  $handler->display->display_options['fields']['field_mdp_categories']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_mdp_categories']['delta_reversed'] = TRUE;
  $handler->display->display_options['fields']['field_mdp_categories']['separator'] = '';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  $handler->display->display_options['path'] = 'md-portfolio-meet-the-team';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'MD portfolio Meet The Team';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['md_portfolio_meet_the_team'] = $view;

  return $export;
}
