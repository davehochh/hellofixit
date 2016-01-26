<!-- Author widget -->
<div class="author-widget clearfix">								
  <article class="ab">								
    <h4 class="text-center"><small><?php print t('About Author'); ?></small></h4>
    <div class="pentagon clearfix wow fadeInUp">
      <a href="#">
        <?php if (isset($content['#account']->picture->uri)) : ?>
          <img src="<?php print file_create_url($content['#account']->picture->uri); ?>" alt=""/>
        <?php endif; ?>
      </a>
      <div class="ab-heading">
        <h4><?php print render($content['field_author_name']); ?><br><small><?php print render($content['field_author_position']); ?></small></h4>										
        <p><?php print render($content['field_author_about']); ?></p>
      </div>
      <div class="profile-social-wrapper">

        <?php foreach (entity_metadata_wrapper('user', $content['#account'])->field_author_socials->getIterator() as $share) : ?>
          <div data-href="<?php print $share->field_team_socials_link->value(); ?>" class="link">
            <div class="cube twitter">
              <div class="front">
                <i class="fa <?php print $share->field_team_socials_icon->value(); ?>"></i>
              </div>
              <div class="back">
                <i class="fa <?php print $share->field_team_socials_icon->value(); ?>"></i>
              </div>
            </div>
          </div>
        <?php endforeach; ?>
      </div>
    </div>
  </article>					
</div>
<!-- End author widget -->