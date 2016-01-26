<?php
/**
 * @file panels-pane.tpl.php
 * Main panel pane template
 *
 * Variables available:
 * - $pane->type: the content type inside this pane
 * - $pane->subtype: The subtype, if applicable. If a view it will be the
 *   view name; if a node it will be the nid, etc.
 * - $title: The title of the content
 * - $content: The actual content
 * - $links: Any links associated with the content
 * - $more: An optional 'more' link (destination only)
 * - $admin_links: Administrative links associated with the content
 * - $feeds: Any feed icons or associated with the content
 * - $display: The complete panels display object containing all kinds of
 *   data including the contexts and all of the other panes being displayed.
 */
?>
<?php if ($pane_prefix): ?>
  <?php print $pane_prefix; ?>
<?php endif; ?>
<div class="<?php print $classes; ?>" <?php print $id; ?> <?php print $attributes; ?>>
  <?php if ($admin_links): ?>
    <?php print $admin_links; ?>
  <?php endif; ?>
  
    <section id="contact-adderss" <?php ($bg_style == 'no') ? print 'style="background-image: none;"' : print 'style="background-image:url('.$bg_image.')"'; ?> <?php if ($bg_effect == 'yes') print 'class="parallax" data-stellar-background-ratio="0.5" data-stellar-vertical-offset=""'; ?>>
        <div class="container">
            <div class="col-lg-12 text-center section-title">
                <?php print render($title_prefix); ?>
				<?php if ($title): ?>
                    <h2><?php print $title; ?></h2>
                    <hr>
                    <?php if($subtitle) : ?><p class="lead"><?php print $subtitle;?></p><?php endif; ?>
                <?php endif; ?>
            </div>
            <div class="col-md-6 col-contact-form ">
                <h4><i class="fa fa-map-marker"></i> <small><?php print t('Send us a postcard'); ?></small></h4>          
                <p class="lead">
                	<?php
					$contact = theme_get_setting('contact_info','md_springspray');
						if(isset($contact)) :
							foreach($contact as $key => $value) :
								print '<strong><i class="fa '.$contact[$key]['icon']['icon'].'"></i></strong> '.str_replace("<br>"," ",$contact[$key]['detail']).'<br>';
							endforeach;
						endif;
					?>
                </p>
                                                    
                <a href="#" class="loc fancybox">Find us on map</a>
                <hr>	
                <div class="profile-social-wrapper text-left">
                    <?php
						$ft_social = theme_get_setting('ft_social','md_springspray');
						$social = "";
						if(isset($ft_social)) :
							foreach($ft_social as $key => $value) :
								$social .= '<a class="link" target="_blank" href="'.$ft_social[$key]['link'].'">
												<div class="cube twitter">
													<div class="frontend">
														<i class="fa '.str_replace('md', 'fa', $ft_social[$key]['icon']['icon']).'"></i>
													</div>
													<div class="back">
														<i class="fa '.str_replace('md', 'fa', $ft_social[$key]['icon']['icon']).'"></i>
													</div>
												</div>
											 </a>';
							endforeach;
						endif;
						print $social;
					?>								
                </div>
                <hr>
            </div>
            <div class="col-md-6 col-contact-form text-center" id="contact">
                <div id="message"></div>
                <?php print render($content); ?>			                       	
            </div> 								
        </div>
        <div class="section-scroll">
            <a class="next-section" href="#section-separator-video"><span class="section-arrow"></span></a>
        </div>
    </section>
    <script>
		$(document).ready(function() {
			$(".loc").fancybox({
				'content': '<?php print theme_get_setting('map_info','md_springspray') ; ?>'
			});
		});
	</script>

  <?php if ($links): ?>
    <div class="links">
      <?php print $links; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <div class="more-link">
      <?php print $more; ?>
    </div>
  <?php endif; ?>
</div>
<?php if ($pane_suffix): ?>
  <?php print $pane_suffix; ?>
<?php endif; ?>
