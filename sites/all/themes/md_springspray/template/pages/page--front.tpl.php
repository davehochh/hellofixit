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
        <?php print $messages; ?>
		<?php print render($page['content']); ?>        
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