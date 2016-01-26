<?php

/**
 * @file
 * Theme settings .
 */

function md_springspray_theme_settings_display(&$form, &$form_state) {
    global $base_url;
	$form['md_springspray_settings']['display'] = array(
		'#type' 			    => 'fieldset',
		'#weight' 				=> -1,
		'#prefix'  				=> '<div id="md-display" class="md-tabcontent clearfix">',
		'#suffix'               => '</div><!-- / #md-display -->',
	);

	$form['md_springspray_settings']['display']['display_htmllist'] = array(
		'#markup' 				=> '<div id="md-content-sidebar" class="md-content-sidebar">
                                        <ul class="clearfix">
                                            <li><a href="#s-photo"><i class="fa fa-picture-o"></i>Photo Gallery</a></li>
                                            <li><a href="#s-map"><i class="fa fa-map-marker"></i>Map</a></li>
                                            <li><a href="#s-contact"><i class="fa fa-info-circle"></i>Contact Information</a></li>
                                            <li><a href="#s-404"><i class="fa fa-chain-broken"></i>404 Page</a></li>
                                        </ul>
                                    </div><!-- /.md-content-sidebar -->
			                        <div class="md-content-main">',
		'#weight' 				=> -15,
	);

	$form['md_springspray_settings']['display']['display_htmllistclose'] = array(
		'#markup' 				=> '</div><!-- /.md-listleft -->',
		'#weight' 				=> 15,
	);

/* ================================================================================
================================= Photo Gallery ====================================
==================================================================================*/
    $form['md_springspray_settings']['display']['photostream'] = array(
        '#type'                 => 'fieldset',
        '#weight'               => -6,
        '#prefix'               => '<div id="s-photo" class="md-tabcontent clearfix">',
        '#suffix'               => '</div><!-- / #ds-block -->',
    );

    $form['md_springspray_settings']['display']['photostream']['photostream_wrapper'] = array(
        '#type'                 => 'fieldset',
        '#prefix'               => '<div id="photostream-wrapper">',
        '#suffix'               => '</div>',
    );


    $form['md_springspray_settings']['display']['photostream']['photostream_wrapper']['photostream_image'] = array(
        '#type'                         => 'fieldset',
        '#title'                        => '<h4 class="md-row-title">Photo Stream Images</h4>',
        '#prefix'                       => '<div id="photostream-image-wrapper">',
        "#suffix"                       => '</div>',
    );

    $form['md_springspray_settings']['display']['photostream']['photostream_wrapper']['photostream_image']['gallery_image_slide_wrapper'] = array(
        '#type'                     => 'fieldset',
        '#prefix'                   => '<div id="gallery-image-slide-wrapper" class="gallery-image-slide-wrapper">',
        '#suffix'                   => '</div>'
    );
    $max_num = theme_get_setting('gallery_image_slide_max_num','md_springspray') ? theme_get_setting('gallery_image_slide_max_num','md_springspray') : 1;
    $form['md_springspray_settings']['display']['photostream']['photostream_wrapper']['photostream_image']['gallery_image_slide_content_wrapper']['gallery_popup_add_wrapper'] = array(
        '#markup'                   => '<a class="add-more md-button" data-preview="gallery_image_slide_preview" data-max-num="'.$max_num.'" href="#gallery-image-slide-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_springspray_settings']['display']['photostream']['photostream_wrapper']['photostream_image']['gallery_image_slide_content_wrapper']['gallery_popup_close_wrapper'] = array(
        '#markup'                   => '</div>'
    );
    $form['md_springspray_settings']['display']['photostream']['photostream_wrapper']['photostream_image']['gallery_image_slide_content_wrapper']['gallery_image_slide_preview'] = array(
        '#type'                     => 'fieldset',
        '#prefix'                   => '<div id="gallery_image_slide_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'                    => '</div>'
    );
    $form['md_springspray_settings']['display']['photostream']['photostream_wrapper']['photostream_image']['gallery_image_slide_content_wrapper']['gallery_image_slide_order'] = array(
        '#type'                     => 'hidden',
        '#attributes'               => array(
            'class'                 => 'hidden-order'
        ),
    );
    $form['md_springspray_settings']['display']['photostream']['photostream_wrapper']['photostream_image']['gallery_image_slide_content_wrapper']['gallery_image_slide_max_num'] = array(
        '#type'                     => 'hidden',
        '#attributes'               => array(
            'class'                 => 'hidden-num'
        ),
        '#default_value'            => isset($max_num) ? $max_num : 1,
    );
    $form['md_springspray_settings']['display']['photostream']['photostream_wrapper']['photostream_image']['gallery_image_slide_content_wrapper']['gallery_image_slide_preview']["gallery_image_slide_preview_openhtml"] = array(
        '#markup'                   => '<ul id="gallery_image_slide_sortable" class="sortable">'
    );
    if(theme_get_setting('gallery_image_slide','md_springspray') == null) {
        $gallery_image_slide = array(
            'gallery_image_slide_sortable_no1' => array('image' => '')
        );
    } else {
        $gallery_image_slide = theme_get_setting('gallery_image_slide','md_springspray');
    }
    foreach($gallery_image_slide as $key => $value) {
        $explode = explode("_",$key);
        end($explode);
        $num = current($explode);
        if($gallery_image_slide[$key]['image'] != null && $gallery_image_slide[$key]['image'] != 0) {
            // Load file from fid
            $file = file_load($gallery_image_slide[$key]['image']);
            if(!empty($file->uri)) {
                $img_preview = image_style_url('theme_settings_small',$file->uri);
            }
        } else {
            $img_preview = $base_url.'/'.theme_path().'/img/theme-settings/no_image.png';
        }
        $form['md_springspray_settings']['display']['photostream']['photostream_wrapper']['photostream_image']['gallery_image_slide_content_wrapper']['gallery_image_slide_preview'][$key.'_openhtml'] = array(
            '#markup'               => '<li id="gallery-image-slide-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="gallery-image-slide-sortable-no'.substr($num,2).'"><a href="#" class="md-remove">X</a>'
        );
        $form['md_springspray_settings']['display']['photostream']['photostream_wrapper']['photostream_image']['gallery_image_slide_content_wrapper']['gallery_image_slide_preview'][$key]['gallery_image_slide_preview_no1'] = array(
            '#markup'               => '<div class="media-preview"><img class="media-preview" src="'.$img_preview.'"></div><a href="#" class="select-media md-button">Choose Image</a><input type="hidden" class="data-image-hidden" value="'.$gallery_image_slide[$key]['image'].'" name="gallery_image_slide_upload_'.$num.'"/>'
        );
        $form['md_springspray_settings']['display']['photostream']['photostream_wrapper']['photostream_image']['gallery_image_slide_content_wrapper']['gallery_image_slide_preview'][$key.'_closehtml'] = array(
            '#markup'               => '</li>'
        );
    }

    $form['md_springspray_settings']['display']['photostream']['photostream_wrapper']['photostream_image']['gallery_image_slide_content_wrapper']['gallery_image_slide_preview']["gallery_image_slide_preview_closehtml"] = array(
        '#markup'                   => '</ul>'
    );

////////////////////////////////////////////////////// Google map //////////////////////////////////////////////////////

    $form['md_springspray_settings']['display']['map'] = array(
        '#type'                 => 'fieldset',
        '#weight'               => 1,
        '#prefix'               => '<div id="s-map">',
        '#suffix'               => '</div><!-- / #footer -->',
    );

    $form['md_springspray_settings']['display']['map']['map_info'] = array(
        '#type'                 => 'textarea',
        '#description'          => 'Paste Google Map iframe into this form textarea',
        '#resizable'            => FALSE,
        '#default_value'        =>  theme_get_setting('map_info','md_springspray') ? theme_get_setting('map_info','md_springspray') : 'Please Update Google Map Info.',
        '#prefix'               => '<div class="md-tabcontent-header">
                                            <h3 class="md-tabcontent-title">Map Content</h3>
                                        </div><!-- /.md-row-description -->
                                        <div class="form-group">',
        '#suffix'               => '</div>',
        '#attributes'           => array(
            'class'             => array('input-border normal')
        )
    );
//////////////////////////////////////////// Contact Information ///////////////////////////////////////////////////////
    $form['md_springspray_settings']['display']['display_contact'] = array(
        '#type'                 => 'fieldset',
        '#weight' 				=> 1,
        '#prefix'  				=> '<div id="s-contact">',
        '#suffix'               => '</div><!-- / #footer -->',
    );
    $form['md_springspray_settings']['display']['display_contact']['contact_info'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="contact-info"><h3 class="md-tabcontent-title">Contact Infomation</h3>',
        '#suffix'   => '</div>',
    );
    $form['md_springspray_settings']['display']['display_contact']['contact_info']['_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="contact-info-wrapper">',
        '#suffix'   => '</div>',
        '#attributes'   => array(
            'class' => array('contact-info-wrapper'),
        )
    );
    $max_num = theme_get_setting('contact_info_max_num','md_springspray') ? theme_get_setting('contact_info_max_num','md_springspray') : 1;
    $form['md_springspray_settings']['display']['display_contact']['contact_info']['contact_info_wrapper']['contact_popup_add_wrapper'] = array(
        '#markup'   => '<a class="add-more md-button" data-preview="contact_info_preview" data-max-num="'.$max_num.'" href="#contact-info-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_springspray_settings']['display']['display_contact']['contact_info']['contact_info_wrapper']['contact_popup_close_wrapper'] = array(
        '#markup' => '</div>'
    );
    $form['md_springspray_settings']['display']['display_contact']['contact_info']['contact_info_wrapper']['contact_info_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="contact_info_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_springspray_settings']['display']['display_contact']['contact_info']['contact_info_wrapper']['contact_info_preview']['contact_info_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_springspray_settings']['display']['display_contact']['contact_info']['contact_info_wrapper']['contact_info_preview']['contact_info_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('contact_info_max_num','md_springspray') ? theme_get_setting('contact_info_max_num','md_springspray') : 1,
    );
    $form['md_springspray_settings']['display']['display_contact']['contact_info']['contact_info_wrapper']['contact_info_preview']["contact_info_preview_openhtml"] = array(
        '#markup'   => '<ul id="contact_info_sortable" class="sortable">'
    );
    if(theme_get_setting('contact_info','md_springspray') == null) {
        $contact_info = array(
            'contact_info_sortable_no1' => array(
                'icon' => array(
                    'icon' => '',
                    'bundle' => ''
                ),
                'detail'  => ''
            )
        );
    } else {
        $contact_info = theme_get_setting('contact_info','md_springspray');
    }

    foreach($contact_info as $key => $value){
        $explode = explode("_",$key);
        end($explode);
        $num = current($explode);
        $info_icon = $contact_info[$key]['icon'];
        $form['md_springspray_settings']['display']['display_contact']['contact_info']['contact_info_wrapper']['contact_info_preview'][$key.'_openhtml'] = array(
            '#markup' => '<li id="contact-info-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="contact-info-sortable-no'.substr($num,2).'"><a href="#" class="md-remove">X</a>'
        );
        $form['md_springspray_settings']['display']['display_contact']['contact_info']['contact_info_wrapper']['contact_info_preview'][$key]['contact_info_icon_'.$num] = array(
            '#type' => 'icon_selector',
            '#title'    => 'Contact Icon',
            '#default_bundle' => isset($info_icon['bundle']) ? $info_icon['bundle'] : '',
            '#default_icon' => isset($info_icon['icon']) ? $info_icon['icon'] : '',
            '#prefix'               => '<div class="form-group icon-picker">',
            '#suffix'               => '</div>',
        );

        $form['md_springspray_settings']['display']['display_contact']['contact_info']['contact_info_wrapper']['contact_info_preview'][$key]['contact_info_detail_'.$num] = array(
            '#type'       => 'textarea',
            '#format'     => 'full_html',
            '#title'    => 'Detail',
            '#attributes' => array(
                'class' => array('input-border'),
            ),
            '#default_value' => $contact_info[$key]['detail'],
            '#maxlength' => 1000,
            '#prefix'               => '<div class="form-group">',
            '#suffix'               => '</div>'
        );
        $form['md_springspray_settings']['display']['display_contact']['contact_info']['contact_info_wrapper']['contact_info_preview'][$key.'_closehtml'] = array(
            '#markup' => '</li>'
        );
    }
    $form['md_springspray_settings']['display']['display_contact']['contact_info']['contact_info_wrapper']['contact_info_preview']["contact_info_preview_closehtml"] = array(
        '#markup'   => '</ul>'
    );

////////////////////////////////////////////////////// 404 Page //////////////////////////////////////////////////////
    $form['md_springspray_settings']['display']['404'] = array(
        '#type'                 => 'fieldset',
        '#weight'               => 1,
        '#prefix'               => '<div id="s-404">',
        '#suffix'               => '</div><!-- / #404-page -->',
    );

    $form['md_springspray_settings']['display']['404']['404_title'] = array(
        '#type'                 => 'textfield',
        '#format'               => 'full_html',
        '#prefix'               => '<div class="md-tabcontent-header">
                                            <h3 class="md-tabcontent-title">404 Title</h3>
                                        </div><!-- /.md-row-description -->
                                        <div class="form-group">',
        '#suffix'               => '</div>',
        '#default_value'        =>  theme_get_setting('404_title','md_springspray') ? theme_get_setting('404_title','md_springspray') : t('404 Error!'),
        '#attributes'           => array(
            'class'             => array('input-border normal')
        )
    );
    $form['md_springspray_settings']['display']['404']['404_subtitle'] = array(
        '#type'                 => 'textfield',
        '#prefix'               => '<div class="md-tabcontent-header">
                                            <h3 class="md-tabcontent-title">404 Sub-Title</h3>
                                        </div><!-- /.md-row-description -->
                                        <div class="form-group">',
        '#suffix'               => '</div>',
        '#default_value'        =>  theme_get_setting('404_subtitle','md_springspray') ? theme_get_setting('404_subtitle','md_springspray') : t('The page you are looking for doesn\'t exist.'),
        '#attributes'           => array(
            'class'             => array('input-border normal')
        )
    );
    $form['md_springspray_settings']['display']['404']['404_link'] = array(
        '#type'                 => 'textfield',
        '#prefix'               => '<div class="md-tabcontent-header">
                                            <h3 class="md-tabcontent-title">404 Link Label</h3>
                                        </div><!-- /.md-row-description -->
                                        <div class="form-group">',
        '#suffix'               => '</div>',
        '#default_value'        =>  theme_get_setting('404_link','md_springspray') ? theme_get_setting('404_link','md_springspray') : t('Go back!'),
        '#attributes'           => array(
            'class'             => array('input-border normal')
        )
    );

    $form['md_springspray_settings']['display']['404']['404_static_image'] = array(
        '#type'     => 'fieldset',
        '#title'    => '<h4 class="md-row-title">Custom 404 Static Image Background</h4>',
        '#prefix'   => '<div id="404-static-image-wrapper">',
        '#suffix'   => '</div>',
    );
    if(module_exists('media')) {
        $static = theme_get_setting('404_static_image_upload','md_springspray');
        $form['md_springspray_settings']['display']['404']['404_static_image']['404_static_image_media_wrapper'] = array(
            '#type' => 'container',
            '#attributes'   => array(
                'class'     => array('md-media-wrapper')
            )
        );
        $error_static_image_file = new stdClass();
        $error_static_image_file->url = '';
        $error_static_image_file->fid = '';

        $error_static_image_file_hidden_value = theme_get_setting('404_static_image_upload','md_springspray');
        if(is_array($error_static_image_file_hidden_value)) {
            if($error_static_image_file_hidden_value['fid'] != 0) {
                $file = file_load($error_static_image_file_hidden_value['fid']);
                if($file) {
                    $error_static_image_file->url = $file->url;
                    $error_static_image_file->fid = $file->fid;
                }
            }
        } else {
            if(!empty($error_static_image_file_hidden_value)) {
                $error_static_image_file = json_decode($error_static_image_file_hidden_value);
            }

        }

        $form['md_springspray_settings']['display']['404']['404_static_image']['404_static_image_media_wrapper']['404_static_image_upload_media'] = array(
            '#markup'       => '
                <div class="form-wrapper  mb-20">
                    <h4 class="md-row-title">'.t('Upload 404 Static Image').'</h4>
                        <div class="form-elements">
                            <div class="preview">
                                <img class="img-preview" src="'.(!empty($error_static_image_file->url) ? $error_static_image_file->url : $base_url.'/'.THEME_PATH.'/img/theme-settings/no_image.png').'" alt="">
                            </div>
                        </div>
                        <a href="#" class="media-select-button button element-hidden md-button">'.t('Select').'</a>
                </div>'
        );
        $form['md_springspray_settings']['display']['404']['404_static_image']['404_static_image_media_wrapper']['404_static_image_upload'] = array(
            '#type'         => 'hidden',
            '#default_value' => theme_get_setting('404_static_image_upload','md_springspray'),
            '#attributes'       =>  array(
                'class'         => array('media-hidden-value')
            )
        );
    }

}