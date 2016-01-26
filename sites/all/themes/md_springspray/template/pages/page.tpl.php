<div class="main_wrap">
    <!--Preloader div -->
    <div class="blank">
        <span class="loader"><span class="loader-inner"></span></span>
    </div>		
    <!--End Preloader div-->
    
    <?php if($page['header']):?>
		<?php print render($page['header']);?>
    <?php endif; ?>
   
    <!--main wrapper-->
    <div class="site-wrapper">
        <?php if($title) : ?>
          <?php
			if (theme_get_setting('page_static_image_upload', 'md_springspray')) :
			  $file = json_decode(theme_get_setting('page_static_image_upload', 'md_springspray'));
			endif;
		  ?>
          <section id="section-separator2" data-stellar-background-ratio="0.5" data-stellar-vertical-offset="" style="background-image:url(<?php print $file->url; ?>);">
                <div class="row text-center position-rel">					
                    <div class="container"> 
                        <div class="quotes clearfix">													
                            <div class="col-lg-12 text-center">
                                <h3 class="white wow fadeInLeft"><?php print $title; ?><br>-</h3>
                            </div>		
                        </div>
                    </div>
                </div>
          </section>
        <?php endif; ?>
        <?php $node = menu_get_object(); ?>
        <?php if(isset($node)) : ?>
        	<?php if($node->type == 'portfolio') : ?>
            	<div class="project-nav">
                    <div class="p-nav">
                        <?php if (isset($node_previous_link)): ?>
                          <a href="<?php print $node_previous_link;?>"><i class="fa fa-caret-left"></i></a>
                        <?php endif;?>
                        <a href="#"><i class="fa fa-th-large"></i></a>
                        <?php if (isset($node_next_link)): ?>
                          <a href="<?php print $node_next_link;?>"><i class="fa fa-caret-right"></i></a>	
                        <?php endif;?>
                    </div>
                </div>
			<?php endif; ?>
        <?php endif; ?>
        <?php if (panels_get_current_page_display()) : ?>
        	<?php print $messages; ?>
			<?php print render($page['content']); ?>
        <?php else : ?>
        	<section id="blogsinglepage">				
                <div class="container">                                       
                    <div class="row">
                        <?php print $messages; ?>
                        <?php if ($page['sidebar']) : ?>
                            <?php if(theme_get_setting('sidebar_position','md_springspray') != 'no') : ?>
                                <?php if(theme_get_setting('sidebar_position','md_springspray') == 'left') : ?>
                                    <div class="col-md-4 blog-sidebar">
                                        <?php print render($page['sidebar']); ?>
                                    </div>
                                <?php endif; ?>
                                <div class="col-md-8">
                                    <?php if ($tabs): ?><div class="tabs node-tabs"><?php print render($tabs); ?></div><?php endif; ?>
                                    <?php print render($page['content']); ?>
                                </div>
                                <?php if(theme_get_setting('sidebar_position','md_springspray') == 'right') : ?>
                                    <div class="col-md-4 blog-sidebar">
                                        <?php print render($page['sidebar']); ?>
                                    </div>
                                <?php endif; ?>
                            <?php else : ?>
                                <?php if ($tabs): ?><div class="tabs node-tabs"><?php print render($tabs); ?></div><?php endif; ?>
                                <?php print render($page['content']); ?>
                            <?php endif; ?>
                        <?php else : ?>
                            <?php if ($tabs): ?><div class="tabs node-tabs"><?php print render($tabs); ?></div><?php endif; ?>
                            <?php print render($page['content']); ?>
                        <?php endif; ?>
                    </div>
                </div>
            </section>
        <?php endif; ?>
        <?php if(isset($node)) : ?>
        	<?php if($node->type == 'portfolio') : ?>
            	<div class="project-nav">
                    <div class="p-nav">
                        <?php if (isset($node_previous_link)): ?>
                          <a href="<?php print $node_previous_link;?>"><i class="fa fa-caret-left"></i></a>
                        <?php endif;?>
                        <a href="#"><i class="fa fa-th-large"></i></a>
                        <?php if (isset($node_next_link)): ?>
                          <a href="<?php print $node_next_link;?>"><i class="fa fa-caret-right"></i></a>	
                        <?php endif;?>
                    </div>
                </div>
			<?php endif; ?>
        <?php endif; ?>    
        <!-- Footer -->
        <footer id="footer">
            <div class="container foorow-1 foorow">
                <div class="row">
                    <?php if($page['footer']):?>
						<?php print render($page['footer']);?>
                    <?php endif; ?>                   
                </div>
            </div>
            <hr>
            <div class="container text-center">
                <div class="row">
                    <div class="col-lg-12 footer-menu">
                        <div class="pull-left"><?php print theme_get_setting('footer_text','md_springspray'); ?></div>
                        <div class="pull-right">
                            <?php if (module_exists('i18n_menu')) {
								$footer_menu_tree = i18n_menu_translated_tree(variable_get('footer_menu_links_source', 'menu-footer-menu'));
							  } else {
								$footer_menu_tree = menu_tree(variable_get('footer_menu_links_source', 'menu-footer-menu'));
							  }
							  print drupal_render($footer_menu_tree);
							?> 
                        </div>
                    </div>
                </div>
            </div>
            <div id="scroll-container">
                <a href="#home-content" class="scroll-top"><span id="scroll-arrow"></span></a>
            </div>
        </footer>
        <!-- End Footer -->

    </div>
    <!--End main wrapper-->

</div>