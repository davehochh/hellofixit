<?php
$hd_image_slide = theme_get_setting('hd_image_slide', 'md_springspray');
?>
<!-- Home Slider -->
<div id="slide01" class="iS iS-SkinDots iS-Fullscreen">
    <!--overlay -->
    <div class="parallax-overlay"></div>
    <!--Start Commands-->
    <div class="iS-Commands">
        <div class="iS-Previous"><i class="fa fa-chevron-left"></i></div>
        <div class="iS-Next"><i class="fa fa-chevron-right"></i></div>
        <div class="iS-Play"><i class="fa fa-play"></i></div>
        <div class="iS-Stop"><i class="fa fa-pause"></i></div>
        <div class="iS-Loopline"></div>
        <div class="iS-Dots">
            <div class="iS-Dot iS-Dotactive"></div>
            <div class="iS-Dot"></div>
            <div class="iS-Dot"></div>
            <div class="iS-Dot"></div>            
        </div>
    </div>
    <!--End Commands-->
      
    <!--Start slider Content-->
    <div class="iS-Content">

        <?php
		  foreach ($hd_image_slide as $key => $value) :
			$explode = explode("_", $key);
			end($explode);
			$num = current($explode);
			if ($hd_image_slide[$key]['image'] != null && $hd_image_slide[$key]['image'] != 0) :
			  // Load file from fid
			  $file = file_load($hd_image_slide[$key]['image']);
			  if ($file) :
		?>
        		<div class="iS-Items" data-loopTime="7000">
            
                    <div class="iS-Item iS-Cinematic iS-CinematicCustom"
                       data-effectIn="fadein" data-effectInTime="100" data-effectInDelay="0" 
                         data-effectOut="fadein" data-effectOutTime="500" data-effectOutDelay="1000">
                         <img class="iS-Image iS-ImageAutofit md-invisible lg-invisible " src="<?php print file_create_url($file->uri); ?>" />
                         
                    </div>
                    
                    <div class="iS-Item"
                       data-effectIn="flipright" data-effectInTime="500" data-effectInDelay="100" 
                         data-effectOut="slideleft fadein" data-effectOutTime="500" data-effectOutDelay="0">
                          <p class="iS-Text slide1-text1 iS-TextHole iS-TextCenter iS-TextMiddle"><?php print $hd_image_slide[$key]['title']; ?></p>
                    </div>
                    
                    <div class="iS-Item"
                       data-effectIn="flipright" data-effectInTime="1000" data-effectInDelay="100" 
                         data-effectOut="slideleft fadein" data-effectOutTime="500" data-effectOutDelay="0">
                           <p class="slide1-text2 iS-TextCenter lead">
                             <?php print $hd_image_slide[$key]['subtitle']; ?>
                         </p>
                    </div>
                    
                </div>
        <?php
			  endif;
			endif;
		  endforeach;
		?>
    
    </div>
    <!--End slider Content-->


</div>
<!--End Slider -->

<?php
$themepath = drupal_get_path('theme', 'md_springspray');
drupal_add_css($themepath . '/css/front/skin-all.css');
drupal_add_css($themepath . '/css/front/slide1-positions-fullscreen.css');
drupal_add_css($themepath . '/css/front/cinematic.css');
drupal_add_css($themepath . '/css/front/index-home4.css');
drupal_add_js($themepath . '/js/front/canvasblur.js');
drupal_add_js($themepath . '/js/front/canvasgrayscale.js');
drupal_add_js($themepath . '/js/front/cinematic.js');
drupal_add_js($themepath . '/js/front/fullscreen.js');
drupal_add_js($themepath . '/js/front/thumbnails-horizontal.js');
drupal_add_js($themepath . '/js/front/infinitySlider.js');
?>

<script>
$(document).ready(function() {
  infinitySlider(
	infinitySliderId = 'slide01',
	infinitySliderCommandsClass = 'iS-Commands',
	
	infinitySliderPreviousButtonClass = 'iS-Previous',
	infinitySliderNextButtonClass = 'iS-Next',
	
	infinitySliderDotsClass = 'iS-Dots',
	infinitySliderDotClass = 'iS-Dot',
	infinitySliderDotActiveClass = 'iS-Dotactive',
	
	
	infinitySliderLoopIndicator ='iS-Loopline',
	
	infinitySliderContentClass ='iS-Content',   
	infinitySliderItemsClass = 'iS-Items',
	infinitySliderItemClass = 'iS-Item',
	infinitySliderAutoStartLoop = true,
	infinitySliderKeyboardNavigation = true,
	infinitySliderTouchNavigation = 'mobile',
	infinitySliderStarterSlide = 1
  )
});
</script>