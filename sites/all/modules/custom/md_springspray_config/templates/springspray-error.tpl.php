<?php
if (theme_get_setting('404_static_image_upload', 'md_springspray')) :
  $file = json_decode(theme_get_setting('404_static_image_upload', 'md_springspray'));
endif;
?>
<section id="home" class="fullscreen" data-stellar-background-ratio="0.6" data-stellar-vertical-offset="" style="background-position: 50% 0px; background-image:url(<?php print $file->url; ?>);">
    <div class="home-container text-center">				
        <div class="home-title">
            <div class="banner-title title">							
                    <h1 class="white"><?php print theme_get_setting('404_title','md_springspray'); ?></h1>
                    <p class="lead"><?php print theme_get_setting('404_subtitle','md_springspray'); ?> </p>
                    <a href="<?php print base_path(); ?>" class="btn btn-default"><?php print theme_get_setting('404_link','md_springspray'); ?></a>
                </div>
        </div>				
    </div>           
</section>