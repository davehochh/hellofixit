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
  
    <section id="section-separator-video">
        <div id="iconsholder">
            <div class="icons">						
                <div class="ico" id="ico2"></div>
                <div class="ico" id="ico3"></div>
                <div class="ico" id="ico4"></div>
                <div class="ico" id="ico5"></div>
                <div class="ico" id="ico6"></div>
                <div class="ico" id="ico7"></div>
                <div class="ico" id="ico8"></div>
                <div class="ico" id="ico9"></div>
                <div class="ico" id="ico10"></div>
                <div class="ico" id="ico11"></div>
                <div class="ico" id="ico12"></div>
                <div class="ico" id="ico13"></div>
                <div class="ico" id="ico14"></div>
                <div class="ico" id="ico15"></div>
                <div class="ico" id="ico16"></div>
                <div class="ico" id="ico17"></div>
                <div class="ico" id="ico18"></div>
                <div class="ico" id="ico19"></div>
                <div class="ico" id="ico20"></div>
                <div class="ico" id="ico21"></div>
                <div class="ico" id="ico22"></div>
                <div class="ico" id="ico23"></div>
                <div class="ico" id="ico24"></div>
                <div class="ico" id="ico25"></div>
                <div class="ico" id="ico26"></div>
                <div class="ico" id="ico27"></div>
                <div class="ico" id="ico28"></div>
                <div class="ico" id="ico29"></div>
                <div class="ico" id="ico30"></div>
                <div class="ico" id="ico31"></div>
                <div class="ico" id="ico32"></div>
                <div class="ico" id="ico33"></div>
                <div class="ico" id="ico34"></div>
            </div>
        </div>
        <div class="row text-center position-rel">
            <div class="container"> 
                <div class="col-lg-12 text-center section-title">
                    <?php print render($title_prefix); ?>
					<?php if ($title): ?>
                        <h2><?php print $title; ?></h2>
                    	<p class="lead"><?php print $subtitle; ?></p>
                    <?php endif; ?>
                    <?php print render($title_suffix); ?>
                    <?php if(isset($vcode)) : ?>
                    	<?php if(is_numeric($vcode)) : ?>
                        	<a href="http://player.vimeo.com/video/<?php print $vcode; ?>" class="play fancybox-media">
								<i class="fa fa-play-circle"></i>
							</a>
                        <?php else : ?>
                        	<a href="http://www.youtube.com/embed/<?php print $vcode; ?>?autoplay=1" class="play fancybox-media">
								<i class="fa fa-play-circle"></i>
							</a>
                        <?php endif; ?>
					<?php endif; ?>
                </div>
            </div>
        </div>
    </section>

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
