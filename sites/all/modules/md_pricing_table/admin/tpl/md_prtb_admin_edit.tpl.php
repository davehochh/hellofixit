<!-- /////////////////// Pricing Wrapper  ///////////////// -->

<div id="md-pricing-table-wrapper" class="md-pricing-table-wrapper">
    <div id="md-pb-items" class="md-pb-items clearfix">
        <!-- /////////////////// Pricing Item  ///////////////// -->
        <!-- /////////////////// Pricing placeholder ///////////////// -->
        <div class="md-pb-item-placeholder js-hidden" ></div>
    </div>
    <!-- /////////////////// Pricing Add New ///////////////// -->
    <div class="md-pb-addnew js-add-pricing-table">
        <i class="icon-plus"></i> Add New Pricing Table
    </div>
    <!-- /////////////////// Popup Setting /////////////////// -->
    <div  class="js-popup-setting js-hidden">
        <div class="md-pb-setting popup-setting">
            <!-- /////////////////// Block Header  ///////////////// -->
            <div class="block-header">
                <h3 class="title">Setting</h3>
                <i class="icon-pb-delete" id="js-icon-delete-setting"></i>
            </div>
            <!-- /////////////////// Block Content  ///////////////// -->
            <div class="block-content">
                <div class="primary-content">
<!--                    <div class="form-element">-->
<!--                        <input id="custom-class" class="input-checkbox js-ck-add-class" type="checkbox">-->
<!--                        <label class="label-checkbox" for="custom-class">Custom class</label>-->
<!--                    </div>-->
                    <div class="class-add-setting js-hidden">
                        <input type="text" class="js-setting-add-class" placeholder="Class add"/>
                    </div>
                    <div class="form-element">
                        <input id="highlight" class="input-checkbox js-sts-highlight" type="checkbox">
                        <label class="label-checkbox" for="highlight">Highlight</label>
                    </div>
                    <div class="form-element ">
                        <input id="ribbon" class="input-checkbox js-ck-ribbon" type="checkbox">
                        <label class="label-checkbox" for="ribbon">Ribbon</label>
                    </div>
                    <div class="js-setting-ribbon js-hidden">
                        <div class="form-element">
                            <div class="form-select">
                                <select class="select js-sts-ribbon">
                                  <option value="top-left">Top - left</option>
                                  <option value="top-right">Top - right</option>
                                  <option value="burgee-left">Burgee - left</option>
                                  <option value="burgee-right">Burgee - right</option>
                                  <option value="flag-left">Flag - left</option>
                                  <option value="flag-right">Flag - right</option>
                                  <option value="top-ribbon">Top ribbon</option>
                                  <option value="bottom-ribbon">Bottom ribbon</option>
                                </select>
                            </div>
                        </div>
                        <div class="form-element custom">
                            <!-- <input type='color' class="js-setting-color" name='color' /> -->
                            <input type='hidden' class="burgee-right" id="burgee-right"/>
                            <div class="input-label">
                            	<input type='text' class="js-setting-color" id="pricing-pickercolor" />
                            	<label class="label-checkbox" for="pricing-pickercolor">Ribbon text color</label>
                            </div>
                            <div class="input-label">
                            	<input type='text' class="js-setting-color-bg" id="pricing-pickercolor-bg" />
                            	<label class="label-checkbox" for="pricing-pickercolor-bg">Ribbon background color</label>
                            </div>
                            <input type="text"  class="js-setting-text-ribbon" placeholder="Text on ribbon">
                        </div>
	                    <div style="position: relative" class="ribbon-block">
	                        <div class=" mdp-ribbon ribbon-pos-hidden " style="background: #0B2C3C;">
	                            <div class="ribbon">
	                                <div class="ribbon-inner">
	                                    <span class="text-ribbon">Sale</span>
	                                </div>
	                            </div>
	                        </div>
	                    </div>
                    </div>
                    <div class="form-element form-button btn-right" >
                        <a class="pb-button" id="js-sts-save" href="#">Save &amp; Close</a>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <!-- /////////////////// Popup Header /////////////////// -->
    <div  class="js-popup-header js-hidden">
        <div class="md-pb-header popup-setting">
            <!-- /////////////////// Block Header  ///////////////// -->
            <div class="block-header">
                <h3 class="title">Header</h3>
                <i class="icon-pb-delete" id="js-icon-delete-header"></i>
            </div>
            <!-- /////////////////// Block Content  ///////////////// -->
            <div class="block-content js-header-add-extend clearfix">
                <div class="primary-content">
                    <div class="form-element">
                        <input id="tf-header-title" type="text" placeholder="Title">
                        <p class="js-error js-error-header-title"></p>
                    </div>
                    <div class="form-element form-checkbox ">
                        <input id="custom" class="input-checkbox js-ck-custom"  type="checkbox">
                        <label class="label-checkbox js-header-cutom" for="custom">Custom</label>
                    </div>
                    <div class="js-hidden js-header-custom">
                        <div class="header-media">
                            <input type="hidden" class="js-header-hidden-media">
                            <input type="hidden" class="js-header-toogle-media">
                            <ul class="clearfix">
                                <li class="js-header-click-media"><i id="extend-image" class="media-image "></i></li>
                                <li class="js-header-click-media"><i id="extend-video" class="media-video"></i></li>
                                <li class="js-header-click-media"><i id="extend-map" class="media-map"></i></li>
                                <li class="js-header-click-media"><i id="extend-html" class="export-html">HTML</i></li>
                            </ul>
                        </div>
                        <div class="form-element form-button no-pt">
                            <a class="pb-button " id="js-header-bt-css" href="#">Custom CSS</a>
                        </div>
                        <div id="js-custom-element-css" >
                            <div class="form-element">
                                <input id ="tf-header-custom-class"  type="text" placeholder="Class add">
                            </div>
                            <div class="form-element">
                                <textarea id="area-header-custom-css" placeholder="Custom Css"></textarea>
                            </div>
                        </div>
                    </div>
                    <div class="form-element form-button btn-right" >
                        <a class="pb-button js-header-save" id="js-header-save" href="#">Save &amp; Close</a>
                    </div>
                </div>
    <!-- hidden header extend video-->
    <div class="block-content-extend extend-video js-hidden">
      <label class="form-label">Url Video(Youtube/Vimeo)</label>
                    <input type="hidden" class="js-header-video-select">
                    <input type="hidden" class="js-header-video-id">

      <div class="form-element big">
                        <p class="js-header-video-error"></p>
        <input id="js-header-video-url" type="text" placeholder="Link video">
      </div>
      <div class="mdpb-form-group form-inline">
        <label class="form-label">Height</label>
        <div class="form-element small">
          <input id="js-header-video-height" type="text" placeholder="124px">
        </div>
        <p class="js-error-header-video-height"></p>
      </div>
      <div class="form-element big">
        <input id="js-header-video-custom-class" type="text" placeholder="Custom class">
      </div>
      <div class="form-element big">
        <div class="video-img-bg">
        </div>
      </div>
    </div>
     <!-- hidden header extend map-->
    <div class="block-content-extend extend-map js-hidden" >
      <label class="form-label">Google Map</label>
      <div class="form-element big">
        <input id="js-header-map-long" type="text" placeholder="Long, lat">
      </div>

    <div class="form-element big market-preview-big">
      <div class="market-preview">
        <input type="hidden" class="js-header-map-fid">
          <input type="hidden" class="js-header-map-url">
        <div class="js-header-map-preview"><img src="<?php print $prtb_data['md_path'];?>/admin/images/preview.png" alt=""></div>
        <span class="preview-del js-map-preview-delete"></span>
      </div>
      <a class="pb-button js-header-map-upload" href="#">Select marker source</a>
    </div>


    <div class="mdpb-form-group form-inline">

      <label class="form-label">Zoom level</label>
      <div class="form-select small">
        <select class="select" id="js-header-map-zoom">
          <?php for($i=1;$i<=20;$i++):?>
            <option value="<?php echo $i;?>"><?php echo $i;?></option>
          <?php endfor;?>
        </select>
      </div>


      <label class="form-label">Height</label>
      <div class="form-element small">
        <input id="js-header-map-height" name="map_height" type="text" placeholder="124 px">

      </div>
      <p class="js-error-header-map-height"></p>


    </div>

    <div class="mdpb-form-group form-inline">
      <div class="form-element">
        <input id="infoBox" class="input-checkbox js-header-map-info" type="checkbox">
        <label class="label-checkbox js-header-map-label-info" for="infoBox">Info box</label>
      </div>
    </div>

      <div class="form-element big">
        <input id="js-header-map-title" type="text" placeholder="Title">
      </div>

      <div class="form-element big">
        <textarea id="js-header-map-descript" placeholder="Description"></textarea>
      </div>

      <div class="form-element">
        <input id="openByDefault" class="input-checkbox js-header-map-open-default" type="checkbox">
        <label class="label-checkbox js-header-map-label-default" for="openByDefault">Open by default</label>
      </div>
    </div>

    <!-- hidden header extend image-->
    <div class="block-content-extend extend-image js-hidden" >
      <label class="form-label">Image</label>
      <input type="hidden" class="js-header-image-id">
                    <input type="hidden" class="js-header-image-url">
      <div class="img-preview">
        <div class="js-header-img-preview"></div>
        <span class="preview-del"></span>
      </div>

      <div class="form-element">
        <a class="pb-button js-header-bt-upload" href="#">Select Image</a>
      </div>

      <label class="form-label">Image Style</label>
      <div class="form-element">
        <div class="form-select">

          <select class="select js-header-img-style">
                                <?php
                                if($prtb_data['img_style'] != null){
                                    foreach($prtb_data['img_style'] as $key => $name){
                                        echo '<option value="'.$key.'">'.$name.'</option>';
                                    }
                                }
                                ?>
          </select>

        </div>
      </div>

      <div class="form-element big">
        <input type="text" class="js-header-custom-class" placeholder="Custom class">
      </div>

      <div class="form-element">
        <a class="pb-button js-header-export-html" href="#">Export HTML</a>
      </div>
    </div>

    <!-- hidden header extend html-->
    <div class="block-content-extend extend-html js-hidden">
      <label class="form-label">Custom HTML</label>
      <div class="form-element">
        <textarea class="js-header-extend-html-area" placeholder="Custom HTML"></textarea>
      </div>
    </div>
            </div>
        </div>
    </div>

    <!-- /////////////////// Popup Price /////////////////// -->
    <div  class="js-popup-price js-hidden">
        <div class="md-pb-price popup-setting">
            <div class="block-header">
                <h3 class="title">Price</h3>
                <i class="icon-pb-delete" id="js-icon-delete-price"></i>
            </div>
            <!-- /////////////////// Block Content  ///////////////// -->
            <div class="block-content">
               <div class="primary-content">
                    <label class="form-label">Select Style</label>
                   <div class="pricing-style">
                       <ul class="clearfix" id="js-price-style-ul">
                           <li class="active js-price-click-style" id="style-op1">
                               <p class="plan-price style-op1">
                                   <span class="plan-currency">$</span>69<span class="plan-duration">per month</span>
                               </p>
                           </li>
                           <li class="js-price-click-style" id="style-op2">
                               <p class="plan-price style-op2">
                                   <span class="plan-currency">$</span>96<span class="plan-duration">/m</span>
                               </p>
                           </li>
                           <li class="js-price-click-style" id="style-op3">
                               <p class="plan-price style-op3">
                                   <span class="plan-currency">$</span>68<span class="plan-decima">.99</span>
                               </p>
                           </li>
                       </ul>
                       <input type="hidden" class="js-price-hidden-style" value="style-op1" >
                   </div>
                    <div class="form-element">
                        <input type="text" class="js-price-price" placeholder="Price">
                        <p class="js-error-price"></p>
                    </div>
                    <div class="mdpb-form-group form-inline">
                        <div class="form-element medium">
                            <input type="text" class="js-price-currency" placeholder="Currency">
                        </div>
                        <div class="form-element medium">
                            <input type="text" class="js-price-per-day" placeholder="per day">
                        </div>
                    </div>
                   <div class="form-element form-button btn-right">
                       <a class="pb-button pb-button-dark js-bt-position" id="js-price-click-css" href="#">Custom CSS</a>
                        <div  class="js-price-custom-css js-hidden">
                            <div class="form-element">
                                <input class="js-price-tf-class" type="text" placeholder="Class add">
                            </div>
                            <div class="form-element">
                                <textarea  class="js-price-area-css" placeholder="Custom Css"></textarea>
                            </div>
                        </div>
                       <a id="js-price-save" class="pb-button js-price-save" href="#">Save &amp; Close</a>
                   </div>

               </div>
            </div>

        </div>
    </div>

    <!-- /////////////////// Popup Body /////////////////// -->
    <div  class="js-popup-body js-hidden">
        <div class="md-pb-body popup-setting">
            <!-- /////////////////// Block Header  ///////////////// -->
            <div class="block-header">
                <h3 class="title">Body</h3>
                <span class="icon-pb-delete" id="js-icon-delete-body"><i></i></span>
            </div>

            <!-- /////////////////// Block Content  ///////////////// -->
            <div class="block-content">
                <div class="primary-content">

                    <!-- /////////////////// Block sortable  ///////////////// -->
                    <div class="block-sortable-items js-body-items clearfix">
                        <div class="block-sortable js-body-item">
                            <h3 class="sortable-header">
                                <p class="js-add-content"></p>
                                <i class="" aria-hidden="true"></i>
                                <input type="hidden" class="js-body-icon js-change-icon[]" value="1">
                                <i class="icon-pb-duplicate js-body-duplicate"></i>
                                <i class="icon-pb-delete"></i>
                            </h3>
                            <div class="js-body-accordion"></div>
                            <div class="sortable-content">
                                <div class="sortable-tools">
                                    <span class="text-align">
                                        <i id="left" class="icon-ta-left js-body-align-click"></i>
                                        <i id="justify" class="icon-ta-justify js-body-align-click"></i>
                                        <i id="right" class="icon-ta-right js-body-align-click"></i>
                                        <input type="hidden"  class="js-body-text-align js-body-align[]" value="1">
                                    </span>
                                    <!-- Box list ICON FONT -->
                                    <div class="md-box-icon">
                                        <a href="#" class="select-icon">Select Icon<i class="iconpb-select"></i></a>

                                        <!--  POPUP LIST ICON -->
                                        <div class="popup-icon-lib js-hidden">
                                            <div class="box-icon-chose">
                                                <i class="" aria-hidden="false"></i>
                                                <span>Choose icon</span>
                                            </div>
                                            <div class="box-list clearfix">
                                                <?php echo $prtb_data['icon'];?>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                                <div class="form-element">
                                    <textarea  class="js-body-area-descript js-body-descript[]" placeholder="Description"></textarea>
                                </div>
                                <div class="form-element js-hidden js-body-area-tooltip">
                                    <textarea  class="js-body-content-tooltip js-body-tooltips[]" placeholder="Tooltips"></textarea>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="js-hidden">
                        <div class="block-sortable js-body-item" id="js-body-item-hidden">

                            <h3 class="sortable-header">
                                <p class="js-add-content"></p>
                                <i class=""  aria-hidden="true"></i>
                                <input type="hidden" class="js-body-icon js-change-icon[]" value="1">
                                <i class="icon-pb-duplicate js-body-duplicate"></i>
                                <i class="icon-pb-delete"></i>
                            </h3>
                            <div class="js-body-accordion"></div>
                            <div class="sortable-content">
                                <div class="sortable-tools">
                                    <span class="text-align">
                                        <i id="left" class="icon-ta-left js-body-align-click"></i>
                                        <i id="justify" class="icon-ta-justify js-body-align-click"></i>
                                        <i id="right" class="icon-ta-right js-body-align-click"></i>
                                        <i class="icon-custom-code"></i>
                                        <input type="hidden" class="js-body-text-align js-body-align[]" value="1">
                                    </span>
                                    <!-- Box list ICON FONT -->
                                    <div class="md-box-icon">
                                        <a href="#" class="select-icon js-select-icon">Select Icon<i class="iconpb-select"></i></a>

                                        <!--  POPUP LIST ICON -->
                                        <div class="popup-icon-lib js-hidden">
                                            <div class="box-icon-chose">
                                                <i class="" aria-hidden="false"></i>
                                                <span>Choose icon</span>
                                            </div>
                                            <div class="box-list clearfix">
                                                <?php echo $prtb_data['icon'];?>
                                            </div>
                                        </div>
                                    </div>
                                </div>
                                <div class="form-element">
                                    <textarea class="js-body-area-descript js-body-descript[]" placeholder="Description"></textarea>
                                </div>
                                <div class="form-element js-hidden js-body-area-tooltip">
                                    <textarea  class="js-body-content-tooltip js-body-tooltips[]" placeholder="Tooltips default"></textarea>
                                </div>
                            </div>
                        </div>
                    </div>
                    <div class="md-pb-addnew border" id="js-body-add-new-item">
                        <i class="icon-plus"></i> Add New Content
                    </div>
                  <div class="form-element form-button btn-right">
                    <a class="pb-button pb-button-dark js-bt-position " id="js-body-click-css" href="#">Custom CSS</a>
                    <div  class="js-body-custom-css js-hidden">
                      <div class="form-element">
                        <input class="js-body-tf-class" type="text" placeholder="Class add">
                      </div>
                      <div class="form-element">
                        <textarea  class="js-body-area-css" placeholder="Custom Css"></textarea>
                      </div>
                    </div>
                    <div class="form-element js-body-area-html js-hidden">
                      <textarea class="js-body-custom-html"  placeholder="Custom HTML"></textarea>
                    </div>
                    <a class="pb-button js-body-save" href="#">Save &amp; Close</a>
                  </div>
                </div>
            </div>
        </div>
    </div>

    <!-- /////////////////// Popup Footer /////////////////// -->
    <div  class="js-popup-footer js-hidden">
        <div class="md-pb-footer popup-setting">
            <div class="block-header">
                <h3 class="title">Footer</h3>
                <i class="icon-pb-delete" id="js-icon-delete-footer"></i>
            </div>
            <!-- /////////////////// Block Content  ///////////////// -->
            <div class="block-content">
                <div class="primary-content">
                    <label class="form-label">Button type</label>
                    <div class="form-select">
                        <select class="select js-footer-select" name="" >
                            <option value="0">Normal</option>
                            <option value="1">Custom</option>
                        </select>
                    </div>
                    <div class="js-footer-diable">
                        <div class="form-element">
                            <input type="text" id="js-footer-tf-title" placeholder="Button title ( typing mode )">
                        </div>
                        <div class="form-element">
                            <input type="text" id="js-footer-tf-link" placeholder="Button link">
                        </div>
                        <div class="form-element">
                            <input id="checkbox" class="input-checkbox js-footer-ck-new-window"  type="checkbox">
                            <label class="label-checkbox" for="checkbox">Open in new window</label>
                        </div>
                    </div>

                    <div class="form-element form-button btn-right">
                        <a class="pb-button pb-button-dark js-bt-position " id="js-footer-click-css" href="#">Custom CSS</a>
                        <div  class="js-footer-custom-css js-hidden">
                            <div class="form-element">
                                <input class="js-footer-tf-class" type="text" placeholder="Class add">
                            </div>
                            <div class="form-element">
                                <textarea  class="js-footer-area-css" placeholder="Custom Css"></textarea>
                            </div>
                        </div>
                        <div class="form-element js-footer-area-html js-hidden">
                            <textarea class="js-footer-custom-html"  placeholder="Custom HTML"></textarea>
                        </div>
                        <a class="pb-button js-footer-save" href="#">Save &amp; Close</a>
                    </div>
                </div>
            </div>

        </div>
    </div>

    <!-- /////////////////// Popup Pricing Table /////////////////// -->
    <div class="js-hidden">
        <div class="md-pb-item" id="js-content-pricing-table">
            <input type="hidden" name="no"  class="js-hd-json">
            <div class="md-pb-toolbar">
                <i class="icon-pb-setting"></i>
                <h3 class="label-pb"><span class="js-header-label-pb">$ 00.00</span></h3>
                <i class="icon-pb-duplicate"></i>
                <i class="icon-pb-delete"></i>
            </div><!-- /.md-pb-toolbar -->
            <div class="md-pb-content">
                <div class="md-pb-block md-pb-header">
                    <div class="md-pb-title">Header</div>
                </div><!-- /.md-pb-header -->
                <div class="md-pb-block md-pb-price">
                    <div class="md-pb-title">Price</div>
                </div><!-- /.md-pb-price -->
                <div class="md-pb-block md-pb-body">
                    <div class="md-pb-title">Body</div>
                </div><!-- /.md-pb-body -->
                <div class="md-pb-block md-pb-footer">
                    <div class="md-pb-title">Footer</div>
                </div><!-- /.md-pb-footer -->
            </div><!-- /.md-pb-content -->
        </div>
    </div>
    <div class="md-pb-backdrop"></div>
    <input type="hidden" name="dynamic-id" class="dynamic-id">
</div><!-- /.md-pricing-table-wrapper -->
<!--Prview Pricing Table-->
<div class="preview_pricing_table js-hidden" >
    <div >
        <i class="icon-pb-delete" id="delete_preview"></i>
    </div>
    <div class="content_preview_pricing_table"></div>
</div>
