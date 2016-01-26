<?php
/**
 * Created by PhpStorm.
 * User: ngoctubka
 * Date: 4/19/14
 * Time: 10:26 AM
 */
function md_pricing_table_block_info() {//display prtb in block
	$md_prtb = new MD_PRTB;
	$blocks = array();
	$md_datas = $md_prtb->get_full('block',array('id','title'));
	//dsm($w_prtb);
	if ($md_datas !== FALSE) {
		foreach ($md_datas as $md_data) {
				$blocks["{$md_data->id}"] = array(
					"info" => t("MD Pricing Table: {$md_data->title}"),
					"cache" => DRUPAL_CACHE_GLOBAL
				);
		}
	}
	return $blocks;
}

function md_pricing_table_block_view($delta = "") {
  md_prtb_icon_load();
	$block = array();
	$md_prtb = new MD_PRTB();
	$md_data  = $md_prtb->get_by_id($delta);
	if($md_data != false){
		if(($md_data->content != null) && ($md_data->content != '') && ($md_data->display_block == 1)){
      $md_content = $md_data->content;
      $md_data->delta_rd = rand(10,99);
      unset($md_data->content);
      $md_theme_registry = theme_get_registry();
      if(isset($md_theme_registry[$md_data->style_name])) {
        $block['content'] = theme($md_data->style_name,array('machine_name' => $md_data->machine_name,'settings' => get_object_vars($md_data), 'md_data' => drupal_json_decode($md_content)));
      } else {
        $block['content'] = 'Theme style for Md Pricing Table do not exist!';
      }
    }
	}

	return $block;
}