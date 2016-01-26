<?php

function md_prtb_load_header($md_header = '') {
  $md_media = '';
  if($md_header != null) {
    if($md_header['header_extend'] == 'extend-image') {
      $md_img_style = $md_header['images']['img_style'];
      $md_img_style_list = image_styles();
      $md_img_height = '220px';
      if($md_img_style_list[$md_img_style]){
        $md_img_style = $md_img_style_list[$md_img_style]['effects'];
        $md_img_style = array_pop($md_img_style);
        $md_img_height = $md_img_style['data']['height'] . 'px';
      }
      $fid = $md_header['images']['fid'];
      $md_img_load = file_load($fid);//load file to fid
      if($md_img_load !=  false) {
        $md_media .='    <div class="mdp-background" style="height: '.$md_img_height.';">';
        $md_media .= theme('image_style', array(
            'style_name' => $md_header['images']['img_style'],
            'path' => $md_img_load->uri,
            'attributes' => array(
              'class' => array($md_header['images']['img_custom_class'])
            )
          )
        );
        $md_media .='    </div>';
      }
    } elseif($md_header['header_extend'] == 'extend-video') {
      if(strlen($md_header['video']['height'] > 0)) {
      } else {
        $md_header['video']['height'] = 200;
      }
      $md_media .= '<div class="'.((isset($md_header['video']['custom_class']))? $md_header['video']['custom_class'] : "").'" >';
      if($md_header['video']['video_id'] != null) {
        if($md_header['video']['video_select'] == 'youtube') {
          $md_media .= '<iframe id="player" type="text/html"
                    width="100%"
                    height=" '.$md_header['video']['height'].'"
                    src="http://www.youtube.com/embed/'.$md_header['video']['video_id'].'?enablejsapi=1"
                    frameborder="0"></iframe>';
        } elseif($md_header['video']['video_select'] == 'vimeo') {
          $md_media .= '<iframe src="//player.vimeo.com/video/'.$md_header['video']['video_id'].'"
                  width="100%"
                  height=" '.$md_header['video']['height'].'"
                  frameborder="0" webkitallowfullscreen mozallowfullscreen allowfullscreen>
                  </iframe>';
        }
      }
      $md_media .= '</div>';
    } elseif($md_header['header_extend'] == 'extend-map') {
      drupal_add_js("http://maps.googleapis.com/maps/api/js");
      $rand_id = 'prtb-map-'.rand(10,50).'-'.rand(51,99);
      $md_media .="<input type='hidden' class='setting-hidden-map'"." data='".json_encode($md_header['map'])."'/>";
      $md_media .="<input type='hidden' class='rand-id-hidden-map'"." name='".$rand_id."'/>";
      $md_media .= "<div id='".$rand_id."' class ='setting-active-map'></div>";
    } elseif($md_header['header_extend'] == 'extend-html') {
      $md_media .= $md_header['custom_html'];
    }
  }

  return   $md_media;
}

function md_prtb_ribbron_array($md_key = '') {
  $md_array = array(
    'top-left' => 'ribbon-pos-hidden',
    'top-right' => 'ribbon-pos-hidden',
    'top-ribbon' => 'ribbon-pos-none-hidden-top',
    'bottom-ribbon' => 'ribbon-pos-none-hidden-bottom',
    'flag-left' => 'ribbon-pos-none-hidden-top',
    'flag-right' => 'ribbon-pos-none-hidden-top',
    'burgee-left' => 'ribbon-pos-visible-top',
    'burgee-right' => 'ribbon-pos-visible-top',
  );
  return $md_array[$md_key];
}

