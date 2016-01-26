<?php
$hd_image_slide = theme_get_setting('hd_image_slide', 'md_springspray');
?>
<!--Home slider-->
<div id="home-content">              
    <div id="content-top" class="slider">
    
        <!-- Slider nav -->
        <a class="arrow-left" href="#"></a>
        <a class="arrow-right" href="#"></a>
        <!-- End Slider nav -->
        
        <div class="swiper-container">
            <div class="swiper-wrapper">
            
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
                          <div class="swiper-slide" style="background-image:url(<?php print file_create_url($file->uri); ?>)">
                              <!--overlay -->
                              <div class="parallax-overlay"></div>
                              
                              <!-- slider content -->
                              <div class="slider-teaser white">								
                                  <h1><?php print $hd_image_slide[$key]['title']; ?></h1>
                                  <hr>
                                  <div class="slider-teaser-text">
                                      <p><?php print $hd_image_slide[$key]['subtitle']; ?></p>
                                  </div>
                                  <a href="<?php print $hd_image_slide[$key]['link']; ?>" class="slider-teaser-link"><?php print $hd_image_slide[$key]['link_label']; ?></a>
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
                <?php
						endif;
					  endif;
					endforeach;
				?>
                
            </div><!--End Swipper Wrapper -->					
        </div><!-- swiper-container -->
        
        <!-- Swipper pagination -->
        <div class="pagination"></div>
        <!-- End Swipper pagination -->
    </div>		
</div>
<!--End Home slider-->