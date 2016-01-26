<?php
/**
 * Add body classes if certain regions have content.
 */
function md_springspray_preprocess_html(&$vars) {
    global $base_url;
    $css = "";
    $themepath = drupal_get_path('theme', 'md_springspray');
    drupal_add_js(array('themePath' => $themepath),'setting');
    if(module_exists('icon') && module_exists('fontello')) {
        $icon_bundles = icon_bundles();
        foreach($icon_bundles as $key => $value) {
            if($value['status'] == 1) {
                fontello_process_attached($key);
            }
        }
    }
    drupal_add_css($themepath . '/fonts/font-face.css');
    drupal_add_css($themepath . '/css/front/bootstrap.css');
    drupal_add_css($themepath . '/css/front/font-awesome.min.css');
    drupal_add_css($themepath . '/fonts/HeliumIconFont/iconfont.css');
    drupal_add_css($themepath . '/css/front/animate.css');
    drupal_add_css($themepath . '/css/front/owl.carousel.css');
    drupal_add_css($themepath . '/css/front/jquery.fancybox.css');
    drupal_add_css($themepath . '/css/front/style.css');
    drupal_add_css($themepath . '/css/front/swipebox.css');
    drupal_add_css($themepath . '/css/front/subscribe.css');


    drupal_add_js('https://maps.googleapis.com/maps/api/js?sensor=false');
    drupal_add_js($themepath . '/js/front/modernizr.custom.js');
    drupal_add_js($themepath . '/js/front/jquery.easing.1.3.min.js');
    drupal_add_js($themepath . '/js/front/nprogress.js');
    drupal_add_js($themepath . '/js/front/NProgress-start.js');
    drupal_add_js($themepath . '/js/front/bootstrap.min.js');
    drupal_add_js($themepath . '/js/front/jquery.counterup.min.js');
    drupal_add_js($themepath . '/js/front/owl.carousel.min.js');
    drupal_add_js($themepath . '/js/front/jquery.stellar.js');
    drupal_add_js($themepath . '/js/front/waypoints.min.js');
    drupal_add_js($themepath . '/js/front/wow.min.js');
    drupal_add_js($themepath . '/js/front/jquery.placeholder.js');
    drupal_add_js($themepath . '/js/front/jquery.tweet.js');
    drupal_add_js($themepath . '/js/front/idangerous.swiper-2.4.min.js');
    drupal_add_js($themepath . '/js/front/home.js');
    drupal_add_js($themepath . '/js/front/jquery.fancybox.pack.js');
    drupal_add_js($themepath . '/js/front/jquery.fancybox-media.js');
    drupal_add_js($themepath . '/js/front/scripts.js');
    drupal_add_js($themepath . '/js/front/velocity.min.js');

    if(!drupal_is_front_page()) {
        drupal_add_css($themepath . '/css/front/blog.css');
    }

    if(theme_get_setting('menu_style','md_springspray') == "default") {
        drupal_add_css($themepath . '/css/front/nav-style1.css');
        drupal_add_js($themepath . '/js/front/nav_style1.js');
    }
    if(theme_get_setting('menu_style','md_springspray') == "nav-1") {
        drupal_add_css($themepath . '/css/front/nav-style2.css');
        drupal_add_js($themepath . '/js/front/nav_style2.js');
        drupal_add_js($themepath . '/js/front/navigation.js');
    }
    if(theme_get_setting('menu_style','md_springspray') == "nav-2") {
        drupal_add_css($themepath . '/css/front/nav-style3.css');
        drupal_add_js($themepath . '/js/front/jquery.sticky.js');
        drupal_add_js($themepath . '/js/front/nav_style3.js');
    }
    if(theme_get_setting('menu_style','md_springspray') == "nav-3") {
        drupal_add_css($themepath . '/css/front/slimmenu.css');
        drupal_add_css($themepath . '/css/front/nav-style4.css');
        drupal_add_js($themepath . '/js/front/jquery.slimmenu.min.js');
        drupal_add_js($themepath . '/js/front/nav_style4.js');
    }
    if(theme_get_setting('menu_style','md_springspray') == "nav-4") {
        drupal_add_css($themepath . '/css/front/nav-style5.css');
        drupal_add_js($themepath . '/js/front/nav_style5.js');
    }
    if(theme_get_setting('menu_style','md_springspray') == "nav-5") {
        drupal_add_css($themepath . '/css/front/nav-style6.css');
        drupal_add_js($themepath . '/js/front/nav_style6.js');
    }
    if(theme_get_setting('menu_style','md_springspray') == "nav-6") {
        drupal_add_css($themepath . '/css/front/nav-style7.css');
        drupal_add_js($themepath . '/js/front/responsive-nav.js');
        drupal_add_js($themepath . '/js/front/dropdown-nav.js');
    }

//////////////////////////////////////////// FAVICON SETTING ////////////////////////////////////////////
    // Add favicon.
    if (theme_get_setting('toggle_fvicon','md_springspray')) {
        $favicon_path = '';
        if(theme_get_setting('default_favicon','md_springspray') == 0) {
            $favicon = theme_get_setting('fvicon_upload','md_springspray');
            if(!empty($favicon)) {
                if(is_array($favicon)) {
                    if($favicon['fid'] != 0) {
                        $file = file_load((string)($favicon['fid']));
                        if($file) {
                            $favicon_path = file_create_url($file->uri);
                        }
                    }
                } else {
                    $file = json_decode($favicon);
                    $favicon_path = $file->url;
                }
            } else {
                $favicon_path = base_url().'/'.$themepath.'/favicon.ico';
            }
        } else {
            $favicon_path = base_url().'/'.$themepath.'/favicon.ico';
        }
        $type = theme_get_setting('favicon_mimetype','md_springspray');
        drupal_add_html_head_link(array('rel' => 'shortcut icon', 'href' => drupal_strip_dangerous_protocols($favicon_path), 'type' => $type));
    }
    // iOs webclip
    if(theme_get_setting('webclip_57_upload','md_springspray')) {
        $file_upload = theme_get_setting('webclip_57_upload','md_springspray');
        if(is_array($file_upload)) {
            if($file_upload['fid'] != 0) {
                $file = file_load($file_upload['fid']);
                if($file) {
                    $path = file_create_url($file->uri);
                    $vars['ios_57'] = $path;
                }
            } else {
                $vars['ios_57'] = '';
            }
        } else {
            $file = json_decode($file_upload);
            $vars['ios_57'] = $file->url;
        }
    } else {
        $vars['ios_57'] = '';
    }
    if(theme_get_setting('webclip_72_upload','md_springspray')) {
        $file_upload = theme_get_setting('webclip_72_upload','md_springspray');
        if(is_array($file_upload)) {
            if($file_upload['fid'] != 0) {
                $file = file_load($file_upload['fid']);
                if($file) {
                    $path = file_create_url($file->uri);
                    $vars['ios_72'] = $path;
                }
            } else {
                $vars['ios_72'] = '';
            }
        } else {
            $file = json_decode($file_upload);
            $vars['ios_72'] = $file->url;
        }
    }
    if(theme_get_setting('webclip_114_upload','md_springspray')) {
        $file_upload = theme_get_setting('webclip_114_upload','md_springspray');
        if(is_array($file_upload)) {
            if($file_upload['fid'] != 0) {
                $file = file_load($file_upload['fid']);
                if($file) {
                    $path = file_create_url($file->uri);
                    $vars['ios_114'] = $path;
                }
            } else {
                $vars['ios_114'] = '';
            }
        } else {
            $file = json_decode($file_upload);
            $vars['ios_114'] = $file->url;
        }
    }
    if(theme_get_setting('webclip_144_upload','md_springspray')) {
        $file_upload = theme_get_setting('webclip_144_upload','md_springspray');
        if(is_array($file_upload)) {
            if($file_upload['fid'] != 0) {
                $file = file_load($file_upload['fid']);
                if($file) {
                    $path = file_create_url($file->uri);
                    $vars['ios_144'] = $path;
                }
            } else {
                $vars['ios_144'] = '';
            }
        } else {
            $file = json_decode($file_upload);
            $vars['ios_144'] = $file->url;
        }
    }


    /* ------------------------- Blog Page ------------------------*/

    if(in_array('node-type-blog',$vars['classes_array'])) {
        $vars['classes_array'][] = 'blog-page';
    }

    /* ----------------------------------------------- Menu ---------------------------------------------------------*/
    /*if(theme_get_setting('menu_sticky','md_springspray')) {
        drupal_add_js(array('menuStickyEnable' => theme_get_setting('menu_sticky','md_springspray')),'setting');
    }
    if(theme_get_setting('menu_bg_color','md_springspray')) {
        $css .= '.main-menu {background-color: #'.theme_get_setting('menu_bg_color','md_springspray').'}'."\n";
    }
    if(theme_get_setting('menu_link_color','md_springspray')) {
        $css .= '.menu-nav li a {color: #'.theme_get_setting('menu_link_color','md_springspray').'}'."\n";
    }
    if(theme_get_setting('menu_link_hover_color','md_springspray')) {
        $css .= '.menu-nav li a:hover {color: #'.theme_get_setting('menu_link_hover_color','md_springspray').'}'."\n";
    }*/
    /* ---------------------------------------------- Header -----------------------------------------------------*/
    $header_bg_type = theme_get_setting('header_background_type','md_springspray');
    drupal_add_js(array('hdBgType' => $header_bg_type),'setting');
    if($header_bg_type == 'image') {
        if(theme_get_setting('header_slide_delay_time','md_springspray')) {
            drupal_add_js(array('hdSlideDelayTime' => theme_get_setting('header_slide_delay_time','md_springspray')),'setting');
        }
        if(theme_get_setting('header_slide_effect','md_springspray')) {
            drupal_add_js(array('hdSlideEffect' => theme_get_setting('header_slide_effect','md_springspray')),'setting');
        }
        if(theme_get_setting('header_slide_animation','md_springspray')) {
            drupal_add_js(array('hdSlideAnimation' => theme_get_setting('header_slide_animation','md_springspray')),'setting');
        }
    }
    if($header_bg_type == 'video') {
        if(theme_get_setting('header_video_resolution','md_springspray')){
            $hd_video_res = theme_get_setting('header_video_resolution','md_springspray');
            drupal_add_js(array('headerVideoRes' => $hd_video_res),'setting');
        }
    }
    if($header_bg_type == 'static') {
        if(theme_get_setting('header_static_image_upload','md_springspray')) {
            $file_upload =  theme_get_setting('header_static_image_upload','md_springspray');
            if(is_array($file_upload)) {
                if($file_upload['fid'] != 0) {
                    $file = file_load($file_upload['fid']);
                    if($file) {
                        $css .= '.text-ticker-holder {background-image : url("'.file_create_url($file->uri).'");}';
                    }
                }
            } else {
                $file = json_decode(($file_upload));
                $css .= '.text-ticker-holder {background-image : url("'.$file->url.'");}';
            }
        }
    }


    /* ----------------------- Parallax  --------------------------*/
    /*for($i=1;$i<=4;$i++){
        if(theme_get_setting('pr_'.$i.'_enabled','md_springspray') == 1) {
            if(theme_get_setting('pr_'.$i.'_overlay_enable','md_springspray') == TRUE){
                if(theme_get_setting('pr_'.$i.'_overlay_color','md_springspray')) {
                    $css .= '#parallax-'.$i.' .overlay { background-color: #'.theme_get_setting(theme_get_setting('pr_'.$i.'_overlay_color','md_springspray')).'; }';
                }
                if(theme_get_setting('pr_'.$i.'_overlay_opacity','md_springspray')) {
                    $css .= '#parallax-'.$i.' .overlay { opacity: '.(theme_get_setting('pr_'.$i.'_overlay_opacity','md_springspray')/100).'; }';
                }
            }
            if(theme_get_setting('pr_'.$i.'_bg_image_upload','md_springspray')) {
                $file_upload =  theme_get_setting('pr_'.$i.'_bg_image_upload','md_springspray');

                // Keep it for old settings
                if(is_array($file_upload)) {
                    if($file_upload['fid'] != 0) {
                        $file = file_load($file_upload['fid']);
                        if($file) {
                            $css .= '#parallax-'.$i.' .parallax-background {background-image : url("'.file_create_url($file->uri).'");}';
                        }
                    }
                } else {
                    $pr_bg = json_decode($file_upload);
                    if(is_object($pr_bg)) {
                        if($pr_bg->fid != 0) {
                            $css .= '#parallax-'.$i.' .parallax-background {background-image : url("'.$pr_bg->url.'");}';
                        }
                    }
                }

            }
        }
    }*/

    /* ---------------------------------------------- 404 Page -----------------------------------------------------*/
    if(theme_get_setting('choose_nf_pattern','md_springspray')) {
        $css .= ".nf-pattern { background: #000000 url(" . $base_url .'/'. $themepath ."/images/background/patterns/". theme_get_setting('choose_nf_pattern','md_springspray') . ".png) repeat scroll center center;}\n";
    }

    $vars['theme_setting_css'] = $css;


    // Enable Responsive
    if (theme_get_setting('responsive','md_springspray')) {
        $menuid = 'main-menu';
        if (!empty($vars['page']['superfish'])) {
            $tmp_array_keys = array_keys($vars['page']['superfish']);
            $menuid = str_replace("_","-",$tmp_array_keys[0]);
        }
        $selecnav = '(function ($) {
            $(function(){
                selectnav(\''.$menuid.'\', {
                    label: \''.t('--- Table of content ---').'\',//first select field
                    nested: true,
                    indent: \'-\'
             });
        });
        })(jQuery);';
        drupal_add_js($selecnav, 'inline');
        $vp = array(
          '#type' => 'html_tag',
          '#tag' => 'meta',
          '#attributes' => array(
            'name' =>  'viewport',
            'content' =>  'width=100%, initial-scale=1, maximum-scale=1, minimum-scale=1, user-scalable=no'
          )
        );
        drupal_add_html_head($vp, 'viewport');
    }

    $vars['theme_setting_css'] = $css;
    //Google Fonts
    if(theme_get_setting('googlewebfonts','md_springspray')) {
        drupal_add_css(theme_get_setting('googlewebfonts'),'external');
    }
    // Typekit
    if (theme_get_setting('typekit_id','md_springspray')) {
        drupal_add_js('http://use.typekit.net/'.theme_get_setting('typekit_id','md_springspray').'.js', 'external');
        drupal_add_js('try{Typekit.load();}catch(e){}', 'inline');
    }

    /* Text/typography
    ---------------------------------------------------------------------------------------- */
    $typography = '';
    // common text
    if (theme_get_setting('text_font','md_springspray') || theme_get_setting('ts_font_color','md_springspray')) {
    $typography = "body {";
    $typography .= md_springspray_font_to_css(theme_get_setting('text_font','md_springspray'));
        if (theme_get_setting('ts_font_color','md_springspray')) {
      $typography .= 'color: #' . theme_get_setting('ts_font_color') . ';';
        }
    $typography   .= "}\n";
    }
    /////
  $text_font_arr = explode("|", theme_get_setting('text_font','md_springspray'));
  if (count($text_font_arr) == 5 && $text_font_arr[0] != '0') {
    $typography   .= '#forum, ul.quicktabs-tabs, #nav ul.sf-menu li li,.ui-widget {font-family: '.$text_font_arr[4].';}';
  }
    /////
    // Text selection
    if (theme_get_setting('tss_bgcolor','md_springspray') || theme_get_setting('tss_tcolor','md_springspray')) {
    $tss_bgcolor = '';
    $tss_tcolor = '';
        if (theme_get_setting('tss_bgcolor','md_springspray')) {
          $tss_bgcolor   = 'background: #'.theme_get_setting('tss_bgcolor','md_springspray').';';
        }
        if (theme_get_setting('tss_tcolor','md_springspray')) {
          $tss_tcolor   = 'color: #'.theme_get_setting('tss_tcolor','md_springspray').';';
        }
    $typography   .= "::-moz-selection {". $tss_bgcolor . $tss_tcolor . "text-shadow: none;}\n";
    $typography   .= "::selection {" . $tss_bgcolor . $tss_tcolor. "text-shadow: none;}\n";
    }
    // link regular
    if (theme_get_setting('l_regular_color','md_springspray') || theme_get_setting('l_regular_st','md_springspray') || theme_get_setting('l_regular__hl','md_springspray') || theme_get_setting('l_regular_ts','md_springspray')) {
    $typography   .= "a:link, #node-title a {";
        if (theme_get_setting('l_regular_color','md_springspray')) {
      $typography   .= 'color: #'.theme_get_setting('l_regular_color','md_springspray').';';
        }
        if (theme_get_setting('l_regular__hl','md_springspray')) {
          $typography   .= 'background-color: #'.theme_get_setting('l_regular__hlc','md_springspray').';';
        }
        if(theme_get_setting('l_regular_st','md_springspray') == 1) {
            $typography .= 'text-decoration: line-through';
        }
        $l_text_style = theme_get_setting('l_regular_ts','md_springspray');
        if ($l_text_style['bold']) {
          $typography   .= 'font-weight: '.$l_text_style['bold'].';';
        }
        if ($l_text_style['italic']) {
          $typography   .= 'font-style: '.$l_text_style['italic'].';';
        }
        if ($l_text_style['underline']) {
          $typography   .= 'text-decoration: '.$l_text_style['underline'].';';
        }
        $typography   .= "}\n";
    }
    // link rollover
    if (theme_get_setting('l_rollover_color','md_springspray') || theme_get_setting('l_rollover_st','md_springspray') || theme_get_setting('l_rollover__hl','md_springspray') || theme_get_setting('l_rollover_ts','md_springspray')) {
        $typography   .= "a:hover, #node-title a:hover {";
        if (theme_get_setting('l_rollover_color')) {
          $typography   .= 'color: #'.theme_get_setting('l_rollover_color','md_springspray').';';
        }
        if (theme_get_setting('l_rollover__hl')) {
          $typography   .= 'background-color: #'.theme_get_setting('l_rollover__hlc','md_springspray').';';
        }
        if(theme_get_setting('l_rollover_st','md_springspray') == 1) {
            $typography .= 'text-decoration: line-through';
        }
        $l_text_style = theme_get_setting('l_rollover_ts','md_springspray');
        if ($l_text_style['bold']) {
          $typography   .= 'font-weight: '.$l_text_style['bold'].';';
        }
        if ($l_text_style['italic']) {
          $typography   .= 'font-style: '.$l_text_style['italic'].';';
        }
        if ($l_text_style['underline']) {
          $typography   .= 'text-decoration: '.$l_text_style['underline'].';';
        }
        $typography   .= "}\n";
    }

    // link visited
    if (theme_get_setting('l_visited_color','md_springspray') || theme_get_setting('l_visited_st','md_springspray') || theme_get_setting('l_visited__hl','md_springspray') || theme_get_setting('l_visited_ts','md_springspray')) {
        $typography   .= "a:visited, #node-title a:visited {";
        if (theme_get_setting('l_visited_color')) {
          $typography   .= 'color: #'.theme_get_setting('l_visited_color','md_springspray').';';
        }
        if (theme_get_setting('l_visited__hl')) {
          $typography   .= 'background-color: #'.theme_get_setting('l_visited__hlc','md_springspray').';';
        }
        if(theme_get_setting('l_visited_st','md_springspray') == 1) {
            $typography .= 'text-decoration: line-through';
        }
        $l_text_style = theme_get_setting('l_visited_ts','md_springspray');
        if ($l_text_style['bold']) {
          $typography   .= 'font-weight: '.$l_text_style['bold'].';';
        }
        if ($l_text_style['italic']) {
          $typography   .= 'font-style: '.$l_text_style['italic'].';';
        }
        if ($l_text_style['underline']) {
          $typography   .= 'text-decoration: '.$l_text_style['underline'].';';
        }
        $typography   .= "}\n";
    }

    // link on
    if (theme_get_setting('l_on_color','md_springspray') || theme_get_setting('l_on_st','md_springspray') || theme_get_setting('l_on_hl','md_springspray') || theme_get_setting('l_on_ts','md_springspray')) {
        $typography   .= "a:focus, a:active, #node-title a:focus, #node-title a:active {";
        if (theme_get_setting('l_on_color')) {
          $typography   .= 'color: #'.theme_get_setting('l_on_color','md_springspray').';';
        }
        if (theme_get_setting('l_on_hl')) {
          $typography   .= 'background-color: #'.theme_get_setting('l_on_hlc','md_springspray').';';
        }
        if(theme_get_setting('l_on_st','md_springspray') == 1) {
            $typography .= 'text-decoration: line-through';
        }
        $l_text_style = theme_get_setting('l_on_ts','md_springspray');
        if ($l_text_style['bold']) {
          $typography   .= 'font-weight: '.$l_text_style['bold'].';';
        }
        if ($l_text_style['italic']) {
          $typography   .= 'font-style: '.$l_text_style['italic'].';';
        }
        if ($l_text_style['underline']) {
          $typography   .= 'text-decoration: '.$l_text_style['underline'].';';
        }
        $typography   .= "}\n";
    }
    // Main menu
    if (theme_get_setting('typo_menu_style','md_springspray') || theme_get_setting('typo_menu_color','md_springspray')) {
        $typography   .= "#menu li{";
        if (theme_get_setting('text_font','md_springspray')) {
          $typography   .= md_springspray_font_to_css(theme_get_setting('typo_menu_style','md_springspray'));
        }

        if (theme_get_setting('typo_menu_color','md_springspray')) {
          $typography   .= 'color: #'.theme_get_setting('typo_menu_color','md_springspray').';';
        }
        $typography   .= "}\n";

        if (theme_get_setting('typo_menu_color','md_springspray')) {
          $typography   .= '#menu li a, #nav ul.sf-menu li a {color: #'.theme_get_setting('typo_menu_color','md_springspray').';}';
        }
        if (theme_get_setting('typo_menu_hover_color','md_springspray')) {
          $typography   .= '#menu li > a:hover,#menu li.sfHover > a, #main li:hover a {color: #'.theme_get_setting('typo_menu_hover_color','md_springspray').';}'."\n";
        }
        if (theme_get_setting('typo_menu_active_color','md_springspray')) {
          $typography   .= '#menu li > a:hover, #menu li.sfHover > a, #menu li a.active, #menu li.active a {color: #'.theme_get_setting('typo_menu_active_color','md_springspray').';}'."\n";
        }
    }
    /*-------------------------------------- Heading --------------------------------*/
    if(theme_get_setting('typo_heading_style_enable','md_springspray') == 1){
        for($i=1;$i<=6;$i++){
            $typography .= 'h'.$i.' {';
            if(theme_get_setting('typo_heading_h'.$i.'_style') || theme_get_setting('typo_heading_h'.$i.'_color','md_springspray')){
                if(theme_get_setting('typo_heading_h'.$i.'_style')){
                    $typography .= md_springspray_font_to_css(theme_get_setting('typo_heading_h'.$i.'_style'));
                }
                if(theme_get_setting('typo_heading_h'.$i.'_color','md_springspray')){
                    $typography .= ' color: #'.theme_get_setting('typo_heading_h'.$i.'_color').';';
                }
            }
            $typography .= "}\n";
        }
    }
    /*------------------------------------ Node title ---------------------------------*/
    if (theme_get_setting('typo_nodetitle_style','md_springspray') || theme_get_setting('nodetitle_color','md_springspray')) {
        $typography   .= "#node-title {";
        if (theme_get_setting('typo_nodetitle_style')) {
          $typography   .= md_springspray_font_to_css(theme_get_setting('typo_nodetitle_style'));
        }

        if (theme_get_setting('nodetitle_color','md_springspray')) {
          $typography   .= 'color: #'.theme_get_setting('nodetitle_color','md_springspray').';';
        }
        $typography   .= "}\n";

        if (theme_get_setting('nodetitle_color')) {
          $typography   .= '#node-title a {color: #'.theme_get_setting('nodetitle_color','md_springspray').';}'."\n";
        }

        if (theme_get_setting('nodetitle_hover_color')) {
          $typography   .= '#node-title a:hover {color: #'.theme_get_setting('nodetitle_hover_color','md_springspray').';}'."\n";
        }
    }

    if (theme_get_setting('nodetitle_enable','md_springspray') == 1) {
        foreach (node_type_get_types() as $type => $name) {
            if (theme_get_setting('typo_n'.$type.'title_style') || theme_get_setting('n'.$type.'title_color','md_springspray')) {
                $typography   .= "#node-title span.node-$type-title {";
                if (theme_get_setting('typo_n'.$type.'title_style')) {
                  $typography   .= md_springspray_font_to_css(theme_get_setting('typo_n'.$type.'title_style','md_springspray'));
                }

                if (theme_get_setting('n'.$type.'title_color','md_springspray')) {
                  $typography   .= 'color: #'.theme_get_setting('n'.$type.'title_color','md_springspray').';';
                }
                $typography   .= "}\n";

                if (theme_get_setting('n'.$type.'title_color','md_springspray')) {
                  $typography   .= '#node-title span.node-'.$type.'-title a {color: #'.theme_get_setting('n'.$type.'title_color','md_springspray').';}'."\n";
                }

                if (theme_get_setting('n'.$type.'title_hover_color','md_springspray')) {
                  $typography   .= '#node-title span.node-'.$type.'-title a:hover {color: #'.theme_get_setting('n'.$type.'title_hover_color','md_springspray').';}'."\n";
                }
            }
        }
    }

    // View block title
    if (theme_get_setting('typo_view_title_style','md_springspray') || theme_get_setting('typo_view_title_color','md_springspray')) {
        $typography   .= ".flx-intro-2 h2 {";
        if (theme_get_setting('typo_view_title_style','md_springspray')) {
            $typography   .= md_springspray_font_to_css(theme_get_setting('typo_view_title_style','md_springspray'));
        }

        if (theme_get_setting('typo_view_title_color')) {
            $typography   .= 'color: #'.theme_get_setting('typo_view_title_color','md_springspray').' !important;';
        }
        $typography   .= "}\n";

    }

    if (theme_get_setting('typo_view_title_enable','md_springspray') == 1) {
        $views = views_get_all_views($reset = FALSE);
        foreach ($views as $view_name => $view) {
            if(($view->disabled) !== true){
                $view_title = $view->name;

                if (theme_get_setting('typo_view_'.$view_title.'_title_style') || theme_get_setting('typo_view_'.$view_title.'_title_color','md_springspray')) {
                    $typography   .= ".flx-intro-2 h2.view-".$view_title."-title {";
                    if (theme_get_setting('typo_view_'.$view_title.'_title_style')) {
                        $typography   .= md_springspray_font_to_css(theme_get_setting('typo_view_'.$view_title.'_title_style','md_springspray'));
                    }

                    if (theme_get_setting('typo_view_'.$view_title.'_title_color','md_springspray')) {
                        $typography   .= 'color: #'.theme_get_setting('typo_view_'.$view_title.'_title_color','md_springspray').' !important;';
                    }
                    $typography   .= "}\n";
                }
            }

        }
    }
    //View block description
    if (theme_get_setting('typo_view_description_style','md_springspray') || theme_get_setting('typo_view_description_color','md_springspray')) {
        $typography   .= ".flx-intro-2 h5.flx-intro-excerpt {";
        if (theme_get_setting('typo_view_description_style','md_springspray')) {
            $typography   .= md_springspray_font_to_css(theme_get_setting('typo_view_description_style','md_springspray'));
        }

        if (theme_get_setting('typo_view_description_color','md_springspray')) {
            $typography   .= 'color: #'.theme_get_setting('typo_view_description_color','md_springspray').' !important;';
        }
        $typography   .= "}\n";

    }

    if (theme_get_setting('typo_view_description_enable','md_springspray') == 1) {
        $views = views_get_all_views($reset = FALSE);
        foreach ($views as $view_name => $view) {
            if(($view->disabled) !== true){
                $view_title = $view->name;

                if (theme_get_setting('typo_view_'.$view_title.'_description_style','md_springspray') || theme_get_setting('typo_view_'.$view_title.'_description_color','md_springspray')) {
                    $typography   .= ".flx-intro-2 span.view-".$view_title."-description {";
                    if (theme_get_setting('typo_view_'.$view_title.'_description_style','md_springspray')) {
                        $typography   .= md_springspray_font_to_css(theme_get_setting('typo_view_'.$view_title.'_description_style','md_springspray'));
                    }

                    if (theme_get_setting('typo_view_'.$view_title.'_description_color','md_springspray')) {
                        $typography   .= 'color: #'.theme_get_setting('typo_view_'.$view_title.'_description_color','md_springspray').' !important;';
                    }
                    $typography   .= "}\n";
                }
            }

        }
    }
    if (theme_get_setting('typo_webformtitle_style','md_springspray') || theme_get_setting('typo_webformtitle_color','md_springspray')) {
        $typography   .= ".flx-map-form span.webform-title{";
        if (theme_get_setting('typo_webformtitle_style','md_springspray')) {
            $typography   .= md_springspray_font_to_css(theme_get_setting('typo_webformtitle_style','md_springspray'));
        }

        if (theme_get_setting('typo_webformtitle_color','md_springspray')) {
            $typography   .= 'color: #'.theme_get_setting('typo_webformtitle_color','md_springspray').' !important;';
        }
        $typography   .= "}\n";

    }
    if (theme_get_setting('typo_webformdescription_style','md_springspray') || theme_get_setting('typo_webformdescription_color','md_springspray')) {
        $typography   .= ".flx-map-form span.webform-description{";
        if (theme_get_setting('typo_webformdescription_style','md_springspray')) {
            $typography   .= md_springspray_font_to_css(theme_get_setting('typo_webformdescription_style','md_springspray'));
        }

        if (theme_get_setting('typo_webformdescription_color','md_springspray')) {
            $typography   .= 'color: #'.theme_get_setting('typo_webformdescription_color','md_springspray').' !important;';
        }
        $typography   .= "}\n";
    }

    $vars['typography'] = $typography;

    /* Get theme settings
    ---------------------------------------------------------------------------------------- */
    $vars['footer_text']   = theme_get_setting('footer_text','md_springspray');
    $vars['header_code']   = theme_get_setting('header_code','md_springspray');
    $vars['footer_code']   = theme_get_setting('footer_code','md_springspray');
    if (theme_get_setting('custom_css','md_springspray')) {
        $vars['custom_css']  = theme_get_setting('custom_css','md_springspray');
    }
    drupal_add_css(path_to_theme() . '/css/ie7.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 7', '!IE' => FALSE), 'preprocess' => FALSE));
}

