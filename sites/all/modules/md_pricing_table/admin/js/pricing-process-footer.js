/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
(function($) {
    pricing.ProcessFooter = function() {
        this.init();
    };
    pricing.ProcessFooter.prototype = {
        constructor: pricing.ProcessFooter,
        init: function() {
            this.displayForm();
            this.hiddenForm();
            this.customCss();
            this.setData();
            this.saveData();
            this.disableElement();
        },
        displayForm: function(){
            $(document).on("click", ".md-pb-title:contains(Footer)", function() {
                $(".js-popup-footer").dialog({
                    autoOpen: false,
                    draggable: true,
                    resizable: false,
                    minWidth: 340,
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
                    create: function() {
                        $(this).closest('.ui-dialog').on('keydown', function(ev) {
                            if (ev.keyCode === $.ui.keyCode.ESCAPE) {
                                $(".js-popup-footer").dialog('close');
                                $(".md-pb-backdrop").removeClass("js-backdrop");
                                $(".md-pb-item").children().children().removeClass("active");
                            }
                        });
                    },
                    dialogClass: "no-close",
                    closeOnEscape: false
                });
                $('.js-popup-footer').dialog("open");
                $(".md-pb-backdrop").addClass("js-backdrop");
            });
        },
        hiddenForm: function(){
            $(document).on('click', '#js-icon-delete-footer', function() {
                $(".js-popup-footer").dialog('close');
                $(".md-pb-backdrop").removeClass("js-backdrop");
                $(".md-pb-item").children().children().removeClass("active");
            });
        },
        customCss: function() {
            $.statusFooter = true;
            $(document).on("click", "#js-footer-click-css", function(event) {
                if ($.statusFooter) {
                    $("#js-footer-click-css").removeClass("js-bt-position");
                    $(".js-footer-custom-css").slideDown("slow");
                    $("#js-footer-click-css").removeClass("pb-button-dark");
                    $.statusFooter = false;
                } else {
                    $(".js-footer-custom-css").slideUp("slow");
                    $("#js-footer-click-css").addClass("pb-button-dark");
                    $("#js-footer-click-css").addClass("js-bt-position");
                    $.statusFooter = true;
                }
                event.preventDefault();
            });
        },
        disableElement : function(){
            $(".js-footer-select").change(function(){
                var action = $(this).val();
                if(action == true){
                    $("#js-footer-click-css").hide();
                    $(".js-footer-custom-css").hide();
                    $(".js-footer-diable").hide();
                    $(".js-footer-area-html").slideDown();
                    $.statusFooter = false;
                }else{
                    $("#js-footer-click-css").addClass("pb-button-dark");
                    $("#js-footer-click-css").slideDown();
                    $(".js-footer-custom-css").hide();
                    $(".js-footer-diable").slideDown();
                    $(".js-footer-area-html").hide();
                    $.statusFooter = true;
                }
            });
        },
        setData: function(){
            var arrFooter = [];
            $(document).on("click", ".md-pb-title:contains(Footer)", function() {

                // set data for elements
                var idItem = $(this).parents(".md-pb-item").attr("id");// get id current
                $(".dynamic-id").attr("id", idItem);// set id to input hidden
                var arr = $(this).parents(".md-pb-item").find(".js-hd-json").data("pricingTable");
                if ($.checkExistArray(arr) !== "" && $.checkExistObj(arr[0].tbl_footer) !== "") {
                    var arrayFooter = arr[0].tbl_footer;
                    $(".js-footer-select option[value = "+arrayFooter.button_type+"]").prop("selected", "selected");
                    if(arrayFooter.button_type == "0"){
                        $("#js-footer-click-css").slideDown();
                        //$(".js-footer-custom-css").slideUp();
                        $(".js-footer-diable").slideDown();
                        $(".js-footer-area-html").hide();
                        if (arrayFooter.class_add != "" || arrayFooter.custom_css != "") {
                            $(".js-footer-tf-class").val(arrayFooter.class_add);
                            $(".js-footer-area-css").val(arrayFooter.custom_css);
                            $("#js-footer-click-css").removeClass("pb-button-dark");
                            $(".js-footer-custom-css").show();
                            $.statusFooter = false;
                        } else {
                            $(".js-footer-tf-class").val("");
                            $(".js-footer-area-css").val("");
                            $("#js-footer-click-css").addClass("pb-button-dark");
                            $("#js-footer-click-css").addClass("js-bt-position");
                            $(".js-footer-custom-css").hide();
                            $.statusFooter = true;
                        }
                    }else{
                        $("#js-footer-click-css").hide();
                        $(".js-footer-custom-css").hide();
                        $(".js-footer-diable").hide();
                        $(".js-footer-area-html").slideDown();
                    }
                    $("#js-footer-tf-title").val(arrayFooter.button_title);
                    $("#js-footer-tf-link").val(arrayFooter.button_link);
                    $(".js-footer-custom-html").val(arrayFooter.custom_html);
                    $(".js-footer-ck-new-window").prop("checked", arrayFooter.new_window);


                } else {
                    $("#js-footer-tf-title").val("");
                    $("#js-footer-tf-link").val("");
                    $(".js-footer-ck-new-window").prop("checked", false);
                    $(".js-footer-tf-class").val("");
                    $(".js-footer-area-css").val("");
                    $("#js-footer-click-css").addClass("pb-button-dark");
                    $("#js-footer-click-css").addClass("js-bt-position");
                    $(".js-footer-custom-css").hide();
                    // reset button type
                    $('.js-footer-select option:eq(0)').prop('selected', true),
                        $(".js-footer-custom-html").val("");
                    $("#js-footer-click-css").slideDown();
                    $(".js-footer-custom-css").hide();
                    $(".js-footer-diable").slideDown();
                    $(".js-footer-area-html").hide();
                    $.statusFooter = true;
                }
                // remove property default jquery ui
                $(".ui-dialog").css({"background" : "none", "border" : "none", "width" : "auto"});
                $(".ui-dialog-titlebar ").remove();
                //$(".ui-resizable-handle").remove();
                $(".js-popup-footer").removeClass("ui-dialog-content ui-widget-content");
                // hight light current element
                $(".md-pb-item").children().children().removeClass("active");
                $(this).parent().addClass("active");
            });
        },
        saveData: function() {
            $(document).on("click", ".js-footer-save", function(event) {
                var keyId = $(".dynamic-id").attr("id"),
                    btType = $(".js-footer-select").val(),
                    tfTitle = $("#js-footer-tf-title").val(),
                    tfLink = $("#js-footer-tf-link").val(),
                    ckNewWindow = $(".js-footer-ck-new-window").prop("checked"),
                    tfClass = "",
                    areaCss = "",
                    customHtml = $(".js-footer-custom-html").val(),
                    arrFooter = [], idRandom = "";
                if($.statusFooter === false){
                    tfClass = $(".js-footer-tf-class").val();
                    areaCss = $(".js-footer-area-css").val();
                }
                if(areaCss !== ""){
                    idRandom = "prtb_" + Date.now();
                }
                    arrFooter.push({
                        footer_id: keyId,
                        button_type: btType,
                        button_title: tfTitle,
                        button_link: tfLink,
                        new_window: ckNewWindow,
                        custom_class: idRandom,
                        custom_css: areaCss,
                        class_add : tfClass,
                        custom_html :customHtml
                    });
                console.log(arrFooter[0]);
                var arr = $("input[name='" + keyId + "']").data("pricingTable");
                var result = $.checkExistArray(arr);
                var setting = "", body = "", header = "", price = "";
                if (result != "") {
                    setting = result[0].tbl_setting;
                    body = result[0].tbl_body;
                    header = result[0].tbl_header;
                    price = result[0].tbl_price;
                }
                var arrSave = [];
                arrSave.push({
                    id: keyId,
                    tbl_setting: setting,
                    tbl_header: header,
                    tbl_body: body,
                    tbl_price: price,
                    tbl_footer: arrFooter[0]
                });
                $("input[name='" + keyId + "']").data("pricingTable", arrSave);
//                console.log(arrSave);
                $(".js-popup-footer").dialog('close');
                $(".md-pb-backdrop").removeClass("js-backdrop");
                $(".md-pb-item").children().children().removeClass("active");
                event.preventDefault();
            });
        }
    };
})(jQuery);

