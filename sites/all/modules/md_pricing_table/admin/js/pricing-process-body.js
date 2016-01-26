/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
(function($) {
    pricing.ProcessBody = function() {
        this.init();
    };

    pricing.ProcessBody.prototype = {
        // method constructor
        constructor: pricing.ProcessBody,
        init: function() {
            this.displayForm();
            this.hiddenForm();
            this.bodyAccordion();
            this.itemRemove();
            this.itemDuplicate();
            this.itemAddNew();
            this.changeIcon();
            this.customCss();
            this.processAlign();
            this.setData();
            this.saveData();
            this.addContentToHeader();

        },
        displayForm: function(){
            $(document).on('click','.md-pb-title:contains(Body)', function(){
                $(".js-popup-body").dialog({
                    autoOpen: false,
                    minWidth: 340,
                    modal: true,
                    resizable: false,
                    show: {
                        effect: "fade", //scale, puff, slide
                        direction: "up",
                        easing: "easeOutCubic"
                    },
                    hide: {
                        effect: "fade", //scale, puff, slide
                        direction: "up",
                        easing: "easeOutCubic"
                    },
                    create: function() {
                        $(this).closest('.ui-dialog').on('keydown', function(ev) {
                            if (ev.keyCode === $.ui.keyCode.ESCAPE) {
                                $(".js-popup-body").dialog('close');
                                $(".md-pb-backdrop").removeClass("js-backdrop");
                                $(".md-pb-item").children().children().removeClass("active");
                            }
                        });
                    },
                    dialogClass: "no-close",
                    closeOnEscape: false
                });

                $('.js-popup-body').dialog("open");
                $(".md-pb-backdrop").addClass("js-backdrop");
                // remove property default jquery ui
                $(".ui-dialog").css({"background" : "none", "border" : "none", "width" : "auto"});
                $(".ui-dialog-titlebar ").remove();
                //$(".ui-resizable-handle").remove();
                $(".js-popup-body").removeClass("ui-dialog-content ui-widget-content");
            });
        },
        hiddenForm: function(){
            $(document).on('click', '#js-icon-delete-body', function() {
                $(".js-popup-body").dialog('close');
                $(".md-pb-backdrop").removeClass("js-backdrop");
                $(".md-pb-item").children().children().removeClass("active");
            });
        },
        // create effect accordion and sortable
        bodyAccordion: function() {
            $(".block-sortable-items").accordion({
                header: ".js-body-accordion",
                icons : false,
                active: 1,
                autoHeight: true,
                collapsible: true, // toogle
                heightStyle: "content", // attributes importants
                event: "click"
            }).sortable({
                    axis: "y",
                    handle: ".js-body-accordion",
                    //delay: 50,
                    opacity: 0.8,
                    scrollSpeed: 4,
                    placeholder: "block-sortable-placeholder",
                    stop: function(event, ui) {
                        ui.item.children("h3.sortable-header").triggerHandler("focusout");
                    }
                });
        },
        itemRemove: function() {
            $(document).on("click", ".icon-pb-delete", function() {
                $(this).parents(".js-body-item").remove();
                $.count--;
            });
        },
        // duplicate item
        itemDuplicate: function() {
            $(document).on("click", ".js-body-duplicate", function(event) {
                var $itemParents = $(this).parents(".js-body-item");
                var $content = $itemParents.clone();
                var idRandom = Date.now();
                // fill data to textarea
                var descript = $itemParents.find(".js-body-area-descript").val();
                var tooltip = $itemParents.find(".js-body-content-tooltip").val();
                $content.find(".js-body-area-descript").val(descript);
                $content.find(".js-body-content-tooltip").val(tooltip);
                // clone data
                $(".js-body-items").append($content);
                $(".sortable-content").removeAttr("style");// remove attributes of jquery ui 
                // process checkbox
                $itemParents.find(".js-body-checkbox-tooltip").attr("id", idRandom);
                $itemParents.find(".js-body-label-tooltip").attr("for", idRandom);
                var index = $(".block-sortable-items .js-body-accordion").length - 1;
                $(".block-sortable-items").accordion("refresh");
                $(".block-sortable-items").accordion({active:index});
            });
        },
        // add new item default
        itemAddNew: function() {
            $(document).on("click", "#js-body-add-new-item", function() {
                var $selector = $("#js-body-item-hidden:last");
                console.log($selector);
                var $content = $selector.clone();
                $content.find(".js-body-align-click").removeClass("active");
                console.log($content.find(".js-body-align-click"));
                $content.find(".js-add-content").empty();
                $content.find(".js-body-text-align").val("1");
                $content.find(".js-body-icon").val("0");
                $content.find(".sortable-header i:first").removeClass();
                $content.find(".box-list > i").removeClass("chose");
                $content.find(".box-icon-chose > i").removeClass();
                var $append = $(".js-body-items").append($content);

                $(".block-sortable-items").accordion("refresh");
                var index = $(".block-sortable-items .js-body-accordion").length - 1;
                $(".block-sortable-items").accordion({active:index});
                $('.js-body-area-descript').focus();
            });
        },
        changeIcon: function() {
            // disable choose icon
            var iconStatus = true;
            $(document).on("click", ".js-select-icon", function(event) {
                if(iconStatus)
                    $(this).parent().find(".popup-icon-lib").slideDown();
                else
                    $(this).parent().find(".popup-icon-lib").slideUp();
                iconStatus = !iconStatus;
                event.preventDefault();
            });
            //event click outside this element jquery
            $(document).click(function(event) {
                if(!$(event.target).closest('.js-select-icon').length) {
                    if($('.js-select-icon').is(":visible") && iconStatus == false) {
                        $(".popup-icon-lib").slideUp();
                        iconStatus = true;
                    }
                }
            });
            // change icon
            $(document).on("click", ".box-list>i", function(){
                var icon = $(this).attr("class");
                $(this).parent().children().removeClass("chose");
                $(this).addClass(" chose");
                $(this).parents(".popup-icon-lib").find(".box-icon-chose > i").removeClass().addClass(icon + " chose");
                $(this).parents(".js-body-item").find("i:first").removeClass().addClass("chose " + icon);
                $(this).parents(".popup-icon-lib").slideUp();
                iconStatus = true;
                $(this).parents(".js-body-item").find(".js-body-icon").val(icon);
            });
        },
        customCss: function() {
            $.statusBody = true;
            $(document).on("click", "#js-body-click-css", function(event) {
                if ($.statusBody) {
                    $("#js-body-click-css").removeClass("js-bt-position");
                    $(".js-body-custom-css").slideDown("slow");
                    $("#js-body-click-css").removeClass("pb-button-dark");
                    $.statusBody = false;
                } else {
                    $(".js-body-custom-css").slideUp("slow");
                    $("#js-body-click-css").addClass("pb-button-dark");
                    $("#js-body-click-css").addClass("js-bt-position");
                    $.statusBody = true;
                }
                event.preventDefault();
            });
        },
        processAlign: function() {
            // process align
            $(document).on("click", ".js-body-align-click", function (){
                $(this).parent().children().removeClass("active");
                $(this).addClass("active");
                $(this).parent().find(".js-body-text-align").val($(this).attr("id"));
            });
        },
        setData: function(){
            var arrBody = [];
            var arrDescriptSetValue = [];
            $(document).on("click", ".md-pb-title:contains(Body)", function() {

                // set data for elements
                var idItem = $(this).parents(".md-pb-item").attr("id");// get id current
                $(".dynamic-id").attr("id", idItem);// set id to input hidden
                var arr = $(this).parents(".md-pb-item").find(".js-hd-json").data("pricingTable");
                var idRandom = Date.now();

                if ($.checkExistArray(arr) != "" && $.checkExistObj(arr[0].tbl_body) != "") {
                    var arrBody = arr[0].tbl_body;
                    arrDescriptSetValue = arrBody.descript;
                    var size = $.arraySize(arrDescriptSetValue);
                    $(".js-body-items").children().remove();
                    var $selector = $("#js-body-item-hidden");
                    for (var i = 1; i <= size; i++) {
                        var res = $.objectFindByKey(arrDescriptSetValue, 'descriptId', i);
                        var $content = $selector.clone();
                        // set value for descript
                        $content.find(".js-body-area-descript").val(res.descript_content);
                        $content.find(".js-add-content").empty().append(res.descript_content);
                        $content.find("#" + res.align).addClass("active");
                        $content.find(".js-body-text-align").val(res.align);
                        // set checkbox for tooltip
                        $content.find(".js-body-content-tooltip").val(res.tooltip);
                        // set icon
                        $content.find(".sortable-header > i:first").removeClass().addClass("chose " + res.icon);
                        $content.find(".js-body-icon").val(res.icon);
                        $content.find(".box-list > i").removeClass("chose");
                        var arrIcon = res.icon.split(/\s+/),
                            lastIcon = arrIcon[arrIcon.length - 1];
                        $content.find("." + lastIcon).addClass("chose");
                        $content.find(".box-icon-chose > i").removeClass().addClass(res.icon + " chose");
                        var $append = $(".js-body-items").append($content);
                    }
                    //set value for text fields
                    if (arrBody.class_add != "" || arrBody.custom_css != "") {
                        $(".js-body-tf-class").val(arrBody.class_add);
                        $(".js-body-area-css").val(arrBody.custom_css);
                        $("#js-body-click-css").removeClass("pb-button-dark");
                        $(".js-body-custom-css").show();
                        $.statusBody = false;
                    } else {
                        $(".js-body-tf-class").val("");
                        $(".js-body-area-css").val("");
                        $("#js-body-click-css").addClass("pb-button-dark");
                        $("#js-body-click-css").addClass("js-bt-position");
                        $(".js-body-custom-css").hide();
                        $.statusBody = true;
                    }

                } else {// invoked when there is no data
                    $(".js-body-items").children().remove();
                    var $value = $("#js-body-item-hidden").clone();
                    $(".js-body-items").append($value);
                    $(".js-body-tf-class").val("");
                    $(".js-body-area-css").val("");
                    $("#js-body-descript").val("");
                    $("#js-body-tooltips").val("");
                    $("#js-change-icon option[value=demo1]").prop('selected', 'selected');
                    $("#js-body-click-css").addClass("pb-button-dark");
                    $(".js-body-custom-css").hide();
                    $.statusBody = true;
                    $('.js-body-checkbox-tooltip').prop('checked', false);
                    $("#js-price-click-css").addClass("pb-button-dark");
                }
                $(".block-sortable-items").accordion("refresh");
                $(".md-pb-item").children().children().removeClass("active");
                $(this).parent().addClass("active");
            });
        },
        saveData: function() {
            $(document).on("click", ".js-body-save", function(event) {
                var arrBody = [];
                // request value from descript and tooltips
                var descript = $('.js-body-descript\\[\\]').map(function() {return this.value;}).get();
//                console.log($('.js-body-descript\\[\\]').map(function() { return this.value;}).get());
                var align = $('.js-body-align\\[\\]').map(function() { return this.value;}).get();
                var icon = $('.js-change-icon\\[\\]').map(function() {return this.value;}).get();
                var tooltip = $('.js-body-tooltips\\[\\]').map(function() {return this.value;}).get();
                // request custom css
                var classRequest = "", cssRequest = "";
                if($.statusBody === false){
                    classRequest = $(".js-body-tf-class").val();
                    cssRequest = $(".js-body-area-css").val();
                }

                var keyId = $(".dynamic-id").attr("id");
                var size = descript.length -1 ;
                var i;
                for(i = 0 ; i < size; i++){
                    arrBody.push({
                        descriptId: i+1,
                        descript_content: descript[i],
                        tooltip: tooltip[i],
                        icon: icon[i],
                        align : align[i]
                    });
                }
                var arrSaveBody = [];
                var arr = $("input[name='" + keyId + "']").data("pricingTable");
                //var result = $.objectFindByKey(arr, 'id', keyId);
                var result = $.checkExistArray(arr);
                var setting = "", price = "", header = "", footer = "";
                var body = [];
                if (result != "") {
                    setting = result[0].tbl_setting;
                    price = result[0].tbl_price;
                    header = result[0].tbl_header;
                    footer = result[0].tbl_footer;
                }
                var idRandom = "";
                if(cssRequest !== ""){
                    idRandom = "prtb_" + Date.now();
                }

                    body.push({
                        body_id: keyId,
                        descript: arrBody,
                        custom_class: idRandom,
                        custom_css: cssRequest,
                        class_add: classRequest
                    });
                arrSaveBody.push({
                    id: keyId,
                    tbl_setting: setting,
                    tbl_header: header,
                    tbl_body: body[0],
                    tbl_price: price,
                    tbl_footer: footer
                });
                $("input[name='" + keyId + "']").data("pricingTable", arrSaveBody);
                $(".js-popup-body").dialog('close');
                $(".md-pb-backdrop").removeClass("js-backdrop");
                $(".md-pb-item").children().children().removeClass("active");
                event.preventDefault();
            });
        },
        addContentToHeader : function(){
            $(document).on("keyup", ".js-body-area-descript", function(){
                var content = $(this).val();
                $(this).parents(".js-body-item").find(".js-add-content").empty().append(content);
            });
        }

    };
})(jQuery);

