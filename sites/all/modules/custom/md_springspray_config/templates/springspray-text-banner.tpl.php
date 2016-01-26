<?php
if (theme_get_setting('header_static_image_upload', 'md_springspray')) :
  $file = json_decode(theme_get_setting('header_static_image_upload', 'md_springspray'));
endif;
?>
<section id="home" class="fullscreen" data-stellar-background-ratio="0.6" data-stellar-vertical-offset="" style="background-image:url(<?php print $file->url; ?>);">
    <div class="parallax-overlay-bg"></div> 			
    <div class="home-container text-center">				
        <div class="home-title">
            <div class="banner-title title">						
                    <h1 class="white">
                    	<?php
							$result = explode("\n", theme_get_setting('header_static_image_alt_text','md_springspray'));
							$str = "";
							for($i=1; $i<count($result); $i++) :
								if($i < count($result)-1) :
									$str .= $result[$i]."|";
								else :
									$str .= $result[$i];
								endif;
							endfor;
							$str .= "|".$result[0];
						?>
						<span class="banner-text-rotator"><?php print $result[0] ?></span>
						<span class="alt-text hidden"><?php print $str; ?></span>	
                    </h1>
                    <p class="lead"><?php print theme_get_setting('header_static_image_small_text','md_springspray') ?></p>
                    <a href="#about" class="btn btn-default"><?php print t('Know more'); ?></a>
                </div>
        </div>
        <!-- home bottom arrow -->
        <div class="arrow">
            <div class="arrow-block">
                <a class="arrow-up-click" href="#about">                              
                    <img alt="" src="<?php print base_path() ?>sites/all/themes/md_springspray/img/arrow-down.png" />
                </a>
            </div>
        </div>				
        <!-- End home bottom arrow -->
    </div>            
</section>
<?php
$themepath = drupal_get_path('theme', 'md_springspray');
drupal_add_css($themepath . '/css/front/home-ticker.css');
?>

<script>
$(document).ready(function () {
	var result = $('#home .alt-text').text().split("|");
	var arr = [];
	var i=0;
	for(i=0;i<result.length;i++) {
		arr.push(result[i]);
	}
	
	var ut_word_rotator = function(arr) {
		var counter = 0;                
		setInterval(function() {
		$(".banner-text-rotator").fadeOut(function(){$(this).html(arr[counter=(counter+1)%arr.length]).fadeIn();});}, 4000 );
	}
	
	ut_word_rotator(arr);
});
</script>