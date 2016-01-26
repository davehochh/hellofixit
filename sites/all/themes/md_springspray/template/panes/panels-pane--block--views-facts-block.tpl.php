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
  
    <!-- Number section -->
    <section id="facts-section" <?php ($bg_style == 'no') ? print 'style="background-image: none;"' : print 'style="background-image:url('.$bg_image.')"'; ?> <?php if ($bg_effect == 'yes') print 'class="parallax" data-stellar-background-ratio="0.5" data-stellar-vertical-offset=""'; ?>>
        <div class="row text-center position-rel">
            <div class="parallax-overlay-bg"></div>
            <div class="facts-section clearfix">
                <div class="container"> 
                    <div class="col-md-10 col-md-offset-1">
                        <?php print render($title_prefix); ?>
						<?php if ($title): ?>
                            <div class="text-center">
                                <h2 class="white"><?php print $title; ?></h2>
                                <?php if($subtitle) : ?><p class="lead"><?php print $subtitle;?></p><?php endif; ?>
                            </div>
                        <?php endif; ?>
                        <?php print render($title_suffix); ?>
                        <?php print render($content); ?>
                    </div>
                </div>
            </div>
        </div>
    </section>
    <!-- End Number section -->

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
