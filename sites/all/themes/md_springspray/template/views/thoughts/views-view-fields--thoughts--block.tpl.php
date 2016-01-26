<article class="blog-bl <?php print $fields['field_thoughts_size']->content;?> "> 
    <a href="<?php print $fields['path']->content;?>" class="start-teaser-link">
        <div class="blog-bl-bg "></div>
        <?php if($fields['field_thoughts_background']->content == 'bg-image') : ?>     	
        	<div class="hover-bg" style="background-image: url(<?php print $fields['field_thoughts_background_image']->content ?>)"></div>
        <?php else : ?>
        	<div class="hover-bg" style="background-image: none; background-color:#<?php print $fields['field_thoughts_background_color']->content ?>"></div>
        <?php endif; ?>
        <div class="blog-bl-holder">
            <h4 class="blog-bl-headline">
            	<?php if($fields['field_thoughts_quotes']->content) : ?>
                	<i class="fa fa-quote-left"></i> <?php print $fields['title']->content;?>  <i class="fa fa-quote-right"></i>
                <?php else : ?>
                	<?php print $fields['title']->content;?>
                <?php endif;?>
            </h4>
            <?php if(isset($row->field_body[0]['raw']['summary'])) : ?>
            	<p class="blog-bl-text"> <?php print $row->field_body[0]['raw']['summary']; ?></p>
            <?php endif; ?>
            <p class="more"><a class="white" href="<?php print $fields['path']->content;?>"><?php print t('Read more'); ?></a></p>
        </div> 
    </a>
</article>