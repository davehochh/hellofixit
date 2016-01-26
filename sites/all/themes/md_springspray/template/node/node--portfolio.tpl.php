<?php if($node->field_portfolio_display['und'][0]['value'] == 'type1') : ?>
<!-- project page -->
<div id="project-page">				
    <div class="container">
        <div class="row project_images">
            <div class="clearfix">
                <?php if($node->field_portfolio_multimedia['und'][0]['file']->type == 'video') : ?>
					<?php $uri = explode('v/',$node->field_portfolio_multimedia['und'][0]['file']->uri); ?>
                    <div class="video-inner">
                        <?php if($node->field_portfolio_multimedia['und'][0]['file']->filemime == 'video/vimeo') : ?>
                            <iframe src="http://player.vimeo.com/video/<?php print $uri[1]; ?>?title=0&amp;byline=0&amp;portrait=0&amp;color=ec155a" ></iframe>
                        <?php else : ?>
                            <iframe src="http://www.youtube.com/embed/<?php print $uri[1]; ?>?feature=oembed" ></iframe>
                        <?php endif; ?>
                    </div>
                <?php else : ?>
                    <div class="video-inner"><?php print render($content['field_portfolio_multimedia']); ?></div>
                <?php endif; ?>
                <div class="about-project p2">
                    <h3><?php print $node->title; ?></h3>								
                    <?php print render($content['field_portfolio_body']); ?>
                    <div class="project-field1">
                        <h6 class="color"><?php print t('Date'); ?></h6>
                        <p><?php print format_date($node->created, 'custom', 'd F Y'); ?></p>
                    </div>
                    <div class="project-field1">
                        <h6 class="color"><?php print t('Category'); ?> </h6>
                        <p>
                        	<?php if(isset($node->field_portfolio_categories)) : ?>
                            	<?php for($i=0; $i < count($node->field_portfolio_categories['und']); $i++) : ?>
                                	<?php if($i < count($node->field_portfolio_categories['und']) - 1) : ?>
										<?php print $node->field_portfolio_categories['und'][$i]['taxonomy_term']->name . ', ' ;?>
                                    <?php else : ?>
                                    	<?php print $node->field_portfolio_categories['und'][$i]['taxonomy_term']->name;?>
									<?php endif; ?>
								<?php endfor; ?>
							<?php endif; ?>
                        </p>
                    </div>
                    <a href="<?php print render($content['field_portfolio_link']); ?>" class="btn-default"><?php print t('Visit site'); ?></a>
                </div>	
            </div>
        </div>
    </div>		
</div>
<!-- End Blog single page -->
<?php elseif($node->field_portfolio_display['und'][0]['value'] == 'type2') : ?>
<!-- Project page -->
<div id="project-page">				
    <div class="container">
        <div class="row project_images">
            <?php if($node->field_portfolio_multimedia['und'][0]['file']->type == 'video') : ?>
				<?php $uri = explode('v/',$node->field_portfolio_multimedia['und'][0]['file']->uri); ?>
                <div class="video-inner-2">
                    <?php if($node->field_portfolio_multimedia['und'][0]['file']->filemime == 'video/vimeo') : ?>
                        <iframe src="http://player.vimeo.com/video/<?php print $uri[1]; ?>?title=0&amp;byline=0&amp;portrait=0&amp;color=ec155a" ></iframe>
                    <?php else : ?>
                        <iframe src="http://www.youtube.com/embed/<?php print $uri[1]; ?>?feature=oembed" ></iframe>
                    <?php endif; ?>
                </div>
            <?php else : ?>
                <div class="video-inner-2"><?php print render($content['field_portfolio_multimedia']); ?></div>
            <?php endif; ?>
        </div>
    </div>
    <div class="container project-page">
        <div class="row">
            <div class="col-md-8">
                <h3><?php print $node->title; ?></h3>								
                <?php print render($content['field_portfolio_body']); ?>
            </div>
            <div class="col-md-4">
                <div class="project-field1">
                    <h6 class="color"><?php print t('Date'); ?></h6>
                    <p><?php print format_date($node->created, 'custom', 'd F Y'); ?></p>
                </div>
                <div class="project-field1">
                    <h6 class="color"><?php print t('Category'); ?> </h6>
                    <p>
                        <?php if(isset($node->field_portfolio_categories)) : ?>
                            <?php for($i=0; $i < count($node->field_portfolio_categories['und']); $i++) : ?>
                                <?php if($i < count($node->field_portfolio_categories['und']) - 1) : ?>
                                    <?php print $node->field_portfolio_categories['und'][$i]['taxonomy_term']->name . ', ' ;?>
                                <?php else : ?>
                                    <?php print $node->field_portfolio_categories['und'][$i]['taxonomy_term']->name;?>
                                <?php endif; ?>
                            <?php endfor; ?>
                        <?php endif; ?>
                    </p>
                </div>
                <a href="<?php print render($content['field_portfolio_link']); ?>" class="btn-default"><?php print t('Visit site'); ?></a>
            </div>
        </div>
    </div>				
</div>
<!-- End Blog single page -->
<?php else : ?>
<div id="project-page">				
    <div class="container">
        <div class="row project_images">
            <div class="col-md-8">
                <?php if($node->field_portfolio_multimedia['und'][0]['file']->type == 'video') : ?>
					<?php $uri = explode('v/',$node->field_portfolio_multimedia['und'][0]['file']->uri); ?>
                    <div class="video-inner-3">
                        <?php if($node->field_portfolio_multimedia['und'][0]['file']->filemime == 'video/vimeo') : ?>
                            <iframe src="http://player.vimeo.com/video/<?php print $uri[1]; ?>?title=0&amp;byline=0&amp;portrait=0&amp;color=ec155a" ></iframe>
                        <?php else : ?>
                            <iframe src="http://www.youtube.com/embed/<?php print $uri[1]; ?>?feature=oembed" ></iframe>
                        <?php endif; ?>
                    </div>
                <?php else : ?>
                    <div class="video-inner-3"><?php print render($content['field_portfolio_multimedia']); ?></div>
                <?php endif; ?>			
            </div>
            <div class="col-md-4 project-page">
                <h3><?php print $node->title; ?></h3>								
                <?php print render($content['field_portfolio_body']); ?>
                <div class="project-field1">
                    <h6 class="color"><?php print t('Date'); ?></h6>
                    <p><?php print format_date($node->created, 'custom', 'd F Y'); ?></p>
                </div>
                <div class="project-field1">
                    <h6 class="color"><?php print t('Category'); ?> </h6>
                    <p>
                        <?php if(isset($node->field_portfolio_categories)) : ?>
                            <?php for($i=0; $i < count($node->field_portfolio_categories['und']); $i++) : ?>
                                <?php if($i < count($node->field_portfolio_categories['und']) - 1) : ?>
                                    <?php print $node->field_portfolio_categories['und'][$i]['taxonomy_term']->name . ', ' ;?>
                                <?php else : ?>
                                    <?php print $node->field_portfolio_categories['und'][$i]['taxonomy_term']->name;?>
                                <?php endif; ?>
                            <?php endfor; ?>
                        <?php endif; ?>
                    </p>
                </div>
                <a href="<?php print render($content['field_portfolio_link']); ?>" class="btn-default"><?php print t('Visit site'); ?></a>
            </div>
        </div>
    </div>
    
</div>
<?php endif; ?>