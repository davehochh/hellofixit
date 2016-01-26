<!--Home slider-->
<section id="home" class="fullscreen">
    <div class="parallax-overlay"></div> 			
    <div class="home-container text-center">				
        <div class="home-title">
            <div id="slideshow-info">
                <div id="slideshow-nav">
                    <div id="slideshow-next"><img class="hover-on" src="<?php print base_path() ?>sites/all/themes/md_springspray/img/right-arrow-off.png" alt="next"></div>
                    <div id="slide-number">&nbsp;</div>
                    <div id="slideshow-prev"><img class="hover-on" src="<?php print base_path() ?>sites/all/themes/md_springspray/img/left-arrow-off.png" alt="prev"></div>
                </div>
                
                <H1 id="slide-caption">&nbsp;</H1>
            </div>
        </div>	
        <!-- slider bottom arrow -->
        <div class="arrow">
            <div class="arrow-block">
                <a class="arrow-up-click" href="#about">                              
                    <img alt="" src="<?php print base_path() ?>sites/all/themes/md_springspray/img/arrow-down.png" />
                </a>
            </div>
        </div>		
    </div>   
    
</section>
<!--End Home-->
<?php
$themepath = drupal_get_path('theme', 'md_springspray');
drupal_add_css($themepath . '/css/front/supersized.css');
drupal_add_js($themepath . '/js/front/supersized.3.2.6.js');
drupal_add_js($themepath . '/js/front/supersized.fa-d.1.1.js');
?>

<?php
$hd_image_slide = theme_get_setting('hd_image_slide', 'md_springspray');
?>

<script type="text/javascript">
jQuery(function ($) {
    "use strict";
	$.supersized({
		slide_interval: <?php print theme_get_setting('header_slide_delay_time','md_springspray'); ?>,
		transition: <?php print theme_get_setting('header_slide_animation','md_springspray'); ?>,
		transition_speed: <?php print theme_get_setting('header_slide_speed','md_springspray')  ?>,
		slides: [
			<?php
			foreach ($hd_image_slide as $key => $value) :
			  $explode = explode("_", $key);
			  end($explode);
			  $num = current($explode);
			  if ($hd_image_slide[$key]['image'] != null && $hd_image_slide[$key]['image'] != 0) :
				// Load file from fid
				$file = file_load($hd_image_slide[$key]['image']);
				if ($file) :
				  print '{"image":"'.file_create_url($file->uri).'","title":"'.$hd_image_slide[$key]['title'].'"},';
				endif;
			  endif;
			endforeach;
			?>
			]  		
	});
});
</script>
<script>
$(document).ready(function () {
	
	/* Home Slider navigation hover
		================================================= */	
	$('.hover-on').hover(function() {
	  var src= this.src;
	  this.src= src.replace(/\.(gif|png|jpe?g)$/, '-on.$1');
	}, function() {
	  var src= this.src;
	  this.src= src.replace(/-on\.(gif|png|jpe?g)$/, '.$1');
	});
	
	$('.hover-on').each(function() {
		var src= this.src;
		$('<img/>').attr('src', src.replace(/\.(gif|png|jpe?g)$/, '-on.$1'));
	});
});

</script>