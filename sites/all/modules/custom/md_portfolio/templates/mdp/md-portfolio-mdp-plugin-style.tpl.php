<?php
//  dsm($md_data['options']);
  $md_gridAdjustment = '';
  if($md_data['options']['md_style_gridAdjustment'] != 'default'){
      $md_gridAdjustment = "margin : 0 auto;";
  }
  $md_data['data_js'] = str_replace('"', "#MD#", $md_data['data_js']);
?>
<div class="md_portfolio_display_content" style="display: none;"></div>
<div class="md-portfolio-content <?php print $md_data['options']['md_style_class_add_style']; ?>" style="clear: both;<?php print $md_gridAdjustment;?> width:100%; max-width: <?php print($md_data['options']['md_style_width'].$md_data['options']['md_style_width_unit']); ?>;">
	<div style="display: none;" class="md-portfolio-data" data-json="<?php print $md_data['data_js'];?>"></div>
  <?php if($md_data['options']['md_style_filter_type'] != 'cbp-l-filters-dropdown'): ?>
  <div id="<?php print($md_data['options']['md_style_view']['filter_div_id']) ?>" class="<?php print($md_data['options']['md_style_filter_type']); ?> mdp-filter-default <?php print($md_data['options']['md_style_class_add_filter']); ?>">
    <?php print($md_data['filter']) ?>
  </div>
  <?php else: ?>
    <div id="<?php print($md_data['options']['md_style_view']['filter_div_id']) ?>" class="cbp-l-filters-dropdown">
      <div class="cbp-l-filters-dropdownWrap">
        <?php print($md_data['filter']) ?>
      </div>
    </div>
  <?php endif; ?>
  <div id="<?php print($md_data['options']['md_style_view']['grid_div_id']) ?>" class="<?php print($md_data['options']['md_style_container_type']) ?>">
    <ul>
      <!--mdsstart-->
      <?php
        if(count($rows) != 0) {
          foreach($rows as $key => $row) {
            print $row;
          }
        }
      ?>
      <!--mdsend-->
    </ul>
  </div>
</div>

<?php
  $md_path = current_path();
  if(strpos($md_path, 'admin/structure/views') !== false):
?>
<script type="text/javascript">
  (function($){
    setTimeout(function(){
      $.md_portfolio_admin();
    })
  })(jQuery)
</script>
<?php endif; ?>