function md_springspray_font_to_css($font) {
    $font_arr = explode("|", $font);
    $css = "";
    if(count($font_arr) == 6) {
        if ($font_arr[0] != '0') {
            $css = ''.$font_arr[5].';';
        }
    }
    return $css;
}

function md_springspray_expand_font_weight($fw) {
                switch($fw) {
                    case 'n1':
                        $fontExpand = "font-style: normal; font-weight: 100;";
                    break;
                    case 'i1':
                        $fontExpand = "font-style: italic; font-weight: 100;";
                        break;
                    case 'n2':
                        $fontExpand = "font-style: normal; font-weight: 200;";
                    break;
                    case 'i2':
                        $fontExpand = "font-style: italic; font-weight: 200;";
                        break;
                    case 'n3':
                        $fontExpand = "font-style: normal; font-weight: 300;";
                    break;
                    case 'i3':
                        $fontExpand = "font-style: italic; font-weight: 300;";
                        break;
                    case 'n4':
                        $fontExpand = "font-style: normal; font-weight: normal;";
                    break;
                    case 'i4':
                        $fontExpand = "font-style: italic; font-weight: normal";
                        break;
                    case 'n5':
                        $fontExpand = "font-style: normal; font-weight: 500;";
                    break;
                    case 'i5':
                        $fontExpand = "font-style: italic; font-weight: 500;";
                        break;
                    case 'n6':
                        $fontExpand = "font-style: normal; font-weight: 600;";
                    break;
                    case 'i6':
                        $fontExpand = "font-style: italic; font-weight: 600;";
                        break;
                    case 'n7':
                        $fontExpand = "font-style: normal; font-weight: bold;";
                    break;
                    case 'i7':
                        $fontExpand = "font-style: italic; font-weight: bold;";
                        break;
                    case 'n8':
                        $fontExpand = "font-style: normal; font-weight: 800;";
                    break;
                    case 'i8':
                        $fontExpand = "font-style: italic; font-weight: 800;";
                        break;
                    case 'n9':
                        $fontExpand = "font-style: normal; font-weight: 800;";
                    break;
                    case 'i9':
                        $fontExpand = "font-style: italic; font-weight: 800;";
                        break;
                    default:
                        $fontExpand = "";
                }

                return $fontExpand;
            }

