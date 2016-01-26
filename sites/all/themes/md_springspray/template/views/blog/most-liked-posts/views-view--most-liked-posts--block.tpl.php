<!-- Post widget -->
<?php if ($rows): ?>
  <div class="view-content widget-item bg-widget">
    <h4><small><?php print $view->get_title(); ?></small></h4>
    <?php print $rows; ?>
  </div>
<?php elseif ($empty): ?>
  <div class="view-empty">
    <?php print $empty; ?>
  </div>
<?php endif; ?>
<!-- End Post widget -->