<?php
/**
 * Created by PhpStorm.
 * User: ngoctubka
 * Date: 4/19/14
 * Time: 10:27 AM
 */
function md_pricing_table_field_info() {
	return array(
		'md_prtb' => array(
			'label' => t('MD Pricing Table'),
			'description' => t('Type: Pricing Table'),//trs/43/field_info: ki?u d? li?u : Pricing Table
			'default_widget' => 'md_prtb_widget_layout',
			'default_formatter' => 'md_prtb_formatter_layout',
		)
	);
}

function md_pricing_table_field_is_empty($item) {
	return empty($item['prtb']);
}

function md_pricing_table_field_validate() {

}

function md_pricing_table_field_formatter_info() {
	return array(
		'md_prtb_formatter_layout' => array(
			'label' => t('formatter for pricing table'),//trs/44/forrmatter_info: ??nh d?ng hi?n th? cho pricing table
			'field types' => array('md_prtb')
		)
	);
}

function md_pricing_table_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  md_prtb_icon_load();
	$element = array();
	if($items != null) {
		$md_prtb = new MD_PRTB();
		foreach($items as $key => $item) {
			$md_id = $item['prtb'];
			$md_data = $md_prtb->get_by_id($md_id);
			if($md_data != null){
				if(($md_data->content != '') && ($md_data->content != '"[]"')  && ($md_data->display_field == 1)) {//check data <> null
          $md_content = $md_data->content;
          $md_data->delta_rd = rand(10,99);
          unset($md_data->content);
          $md_theme_registry = theme_get_registry();
          if(isset($md_theme_registry[$md_data->style_name])) {
            $element[$key]['#markup'] = theme($md_data->style_name,array('machine_name' => $md_data->machine_name,'settings' => get_object_vars($md_data), 'md_data' => drupal_json_decode($md_content)));
          } else {
            $element[$key]['#markup'] = 'Theme style for Md Pricing Table do not exist!';
          }
				}
			}
		}
	}

	return $element;
}

function md_pricing_table_field_widget_info() {
	return array(
		'prtb_select' => array(
			'label' => t('MD Pricing Table Selected'),//trs/45/widget_info: Danh sách ch?n trong pricing table
			'field types' => array('md_prtb'),
		)
	);
}

function md_pricing_table_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {

	$md_prtb = new MD_PRTB();
	$md_items = array();//list items pricing table
  $md_items[0] ='No items';
	$md_datas = $md_prtb->get_full('field',array('title'));
	$value = isset($items[$delta]['prtb']) ? $items[$delta]['prtb'] : '0';//check value in field
	if($md_datas != null) {//if items
		foreach($md_datas as $md_data) {
      $md_items[$md_data->id] = $md_data->title;
		}
		$value = isset($md_items[$value]) ? $value : '0';
	} else {
		$value = 0;
	}


	$widget = $element;
	$widget['#delta'] = $delta;
	$widget += array(
		'#type' => 'radios',
		'#default_value' => $value,
		'#options' => $md_items,
	);

	$element['prtb'] = $widget;
	return $element;
}

function md_pricing_table_field_widget_error($element, $error) {

}

