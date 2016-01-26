<?php
/**
 * Created by PhpStorm.
 * User: ngoctubka
 * Date: 3/31/14
 * Time: 9:32 AM
 */

class MDPRTB {

  public $tb = "md_pricing_table";
  public $name = "MDPRTB";

  function get_all($type = '', $wfds = '') {//type: block(=1)/field(=1)/null | wfds : field for table // limit = 30
		if($wfds == null) {
			$wfds = array();
		}
		$wfds[] = 'id';
    $wdts = db_select($this->tb,'w')->extend('PagerDefault');
    $wdts->fields('w', $wfds);
    if($type == 'block'){
			$wdts->condition('display_block','1','=');
    } elseif($type == 'field') {
			$wdts->condition('display_field','1','=');
    }
		$wdts->limit(30);
		$wdts->orderBy('created','DESC');

		return $wdts->execute();
  }

	function get_full($type= '', $wfds = '') { // limit = unlimited | wfds : field for query
		if($wfds == null) {
			$wfds = array();
		}
		$wfds[] = 'id';
		$wdts = db_select($this->tb,'w');
		$wdts->fields('w', $wfds);
		if($type == 'block'){
			$wdts->condition('display_block','1','=');
		} elseif($type == 'field') {
			$wdts->condition('display_field','1','=');
		}
		$wdts->orderBy('created','DESC');

		return $wdts->execute();
	}

  function get_by_id($id = null){
      $wdt = db_select($this->tb,'w')
        ->fields('w')
        ->condition('id', $id, '=')
        ->execute()
        ->fetchAll();
    if($wdt == null){
      return false;
    } else {
      return $wdt[0];
    }
  }

  function get_other($ids = '') {
    if($ids == null) {
      return null;
    }

    $wdts = db_select($this->tb,'w')
      ->fields('w')
      ->condition('id', $ids,'IN');

    return $wdts->execute();
  }

  function get_by_other($id = '', $wfield = '', $wdt = '') {//input field => value is condition
    if($wdt == null) {
      return null;
    }
    $w_key = '';
    $w_value = '';
    foreach($wdt as $key => $value) {
      $w_key = $key;
      $w_value = $value;
    }
    $wdts = db_select($this->tb,'w')
      ->fields('w',$wfield)
      ->condition($w_key, $value,'=')
      ->condition('id', $id,'<>')
      ->execute()
      ->fetchAll();
    if(count($wdts) == 0) {
      return 0;
    } else {
      return count($wdts);
    }

  }

  function insert($md_data = '') {
    $md_insert = db_insert($this->tb)
      ->fields($md_data)
      ->execute();
    if($md_insert != 0){//check data insert
      return $md_insert;
    } else {
      return false;
    }
  }

  function delete($id = null) {
    $w_del = db_delete($this->tb)
      ->condition('id',$id, '=');
    if($w_del->execute() == 1){//delete record in table: md_pricing_table
      return TRUE;
		} else {
			return FALSE;
		}
  }

  function update($id = '', $wdts = ''){
    $wle_update = db_update($this->tb)
      ->fields($wdts)
      ->condition('id',$id,'=');
    return $wle_update->execute();
  }

  function prtb_check_machine_name($name = null) {
    $wdts = db_select($this->tb,'w')
      ->fields('w')
      ->condition('machine_name',$name,'=')
      ->execute()
      ->fetchAll(PDO::FETCH_CLASS, $this->name);
    if($wdts == null) {
      return false;
    } else {
      return true;
    }
  }

}

function md_pricing_table_permission() {
	return array(
		'prtb admin' => array(
			'title' => t('Administer MD Pricing Table'),//trs/46/permission: quyền quản trị trên md pricing table
			'description' => t('Administer MD Pricing Table'),//trs/47/permission toàn quyền thao tác trên các chức năng của md pricing table
		),
		'prtb manager' => array(
			'title' => t('Manager MD Pricing Table'),//trs/48/permission quản lý các item của md pricing table
			'description' => t('Manager MD Pricing Table')//trs/49/permission có quyền chỉnh sửa nội dung và cấu hình lại các item
		)
	);
}

