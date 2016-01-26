<?php if($md_data != null): ?>

<div class="md-pricing-table">
  <div class="md-pricing-table-cell <?php print $settings['equal_height'] ?>">
    <?php $key = 1; ?>
    <?php foreach($md_data as $key => $data): ?>
      <?php //dsm($data); ?>
      <div class="md-pricing-option-padding <?php print $settings['class_add'];?>"   style="<?php print $settings['column_width'];?>">
        <div id="md-pricing-option-<?php print $settings['delta_rd'].'-'.($key++);?>"
             class="md-pricing-option text-align <?php if($data['json_setting']['hight_light']) print 'highlight';?>"
             style="<?php print $settings['column_margin']; ?>">
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
          <!-- Header -->
          <div class="mdp-header">
            <div class="header-content <?php print $data['json_header']['class_add'].' '.$data['json_header']['custom_class']; ?>">
              <p>
                <?php print $data['json_header']['title']; ?>
              </p>
            </div>
            <div class="mdp-media">
              <!-- Image , Slide, Video, Map -->
              <?php print md_prtb_load_header($data['json_header']); ?>
            </div>
          </div>
          <!-- Price -->
          <div class="mdp-price">
              <div class="pricing-content <?php print $data['json_price']['custom_class'].' '.$data['json_price']['class_add'] ?>">
              <div class="plan-price <?php print $data['json_price']['style'] ?>">
                <?php if($data['json_price']['style'] != 'style-op3'): ?>
                  <span class="plan-currency"><?php print $data['json_price']['currency'] ?></span>
                  <?php print $data['json_price']['price_price'] ?>
                  <span class="plan-duration"><?php print $data['json_price']['per_day'] ?></span>
                <?php else: ?>
                  <?php $md_price_style_3 = md_prtb_price_style3($data['json_price']['price_price']); ?>
                  <span class="plan-currency"><?php print $data['json_price']['currency'] ?></span><?php print $md_price_style_3[0]; ?><span class="plan-decima"><?php print $md_price_style_3[1]; ?></span>
                <?php endif; ?>
              </div>
            </div>
          </div>
          <!-- Body -->
          <div class="mdp-body">
            <div class="body-content <?php print $data['json_body']['custom_class'].' '.$data['json_body']['class_add'] ?>">
            <ul class="">
              <?php foreach($data['json_body']['descript'] as $md_body_key => $md_body_value): ?>
                <?php if(($settings['tooltip_flag'] == 1) && (strlen($md_body_value['tooltip']) > 0)): ?>
                  <li style="cursor: pointer;">
                <?php else: ?>
                  <li style="cursor: text;">
                <?php endif; ?>
                    <i class="<?php print $md_body_value['icon'] ?>"></i>
                    <?php if(($settings['tooltip_flag'] == 1) && (strlen($md_body_value['tooltip']) > 0)): ?>
                      <div class="content-tooltips md-prtb-tooltip-<?php print $settings['delta_rd']; ?>"
                           style="
                           background: <?php print $settings['tooltip_bg'] ?>;
                           color: <?php print $settings['tooltip_color'] ?>;
                           width: <?php print $settings['tooltip_width'] ?>px;
                           ">
                        <?php print $md_body_value['tooltip'] ?>
                      </div>
                    <?php endif; ?>
                    <?php print $md_body_value['descript_content'] ?>
                  </li>
              <?php endforeach; ?>
            </ul>
            </div>
          </div>
          <!-- Footer -->
          <div class="mdp-footer">
            <div class="footer-content <?php print $data['json_footer']['class_add'].' '.$data['json_footer']['custom_class']; ?>">
              <?php if($data['json_footer']['button_type']): ?>
                <a href="<?php print $data['json_footer']['button_link']; ?>" class="mdp-button" target="_blank"><?php print $data['json_footer']['button_title']; ?></a>
              <?php else: ?>
                <a href="<?php print $data['json_footer']['button_link']; ?>" class="mdp-button"><?php print $data['json_footer']['button_title']; ?></a>
              <?php endif; ?>
            </div>
          </div>
        </div>
      </div>
    <?php /*?><style type="text/css">
      .md-rb-bg-<?php print $settings['delta_rd'].$key; ?>:before{
        border-color: <?php print $data['json_setting']['color_ribbon_bg']; ?> rgba(0, 0, 0, 0);
      }
    </style><?php */?>
    <?php endforeach; ?>
  </div>
</div>
<?php endif; ?>
<?php /*?><style>
  .body-content .md-prtb-tooltip-<?php print $settings['delta_rd']; ?>:after {
    border-top: 6px solid <?php print $settings['tooltip_bg'] ?> !important;
  }
</style><?php */?>
