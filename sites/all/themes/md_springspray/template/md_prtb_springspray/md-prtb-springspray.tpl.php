<?php if($md_data != null): ?>
<?php
  $md_class_tooltip = '';
  $md_class_has_tooltip = '';
  if($settings['tooltip_flag'] == 1){
    $md_class_tooltip ='mdp-springspray-tooltip';
    $md_class_has_tooltip = 'mdp-springspray-has-tooltip';
  }
      //dsm($settings);
      //dsm($md_data);
?>
<div class="<?php print $settings['custom_class_fid'].' '.$settings['class_add'];?>">
  <?php foreach($md_data as $keyz => $dataz): ?>
    <ul class="cd-pricing-list">
      <?php foreach($dataz as $key => $data): ?>
        <li class="<?php print $settings['column_class'];?> <?php if($data['json_setting']['hight_light']) print 'cd-popular';?>">
            <ul class="cd-pricing-wrapper">
                <li data-type="monthly" class="is-visible">
                    <!-- Ribbon -->
					<?php if($data['json_setting']['check_ribbon']): ?>
                      <div class="mdp-ribbon <?php print md_prtb_ribbron_array($data['json_setting']['position_ribbon']); ?>">
                        <div class="ribbon <?php print $data['json_setting']['position_ribbon']; ?> md-rb-bg-<?php print $settings['delta_rd'].$key; ?>"
                             style="
                             background: <?php print $data['json_setting']['color_ribbon_bg']; ?>;
                             color: <?php print $data['json_setting']['color_ribbon']; ?>;
                             ">
                          <?php if(($data['json_setting']['position_ribbon'] == 'top-left') || ($data['json_setting']['position_ribbon'] == 'top-right')): ?>
                          <div class="ribbon-inner">
                            <span>
                              <span>
                                <?php print $data['json_setting']['text_ribbon']; ?>
                              </span>
                            </span>
                          </div>
                          <?php else: ?>
                            <?php print $data['json_setting']['text_ribbon']; ?>
                          <?php endif; ?>
                        </div>
                      </div>
                    <?php endif; ?>
                    
                    <header class="cd-pricing-header">
                        <?php if($data['json_header']['custom_html']): ?>
							<?php print $data['json_header']['custom_html'];?>
                        <?php else : ?>
                            <h3><?php print $data['json_header']['title']; ?></h3>
                        <?php endif; ?>

                        <div class="cd-price">
                            <?php if($data['json_price']['price_price']): ?>
                                <span class="cd-currency"><?php print $data['json_price']['currency'];?></span>
                                <span class="cd-value"><?php print $data['json_price']['price_price'];?></span>
                                <span class="cd-duration"><?php print $data['json_price']['per_day'];?></span>
                            <?php endif; ?>
                        </div>
                    </header> <!-- .cd-pricing-header -->

                    <?php if($data['json_body']['descript']): ?>
                        <div class="cd-pricing-body <?php print $data['json_body']['class_add'].' '.$data['json_body']['custom_class'];?>">
                          <?php if(count($data['json_body']['descript']) != 0): ?>
                            <ul class="cd-pricing-features">
                              <?php foreach($data['json_body']['descript'] as $key => $value): ?>
                                <?php
                                  if(($value['tooltip'] == '') && $md_class_has_tooltip ){
                                    $md_class_has_tooltip = '';
                                  }
                                ?>
                                <li class="<?php print $md_class_has_tooltip;?>">
                                  <?php if(($settings['tooltip_flag'] == 1)&&($value['tooltip'] != '')):?>
                                    <span class="<?php print $md_class_tooltip;?>"
                                          style="background-color: <?php print $settings['tooltip_bg'];?>;
                                            color: <?php print $settings['tooltip_color'];?>;
                                            width: <?php print $settings['tooltip_width'];?>px;
                                            "><i class="mdp-springspray-icon-arrow" style="border-top-color: <?php print $settings['tooltip_bg'];?>;"></i>
                                      <?php print $value['tooltip'];?>
                                    </span>
                                  <?php endif;?>
                                  <?php if($value['icon']) : ?>
                                    <i class="<?php print str_replace('md', 'rt', str_replace('js-body-selector-icon icon fontello', '', $value['icon']));?>"></i>&nbsp;&nbsp;<?php print $value['descript_content'];?>
                                  <?php else : ?>
                                    <?php print $value['descript_content'];?>
                                  <?php endif; ?>
                                </li>
                              <?php endforeach; ?>
                            </ul>
                          <?php endif; ?>
                        </div>
                    <?php endif; ?>

                    <?php if($data['json_footer']['button_title']): ?>
                        <footer class="cd-pricing-footer <?php print $data['json_footer']['class_add'].' '.$data['json_footer']['custom_class'];?>">
                        	<a class="cd-select" href="<?php print $data['json_footer']['button_link'];?>"><?php print $data['json_footer']['button_title'];?></a>
                        </footer>  <!-- .cd-pricing-footer -->
                    <?php endif; ?>
                </li>
            </ul> <!-- .cd-pricing-wrapper -->
        </li>
      <?php endforeach;?>
    </ul>
  <?php endforeach;?>
</div>
<?php endif;?>