function md_pricing_table_library() {
	$wpath = drupal_get_path("module", "md_pricing_table");
	$prtb_js_default_arg = array(
		'jquery-ui-1.10.4',
	);
	$prtb_js_edit_arg = array(//add js for pricing table edit
		'pricing-main',
		'pricing-function',
		'pricing-process-body',
		'pricing-process-footer',
		'pricing-process-header',
		'pricing-process-price',
		'pricing-process-request-drupal',
		'pricing-process-setting',
		'pricing-save-data-json',
		'pricing-table',
	);
	$prtb_css_edit_arg = array(//add css for pricing table edit
		'md_prtb',
		'validate'
	);

	$prtb_js_list_arg = array();

	$prtb_js_config_arg = array(//js for tooltip
		'spectrum',
		'color_load'
	);
	$prtb_css_config_arg = array(//css for tooltip
		'spectrum',
    'jquery_ui',
    'prtb_config',
	);

	$prtb_js_index_arg = array(
    //'frontend-main',
    'pricing_index',
    //'pricing_map'
	);
	$prtb_css_index_arg = array(//
		'prtb_index',
	);

	$prtb_js_default = array();
	$prtb_js_list = array();

	$prtb_js_index = array();
	$prtb_css_index = array();

	$prtb_js_edit = array();
	$prtb_css_edit = array();

	$prtb_js_config = array();
	$prtb_css_config = array();

	foreach($prtb_js_default_arg as $key => $value) {
		$prtb_js_default["{$wpath}/lib/js/default/{$value}.js"] = array();
	}

	foreach($prtb_js_edit_arg as $key => $value) {
		$prtb_js_edit["{$wpath}/lib/js/edit/{$value}.js"] = array();
	}
	foreach($prtb_css_edit_arg as $key => $value) {
		$prtb_css_edit["{$wpath}/lib/css/{$value}.css"] = array("group" => CSS_THEME, "weight" => $key+1);
	}

	foreach($prtb_js_list_arg as $key => $value) {
		$prtb_js_list["{$wpath}/lib/js/list/{$value}.js"] = array();
	}

	foreach($prtb_js_index_arg as $key => $value) {
		$prtb_js_index["{$wpath}/lib/js/front_end/{$value}.js"] = array();
	}
  $wle_map = 'http://maps.googleapis.com/maps/api/js?v=3.exp&sensor=false';
  $prtb_js_index[$wle_map] = array();

	foreach($prtb_css_index_arg as $key => $value) {
		$prtb_css_index["{$wpath}/lib/css/{$value}.css"] = array("group" => CSS_THEME, "weight" => $key+1);
	}


	foreach($prtb_js_config_arg as $key => $value) {
		$prtb_js_config["{$wpath}/lib/js/config/{$value}.js"] = array();
	}
	foreach($prtb_css_config_arg as $key => $value) {
		$prtb_css_config["{$wpath}/lib/css/{$value}.css"] = array("group" => CSS_THEME, "weight" => $key+1);
	}

	$items = array(
		"md_prtb_default" => array(
			"title" => t("Lib for default"),
			"description" => t("Lib for add{Dev}"),
			"version" => "1.0",
			"js" => $prtb_js_default,
		),
		"md_prtb_config" => array(
			"title" => t("Lib for config"),
			"description" => t("Lib for config{Dev}"),
			"version" => "1.0",
			"js" => $prtb_js_config,
			"css" => $prtb_css_config,
		),
		"md_prtb_edit" => array(
			"title" => t("Lib for add"),
			"description" => t("Lib for add{Dev}"),
			"version" => "1.0",
			"js" => $prtb_js_edit,
			"css" => $prtb_css_edit
		),
		"md_prtb_list" => array(
			"title" => t("Lib for list"),
			"description" => t("Lib for list{Dev}"),
			"version" => "1.0",
			"js" => $prtb_js_list,
			"css" => array("{$wpath}/lib/css/jquery-ui-css.css" => array("group" => CSS_THEME, "weight" => 4))
		),
		"md_prtb_index" => array(
			"title" => t("Lib for list"),
			"description" => t("Lib for list{Dev}"),
			"version" => "1.0",
			"js" => $prtb_js_index,
			"css" => $prtb_css_index,
		)
	);

	return $items;
}

function md_prtb_img_style_load() {//load all style image in system
  $styles = image_styles();
  if($styles != null) {
    $select = array();
    foreach($styles as $style) {
      //dsm($style);
      $select[$style['name']] = $style['label'];
    }

    return $select;
  } else {
    return false;
  }
}

