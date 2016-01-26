<!-- Blog wrapper -->
<div class="single-blog-wrapper clearfix">
  <article>
      <div class="post-header clearfix">
          <h4><?php print $node->title; ?></h4>
          <p>
            <?php print format_date($node->created, 'custom', 'M d, Y'); ?> | 
            <?php print $node->name; ?> | 
            <?php print substr($terms, 0, -2); ?>										
          <hr>
      </div>
      
      <div class="single-post-content clearfix">
          <?php print render($content['body']); ?>
      </div>
  </article>
  <section class="bottom-meta-section clearfix">
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