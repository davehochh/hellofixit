/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
(function($) {

    pricing.PricingTable = function() {
        this.init();
    };

    pricing.PricingTable.prototype = {
        constructor: pricing.PricingTable,
        // method constructor
        init: function() {
            this.addPricingTable();
            this.removePricingTable();
            this.duplicatePricingTable();
//            this.displayFormSetting();
//            this.displayFormHeader();
//            this.displayFormBody();
//            this.displayFormPrice();
//            this.displayFormFooter();
//            this.hideForm();
            this.sortablePricingTable();
        },
        // add new pricing table
        addPricingTable: function() {
            $(document).on("click", '.js-add-pricing-table', function() {
                var $content = $("#js-content-pricing-table").clone();
                var idRandom = Date.now();
                var json = new Array(),objSetting = new Array(), objHeader = new Array(),
                    objPrice = new Array(), objBody = new Array(), objFooter = new Array();
                $content.attr("id", idRandom);
                $content.find(".js-hd-json").attr("name", idRandom);
                $content.find(".box-icon-chose > .fontello").removeClass();
                // Set Data Default
                objSetting.push({
                    setting_id: idRandom,
                    position_ribbon:'top-left',
                    hight_light: false,
                    text_ribbon:"",
                    color_ribbon:"#FFF",
                    color_ribbon_bg: "#EE5B30",
                    check_ribbon: false
                });
                objHeader.push({
                    header_id: idRandom,
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
                    price_id: idRandom,
                    style: "style-op1",
                    price_price: "",
                    custom_class: "",
                    custom_css: "",
                    class_add:"",
                    currency : "",
                    per_day : ""
                });
                objBody.push({
                    body_id: idRandom,
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
                    footer_id: idRandom,
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
                    id: idRandom,
                    tbl_setting: objSetting[0],
                    tbl_header: objHeader[0],
                    tbl_body: objBody[0],
                    tbl_price: objPrice[0],
                    tbl_footer: objFooter[0]
                });
                $content.find(".js-hd-json").data("pricingTable", json);
                console.log($content.find(".js-hd-json").data("pricingTable"));
                $("#md-pb-items").append($content);
            });
        },
        //remove pricing table
        removePricingTable: function() {
            $(document).on("click", ".icon-pb-delete", function() {
                $(this).parents(".md-pb-item").remove();
            });
        },
        // duplicate pricing table
        duplicatePricingTable: function() {
            $.countDuplicate = 4;
            $(document).on("click", ".icon-pb-duplicate", function() {
                var $content = $(this).parents(".md-pb-item").clone();
                $content.attr("id", $.countDuplicate);
                $content.find(".js-hd-json").attr("name", $.countDuplicate);
                var idSelected = $(this).parents(".md-pb-item").attr("id");
                // copy value to tag hidden
                var arr = $(this).parents(".md-pb-item").find(".js-hd-json").data("pricingTable");
//                console.log(arr);
                var checkArrayTotal = $.checkExistArray(arr);
                var arrSetting = [], arrHeader = [], arrPrice = [], arrBody = [], arrFooter = [];
                var setting="", header ="", price ="", body ="", footer ="";
                if(checkArrayTotal != ""){
                    var checkObjSetting = $.checkExistObj(checkArrayTotal[0].tbl_setting);
                    var checkObjHeader = $.checkExistObj(checkArrayTotal[0].tbl_header);
                    var checkObjBody = $.checkExistObj(checkArrayTotal[0].tbl_body);
                    var checkObjPrice = $.checkExistObj(checkArrayTotal[0].tbl_price);
                    var checkObjFooter = $.checkExistObj(checkArrayTotal[0].tbl_footer);
                    if(checkObjSetting != ""){
                        arrSetting.push({
                            setting_id : $.countDuplicate,
                            hight_light : checkObjSetting.hight_light,
                            position_ribbon : checkObjSetting.position_ribbon,
                            text_ribbon : checkObjSetting.text_ribbon,
                            color_ribbon : checkObjSetting.color_ribbon,
                            color_ribbon_bg : checkObjSetting.color_ribbon_bg,
                            check_ribbon: checkObjSetting.check_ribbon,
                            check_add_class: checkObjSetting.check_add_class,
                            class_add:checkObjSetting.class_add
                        });
                        setting = arrSetting[0];
                    }

                    if(checkObjHeader != ""){
                        var image = $.checkExistObj(checkObjHeader.images);
                        var video = $.checkExistObj(checkObjHeader.video);
                        var map = $.checkExistObj(checkObjHeader.map);
                        var customClass = "";
                        if(checkObjHeader.custom_css !== ""){
                            customClass = checkObjHeader.custom_class + "c" + $.countDuplicate;
                        }
                        arrHeader.push({
                            header_id: $.countDuplicate,
                            header_extend: checkObjHeader.header_extend,
                            title: checkObjHeader.title,
                            custom: checkObjHeader.custom,
                            custom_class: customClass,
                            custom_css: checkObjHeader.custom_css,
                            class_add : checkObjHeader.class_add,
                            custom_html: checkObjHeader.custom_html,
                            images: image,
                            video: video,
                            map: map
                        });
                        header = arrHeader[0];
                    }
                    if(checkObjBody != ""){
                        var arrDescript = checkObjBody.descript ;
                        var customClassBody = "";
                        if(checkObjBody.custom_css !== ""){
                            customClassBody = checkObjBody.custom_class + "c" + $.countDuplicate;
                        }
                        arrBody.push({
                            body_id: $.countDuplicate,
                            descript: arrDescript,
                            custom_class: customClassBody,
                            custom_css: checkObjBody.custom_css,
                            class_add: checkObjBody.class_add
                        });
                        body = arrBody[0];
                    }
                    if(checkObjPrice != ""){
                        var customClassPrice = "";
                        if(checkObjPrice.custom_css !== ""){
                            customClassPrice = checkObjPrice.custom_class + "c" + $.countDuplicate;
                        }
                        arrPrice.push({
                            price_id: $.countDuplicate,
                            style: checkObjPrice.style,
                            price_price: checkObjPrice.price_price,
                            custom_class: customClassPrice,
                            custom_css: checkObjPrice.custom_css,
                            class_add : checkObjPrice.class_add,
                            currency : checkObjPrice.currency,
                            per_day : checkObjPrice.per_day
                        });
                        price = arrPrice[0];
                    }
                    if(checkObjFooter != ""){
//                        console.log(checkObjFooter.button_type);
                        var customClassFooter = "";
                        if(checkObjFooter.custom_css !== ""){
                            customClassFooter = checkObjFooter.custom_class + "c" + $.countDuplicate;
                        }
                        arrFooter.push({
                            footer_id: $.countDuplicate,
                            button_type: checkObjFooter.button_type,
                            button_title: checkObjFooter.button_title,
                            button_link: checkObjFooter.button_link,
                            new_window: checkObjFooter.new_window,
                            custom_class: customClassFooter,
                            custom_css: checkObjFooter.custom_css,
                            class_add : checkObjFooter.class_add,
                            custom_html: checkObjFooter.custom_html
                        });
                        footer = arrFooter[0];
                    }
                    var arrTotal = [];
                    arrTotal.push({
                        id: $.countDuplicate,
                        tbl_setting: setting,
                        tbl_header: header,
                        tbl_body: body,
                        tbl_price: price,
                        tbl_footer: footer
                    });
                    $content.find(".js-hd-json").data("pricingTable",arrTotal);
                    console.log(arrTotal);
                }
                $("#md-pb-items").append($content);
                $.countDuplicate ++;
            });
        },
        // create sortable pricing table
        sortablePricingTable: function() {
            $("#md-pb-items").sortable({
                connectWith: "#md-pb-items",
                cancel: ".js-sortable-toggle",
                revert : true,
                opacity: 0.95,
                scrollSpeed: 4,
                placeholder: "md-pb-item-placeholder",
                start: function(e, ui) {

                },
                change: function(e, item) {
//                    console.log($(this).children('.md-pb-item'));
                }
            });
        }


    };
})(jQuery);

