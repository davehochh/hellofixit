<?php

/**
 * @file
 * Default theme implementation to display a block.
 *
 * Available variables:
 * - $block->subject: Block title.
 * - $content: Block content.
 * - $block->module: Module that generated the block.
 * - $block->delta: An ID for the block, unique within each module.
 * - $block->region: The block region embedding the current block.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - block: The current template type, i.e., "theming hook".
 *   - block-[module]: The module generating the block. For example, the user
 *     module is responsible for handling the default user navigation block. In
 *     that case the class would be 'block-user'.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $block_zebra: Outputs 'odd' and 'even' dependent on each block region.
 * - $zebra: Same output as $block_zebra but independent of any block region.
 * - $block_id: Counter dependent on each block region.
 * - $id: Same output as $block_id but independent of any block region.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $block_html_id: A valid HTML ID and guaranteed unique.
 *
 * @see template_preprocess()
 * @see template_preprocess_block()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<?php
    $icon = variable_get(str_replace('-','_',$block->delta.'_icon_description'));
    $before = variable_get($block->delta.'_text_before');
    $after = variable_get($block->delta.'_text_after');
    $current_path = current_path();
    $region = $block->region;
?>

<?php if($block->delta == 'flickr' || $block->delta == 'form'):?>
    <div class="widget clearfix">
        <?php print render($title_prefix); ?>
        <?php if ($block->subject): ?>
            <h4><?php print $block->subject;?></h4>
        <?php endif;?>
        <?php print render($title_suffix); ?>
        <div <?php print $content_attributes; ?>>
            <?php print $content;?>
        </div>

    </div>
<?php elseif($block->delta == 'header_menu'): ?>
    <?php print render($title_prefix); ?>
    <?php print render($title_suffix); ?>
    <div class="content"<?php print $content_attributes; ?>>
        <?php print $content;?>
    </div>
    <?php print render($title_suffix); ?>
<?php elseif($block->delta == 'menu' || $block->delta == 'footer' || $block->delta == 'header'): ?>
    <?php print $content; ?>
<?php else:?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <div class="container <?php if($region != 'parallax_one' && $region != 'parallax_two' && $region != 'parallax_three' && $region != 'parallax_four'): print ' animaper anim '; endif;?>">
        <?php if($region != 'right_header' && $region != 'footer' && $region != 'navigation'):?>
            <?php print render($title_prefix); ?>
            <?php if(isset($before) && $before != null):?>
                <h4 class="margin <?php if($region == 'resume'): print 'color-white';endif?>"><?php print $before;?></h4>
            <?php endif;?>

            <?php if ($block->subject): ?>
                <?php if($region == 'parallax_one' || $region == 'parallax_two' || $region == 'parallax_three' || $region == 'parallax_four' || $region == 'contact' || $region == 'resume') :?>
                    <h2 class="color-white"><?php print $block->subject;?></h2>
                <?php else:?>
                    <h2><?php print $block->subject;?></h2>
                <?php endif;?>
            <?php endif;?>

            <?php if(isset($after) && $after != null):?>
                <h4 class="margin"><?php print $after;?></h4>
            <?php endif;?>

            <?php if(isset($icon) && isset($icon['bundle'])):?>
                <div class="content-separator">
                    <i class="icon <?php if(isset($icon['bundle'])) {print $icon['bundle'];}?> <?php print $icon['icon'];?>"></i>
                    <span></span>
                </div>
            <?php endif;?>
        <?php endif;?>
        <?php print render($title_suffix); ?>
    </div>
    <div <?php print $content_attributes; ?>>
        <?php print $content; ?>
    </div>


</div>
<?php endif;?>