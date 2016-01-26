<section class="col-md-<?php print theme_get_setting('footer_columns_options','md_springspray'); ?> col-sm-6 <?php print $classes; ?>"<?php print $attributes; ?> id="<?php print $block_html_id; ?>">
    <?php print render($title_prefix); ?>
	<?php if ($block->subject): ?>
        <h4><small class="white"><?php print $block->subject;?></small></h4>
    <?php endif;?>
    <?php print render($title_suffix); ?>
    <?php print $content ;?>
</section>