<?php
$terms = "";
if(isset($node->field_blog_tags['und'])) :
	foreach($node->field_blog_tags['und'] as $row) {
		$term = taxonomy_term_load($row['tid']);
		$term_uri = taxonomy_term_uri($term);
		$terms .= '<a href="'.base_path().$term_uri['path'].'">'.$term->name.'</a>' . ', ';
	}
endif;
?>
<!-- Blog wrapper -->
<div class="single-blog-wrapper clearfix">
  <article>
      <div class="post-header clearfix">
          <h4><?php print $node->title; ?></h4>
          <p>
            <?php print format_date($node->created, 'custom', 'M d, Y'); ?> | 
            <?php print $node->name; ?> | 
            <?php print substr($terms, 0, -2); ?> | 
            <?php print $node->comment_count; ?> <?php print t('Comments'); ?></p>										
          <hr>
      </div>
      
      <div class="featured-image">
          <?php if($node->field_blog_multimedia['und'][0]['file']->type == 'video') : ?>
            <?php $uri = explode('v/',$node->field_blog_multimedia['und'][0]['file']->uri); ?>
            <div class="video-inner-3 blog-video">
                <?php if($node->field_blog_multimedia['und'][0]['file']->filemime == 'video/vimeo') : ?>
                    <iframe src="http://player.vimeo.com/video/<?php print $uri[1]; ?>?title=0&amp;byline=0&amp;portrait=0&amp;color=ec155a" ></iframe>
                <?php else : ?>
                    <iframe src="http://www.youtube.com/embed/<?php print $uri[1]; ?>?feature=oembed" ></iframe>
                <?php endif; ?>
            </div>
          <?php else : ?>
            <div class="video-inner-3"><?php print render($content['field_blog_multimedia']); ?></div>
          <?php endif; ?>
      </div>
      <div class="single-post-content clearfix">
          <?php print render($content['body']); ?>
      </div>
      <div class="single-post-tags">
          <span><?php print t('Tags'); ?>: </span>
          <?php print substr(str_replace(",","",$terms), 0, -2); ?>
      </div>
  </article>
  <section class="bottom-meta-section clearfix">
      <div class="float-left comments-holder"><a href="#"><?php print $node->comment_count; ?> <?php print t('Comment(s)'); ?></a></div>
      <div class="float-right">
          <?php $content['rate_blog_vote']['#title'] = '';?>
          <?php print render($content['rate_blog_vote']);?>
      </div>
      <div class="float-right">
          <div class="share-holder"><i class="fa fa-share-alt"></i> <?php print t('Share'); ?>							
          <!-- BEGIN .share-dropdown -->
          <div class="share-dropdown share-dropdown-box">
              <ul class="blog-social-share">
                  <li><a class="facebook-share" onclick="popWindow('http://www.facebook.com/sharer.php?u=<?php print base_path().drupal_get_path_alias("node/$node->nid"); ?>','Facebook','500','400');" title="Facebook" rel="tooltip" data-placement="right"><i class="fa fa-facebook"></i></a></li>
                  <li><a class="twitter-share" onclick="popWindow('http://twitter.com/share?url=<?php print base_path().drupal_get_path_alias("node/$node->nid"); ?>','Twitter','500','258')" title="Twitter" rel="tooltip" data-placement="right"><i class="fa fa-twitter"></i></a></li>
                  <li><a class="googleplus-share" onclick="popWindow('http://plus.google.com/share?url=<?php print base_path().drupal_get_path_alias("node/$node->nid"); ?>','GooglePlus','500','400')" title="Google+" rel="tooltip" data-placement="right"><i class="fa fa-google-plus"></i></a></li>
                  <li><a class="linkedin-share" onclick="popWindow('http://linkedin.com/shareArticle?mini=true&amp;url=<?php print base_path().drupal_get_path_alias("node/$node->nid"); ?>&amp;title=<?php print $node->title; ?>','LinkedIn','500','400')" title="LinkedIn" rel="tooltip" data-placement="right"><i class="fa fa-linkedin"></i></a></li>
                  <li><a class="pinterest-share" onclick="popWindow('http://pinterest.com/pin/create/button/?url=<?php print base_path().drupal_get_path_alias("node/$node->nid"); ?>&amp;media=<?php print file_create_url($node->field_blog_thumbnail['und'][0]['uri']); ?>&amp;description=<?php print $node->title; ?>','Pinterest','500','400')" title="Pinterest" rel="tooltip" data-placement="right"><i class="fa fa-pinterest"></i></a></li>								
                  <li><a class="email-share" href="mailto:?subject=<?php print $node->title; ?>&amp;body=<?php print base_path().drupal_get_path_alias("node/$node->nid"); ?>" target="_blank" title="Email" rel="tooltip" data-placement="right"><i class="fa fa-envelope"></i></a></li>
              </ul>
          </div>
          <!-- END .share-dropdown -->	
      </div>
  </div>
<!-- END .float-right -->
      </section>
</div>
<!-- End Blog wrapper -->

<?php print render($content['comments']); ?>