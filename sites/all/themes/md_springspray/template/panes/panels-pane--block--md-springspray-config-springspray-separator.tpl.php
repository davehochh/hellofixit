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
  
    <!-- Separator -->
    <section class="section-separator1 <?php if ($bg_effect == 'yes') print 'parallax'; ?>" <?php ($bg_style == 'no') ? print 'style="background-image: none;"' : print 'style="background-image:url('.$bg_image.')"'; ?> <?php if ($bg_effect == 'yes') print 'data-stellar-background-ratio="0.5" data-stellar-vertical-offset=""'; ?>>
        <div class="row text-center position-rel">
            <div class="parallax-overlay-bg"></div>
            <div class="container"> 
                <div class="quotes clearfix">													
                    <div class="col-lg-12 text-center">
                        <h3 class="white">
                        	<?php print render($title_prefix); ?>
							<?php if ($title): ?>
                                <span class="color"><?php print $title; ?></span>
                            <?php endif; ?>
                            <?php print render($title_suffix); ?>
                            <?php print render($content); ?>
                            <br>
                            <?php
								$result = explode("\n", $alt_text);
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
                            <span class="banner-text-rotator2"><?php print $result[0] ?></span>
                            <span class="alt-text hidden"><?php print $str; ?></span>
                        </h3>
                        <?php print $section_link; ?>
                    </div>							
                </div>
            </div>
        </div>
    </section>
    <!-- End Separator -->
    
    <script>
	$(document).ready(function () {
		var result = $('.section-separator1 .alt-text').text().split("|");
		var arr = [];
		var i=0;
		for(i=0;i<result.length;i++) {
			arr.push(result[i]);
		}
		
		var ut_word_rotator2 = function(arr) {
			var counter = 0;                
			setInterval(function() {
			$(".banner-text-rotator2").fadeOut(function(){$(this).html(arr[counter=(counter+1)%arr.length]).fadeIn();});}, 4000 );
		}
		
		ut_word_rotator2(arr);
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
