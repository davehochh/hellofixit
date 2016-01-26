<?php
/**
 * Created by PhpStorm.
 * User: ngoctubka
 * Date: 4/15/14
 * Time: 3:05 PM
 */

function md_prtb_icon_load() {
  $items = icon_bundles();
  $md_prtb_output = '';
  //dsm($items);
  foreach($items as $bundle => $icons) {
    if(($icons['settings'] !=  null ) && ($icons['settings']['tag'] ==  'i' )) {
      foreach($icons['icons'] as $icon_value => $icon_name) {
        //$md_prtb_icon_temp = theme('icon',array('attribute' => '','icon' => $icon_value, 'bundle' => $bundle));
        //$md_prtb_output .= '<option value="'.$icon_value.'|'.$bundle.'">'.$icon_name.'</option>';
        $md_prtb_output .= theme('icon',array('attributes' => array('class' => array('js-body-selector-icon')),'icon' => $icon_value, 'bundle' => $bundle));
      }
    }
  }
  return t($md_prtb_output);
}