function md_prtb_wdt_display($wdts = '') {
  //dsm($wdts);
  $wdt = array();
  if($wdts == null){
    $wdt['config'] = null;
    $wdt['ribbon'] = null;
    $wdt['header'] = null;
    $wdt['price'] = null;
    $wdt['body'] = null;
    $wdt['footer'] = null;
  } else {
    if($wdts->content != null) {
      $prtb_content = drupal_json_decode($wdts->content);
      //dsm($prtb_content);
      foreach($prtb_content as $key => $wdt_temp){
        //dsm($wdt_temp);
        $wdt[$key]['config'] = array(
          'equal_height' => $wdts->equal_height,
          'equal_width' => $wdts->equal_width,
          'column_margin' => $wdts->column_margin,
          'column_width' => $wdts->column_width,
        );
        $wdt[$key]['ribbon'] =  (isset($wdt_temp['json_setting'][0]))?$wdt_temp['json_setting'][0] : null;
        $wdt[$key]['header'] =  (isset($wdt_temp['json_header'][0]))?$wdt_temp['json_header'][0] : null;
        $wdt[$key]['price'] = (isset($wdt_temp['json_price'][0]))?$wdt_temp['json_price'][0] : null;
        $wdt[$key]['body'] = array(
          'setting' => array(
            'tooltip' => $wdts->tooltip,
            'tooltip_bg' => $wdts->tooltip_bg,
            'tooltip_color' => $wdts->tooltip_color,
            'tooltip_width' => $wdts->tooltip_width,
          ),
          'content' => (isset($wdt_temp['json_body'][0]))?$wdt_temp['json_body'][0] : null,
        );
        $wdt[$key]['footer'] = (isset($wdt_temp['json_footer'][0]))?$wdt_temp['json_footer'][0] : null;
        //$wdt['content'] = $prtb_content[0];
      }
    } else {
      $wdt = null;
    }

  }

  return $wdt;
}

function md_prtb_str1($str = '') {
  $wdt = array();
  $position = 0;
  if($str != null) {
    for($i= 0; $i < strlen($str); $i++) {
      if(!is_numeric($str[$i])){
        $position = $i;
        break;
      }
    }
    if($position == 0) {
      $wdt[0] = $str;
      $wdt[1] = $str;
    } else {
      $wdt[0] = substr($str,0,$position);
      $wdt[1] = substr($str,$position);
    }
  }

  return $wdt;
}

function md_prtb_image($content = '') {//input : json content | output : array url file image
  $imgs = array();
  if($content == null) {
    $imgs = null;
  } else {
    $wdts = md_prtb_wdt_display($content);
    if($wdts != null) {
      foreach($wdts as $key => $wdt) {
        if($wdt['header'] != null) {
          $fid_image = $wdt['header']['images'][0]['fid'];
          $fid_map = $wdt['header']['map'][0]['map_fId'];
          if((strlen($fid_image) != 0) && (!isset($imgs[$fid_image]))){
            $imgs[$fid_image] = $fid_image;
          }
          if((strlen($fid_map) != 0) && (!isset($imgs[$fid_map]))){
            $imgs[$fid_map] = $fid_map;
          }
        }
      }
    }
  }

  return $imgs;
}

function md_prtb_custom_css($custom_class = '', $wdts = '') {
  $wle_css = '';
  foreach($wdts as $key => $wdt) {
    if($wdt['json_header'] != null) {
      $wle_data = $wdt['json_header'][0];
      if(strlen($wle_data['custom_class']) != 0) {
        $wle_css .= ".".$wle_data['custom_class']." {";
        $wle_css .= $wle_data['custom_css'];
        $wle_css .= '}';
      }
      $wle_data = null;
    }
    if($wdt['json_body'] != null) {
      $wle_data = $wdt['json_body'][0];
      if(strlen($wle_data['custom_class']) != 0) {
        $wle_css .= ".".$wle_data['custom_class']." {";
        $wle_css .= $wle_data['custom_css'];
        $wle_css .= '}';
      }
      $wle_data = null;
    }
    if($wdt['json_price'] != null) {
      $wle_data = $wdt['json_price'][0];
      if(strlen($wle_data['custom_class']) != 0) {
        $wle_css .= ".".$wle_data['custom_class']." {";
        $wle_css .= $wle_data['custom_css'];
        $wle_css .= '}';
      }
      $wle_data = null;
    }
    if($wdt['json_footer'] != null) {
      $wle_data = $wdt['json_footer'][0];
      if(strlen($wle_data['custom_class']) != 0) {
        $wle_css .= ".".$wle_data['custom_class']." {";
        $wle_css .= $wle_data['custom_css'];
        $wle_css .= '}';
      }
      $wle_data = null;
    }
  }

  $wle_css_file = file_load($custom_class);
  if($wle_css_file == false) {
    $wle_css_file = file_save_data($wle_css,'public://prtb_css_'.time().'.css', FILE_EXISTS_RENAME);
  } else {
    $wle_css_file = file_save_data($wle_css,$wle_css_file->uri, FILE_EXISTS_REPLACE);
  }
  return $wle_css_file->fid;
}

