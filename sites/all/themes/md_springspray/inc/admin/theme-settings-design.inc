<?php

/**
 * @file
 * Theme settings .
 */

function md_springspray_theme_settings_design(&$form, &$form_state) {
    global $base_url;
	$form['md_springspray_settings']['design'] = array(
		'#type' 					=> 'fieldset',
		'#weight' 				=> -4,
		'#prefix'  				=> '<div id="md-design" class="md-tabcontent clearfix">',
		'#suffix'        => '</div><!-- / #md-design -->',
	);
	
	$form['md_springspray_settings']['design']['design_htmllist'] = array(
		'#markup' 				=> '<div id="md-content-sidebar" class="md-content-sidebar">
                                        <ul class="clearfix">
                                            <li><a href="#ds-sidebar"><i class="fa fa-th-list"></i>Sidebar</a></li>
                                            <li><a href="#ds-menu"><i class="fa fa-tasks"></i>Menu</a></li>
                                            <li><a href="#ds-header"><i class="fa fa-align-center"></i>Header</a></li>
                                            <li><a href="#ds-footer"><i class="fa fa-question"></i>Footer</a></li>
                                            <li><a href="#ds-page"><i class="fa fa-newspaper-o"></i>Page</a></li>
                                        </ul>
                                    </div><!-- /.md-content-sidebar -->
			                        <div class="md-content-main">',
		'#weight' 				=> -15,
	);
	$form['md_springspray_settings']['design']['design_htmllistclose'] = array(
		'#markup' 				=> '</div><!-- /.md-listleft -->',
		'#weight' 				=> 15,
	);
    $form['md_springspray_settings']['design']['design_skin'] = array(
        '#type' 					=> 'fieldset',
        '#weight' 				=> 1,
        '#prefix'  				=> '<div id="ds-skin">
                                        <div class="md-tabcontent-row">',
        '#suffix'               => '    </div>
                                    </div><!-- / #ds-general -->',
    );

/* ================================================================================
================================= Menu ============================================
==================================================================================*/

    $form['md_springspray_settings']['design']['design_menu'] = array(
        '#type'                     => 'fieldset',
        '#weight'                   => -9,
        '#prefix'                   => '<div id="ds-menu">',
        '#suffix'                   => '</div><!-- / #ds-block -->',
    );

    $form['md_springspray_settings']['design']['design_menu']['menu_style'] = array(
        '#type'                 => 'select',
        '#options'              => array(
            'default'           => 'Fullscreen Navigation',
            'nav-1'             => 'Navigation Style-1',
            'nav-2'             => 'Navigation Style-2',
            'nav-3'             => 'Navigation Style-3',
            'nav-4'             => 'Navigation Style-4',
            'nav-5'             => 'Navigation Style-5',
            'nav-6'             => 'Navigation Style-6',
        ),
        '#default_value'        => theme_get_setting('menu_style','md_springspray') ? theme_get_setting('menu_style','md_springspray') : 'normal',
        '#attributes'           => array(
            'class'             => array('select')
        ),
        '#prefix'               => '<h3 class="md-tabcontent-title">Select Main Menu Style</h3><div class="form-group">',
        '#suffix'               => '</div>',
        '#field_prefix'         => '<div class="md-selection big">',
        '#field_suffix'         => '</div>',
    );

    $form['md_springspray_settings']['design']['design_menu']['menu_static_image'] = array(
        '#type'     => 'fieldset',
        '#title'    => '<h4 class="md-row-title">Custom Menu Static Image Background</h4>',
        '#prefix'   => '<div id="menu-static-image-wrapper">',
        '#suffix'   => '</div>',
        '#states'   => array(
            // Hide the logo settings when using the default logo.
            'visible' => array(
                ':input[name="menu_style"]' => array(
                    array('value' => 'default'),

                ),
            ),
        ),
    );
    if(module_exists('media')) {
        $static = theme_get_setting('menu_static_image_upload','md_springspray');
        $form['md_springspray_settings']['design']['design_menu']['menu_static_image']['menu_static_image_media_wrapper'] = array(
            '#type' => 'container',
            '#attributes'   => array(
                'class'     => array('md-media-wrapper')
            )
        );
        $menu_static_image_file = new stdClass();
        $menu_static_image_file->url = '';
        $menu_static_image_file->fid = '';

        $menu_static_image_file_hidden_value = theme_get_setting('menu_static_image_upload','md_springspray');
        if(is_array($menu_static_image_file_hidden_value)) {
            if($menu_static_image_file_hidden_value['fid'] != 0) {
                $file = file_load($menu_static_image_file_hidden_value['fid']);
                if($file) {
                    $menu_static_image_file->url = $file->url;
                    $menu_static_image_file->fid = $file->fid;
                }
            }
        } else {
            if(!empty($menu_static_image_file_hidden_value)) {
                $menu_static_image_file = json_decode($menu_static_image_file_hidden_value);
            }

        }

        $form['md_springspray_settings']['design']['design_menu']['menu_static_image']['menu_static_image_media_wrapper']['menu_static_image_upload_media'] = array(
            '#markup'       => '
                <div class="form-wrapper  mb-20">
                    <h4 class="md-row-title">'.t('Upload Menu Static Image').'</h4>
                        <div class="form-elements">
                            <div class="preview">
                                <img class="img-preview" src="'.(!empty($menu_static_image_file->url) ? $menu_static_image_file->url : $base_url.'/'.THEME_PATH.'/img/theme-settings/no_image.png').'" alt="">
                            </div>
                        </div>
                        <a href="#" class="media-select-button button element-hidden md-button">'.t('Select').'</a>
                </div>'
        );
        $form['md_springspray_settings']['design']['design_menu']['menu_static_image']['menu_static_image_media_wrapper']['menu_static_image_upload'] = array(
            '#type'         => 'hidden',
            '#default_value' => theme_get_setting('menu_static_image_upload','md_springspray'),
            '#attributes'       =>  array(
                'class'         => array('media-hidden-value')
            )
        );
    }
/* ==================================================================================
================================= Sidebar ===========================================
====================================================================================*/
    $form['md_springspray_settings']['design']['design_sidebar'] = array(
        '#type'             => 'fieldset',
        '#weight' 				=> -5,
        '#prefix'  				=> '<div id="ds-sidebar">',
        '#suffix'        => '</div><!-- / #ds-block -->',
    );
    $form['md_springspray_settings']['design']['design_sidebar']['sidebar_position'] = array(
        '#type'          => 'select',
        '#default_value' => theme_get_setting('sidebar_position','md_springspray') ? theme_get_setting('sidebar_position','md_springspray') : 'right',
        '#options'       => array(
            'no'        => t('No sidebar'),
            'left'      => t('Left'),
            'right' 	=> t('Right'),
        ),
        '#attributes'           => array(
            'class'             => array('select')
        ),
        '#prefix'                     => '<h3 class="md-tabcontent-title">Sidebar position</h3><div class="form-group">',
        '#suffix'                     => '</div>',
        '#field_prefix'               => '<div class="md-selection medium">',
        '#field_suffix'               => '</div>'
    );
/* ================================================================================
================================= Header ==========================================
==================================================================================*/
    $form['md_springspray_settings']['design']['design_header'] = array(
        '#type'                 => 'fieldset',
        '#weight' 				=> -6,
        '#prefix'  				=> '<div id="ds-header" class="md-tabcontent clearfix">',
        '#suffix'               => '</div><!-- / #ds-block -->',
    );

    $form['md_springspray_settings']['design']['design_header']['header_background'] = array(
        '#type'                 => 'fieldset',
        '#prefix'               => '<div id="header-background">',
        '#suffix'               => '</div>',
    );
    $form['md_springspray_settings']['design']['design_header']['header_background']['header_background_type'] = array(
        '#type'                 => 'select',
        '#title'                => 'Choose header background type',
        '#options'              => array(
            'infinity-slider'   => 'Infinity Slider',
            'swiper-slider'     => 'Swiper Slider',
            'supersized-slider' => 'Supersized Slider',
            'text-ticker'       => 'Text Ticker',
        ),
        '#default_value'        => theme_get_setting('header_background_type','md_springspray') ? theme_get_setting('header_background_type','md_springspray') : 'infinity-slider',
        '#attributes'           => array(
            'class'             => array('select')
        ),
        '#prefix'               => '<h3 class="md-tabcontent-title">Header Background Type</h3><div class="form-group">',
        '#suffix'               => '</div>',
        '#field_prefix'         => '<div class="md-selection big">',
        '#field_suffix'         => '</div>',
    );
    $form['md_springspray_settings']['design']['design_header']['header_background']['header_static_image'] = array(
        '#type'     => 'fieldset',
        '#title'    => '<h4 class="md-row-title">Custom Static Image Background</h4>',
        '#prefix'   => '<div id="header-static-image-wrapper">',
        '#suffix'   => '</div>',
        '#states'   => array(
            // Hide the logo settings when using the default logo.
            'visible' => array(
                ':input[name="header_background_type"]' => array(
                    array('value' => 'text-ticker'),

                ),
            ),
        ),
    );
    if(module_exists('media')) {
        $static = theme_get_setting('header_static_image_upload','md_springspray');
        $form['md_springspray_settings']['design']['design_header']['header_background']['header_static_image']['header_static_image_media_wrapper'] = array(
            '#type' => 'container',
            '#attributes'   => array(
                'class'     => array('md-media-wrapper')
            )
        );
        $hd_static_image_file = new stdClass();
        $hd_static_image_file->url = '';
        $hd_static_image_file->fid = '';

        $hd_static_image_file_hidden_value = theme_get_setting('header_static_image_upload','md_springspray');
        if(is_array($hd_static_image_file_hidden_value)) {
            if($hd_static_image_file_hidden_value['fid'] != 0) {
                $file = file_load($hd_static_image_file_hidden_value['fid']);
                if($file) {
                    $hd_static_image_file->url = $file->url;
                    $hd_static_image_file->fid = $file->fid;
                }
            }
        } else {
            if(!empty($hd_static_image_file_hidden_value)) {
                $hd_static_image_file = json_decode($hd_static_image_file_hidden_value);
            }

        }

        $form['md_springspray_settings']['design']['design_header']['header_background']['header_static_image']['header_static_image_media_wrapper']['header_static_image_upload_media'] = array(
            '#markup'       => '
                <div class="form-wrapper  mb-20">
                    <h4 class="md-row-title">'.t('Upload Header Static Image').'</h4>
                        <div class="form-elements">
                            <div class="preview">
                                <img class="img-preview" src="'.(!empty($hd_static_image_file->url) ? $hd_static_image_file->url : $base_url.'/'.THEME_PATH.'/img/theme-settings/no_image.png').'" alt="">
                            </div>
                        </div>
                        <a href="#" class="media-select-button button element-hidden md-button">'.t('Select').'</a>
                </div>'
        );
        $form['md_springspray_settings']['design']['design_header']['header_background']['header_static_image']['header_static_image_media_wrapper']['header_static_image_upload'] = array(
            '#type'         => 'hidden',
            '#default_value' => theme_get_setting('header_static_image_upload','md_springspray'),
            '#attributes'       =>  array(
                'class'         => array('media-hidden-value')
            )
        );
    }

    $form['md_springspray_settings']['design']['design_header']['header_background']['header_static_image']['header_static_image_alt_text'] = array(
        '#type' => 'textarea',
        '#format' => 'full_html',
        '#title'    => '<h3 class="md-tabcontent-title">'.t('Alternative Text').'</h3>',
        '#resizable'    => false,
        '#default_value'    => theme_get_setting('header_static_image_alt_text','md_springspray') ? theme_get_setting('header_static_image_alt_text','md_springspray') : '',
        '#attributes'       => array(
            'class'         => array('textarea-border big')
        ),
        '#states'   => array(
            // Hide the logo settings when using the default logo.
            'visible' => array(
                ':input[name="header_background_type"]' => array(
                    array('value' => 'text-ticker'),

                ),
            ),
        ),
    );
    $form['md_springspray_settings']['design']['design_header']['header_background']['header_static_image']['header_static_image_small_text'] = array(
        '#type' => 'textfield',
        '#title'    => '<h3 class="md-tabcontent-title">'.t('Small Text').'</h3>',
        '#resizable'    => false,
        '#default_value'    => theme_get_setting('header_static_image_small_text','md_springspray') ? theme_get_setting('header_static_image_small_text','md_springspray') : '',
        '#attributes'                   => array(
            'class'                     => array('input-border')
        ),
        '#prefix'                       => '<div class="form-group">',
        '#suffix'                       => '</div>',
        '#states'   => array(
            // Hide the logo settings when using the default logo.
            'visible' => array(
                ':input[name="header_background_type"]' => array(
                    array('value' => 'text-ticker'),

                ),
            ),
        ),
    );


    $form['md_springspray_settings']['design']['design_header']['header_background']['header_image'] = array(
        '#type'                         => 'fieldset',
        '#title'                        => '<h4 class="md-row-title">Custom Slide Image Background</h4>',
        '#prefix'                       => '<div id="header-image-wrapper">',
        "#suffix"                       => '</div>',
        '#states'                       => array(
            // Hide the logo settings when using the default logo.
            'visible'                   => array(
                ':input[name="header_background_type"]' => array(
                    array('value' => 'infinity-slider'),
                    array('value' => 'swiper-slider'),
                    array('value' => 'supersized-slider'),
                ),
            ),
        ),
    );

    $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['header_slide_delay_time'] = array(
        '#type'                         => 'textfield',
        '#title'                        => 'Slide Delay Time (ms)',
        '#default_value'                => theme_get_setting('header_slide_delay_time','md_springspray') ? theme_get_setting('header_slide_delay_time','md_springspray') : '10000',
        '#attributes'                   => array(
            'class'                     => array('input-border small')
        ),
        '#prefix'                       => '<div class="form-group">',
        '#suffix'                       => '</div>',
        '#states'   => array(
            // Hide the logo settings when using the default logo.
            'visible' => array(
                ':input[name="header_background_type"]' => array(
                    array('value' => 'supersized-slider'),

                ),
            ),
        ),
    );
    $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['header_slide_animation'] = array(
        '#type'                         => 'select',
        '#title'                        => 'Choose header image slide animation',
        '#options'                      =>  array(
            'fade'                      => 'fade',
            'slide'                     => 'slide',
        ),
        '#attributes'                   => array(
            'class'                     => array('select')
        ),
        '#prefix'                       => '<div class="form-group">',
        '#suffix'                       => '</div>',
        '#field_prefix'                 => '<div class="md-selection small">',
        '#field_suffix'                 => '</div>',
        '#default_value'                => theme_get_setting('header_slide_animation','md_springspray'),
        '#states'   => array(
            // Hide the logo settings when using the default logo.
            'visible' => array(
                ':input[name="header_background_type"]' => array(
                    array('value' => 'supersized-slider'),

                ),
            ),
        ),
    );

    $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['hd_image_slide_wrapper'] = array(
        '#type'                     => 'fieldset',
        '#prefix'                   => '<div id="hd-image-slide-wrapper" class="hd-image-slide-wrapper"><h5 class="md-row-title">Header Image Slide</h5>',
        '#suffix'                   => '</div>'
    );
    $max_num = theme_get_setting('hd_image_slide_max_num','md_springspray') ? theme_get_setting('hd_image_slide_max_num','md_springspray') : 1;
    $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['hd_image_slide_content_wrapper']['hd_popup_add_wrapper'] = array(
        '#markup'                   => '<a class="add-more md-button" data-preview="hd_image_slide_preview" data-max-num="'.$max_num.'" href="#hd-image-slide-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['hd_image_slide_content_wrapper']['hd_popup_close_wrapper'] = array(
        '#markup'                   => '</div>'
    );
    $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview'] = array(
        '#type'                     => 'fieldset',
        '#prefix'                   => '<div id="hd_image_slide_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'                    => '</div>'
    );
    $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_order'] = array(
        '#type'                     => 'hidden',
        '#attributes'               => array(
            'class'                 => 'hidden-order'
        ),
    );
    $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_max_num'] = array(
        '#type'                     => 'hidden',
        '#attributes'               => array(
            'class'                 => 'hidden-num'
        ),
        '#default_value'            => isset($max_num) ? $max_num : 1,
    );
    $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview']["hd_image_slide_preview_openhtml"] = array(
        '#markup'                   => '<ul id="hd_image_slide_sortable" class="sortable">'
    );
    if(theme_get_setting('hd_image_slide','md_springspray') == null) {
        $hd_image_slide = array(
            'hd_image_slide_sortable_no1' => array(
                'image' => '',
                'title'     => '',
                'subtitle'  => '',
                'link_label'  => '',
                'link'  => ''
            )
        );
    } else {
        $hd_image_slide = theme_get_setting('hd_image_slide','md_springspray');
    }
    foreach($hd_image_slide as $key => $value) {
        $explode = explode("_",$key);
        end($explode);
        $num = current($explode);
        if($hd_image_slide[$key]['image'] != null && $hd_image_slide[$key]['image'] != 0) {
            // Load file from fid
            $file = file_load($hd_image_slide[$key]['image']);
            if(!empty($file->uri)) {
                $img_preview = image_style_url('theme_settings_small',$file->uri);
            }
        } else {
            $img_preview = $base_url.'/'.theme_path().'/img/theme-settings/no_image.png';
        }
        $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview'][$key.'_openhtml'] = array(
            '#markup'               => '<li id="hd-image-slide-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="hd-image-slide-sortable-no'.substr($num,2).'"><a href="#" class="md-remove">X</a>'
        );
        $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview'][$key]['hd_image_slide_preview_no1'] = array(
            '#markup'               => '<div class="media-preview"><img class="media-preview" src="'.$img_preview.'"></div><a href="#" class="select-media md-button">Choose Image</a><input type="hidden" class="data-image-hidden" value="'.$hd_image_slide[$key]['image'].'" name="hd_image_slide_upload_'.$num.'"/>'
        );
        $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview'][$key]['hd_image_slide_title_preview_'.$num] = array(
            '#type' => 'textfield',
            '#format' => 'full_html',
            '#title'    => 'Title',
            '#attributes' => array(
                'class' => array('input-border'),
            ),
            '#default_value' => $hd_image_slide[$key]['title'],
            '#maxlength' => 1000,
            '#prefix'               => '<div class="form-group">',
            '#suffix'               => '</div>',
        );

        $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview'][$key]['hd_image_slide_subtitle_preview_'.$num] = array(
            '#type'       => 'textfield',
            '#title'      => 'Subtitle',
            '#attributes' => array(
                'class' => array('input-border'),
            ),
            '#default_value' => $hd_image_slide[$key]['subtitle'],
            '#prefix'               => '<div class="form-group">',
            '#suffix'               => '</div>'
        );
        $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview'][$key]['hd_image_slide_link_label_preview_'.$num] = array(
            '#type'       => 'textfield',
            '#title'      => 'Link Label',
            '#attributes' => array(
                'class' => array('input-border'),
            ),
            '#default_value' => $hd_image_slide[$key]['link_label'],
            '#states'                       => array(
                // Hide the logo settings when using the default logo.
                'visible'                   => array(
                    ':input[name="header_background_type"]' => array(
                        array('value' => 'swiper-slider'),
                    ),
                ),
            ),
            '#prefix'               => '<div class="form-group">',
            '#suffix'               => '</div>'
        );
        $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview'][$key]['hd_image_slide_link_preview_'.$num] = array(
            '#type'       => 'textfield',
            '#title'      => 'Link',
            '#attributes' => array(
                'class' => array('input-border'),
            ),
            '#default_value' => $hd_image_slide[$key]['link'],
            '#states'                       => array(
                // Hide the logo settings when using the default logo.
                'visible'                   => array(
                    ':input[name="header_background_type"]' => array(
                        array('value' => 'swiper-slider'),
                    ),
                ),
            ),
            '#prefix'               => '<div class="form-group">',
            '#suffix'               => '</div>'
        );
        $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview'][$key.'_closehtml'] = array(
            '#markup'               => '</li>'
        );
    }

    $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview']["hd_image_slide_preview_closehtml"] = array(
        '#markup'                   => '</ul>'
    );

    /*---------------------------- Supersized Slider Config -----------------------------------------------*/

    $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['header_slide_delay_time'] = array(
        '#type'                         => 'textfield',
        '#title'                        => 'Slide Delay Time (ms)',
        '#default_value'                => theme_get_setting('header_slide_delay_time','md_springspray') ? theme_get_setting('header_slide_delay_time','md_springspray') : '3800',
        '#attributes'                   => array(
            'class'                     => array('input-border small')
        ),
        '#prefix'                       => '<div class="form-group">',
        '#suffix'                       => '</div>',
        '#states'   => array(
            // Hide the logo settings when using the default logo.
            'visible' => array(
                ':input[name="header_background_type"]' => array(
                    array('value' => 'supersized-slider'),

                ),
            ),
        ),
    );
    $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['header_slide_speed'] = array(
        '#type'                         => 'textfield',
        '#title'                        => 'Transition Speed(ms)',
        '#default_value'                => theme_get_setting('header_slide_speed','md_springspray') ? theme_get_setting('header_slide_speed','md_springspray') : '200',
        '#attributes'                   => array(
            'class'                     => array('input-border small')
        ),
        '#prefix'                       => '<div class="form-group">',
        '#suffix'                       => '</div>',
        '#states'   => array(
            // Hide the logo settings when using the default logo.
            'visible' => array(
                ':input[name="header_background_type"]' => array(
                    array('value' => 'supersized-slider'),

                ),
            ),
        ),
        '#weight'                       => -1,
    );
    $form['md_springspray_settings']['design']['design_header']['header_background']['header_image']['header_slide_animation'] = array(
        '#type'                         => 'select',
        '#title'                        => 'Choose header image slide animation',
        '#options'                      =>  array(
            '0'                         => 'none',
            '1'                         => 'fade',
            '2'                         => 'slide top',
            '3'                         => 'slide right',
            '4'                         => 'slide bottom',
            '5'                         => 'slide left',
            '6'                         => 'carousel right',
            '7'                         => 'carousel left',
        ),
        '#attributes'                   => array(
            'class'                     => array('select')
        ),
        '#prefix'                       => '<div class="form-group">',
        '#suffix'                       => '</div>',
        '#field_prefix'                 => '<div class="md-selection medium">',
        '#field_suffix'                 => '</div>',
        '#default_value'                => theme_get_setting('header_slide_animation','md_springspray'),
        '#states'   => array(
            // Hide the logo settings when using the default logo.
            'visible' => array(
                ':input[name="header_background_type"]' => array(
                    array('value' => 'supersized-slider'),

                ),
            ),
        ),
    );
    
    
   // 5. ---------------------------------- Footer --------------------------------------------
    $form['md_springspray_settings']['design']['design_footer'] = array(
        '#type'                     => 'fieldset',
        '#weight' 				    => -8,
        '#prefix'  				    => '<div id="ds-footer">',
        '#suffix'                   => '</div><!-- / #ds-block -->',
    );
    $form['md_springspray_settings']['design']['design_footer']['footer_social'] = array(
        '#type'                     => 'fieldset',
        '#prefix'                   => '<div id="footer-social"><h3 class="md-tabcontent-title">Custom Social Account</h3>',
        '#suffix'                   => '</div>',
    );
    $form['md_springspray_settings']['design']['design_footer']['footer_social']['social_acc_wrapper'] = array(
        '#type'                     => 'fieldset',
        '#prefix'                   => '<div id="ft-social-acc-wrapper">',
        '#suffix'                   => '</div>',
        '#attributes'               => array(
            'class'                 => array('ft-social-acc-wrapper'),
        )
    );
    $max_num = theme_get_setting('ft_social_max_num','md_springspray') ? theme_get_setting('ft_social_max_num','md_springspray') : 1;
    $form['md_springspray_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_popup_add_wrapper'] = array(
        '#markup'                   => '<a class="add-more md-button" data-preview="ft_social_preview" data-max-num="'.$max_num.'" href="#ft-social-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_springspray_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_popup_close_wrapper'] = array(
        '#markup'                   => '</div>'
    );
    $form['md_springspray_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="ft_social_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_springspray_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview']['ft_social_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_springspray_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview']['ft_social_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('ft_social_max_num','md_springspray') ? theme_get_setting('ft_social_max_num','md_springspray') : 1,
    );
    $form['md_springspray_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview']["ft_social_preview_openhtml"] = array(
        '#markup'   => '<ul id="ft_social_sortable" class="sortable">'
    );
    if(theme_get_setting('ft_social','md_springspray') == null) {
        $ft_social = array(
            'ft_social_sortable_no1' => array(
                'icon' => array(
                    'icon' => '',
                    'bundle' => ''
                ),
                'link'  => ''
            )
        );
    } else {
        $ft_social = theme_get_setting('ft_social','md_springspray');
    }

    foreach($ft_social as $key => $value){
        $explode = explode("_",$key);
        end($explode);
        $num = current($explode);
        $social_icon = $ft_social[$key]['icon'];
        $form['md_springspray_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview'][$key.'_openhtml'] = array(
            '#markup' => '<li id="ft-social-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="ft-social-sortable-no'.substr($num,2).'"><a href="#" class="md-remove">X</a>'
        );
        $form['md_springspray_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview'][$key]['ft_social_icon_'.$num] = array(
            '#type' => 'icon_selector',
            '#title'    => 'Social Icon',
            '#default_bundle' => isset($social_icon['bundle']) ? $social_icon['bundle'] : '',
            '#default_icon' => isset($social_icon['icon']) ? $social_icon['icon'] : '',
            '#prefix'               => '<div class="form-group icon-picker">',
            '#suffix'               => '</div>',
        );

        $form['md_springspray_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview'][$key]['ft_social_link_'.$num] = array(
            '#type' => 'textfield',
            '#title'    => 'Social Link',
            '#attributes' => array(
                'class' => array('input-border'),
            ),
            '#default_value' => $ft_social[$key]['link'],
            '#maxlength' => 1000,
            '#prefix'               => '<div class="form-group">',
            '#suffix'               => '</div>'
        );
        $form['md_springspray_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview'][$key.'_closehtml'] = array(
            '#markup' => '</li>'
        );
    }
    $form['md_springspray_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_social_preview']["ft_social_preview_closehtml"] = array(
        '#markup'   => '</ul>'
    );

    $form['md_springspray_settings']['design']['design_footer']['footer_content_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="ft-content-wrapper">',
        '#suffix'   => '</div>'
    );
    $form['md_springspray_settings']['design']['design_footer']['footer_content_wrapper']['footer_text'] = array(
        '#type' => 'textarea',
        '#format' => 'full_html',
        '#title'    => '<h3 class="md-tabcontent-title">'.t('Footer Text Display').'</h3>',
        '#resizable'    => false,
        '#default_value'    => theme_get_setting('footer_text','md_springspray') ? theme_get_setting('footer_text','md_springspray') : 'SpringSpray - Megadrupal Theme - ©2014 - All rights reserved.',
        '#attributes'       => array(
            'class'         => array('textarea-border big')
        )
    );
    $form['md_springspray_settings']['design']['design_footer']['footer_columns']['footer_columns_options'] = array(
        '#type'                  => 'select',
        '#default_value'         => theme_get_setting('footer_columns_options','md_springspray') ? theme_get_setting('footer_columns_options','md_springspray') : '4',
        '#options'               => array(
            '12'                 => t('1 Column'),
            '6'                  => t('2 Columns'),
            '4'                  => t('3 Columns'),
            '3'                  => t('4 Columns'),
        ),
        '#attributes'            => array(
            'class'              => array('select')
        ),
        '#prefix'                     => '<h3 class="md-tabcontent-title">Footer Columns Options</h3><div class="form-group">',
        '#suffix'                     => '</div>',
        '#field_prefix'               => '<div class="md-selection medium">',
        '#field_suffix'               => '</div>'
    );


    /* ================================================================================
================================= Page Title ==========================================
==================================================================================*/

    $form['md_springspray_settings']['design']['design_page'] = array(
        '#type'                     => 'fieldset',
        '#weight'                   => -9,
        '#prefix'                   => '<div id="ds-page">',
        '#suffix'                   => '</div><!-- / #ds-block -->',
    );

    $form['md_springspray_settings']['design']['design_page']['page_static_image'] = array(
        '#type'     => 'fieldset',
        '#title'    => '<h4 class="md-row-title">Custom Page Title Static Image Background</h4>',
        '#prefix'   => '<div id="page-static-image-wrapper">',
        '#suffix'   => '</div>',
    );
    if(module_exists('media')) {
        $static = theme_get_setting('page_static_image_upload','md_springspray');
        $form['md_springspray_settings']['design']['design_page']['page_static_image']['page_static_image_media_wrapper'] = array(
            '#type' => 'container',
            '#attributes'   => array(
                'class'     => array('md-media-wrapper')
            )
        );
        $page_static_image_file = new stdClass();
        $page_static_image_file->url = '';
        $page_static_image_file->fid = '';

        $page_static_image_file_hidden_value = theme_get_setting('page_static_image_upload','md_springspray');
        if(is_array($page_static_image_file_hidden_value)) {
            if($page_static_image_file_hidden_value['fid'] != 0) {
                $file = file_load($page_static_image_file_hidden_value['fid']);
                if($file) {
                    $page_static_image_file->url = $file->url;
                    $page_static_image_file->fid = $file->fid;
                }
            }
        } else {
            if(!empty($page_static_image_file_hidden_value)) {
                $page_static_image_file = json_decode($page_static_image_file_hidden_value);
            }

        }

        $form['md_springspray_settings']['design']['design_page']['page_static_image']['page_static_image_media_wrapper']['page_static_image_upload_media'] = array(
            '#markup'       => '
                <div class="form-wrapper  mb-20">
                    <h4 class="md-row-title">'.t('Upload Page Title Static Image').'</h4>
                        <div class="form-elements">
                            <div class="preview">
                                <img class="img-preview" src="'.(!empty($page_static_image_file->url) ? $page_static_image_file->url : $base_url.'/'.THEME_PATH.'/img/theme-settings/no_image.png').'" alt="">
                            </div>
                        </div>
                        <a href="#" class="media-select-button button element-hidden md-button">'.t('Select').'</a>
                </div>'
        );
        $form['md_springspray_settings']['design']['design_page']['page_static_image']['page_static_image_media_wrapper']['page_static_image_upload'] = array(
            '#type'         => 'hidden',
            '#default_value' => theme_get_setting('page_static_image_upload','md_springspray'),
            '#attributes'       =>  array(
                'class'         => array('media-hidden-value')
            )
        );
    }

}