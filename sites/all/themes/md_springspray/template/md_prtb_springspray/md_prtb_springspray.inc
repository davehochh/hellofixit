<?php

function md_pricing_table_preprocess_md_prtb_springspray(&$vars) {
  $md_path_style = md_prtb_style_load();
  if(isset($md_path_style['md_prtb_springspray']['path'])){
    $md_path_style = $md_path_style['md_prtb_springspray']['path'];
    drupal_add_js($md_path_style . '/md-prtb-springspray-index.js');

  };
  drupal_add_css($vars['css']);
  $md_css_file = file_load($vars['settings']['custom_class_fid']);
  if($md_css_file != false) {
    drupal_add_css($md_css_file->uri,array('group' => CSS_THEME, 'weight' => 99));
  }
  // looks for node--promoted.tpl.php in your theme directory
  if(count($vars['classes_array']) != 0) {
    foreach($vars['classes_array'] as $key => $style_name) {
      $vars['theme_hook_suggestions'][] = str_replace('-','_',$style_name).'__'.$vars['machine_name'];
    }
  }
  $md_column_class = '4';
  if(count($vars['md_data']) == 2){
    $md_column_class = '6';
    $vars['md_data'] = array_chunk($vars['md_data'],2);
  } elseif(count($vars['md_data']) == 1){
    $md_column_class = '12';
    $vars['md_data'] = array_chunk($vars['md_data'],1);
  } else {
    $vars['md_data'] = array_chunk($vars['md_data'],3);
  }
  $vars['settings']['column_class'] = $md_column_class;
  $vars['settings']['custom_class_fid'] = '';
  if($vars['settings']['equal_height'] == 1){
    $vars['settings']['custom_class_fid'] = 'md-pricing-table-block-equal-height';
  }
  $vars['settings']['custom_class_fid'] .= ' md-pricing-table-block-'.rand(100,999);

//  dsm($vars);
}

/**
 * style_name + '_info' : display info feature support in style
 */
function md_prtb_springspray_info(){
  return array(
    'support' => array(
      'header html','custom css','add class','tooltip','responsive','class wrapper'
    )
  );
}