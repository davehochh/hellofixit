/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
(function ($){
    pricing.SaveDataJson = function (){
        this.init();
    };
    pricing.SaveDataJson.prototype = {
        constructor : pricing.SaveDataJson,
        init : function(){
            this.copyValueToJson();
            this.setDataForItem();
            this.previewPricingTable();
            this.deletePreviewPricingTable();
        },
        copyValueToJson : function (){
            $(document).on("click", ".md_prtb_add_submit ,#edit-preview", function (){
                var arrName = [];
                $(".js-hd-json").each(function(){
                    arrName.push( $(this).attr("name"));
                });
                var json = new Array();
                var str_css ="";
                var size = arrName.length - 1;
                var count = 0;
                for(var i = 0; i< size; i ++){
                    var arr = $("input[name='" + arrName[i] + "']").data("pricingTable");
                    var checkObjSetting = "", checkObjHeader = "", checkObjBody = "";
                    var checkObjPrice = "", checkObjFooter = "";
                    if($.checkExistArray(arr) !== ""){
                        checkObjSetting = $.checkExistObj(arr[0].tbl_setting);
                        checkObjHeader = $.checkExistObj(arr[0].tbl_header);
                        checkObjBody = $.checkExistObj(arr[0].tbl_body);
                        checkObjPrice = $.checkExistObj(arr[0].tbl_price);
                        checkObjFooter = $.checkExistObj(arr[0].tbl_footer);
                        // Get Data Custom Css
                        if ($.checkExistObj(arr[0].tbl_header)!=""){
                            str_css+= $.returnCustomCss(arr[0].tbl_header);
                        }
                        if ($.checkExistObj(arr[0].tbl_body)!=""){
                            str_css+= $.returnCustomCss(arr[0].tbl_body);
                        }
                        if ($.checkExistObj(arr[0].tbl_price)!=""){
                            str_css+= $.returnCustomCss(arr[0].tbl_price);
                        }
                        if ($.checkExistObj(arr[0].tbl_footer)!=""){
                            str_css+= $.returnCustomCss(arr[0].tbl_footer);
                        }
                    }
                    json.push({
                        json_id : count,
                        json_setting: checkObjSetting,
                        json_header: checkObjHeader,
                        json_body: checkObjBody,
                        json_price: checkObjPrice,
                        json_footer: checkObjFooter
                    });
                    count++ ;
                }
                var str = JSON.stringify(json);
                this.str = str;
                this.str_css= str_css;
                $(".md_prtb_json_data").val(str);
                $(".md-data-custom-class").val(str_css);
            });
        },
        setDataForItem : function(){
            var strConvertToJson={0: ""};
            var strJson = Drupal.settings.md_pricing_table.wdt_json_data;
            var settingJson = Drupal.settings.md_pricing_table.wdt_json_setting;
            if (strJson!="" && strJson!='walle_data_in_here'){
                strConvertToJson = $.parseJSON(strJson);
            }
            var settings = $.parseJSON(settingJson);
            var checkTooltip = $(".md-pricing-table-wrapper").hasClass("js-check-tooltip");
            if(settings.tooltip_flag == 1){
                $(".js-body-area-tooltip").removeClass("js-hidden");
            }else{
                $(".js-body-area-tooltip").addClass("js-hidden");
            }
            if($.checkExistArray(strConvertToJson) === ""){

                //for(var i = 0; i < 3; i++){
                var $content = $("#js-content-pricing-table").clone();
                var json = new Array(),objSetting = new Array(), objHeader = new Array(),
                    objPrice = new Array(), objBody = new Array(), objFooter = new Array();
                var i = 1;
                $content.attr("id", i);
                $content.find(".js-hd-json").attr("name", i);
                objSetting.push({
                    setting_id: i,
                    position_ribbon:'top-left',
                    hight_light: false,
                    text_ribbon:"",
                    color_ribbon:"#FFF",
                    color_ribbon_bg: "#EE5B30",
                    check_ribbon: false
                });
                objHeader.push({
                    header_id: i,
                    header_extend:"",
                    title:"",
                    custom:false,
                    custom_class:"",
                    custom_css:"",
                    class_add:"",
                    images:"",
                    video:"",
                    map:"",
                    custom_html:""
                });
                objPrice.push({
                    price_id: i,
                    style: "style-op1",
                    price_price: "",
                    custom_class: "",
                    custom_css: "",
                    class_add:"",
                    currency : "",
                    per_day : ""
                });
                objBody.push({
                    body_id: i,
                    descript: [{
                        descriptId: 1,
                        descript_content: "",
                        tooltip: "",
                        icon: "1",
                        align : "1"
                    }],
                    custom_class: "",
                    custom_css: "",
                    class_add: ""
                });
                objFooter.push({
                    footer_id: i,
                    button_type: "0",
                    button_title: "",
                    button_link: "",
                    new_window: false,
                    custom_class: "",
                    custom_css: "",
                    class_add : "",
                    custom_html :""
                });
                json.push({
                    id: i,
                    tbl_setting: objSetting[0],
                    tbl_header: objHeader[0],
                    tbl_body: objBody[0],
                    tbl_price: objPrice[0],
                    tbl_footer: objFooter[0]
                });
                $content.find(".js-hd-json").data("pricingTable", json);
                $("#md-pb-items").append($content);
                //}
            }else{
                $.each(strConvertToJson,function(i,json)
                {

                    var $content = $("#js-content-pricing-table").clone();
                    $content.attr("id", json.json_id);
                    $content.find(".js-hd-json").attr("name", json.json_id);
                    // get data to json string
                    var dataItem = [];
                    var checkSetting = $.checkExistObj(json.json_setting);
                    var checkHeader = $.checkExistObj(json.json_header);
                    var checkBody = $.checkExistObj(json.json_body);
                    var checkPrice = $.checkExistObj(json.json_price);
                    if(checkPrice !== ""){
                        $content.find(".js-header-label-pb").remove();
                        $content.find(".label-pb").append("<p class='js-header-label-pb'>$"+checkPrice.price_price+"</p>");
                    }
                    var checkFooter = $.checkExistObj(json.json_footer);
                    dataItem.push({
                        id: json.json_id,
                        tbl_setting: checkSetting,
                        tbl_header: checkHeader,
                        tbl_body: checkBody,
                        tbl_price: checkPrice,
                        tbl_footer: checkFooter
                    });
                    $content.find(".js-hd-json").data("pricingTable", dataItem);
                    $("#md-pb-items").append($content);
                });
            }
        },
        previewPricingTable: function(){
          $(document).on('click',"#edit-preview", function(e){
              e.preventDefault();
              $.ajax({
                  type:"POST",
                  url:  Drupal.settings.basePath+ "?q=admin/structure/md-pricing-table/preview",
//                  async: false,
                  data:{
                      data_content: $(".md_prtb_json_data").val(),
                      data_css: $(".md-data-custom-class").val(),
                      setting:Drupal.settings.md_pricing_table.wdt_json_setting
                  },
                  dataType: 'html',
                  success: function(mgs){
                      $('.content_preview_pricing_table').empty();
                      $('.preview_pricing_table').removeClass('js-hidden');
                      $('.preview_pricing_table').css('transform', 'translateX(-100%');
                      $('.preview_pricing_table').css('left', '0');
                      $('.preview_pricing_table').css('display', 'block');
                      $('.content_preview_pricing_table').append(mgs);
                      $.wle_pricing_setting_equal();
                      $.wle_pricing_set_map();
                      $('.preview_pricing_table').animate({
                          left: "+="+ $('.preview_pricing_table').css('width')
                      }, function(){
                          console.log($('.preview_pricing_table').css('left'));
                      })
                  }
              });
          });
        },
        deletePreviewPricingTable: function(){
            $(document).on('click','#delete_preview', function(){
//                $('.preview_pricing_table').addClass('js-hidden');
                $('.preview_pricing_table').animate({
                    left: "-="+ $('.preview_pricing_table').css('width')
                }, function(){
                    $('.preview_pricing_table').css('transform', 'translateX(-150%');
                });
            });
        }
    };
})(jQuery);

