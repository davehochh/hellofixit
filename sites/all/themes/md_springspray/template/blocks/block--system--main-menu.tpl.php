<?php if(theme_get_setting('menu_style','md_springspray') == "nav-1") : ?>
<!-- Header navigation -->	
<nav>
    <div id="nav">
        <div class="header-inner">
            <a href="#home-content" class="nav-logo hidden-con"></a>
            <div class="close"></div>
            <div class="menunav-container">
                <?php print $content ;?>
            </div>		
        </div>
    </div>
</nav>
<!-- End Header navigation -->
<!-- Header -->	
<div id="header" class="">
    <div class="header-inner">
        <a href="<?php print base_path(); ?>#home-content" class="nav-logo"><img src="<?php ($logo_path) ? print $logo_path : print base_path().path_to_theme().'/logo.png' ; ?>" alt="brand name"></a>
        <div class="navicon"></div>
    </div>
</div>
<!-- End Header -->
<?php endif; ?>
<?php if(theme_get_setting('menu_style','md_springspray') == "nav-2") : ?>
<!--Start Nav Header-->
<section id="fixed-navbar" class="header-top">
    <nav class="navbar navbar-default navbar-static-top" role="navigation">
        <div class="container">
            <!-- Brand logo and mobile display -->
            <div class="navbar-header">
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#main-nav">
                <span class="sr-only"><?php print t('Toggle navigation'); ?></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                <span class="icon-bar"></span>
                </button>
                <a class="logo-brand" href="<?php print base_path(); ?>#home-content" title="<?php print variable_get('site_name'); ?>">
                    <?php if(theme_get_setting('toggle_name','md_springspray')) : ?>
						<h3><?php print variable_get('site_name'); ?></h3>
					<?php else : ?>
                    	<img src="<?php ($logo_path) ? print $logo_path : print base_path().path_to_theme().'/logo.png' ; ?>" alt="brand name">
                    <?php endif; ?>
                </a>
            </div>

            <!-- Main Navigation -->
            <div class="collapse navbar-collapse" id="main-nav">
              <?php print $content ;?>
            </div>
        </div>
    </nav>
</section>
<!--End Nav Header-->
<?php endif; ?>
<?php if(theme_get_setting('menu_style','md_springspray') == "nav-3") : ?>
<!-- Navigation -->
<nav>
    <!-- Mobile menu -->
    <div class="mobile-nav hidden-lg">
        <?php print $content ;?>
    </div>
    <!-- End Mobile menu -->
    <!-- desktop menu -->
    <div class="visible-lg">
        <section id="navi">
            <span id="navicontent"></span>
            <span class="btn" id="navih"></span>
        </section>
        <section id="navibar">
            <section id="navitext">
                <?php print $content ;?>
            </section>
        </section>
    </div>
    <!-- End desktop menu -->
</nav>
<!-- End Navigation -->
<?php endif; ?>
<?php if(theme_get_setting('menu_style','md_springspray') == "nav-4") : ?>
<!-- Header -->	
<div id="header" class="">
    <div class="header-inner">
        <a href="<?php print base_path(); ?>#home-content" class="nav-logo"><img src="<?php ($logo_path) ? print $logo_path : print base_path().path_to_theme().'/logo.png' ; ?>" alt="brand name"></a>
        <div class="nav-container">
            <div class="nav-handle"><i class="fa fa-bars"></i></div>
            <nav id="n5" role="navigation">
                <?php print $content ;?>
            </nav>
        </div><!--nav-container -->	
    </div>			
</div>
<!-- End Header -->
<?php endif; ?>
<?php if(theme_get_setting('menu_style','md_springspray') == "nav-5") : ?>
<!-- Header navigation -->
<header class="navbar">
    <div class="container">
        <div class="row ">
            <div id="main-nav" class="clearfix">
              <div class="navbar-header">
                    <button class="navbar-toggle" type="button" data-toggle="collapse" data-target=".navbar-collapse">
                        <span class="sr-only"><?php print t('navigation'); ?></span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                    </button>						
                    <a id="logo" href="<?php print base_path(); ?>"><img src="<?php ($logo_path) ? print $logo_path : print base_path().path_to_theme().'/logo.png' ; ?>" alt=""></a>
              </div>
              <nav class="collapse navbar-collapse" role="navigation">
                <?php print $content ;?>
                <div id="toggle-navbar"><i class="fa fa-angle-right"></i></div>
              </nav>
          </div>
        </div>
    </div>	
</header>
<!-- End Header navigation -->
<?php endif; ?>
<?php if(theme_get_setting('menu_style','md_springspray') == "nav-6") : ?>
<!-- Header navigation -->
<header class="navstyle7">
    <div class="headleft">
        <h4 id="logo"><a href="<?php print base_path(); ?>">Springspray</a></h4>
    </div>
    <div class="navright">
        <!-- start main nav -->
        <div id="nav-button"> <span class="nav-bar"></span> <span class="nav-bar"></span> <span class="nav-bar"></span> </div>
        <nav id="options" class="clearfix">
          <?php print $content ;?>
        </nav>
        <!-- end main nav -->
    </div>
</header>
<!-- End Header navigation -->
<?php endif; ?>
<?php if(theme_get_setting('menu_style','md_springspray') == "default") : ?>
<!--Header -->	
<div id="header">		
    <header>
        <a class="cd-brand" href="<?php base_path(); ?>#home-content"><img src="<?php ($logo_path) ? print $logo_path : print base_path().path_to_theme().'/logo.png' ; ?>" alt="brand name"></a>
    </header>		
</div>
<!--End Header -->

<!--Navigation-->	
<nav>
    <?php print $content ;?>
</nav>

<!-- cd-overlay-nav -->
<div class="cd-overlay-nav">
    <span></span>
</div> 
<!-- cd-overlay-content -->
<div class="cd-overlay-content">
    <span></span>
</div> 
<!-- Menu icon -->
<a class="cd-nav-trigger"><?php print t('Menu'); ?><span class="cd-icon"></span></a>

<!-- End Navigation -->
<?php endif; ?>