/**
 * Override or insert vars into the page template for HTML output.
 */
function md_springspray_process_html(&$vars) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_html_alter($vars);
  }

    $classes = explode(' ', $vars['classes']);
  if ($node = menu_get_object()) {
    $node_type_class = drupal_html_class('node-type-' . $node->type);
    if (in_array($node_type_class, $classes)) {
      theme_get_setting('extra_page_classes','md_springspray') == 0 ? '' : $classes = str_replace($node_type_class, '', $classes);
      $classes = str_replace('node-type-', 'page-type-', $classes);
    }
  }
  $vars['classes'] = trim(implode(' ', $classes));
}



/**
 * Override or insert vars into the page template.
 */
function md_springspray_process_page(&$vars) {
  if(isset($vars['node'])) {
    $node = $vars['node'];
    $vars['page_title'] = $vars['node']->type;
    // Check and create previous and next link of current node
    $nid = $node->nid;
    $node_type = $node->type;
    $query = db_select('node', 'n');
    $query->fields('n', array('nid'))
        ->condition('type', $node_type)
        ->orderBy('nid');
    $result = $query->execute();
    $nids = array();
    while ($record = $result->fetchAssoc()) {
        $nids[] .= $record['nid'];
    }
    $current_node_key =  array_search($nid, $nids);
    if(($current_node_key-1) > 0) {
        $vars['previous_link'] = url('node/'.$nids[$current_node_key-1],array('absolute'=>true));
    }
    if(($current_node_key + 1) != sizeof($nids)) {
        $vars['next_link'] = url('node/'.$nids[$current_node_key+1],array('absolute'=>true));
    }
  }
  
  // Hook into color.module.
  if (module_exists('color')) {
    _color_page_alter($vars);
  }

    $status = drupal_get_http_header("status");
  if($status == "404 Not Found") {
    $vars['theme_hook_suggestions'][] = 'page__404';
  }

    $vars['social_links'] = 0;

  // Always print the site name and slogan, but if they are toggled off, we'll
  // just hide them visually.
  $vars['hide_site_name']   = theme_get_setting('toggle_name','md_springspray') ? FALSE : TRUE;
  $vars['hide_site_slogan'] = theme_get_setting('toggle_slogan','md_springspray') ? FALSE : TRUE;
  if ($vars['hide_site_name']) {
    // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
    $vars['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
  }
  if ($vars['hide_site_slogan']) {
    // If toggle_site_slogan is FALSE, the site_slogan will be empty, so we rebuild it.
    $vars['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
  // Since the title and the shortcut link are both block level elements,
  // positioning them next to each other is much simpler with a wrapper div.
  if (!empty($vars['title_suffix']['add_or_remove_shortcut']) && $vars['title']) {
    // Add a wrapper div using the title_prefix and title_suffix render elements.
    $vars['title_prefix']['shortcut_wrapper'] = array(
      '#markup' => '<div class="shortcut-wrapper clearfix">',
      '#weight' => 100,
    );
    $vars['title_suffix']['shortcut_wrapper'] = array(
      '#markup' => '</div>',
      '#weight' => -99,
    );
    // Make sure the shortcut link is the first item in title_suffix.
    $vars['title_suffix']['add_or_remove_shortcut']['#weight'] = -100;
  }

}

/**
 * Implements hook_preprocess_page().
 */
function md_springspray_preprocess_page(&$vars, $hook) {
    // Page title in node page

    variable_set('site_name', $vars['site_name']);

    if(isset($vars['node'])) {
        $node = $vars['node'];
        $vars['page_title'] = $vars['node']->type;
        // Check and create previous and next link of current node
        $nid = $node->nid;
        $node_type = $node->type;
        $query = db_select('node', 'n');
        $query->fields('n', array('nid'))
            ->condition('type', $node_type)
            ->orderBy('nid');
        $result = $query->execute();
        $nids = array();
        while ($record = $result->fetchAssoc()) {
            $nids[] .= $record['nid'];
        }
        $current_node_key =  array_search($nid, $nids);
        if(($current_node_key-1) > 0) {
            $vars['previous_link'] = url('node/'.$nids[$current_node_key-1],array('absolute'=>true));
        }
        if(($current_node_key + 1) != sizeof($nids)) {
            $vars['next_link'] = url('node/'.$nids[$current_node_key+1],array('absolute'=>true));
        }
    }
    if(theme_get_setting('footer_text','md_springspray')){
        $vars['footer_text'] = theme_get_setting('footer_text','md_springspray');
    }

    $themepath = drupal_get_path('theme', 'md_springspray');

    $node = menu_get_object();
    if ($node && in_array($node->type, array('portfolio'))) {
        // Check and create previous and next link of current node
        $nid = $node->nid;
        $query = db_select('node', 'n');
        $nids  = $query->fields('n', array('nid', 'nid'))
            ->condition('type', $node->type)
            ->condition('status', NODE_PUBLISHED)
            ->orderBy('nid')
            ->execute()
            ->fetchAllKeyed();
        
        $current_node_key = array_search($nid, $nids);
         if (isset($nids[$current_node_key - 1])) {
			$vars['node_previous_link'] = url('node/' . $nids[$current_node_key - 1], array('absolute' => true));
		  }
		  if (isset($nids[$current_node_key + 1])) {
			$vars['node_next_link'] = url('node/' . $nids[$current_node_key + 1], array('absolute' => true));
		  }
    }
}
/**
 * Implements hook_preprocess_maintenance_page().
 */
function md_springspray_preprocess_maintenance_page(&$vars) {
    $theme_path = drupal_get_path('theme','md_springspray');
    if(module_exists('fontello')) {
        drupal_add_css(drupal_get_path('module','fontello').'/css/fontello.fix.css');
        drupal_add_css('public://icon/fontello/fontello/css/fontello.css');
        drupal_add_css('public://icon/fontello/fontello/css/animation.css');
    }
   
    /********************************** Skin ********************************/
    if (theme_get_setting('skins') != '0') {
        drupal_add_css($theme_path . '/css/colors/'.theme_get_setting('skins').'.css', array('group' => CSS_THEME));
    }
    if (!$vars['db_is_active']) {
        unset($vars['site_name']);
    }
    // Always print the site name and slogan, but if they are toggled off, we'll
    // just hide them visually.
    $vars['hide_site_name']   = theme_get_setting('toggle_name') ? FALSE : TRUE;
    $vars['hide_site_slogan'] = theme_get_setting('toggle_slogan') ? FALSE : TRUE;
    if ($vars['hide_site_name']) {
        // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
        $vars['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
    }
    if ($vars['hide_site_slogan']) {
        // If toggle_site_slogan is FALSE, the site_slogan will be empty, so we rebuild it.
        $vars['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
    }
}

function md_springspray_check_und($param) {
    if (isset($param['und'])) {
        return $param['und'][0];
    } else {
        return $param[0];
    }
}
function theme_path() {
    $theme_path = drupal_get_path('theme','md_springspray');

    return $theme_path;
}