function md_prtb_export() {
  if(isset($_GET['prtb']) && (($_GET['prtb']) != null)) {
    $items = $_GET['prtb'];
  } else {
    $items = null;
  }
  $wle_items = array();
  if($items != null) {
    $wle_items = explode(',', $items);

    if($wle_items != null) {
      $prtb = new MDPRTB();
      $wdts = $prtb->get_other($wle_items);
      $wdts_export = array();
      $imgs_export = array();
      $css_export = array();

      if($wdts != null) {

        $wle_check = array();
        foreach($wdts as $key => $wdt) {
          $css_export[$wdt->custom_class] = $wdt->custom_class;
          $imgs = md_prtb_image($wdt);
          if($imgs != null) {//proccess img to content
            foreach($imgs as $key => $img_id) {
              if(!isset($wle_check['$key'])) {
                $imgs_export[$img_id]= $img_id;
              }
            }
          }
          unset($wdt->id);
          $wdts_export[] = $wdt;
        }
        $wdts_content = serialize($wdts_export);
        $wle_zip =  new prtb_zip();
        $wle_zip->addDirectory("images");
        $wle_zip->addDirectory("css");
        $wle_file_name = 'md_prtb_export_'.time();
        $wle_zip->addFile($wdts_content, $wle_file_name.'.txt');

        if($imgs_export != null) {
          foreach($imgs_export as $key => $img_fid) {
            //var_dump($imgs_export);
            $img = file_load($img_fid);
            if($img != false) {
              $img_type = explode('.',$img->uri);
              $wle_zip->addFile(file_get_contents($img->uri), "images/".$img->fid.".".end($img_type));
            }
            unset($img);
          }
        }

        if($css_export != null) {
          foreach($css_export as $key => $value) {
            $css_file = file_load($key);
            if($css_file != false) {
              $wle_zip->addFile(file_get_contents($css_file->uri), "css/{$css_file->fid}.css");
              unset($css_file);
            }
          }
        }
        //var_dump($css_export);
        //die;
        $wle_zip->sendZip($wle_file_name. '.zip');
      }
    }
  }
}

function md_prtb_import_img_fid($wdts = '', $imgs = '') {//$wdts : content of pricing table, $img : array fid import of image
  //return content and array of image style
  $prtb_content = drupal_json_decode($wdts);
  $wle_img_style = array();
  if($prtb_content != null) {
    foreach($prtb_content as $key => $wdt) {
      if(isset($wdt['json_header'][0]['images'][0]['fid']) && (strlen($wdt['json_header'][0]['images'][0]['fid'])) != 0) {
        $wle_img_fid = $wdt['json_header'][0]['images'][0]['fid'];
        if(isset($imgs[$wle_img_fid])) {
          $img = file_load($imgs[$wle_img_fid]);
          $preview = '<div class="media-item"><div class="media-thumbnail"><img src="'.file_create_url($img->uri).'"  width ="100%" height ="100%"></div></div>';
          $prtb_content[$key]['json_header'][0]['images'][0]['fid'] = $img->fid;
          $prtb_content[$key]['json_header'][0]['images'][0]['img_url'] = file_create_url($img->uri);
          $prtb_content[$key]['json_header'][0]['images'][0]['preview'] = $preview;
          $image_tyle = $prtb_content[$key]['json_header'][0]['images'][0]['img_style'];
          $wle_img_style[$image_tyle] = 1;
        }
      }

      if(isset($wdt['json_header'][0]['map'][0]['map_fId']) && (strlen($wdt['json_header'][0]['map'][0]['map_fId'])) != 0) {
        $wle_img_fid = $wdt['json_header'][0]['map'][0]['map_fId'];
        if(isset($imgs[$wle_img_fid])) {
          $img = file_load($imgs[$wle_img_fid]);
          $preview = '<div class="media-item"><div class="media-thumbnail"><img src="'.file_create_url($img->uri).'" width ="100%" height ="100%" ></div></div>';
          $prtb_content[$key]['json_header'][0]['map'][0]['map_preview'] = $preview;
          $prtb_content[$key]['json_header'][0]['map'][0]['map_fId'] = $img->fid;
          $prtb_content[$key]['json_header'][0]['map'][0]['map_url']= file_create_url($img->uri);
        }
      }

    }
  }

  $wle = array();
  $wle['content'] = drupal_json_encode($prtb_content);
  $wle['image_styles'] = $wle_img_style;
  return $wle;
}
