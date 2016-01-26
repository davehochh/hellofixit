<div class="col-md-4 col-sm-4 ">
    <article class="news-wrapper clearfix">
        <img src="<?php print image_style_url('blog_thumbnail', $fields['field_blog_thumbnail']->content);?>" alt="" class="bg_hover_image"/>
        <div class="date"><?php print $fields['created']->content;?></div>
        <h4><a href="<?php print $fields['path']->content;?>"><?php print $fields['title']->content;?></a></h4>
        <?php print $fields['body']->content;?>
        <p class="news-link"><strong><a href="<?php print $fields['path']->content;?>"><?php print t('Read more'); ?></a></strong></p>
    </article>
</div>