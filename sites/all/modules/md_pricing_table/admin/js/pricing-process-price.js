/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
(function($) {
    pricing.ProcessPrice = function() {
        this.init();
    };
    pricing.ProcessPrice.prototype = {
        constructor: pricing.ProcessPrice,
        init: function() {
            this.displayForm();
            this.hiddenForm();
            this.customCss();
            this.processClickStyle();
            this.setData();
            this.saveData();
        },
        displayForm: function(){
            $(document).on("click", ".md-pb-title:contains(Price)", function() {
                $(".js-popup-price").dialog({
                    autoOpen: false,
                    minWidth: 340,
                    resizable: false,
                    show: {
                        effect: "fade", //scale, puff, slide
                        //duration: 900,
                        direction: "up",
                        easing: "easeOutCubic"
                    },
                    hide: {
                        effect: "fade", //scale, puff, slide
                        //duration: 900,
                        direction: "up",
                        easing: "easeOutCubic"
                    },

                    dialogClass: "no-close",
                    create: function() {
                        $(this).closest('.ui-dialog').on('keydown', function(ev) {
                            if (ev.keyCode === $.ui.keyCode.ESCAPE) {
                                $(".js-popup-price").dialog('close');
                                $(".md-pb-backdrop").removeClass("js-backdrop");
                                $(".md-pb-item").children().children().removeClass("active");
                                $("#js-price-save").addClass("js-price-save");
                            }
                        });
                    },
                    closeOnEscape: false
                });
                // hight light current element
                $('.js-popup-price').dialog("open");
                $(".md-pb-backdrop").addClass("js-backdrop");
                // remove property default jquery ui
                $(".ui-dialog").css({"background" : "none", "border" : "none", "width" : "auto"});
                $(".ui-dialog-titlebar ").remove();
                //$(".ui-resizable-handle").remove();
                $(".js-popup-price").removeClass("ui-dialog-content ui-widget-content");
            });
        },
        hiddenForm: function(){
            $(document).on('click', '#js-icon-delete-price', function() {
                $(".js-popup-price").dialog('close');
                $(".md-pb-backdrop").removeClass("js-backdrop");
                $(".md-pb-item").children().children().removeClass("active");
                $("#js-price-save").addClass("js-price-save");
            });
        },
        customCss: function() {
            $.statusPrice = true;
            $(document).on("click", "#js-price-click-css", function(event) {
                if ($.statusPrice) {
                    $("#js-price-click-css").removeClass("js-bt-position");
                    $(".js-price-custom-css").slideDown("slow");
                    $("#js-price-click-css").removeClass("pb-button-dark");
                    $.statusPrice = false;
                } else {
                    $(".js-price-custom-css").slideUp("slow");
                    $("#js-price-click-css").addClass("pb-button-dark");
                    $("#js-price-click-css").addClass("js-bt-position");
                    $.statusPrice = true;
                }

                event.preventDefault();
            });
        },
        processClickStyle: function() {
            $(document).on("click", ".js-price-click-style", function() {
                $("#js-price-style-ul").children().removeClass("active");
                $(this).addClass("active");
                var style = $(this).attr("id");
                $(".js-price-hidden-style").val(style);
            });
        },
        setData: function(){
            $(document).on("click", ".md-pb-title:contains(Price)", function() {
                // set data for elements
                var idItem = $(this).parents(".md-pb-item").attr("id");// get id current
                $(".dynamic-id").attr("id", idItem);// set id to input hidden
                var arr = $(this).parents(".md-pb-item").find(".js-hd-json").data("pricingTable");
                if ($.checkExistArray(arr) !== "" && $.checkExistObj(arr[0].tbl_price) !== "") {
                    var arrayPrice = arr[0].tbl_price;
                    // selected style
                    var styleSelected = "#" + arrayPrice.style;
                    $("#js-price-style-ul").children().removeClass("active");
                    $(styleSelected).addClass("active");
                    //set value for text fields
                    $(".js-price-hidden-style").val(arrayPrice.style);
                    $(".js-price-price").val(arrayPrice.price_price);
                    $(".js-price-currency").val(arrayPrice.currency);
                    $(".js-price-per-day").val(arrayPrice.per_day);
                    if (arrayPrice.class_add != "" || arrayPrice.custom_css != "") {
                        $(".js-price-tf-class").val(arrayPrice.class_add);
                        $(".js-price-area-css").val(arrayPrice.custom_css);
                        $("#js-price-click-css").removeClass("pb-button-dark");
                        $(".js-price-custom-css").show();
                        $.statusPrice = false;
                    } else {
                        $(".js-price-tf-class").val("");
                        $(".js-price-area-css").val("");
                        $("#js-price-click-css").addClass("pb-button-dark");
                        $("#js-price-click-css").addClass("js-bt-position");
                        $(".js-price-custom-css").hide();
                        $.statusPrice = true;
                    }
                } else {
                    $("#js-price-style-ul").children().removeClass("active");
                    $("#style-op1").addClass("active");
                    $(".js-price-price").val("");
                    $(".js-price-hidden-style").val('style-op1');
                    $(".js-price-tf-class").val("");
                    $(".js-price-area-css").val("");
                    $(".js-price-currency").val("");
                    $(".js-price-per-day").val("");
                    $("#js-price-click-css").addClass("pb-button-dark");
                    $(".js-price-custom-css").hide();
                    $.statusPrice = true;
                }
                $(".md-pb-item").children().children().removeClass("active");
                $(this).parent().addClass("active");
                $(".js-error-price").empty();
            });
        },
        saveData: function() {
            $(document).on("click", ".js-price-save", function(event) {
                var arrDataPrice = [];
                var keyId = $(".dynamic-id").attr("id");
                var pStyle = $(".js-price-hidden-style").val();
                var pPrice = $(".js-price-price").val(),
                    pClass = "", pCss = "";
                if($.statusPrice === false){
                    pClass = $(".js-price-tf-class").val();
                    pCss = $(".js-price-area-css").val();
                }
                var currency = $(".js-price-currency").val();
                var perDay = $(".js-price-per-day").val();
                var idRandom = "";
                if(pCss !== ""){
                    idRandom = "prtb_" + Date.now();
                }
                    arrDataPrice.push({
                        price_id: keyId,
                        style: pStyle,
                        price_price: pPrice,
                        custom_class: idRandom,
                        custom_css: pCss,
                        class_add:pClass,
                        currency : currency,
                        per_day : perDay
                    });
                var arrSaveheader = [];
                var arr = $("input[name='" + keyId + "']").data("pricingTable");
                // check array "arr" object exist or not
                var result = $.checkExistArray(arr);
                var setting = "", body = "", header = "", footer = "";
                if (result != "") {
                    setting = result[0].tbl_setting;
                    body = result[0].tbl_body;
                    header = result[0].tbl_header;
                    footer = result[0].tbl_footer;
                }
                arrSaveheader.push({
                    id: keyId,
                    tbl_setting: setting,
                    tbl_header: header,
                    tbl_body: body,
                    tbl_price: arrDataPrice[0],
                    tbl_footer: footer
                });
                $("input[name='" + keyId + "']").data("pricingTable", arrSaveheader);
                $(".js-popup-price").dialog('close');
                $(".md-pb-backdrop").removeClass("js-backdrop");
                $(".md-pb-item").children().children().removeClass("active");
                if(pPrice !== ""){
                    $("#" + keyId).find(".js-header-label-pb").remove();
                    $("#" + keyId).find(".label-pb").append("<p class='js-header-label-pb'>$"+pPrice+"</p>");
                }
                event.preventDefault();
            });
        }
    };
})(jQuery);

