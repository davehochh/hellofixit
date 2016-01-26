<?php

function md_pricing_table_preprocess_md_prtb_default(&$vars) {
  drupal_add_css($vars['css']);
  drupal_add_js(md_prtb_path . '/admin/js/pricing-front-end.js');
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

  if($vars['settings']['equal_height'] == 1) {
    $vars['settings']['equal_height'] = 'prtb-equal-height';
  } else {
    $vars['settings']['equal_height'] = '';
  }

  if($vars['settings']['column_margin'] != '0') {
    $vars['settings']['column_margin'] = 'margin-right:'.$vars['settings']['column_margin'].'px;';
  } else {
    $vars['settings']['column_margin'] = '';
  }
  $column_width = '';
  if($vars['settings']['equal_width'] == 1) {
    $md_prtb_count = count($vars['md_data']);
      if ($md_prtb_count!=0){
        $column_width = 'width : '.sprintf("%.3f", 100/$md_prtb_count).'%;';
      }
  } else {
    if($vars['settings']['column_width'] != 0) {
      $column_width = 'width : '.$vars['settings']['column_width'].'px;';
    }
  }
  $vars['settings']['column_width'] = $column_width;
//  dsm($vars);
}

/**
 * style_name + '_info' : display info feature support in style
 */
function md_prtb_default_info(){
  return array(
    'support' => array(
      'hightlight','tooltip','google map',
      'link youtube','link vimeo','html',
      'equal hight','three style pricing',
      'ribbon','icon','custom css','add class'
    )
  );
}