function md_prtb_price_style3($md_string = '') {
  $md_data = array();
  $position = 0;
  if($md_string != null) {
    for($i= 0; $i < strlen($md_string); $i++) {
      if(!is_numeric($md_string[$i])){
        $position = $i;
        break;
      }
    }
    if($position == 0) {
      $md_data[0] = $md_string;
      $md_data[1] = $md_string;
    } else {
      $md_data[0] = substr($md_string,0,$position);
      $md_data[1] = substr($md_string,$position);
    }
  }

  return $md_data;
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

function md_prtb_scan_style($md_dirs = '') {
  $md_style_scan = array();
  if(count($md_dirs) != 0) {
    foreach($md_dirs as $key => $md_dir) {
      $md_scan_dir = file_scan_directory($md_dir,'*.*');
      foreach($md_scan_dir as $key => $file) {
        if(strpos($file->filename,'md_prtb_',0) !== false){
          $name_arg = explode('.', $file->filename);
          $name_style =  str_replace('-','_',$name_arg[0]);
          if(strpos($file->filename,'.inc') !== false) {
            $md_style_scan[$name_style]['flag'] = true;
            $md_style_scan[$name_style]['name'] = $name_style;
            $md_style_scan[$name_style]['path'] = str_replace('/'.$file->filename,'',$key);
            $md_style_scan[$name_style]['tpl'] = str_replace('_','-',$name_style);
            $md_style_scan[$name_style]['inc'] = $name_style.'.inc';
            $md_style_scan[$name_style]['css'] = $name_style.'.css';
          }
        }
      }
    }
  }
  if(count($md_style_scan) != 0) {
    foreach($md_style_scan as $name => $value) {
      //dsm($value);
      if(!file_exists($value['path'].'/'.$value['tpl'].'.tpl.php')) {
        $value['flag'] = false;
      }
      if(!file_exists($value['path'].'/'.$value['inc'])) {
        $value['flag'] = false;
      }
      if(!file_exists($value['path'].'/'.$value['css'])) {
        $value['flag'] = false;
      }

      if($value['flag'] == false) {
        unset($md_style_scan[$name]);
      }
    }
  }

  //dsm($md_style_scan);
  return $md_style_scan;
}

function md_prtb_style_load() {//load style
  $md_style_scan = array();
  $md_style_load = array();
  $md_path_theme = drupal_get_path('theme', variable_get('theme_default', NULL));

  array_push($md_style_scan, md_prtb_path.'/templates');
  array_push($md_style_scan, $md_path_theme);
  $md_style_temp =  md_prtb_scan_style($md_style_scan);
  if(count($md_style_temp) != 0) {
    foreach($md_style_temp as $name => $value) {
      $style_name = str_replace('md_prtb_', '', $name);
      $md_style_load[$name]['name'] = ucwords($style_name);
      $md_style_load[$name]['path'] = $value['path'];
    }
  }

  return $md_style_load;
}

function md_prtb_check_machine_name($machine_name = '') {
  $md_prtb = new MD_PRTB();
  return $md_prtb->md_prtb_check_machine_name($machine_name);
}

function md_prtb_check_machine_name_config_form($machine_name = '') {
  $md_prtb = new MD_PRTB();
  $md_machine_name_check = $md_prtb->md_prtb_count_machine_name($machine_name);

  if(($md_machine_name_check == 0) || ($md_machine_name_check == 1)) {
    return false;
  }
  return true;
}

function md_prtb_set_value_in_form() {
  return array(
    'display_block' => 0,
    'display_field' => 0,
    'equal_height' => 0,
    'equal_width' => 0,
    'column_margin' => 0,
    'tooltip_flag' => 0,
  );
}

function md_prtb_form_add($form = '', $form_state = '') {

  $md_style_load = md_prtb_style_load();
  if(count($form_state['input']) == 0) {
    $md_input = array(
      'title' => '',
      'machine_name' => '',
      'description' => '',
      'style_name' => 'md_prtb_default',
      'display_block' => 1,
      'display_field' => 0,
      'equal_height' => 1,
      'equal_width' => 1,
      'column_width' => '200',
      'column_margin' => 10,
      'tooltip_flag' => 0,
      'tooltip_width' => '230',
      'tooltip_bg' => 'rgb(80, 138, 167)',
      'tooltip_color' => 'rgb(255, 255, 255)',
      'content' => '',
      'class_add' => '',
      'custom_class_fid' => 0,
      'created' => time(),
      'modified' => time(),
      'css_content' => '',
      'uid' => 0,
    );
  } else {
    $md_input = $form_state['input'];
  }
  $md_form = array();

  $md_form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),//trs/15/
    '#required' => true,
    '#maxlength' => 255,
    '#default_value' => isset($md_input['title']) ? $md_input['title'] : ''
  );

  $md_form["machine_name"] = array(
    "#type" => "machine_name",
    "#title" => t("Machine name"),
    '#default_value' => isset($md_input['machine_name']) ? $md_input['machine_name'] : '',
    "#maxlength" => MENU_MAX_MENU_NAME_LENGTH_UI,
    "#description" => t("A unique name to identify for the menu. It must only contain lowercase letters, numbers and hyphens."),
    "#machine_name" => array(
      "exists" => 'md_prtb_check_machine_name',
      "source" => array("title"),
      "label" => t("Machine name"),
      "replace_pattern" => "[^a-z0-9-]+",
      "replace" => "-",
    )
  );

  $md_form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => isset($md_input['description']) ? $md_input['description'] : ''
  );

  $md_form['option'] = array(
    '#type' => 'fieldset',
    '#title' => 'Options',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $md_style_templ = array();
  if(count($md_style_load) != 0){
    foreach($md_style_load as $key => $value){
      $md_style_templ[$key] = $value['name'];
    }
  }
  $md_form['option']['style_name'] = array(
    '#type' => 'select',
    '#field_prefix' => '<div style="font-weight: 700;">Choose style: ',
    '#field_suffix' => '</div>',
    '#options' => $md_style_templ,
    '#attributes' => array(
    ),
    '#default_value' => isset($md_input['style_name']) ? $md_input['style_name'] : 'md_prtb_default'
  );

  if(count($md_style_load) != 0){
    foreach($md_style_load as $key => $value){
      require_once($value['path'] . '/' . $key .'.inc');
      if (function_exists($key.'_info')) {
        $md_form['option']['style_name_'.$key] = array(
          '#type' => 'fieldset',
          '#title' => 'Style information : ' . $value['name'],
          '#states' => array(
            'visible' => Array(
              'select[name=style_name]' => array('value' => $key)
            ),
          ),
        );
        $md_info = call_user_func($key.'_info','');
        $md_render = '';
        foreach($md_info as $name => $lists){
          $md_render .= '<h4>'.$name.'</h4>';
          $md_render .= '<ul>';
          foreach($lists as $key_list => $list){
            $md_render .= '<li>'.$list.'</li>';
          }
          $md_render .= '</ul>';
        }
        $md_form['option']['style_name_'.$key]['name'] = array(
          '#markup' => '<div>'.$md_render.'</div>',
        );
      }
    }
  }

  $md_form['option']['column_margin'] = array(
    '#type' => 'hidden',
    '#prefix' => '<div><label style="font-weight: 700;margin-bottom: 10px;" for="column-margin">Space between columns: <span class="md-prtb-slide-px">0</span> px</label>',
    '#suffix' => '<div  id="column-margin" class="md-prtb-slide-load" style="width: 395px;"></div></div>',
    '#attributes' => array(
      'class' => array("md-prtb-slide-width"),
      'data-max-width' => '400'
    ),
    '#default_value' => isset($md_input['column_margin']) ? $md_input['column_margin'] : 200
  );

  $md_form['option']['equal'] = array(
    '#type' => 'fieldset',
    '#title' => 'Equal',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $md_form['option']['equal']['equal_height'] = array(
    '#type' => 'checkbox',
    '#title' => 'Height',
    '#default_value' => isset($md_input['equal_height']) ? $md_input['equal_height'] : 1
  );

  $md_form['option']['equal']['equal_width'] = array(
    '#type' => 'checkbox',
    '#title' => 'Width',
    '#default_value' => isset($md_input['equal_width']) ? $md_input['equal_width'] : 1
  );

  $md_form['option']['equal']['column_option'] = array(
    '#type' => 'fieldset',
    '#title' => 'Column width',
    '#states' => array(
      'visible' => array(
        ':input[name="equal_width"]' => array('checked' => false)
      )
    ),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $md_form['option']['equal']['column_option']['column_width'] = array(
    '#type' => 'hidden',
    '#prefix' => '<div><label style="font-weight: 700;margin-bottom: 10px;" for="column-width">Column width: <span class="md-prtb-slide-px">0</span> px</label>',
    '#suffix' => '<div  id="column-width" class="md-prtb-slide-load" style="width: 395px;"></div></div>',
    '#attributes' => array(
      'class' => array("md-prtb-slide-width"),
      'data-max-width' => '400'
    ),
    '#default_value' => isset($md_input['column_width']) ? $md_input['column_width'] : 200
  );

  $md_form['option']['display'] = array(
    '#type' => 'fieldset',
    '#title' => 'Display',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $md_form['option']['display']['display_block'] = array(
    '#type' => 'checkbox',
    '#title' => 'Block',
    '#default_value' => isset($md_input['display_block']) ? $md_input['display_block'] : 1
  );

  $md_form['option']['display']['display_field'] = array(
    '#type' => 'checkbox',
    '#title' => 'Field',
    '#default_value' => isset($md_input['display_field']) ? $md_input['display_field'] : 0
  );

  $md_form['option']['tooltip_flag'] = array(
    '#type' => 'checkbox',
    '#title' => 'Enable Tooltip',
    '#default_value' => isset($md_input['tooltip_flag']) ? $md_input['tooltip_flag'] : 0
  );

  $md_form['option']['tooltip_option'] = array(
    '#type' => 'fieldset',
    '#states' => array(
      'visible' => array(
        ':input[name="tooltip_flag"]' => array('checked' => true)
      )
    )
  );

  $md_form['option']['tooltip_option']['tooltip_width'] = array(
    '#type' => 'hidden',
    '#prefix' => '<div><label style="font-weight: 700;margin-bottom: 10px;" for="column-margin">Tooltip width: <span class="md-prtb-slide-px">0</span> px</label>',
    '#suffix' => '<div  id="column-margin" class="md-prtb-slide-load" style="width: 395px;margin-bottom: 10px;"></div></div>',
    '#attributes' => array(
      'class' => array("md-prtb-slide-width"),
      'data-max-width' => '400'
    ),
    '#default_value' => isset($md_input['tooltip_width']) ? $md_input['tooltip_width'] : 200
  );

  $md_form['option']['tooltip_option']['tooltip_bg'] = array(
    '#type' => 'hidden',
    '#prefix' => '<div class="input-label">',
    '#suffix' => '<label class="label-checkbox" for="tooltip-bg">Tooltip background color</label></div><br>',
    '#attributes' => array(
      'id' => 'tooltip-bg',
      'class' => array('md-prtb-color'),
    ),
    '#default_value' => isset($md_input['tooltip_bg']) ? $md_input['tooltip_bg'] : 'rgb(80, 138, 167)',
  );

  $md_form['option']['tooltip_option']['tooltip_color'] = array(
    '#type' => 'hidden',
    '#prefix' => '<div class="input-label">',
    '#suffix' => '<label class="label-checkbox" for="tooltip-color">Tooltip color</label></div><br>',
    '#attributes' => array(
      'id' => 'tooltip-color',
      'class' => array('md-prtb-color'),
    ),
    '#default_value' => isset($md_input['tooltip_color']) ? $md_input['tooltip_color'] : 'rgb(80, 138, 167)',
  );

  $md_form['option']['class_add'] = array(
    '#type' => 'textfield',
    '#title' => t('Class add'),
    '#default_value' => isset($md_input['class_add']) ? $md_input['class_add'] : '',
  );

  $md_form['created'] = array(
      '#type' => 'hidden',
      '#default_value' => isset($md_input['created']) ? $md_input['created'] : time(),
    );

  $md_form['modified'] = array(
    '#type' => 'hidden',
    '#default_value' => isset($md_input['modified']) ? $md_input['modified'] : time(),
  );

  $md_form['content'] = array(
    '#type' => 'hidden',
    '#default_value' => isset($md_input['content']) ? $md_input['content'] : '',
  );

  $md_form['css_content'] = array(
    '#type' => 'hidden',
    '#default_value' => isset($md_input['css_content']) ? $md_input['css_content'] : '',
  );

  $md_form['uid'] = array(
    '#type' => 'hidden',
    '#default_value' => isset($md_input['uid']) ? $md_input['uid'] : 0,
  );

  $md_form['custom_class_fid'] = array(
    '#type' => 'hidden',
    '#default_value' => isset($md_input['custom_class_fid']) ? $md_input['custom_class_fid'] : 0,
  );

  $md_form['submit']['create'] = array(
    '#type' => 'submit',
    '#value' => 'Create',
    '#op' => 'create'
  );

  $md_form['submit']['create_and_edit'] = array(
    '#type' => 'submit',
    '#value' => 'Create & edit',
    '#op' => 'create_and_edit',

  );

  $md_form['submit']['save'] = array(
    '#type' => 'submit',
    '#value' => 'Save',
    '#op' => 'save'
  );

  $md_form['submit']['save_and_edit'] = array(
    '#type' => 'submit',
    '#value' => 'Save & edit',
    '#op' => 'save_and_edit'
  );

  return $md_form;
}

class MD_PRTB {

  public $tb = "md_pricing_table";
  public $name = "MD_PRTB";

  function get_all($md_fields = '') {//type: block(=1)/field(=1)/null | wfds : field for table // limit = 30

    if($md_fields == null) {
      $md_fields = array();
    }

    array_push($md_fields, 'id');
    $md_datas = db_select($this->tb,'w')->extend('PagerDefault');
    $md_datas->fields('w', $md_fields);
    $md_datas->limit(30);
    $md_datas->orderBy('created','DESC');

    return $md_datas->execute();
  }

  function get_full($md_type= '', $md_field = '') { // limit = unlimited | wfds : field for query
    if($md_field == null) {
      $md_field = array();
    }
    $md_field[] = 'id';
    $md_data = db_select($this->tb,'w');
    $md_data->fields('w', $md_field);
    if($md_type == 'block'){
      $md_data->condition('display_block','1','=');
    } elseif($md_type == 'field') {
      $md_data->condition('display_field','1','=');
    }
    $md_data->orderBy('created','DESC');

    return $md_data->execute();
  }

  function get_for_export($md_list = '') {

    $md_datas = db_select($this->tb,'w')
      ->fields('w')
      ->condition('id', $md_list,'IN');

    return $md_datas->execute();
  }

  function get_by_id($md_id = null) {
    $md_data = db_select($this->tb,'w')
      ->fields('w')
      ->condition('id', $md_id, '=')
      ->execute()
      ->fetchAll();
    if($md_data == null){
      return false;
    } else {
      return $md_data[0];
    }
  }

  function insert($md_data = '') {
    unset($md_data['op']);
    unset($md_data['form_build_id']);
    unset($md_data['form_token']);
    unset($md_data['form_id']);
    $md_insert = db_insert($this->tb)
      ->fields($md_data)
      ->execute();
    if($md_insert != 0){//check data insert
       $md_custom_class = file_save_data($md_data['css_content'], 'public://md_prtb_css_'.time().'.css', FILE_EXISTS_RENAME);
       $this->update($md_insert, array('custom_class_fid' => $md_custom_class->fid));
       return $md_insert;
    } else {
      return 0;
    }
  }

  function delete($md_id = null) {
    $md_del = db_delete($this->tb)
      ->condition('id',$md_id, '=');
    if($md_del->execute() == 1){//delete record in table: md_pricing_table
      return TRUE;
    } else {
      return FALSE;
    }
  }

  function update($md_id = '', $md_data = ''){
    $md_update = db_update($this->tb)
      ->fields($md_data)
      ->condition('id', $md_id, '=');
    return $md_update->execute();
  }

  function md_prtb_check_machine_name($machine_name = '') {
    $md_select = db_select($this->tb,'w')
      ->fields('w')
      ->condition('machine_name',$machine_name,'=')
      ->execute()
      ->fetchAll(PDO::FETCH_CLASS, $this->name);
    if($md_select == null) {
      return false;
    } else {
      return true;
    }
  }

  function md_prtb_count_machine_name($machine_name = '') {//input field => value is condition
    $md_datas = db_select($this->tb,'w')
      ->fields('w',array('id'))
      ->condition('machine_name', $machine_name,'=')
      ->execute()
      ->fetchAll();
    if(count($md_datas) == 0) {
      return 0;
    } else {
      return count($md_datas);
    }

  }

  function md_prtb_count_machine_name_and_id($md_id = '', $machine_name = '') {//input field => value is condition
    $md_datas = db_select($this->tb,'w')
      ->fields('w', array('id'))
      ->condition('id', $md_id,'<>')
      ->condition('machine_name', $machine_name,'=')
      ->execute()
      ->fetchAll();
    if(count($md_datas) == 0) {
      return 0;
    } else {
      return count($md_datas);
    }

  }

}

function md_prtb_fix_media(){
  $info = system_get_info('module','media');
  // dsm($info);
  if($info['version'] == '7.x-2.0-alpha4'){
    static $included;
    if ($included) {
      return;
    }
    $included = TRUE;
    module_load_include('inc', 'media', 'includes/media.browser');
    $javascript = media_browser_js();
    foreach ($javascript as $key => $definitions) {
      foreach ($definitions as $definition) {
        $function = 'drupal_add_' . $key;
        // Since the arguments to pass are variable, use call_user_func_array().
        // This will not handle all potential drupal_add_*() functions directly
        // but covers the js and library needed here, which are unlikely to be
        // expanded since this function is only a workaround for a wysiwyg
        // limitation.
        call_user_func_array($function, $definition);
      }
    }
    // Add wysiwyg-specific settings.
    $settings = array('wysiwyg_allowed_attributes' => variable_get('media__wysiwyg_allowed_attributes', array('height', 'width', 'hspace', 'vspace', 'border', 'align', 'style', 'class', 'id', 'usemap', 'data-picture-group', 'data-picture-align')));
    drupal_add_js(array('media' => $settings), 'setting');
  } else {
    include_once drupal_get_path("module", "media") . "/wysiwyg_plugins/media.inc";
    // module_load_include('inc', 'media', '/wysiwyg_plugins/media');
    media_include_browser_js();
  }

  return true;
}
