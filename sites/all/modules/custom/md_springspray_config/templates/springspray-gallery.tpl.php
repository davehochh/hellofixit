<?php if(count(theme_get_setting('gallery_image_slide','md_springspray')) > 0) : ?>
	<ul class="recentworks clearfix">
        <?php
			  $hd_image_slide = theme_get_setting('gallery_image_slide','md_springspray');
			  foreach($hd_image_slide as $key => $value) :
				  $explode = explode("_",$key);
				  end($explode);
				  $num = current($explode);
				  if($hd_image_slide[$key]['image'] != null && $hd_image_slide[$key]['image'] != 0) :
					  // Load file from fid
					  $file = file_load($hd_image_slide[$key]['image']);
					  if($file) :
						  print '<li><a class="fancybox" data-rel="gallery1" href="'.file_create_url($file->uri).'" title="Mellentesque habitant morbi tristique senectus et netus et malesuada"><img alt="" src="'.image_style_url('gallery_thumb', $file->uri).'"/></a></li>';
					  endif;
				  endif;
			  endforeach;
		?>
    </ul>
<?php endif; ?>