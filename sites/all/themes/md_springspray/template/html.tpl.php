<!DOCTYPE html>
<!--[if lt IE 7]>      <html class="no-js lt-ie9 lt-ie8 lt-ie7"> <![endif]-->
<!--[if IE 7]>         <html class="no-js lt-ie9 lt-ie8"> <![endif]-->
<!--[if IE 8]>         <html class="no-js lt-ie9"> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js"> <!--<![endif]-->

<head>
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <?php if(isset($ios_144) && $ios_144 != null) :?><link rel="apple-touch-icon-precomposed" sizes="144x144" href="<?php print $ios_144; ?>"><?php endif;?>
    <?php if(isset($ios_114) && $ios_114 != null) :?><link rel="apple-touch-icon-precomposed" sizes="114x114" href="<?php print $ios_114; ?>"><?php endif;?>
    <?php if(isset($ios_72) && $ios_72 != null)  :?><link rel="apple-touch-icon-precomposed" sizes="72x72" href="<?php print $ios_72; ?>"><?php endif;?>
    <?php if(isset($ios_57) && $ios_57 != null)  :?><link rel="apple-touch-icon-precomposed" sizes="57x57" href="<?php print $ios_57; ?>"><?php endif;?>
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <?php
        print $styles;
        print $scripts;
    ?>
    <style type="text/css">
        <?php if (isset($googlewebfonts)): print $googlewebfonts; endif; ?>
        <?php if (isset($theme_setting_css)): print $theme_setting_css; endif; ?>
        <?php
        // custom typography
        if (isset($typography)): print $typography; endif;
        ?>
        <?php if (isset($custom_css)): print $custom_css; endif; ?>
    </style>
    <?php if (isset($header_code)): print $header_code; endif;?>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php 
		print $page_bottom; 
		if (isset($footer_code)) : print $footer_code; endif;
  ?>
  <script>
		if($(".share-holder").size() > 0) {
			var $current;
			var $dropdown;
			$('body').on("mouseenter", ".share-holder", function () {
				$dropdown = $(this).find('.share-dropdown');
				if ($dropdown.hasClass('dropdown-visible')) {
					$dropdown.removeClass('dropdown-visible');
				} else {
					$dropdown.addClass('dropdown-visible');
				}
				$current = $dropdown;
			}).on("mouseleave", ".share-holder", function () {
					$current.removeClass('dropdown-visible');
			});
			
			/* Window Popup */
			function popWindow(url,winName,w,h) {
			if (window.open) {
				if (poppedWindow) { poppedWindow = ''; }
				windowW = w;
				windowH = h;
				var windowX = (screen.width/2)-(windowW/2);
				var windowY = (screen.height/2)-(windowH/2);
				var myExtra = "status=no,menubar=no,resizable=yes,toolbar=no,scrollbars=yes,addressbar=no";
				var poppedWindow = window.open(url,winName,'width='+w+',height='+h+',top='+windowY+',left=' + windowX + ',' + myExtra + '');
			}
			else {
				alert('Your security settings are not allowing our popup windows to function. Please make sure your security software allows popup windows to be opened by this web application.');
			}
			return false;
		}
	}
	</script>
</body>
</html>