/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

(function($) {
    pricing.ProcessSetting = function() {
        this.init();
    };
    pricing.ProcessSetting.prototype = {
        constructor: pricing.ProcessSetting,
        init: function() {
            this.displayForm();
            this.hiddenForm();
            this.processDisableElements();
            this.previewRibbon();
            this.setData();
            this.saveData();
        },
        displayForm: function(){
            var checkPopupSetting =0;
            $(document).on('click','.icon-pb-setting', function(){
                $(".js-popup-setting").dialog({

                    autoOpen: false,
                    minWidth: 340,
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
                                $(".js-popup-setting").dialog('close');
                                $(".md-pb-backdrop").removeClass("js-backdrop");
                            }
                        });
                    },

                    dialogClass: "no-close",
                    closeOnEscape: false
                });
                $('.js-popup-setting').dialog("open");

                $(".md-pb-backdrop").addClass("js-backdrop");
                // remove property default jquery ui
                $(".ui-dialog").css({"background" : "none", "border" : "none", "width" : "auto"});
                $(".ui-dialog-titlebar ").remove();
                $(".js-popup-setting").removeClass("ui-dialog-content ui-widget-content");

            });
            if (checkPopupSetting==1){
                $('.md-pb-setting').removeClass('popup-setting');
            }
        },
        hiddenForm: function(){
            $(document).on('click', '#js-icon-delete-setting', function() {
                $(".js-popup-setting").dialog('close');
//                $(".js-popup-setting").addClass('popup-setting');
                $(".md-pb-backdrop").removeClass("js-backdrop");
                $(".md-pb-item").children().children().removeClass("active");
            });
        },
        previewRibbon: function(){
            // OnChange js-sts-ribbon
            var color_text = $(".js-setting-color").val();
            var color_bg= $(".js-setting-color-bg").val();
            $(document).on('change',".js-sts-ribbon", function(){
                var color_text = $(".js-setting-color").val();
                var color_bg= $(".js-setting-color-bg").val();
                $(".mdp-ribbon").find(".ribbon").removeClass("top-left top-right burgee-left burgee-right flag-left flag-right top-ribbon bottom-ribbon");
                $(".mdp-ribbon").find(".text-ribbon").css("color",color_text);
                $(".mdp-ribbon").find(".ribbon").css("background",color_bg);
                if ($('.js-sts-ribbon').val()=='top-left'||$('.js-sts-ribbon').val()=='top-right'){
                    $(".ribbon-pos-hidden").css('overflow','hidden');
                }
                else{
                    $(".ribbon-pos-hidden").css('overflow','visible');
                }
                if ($(".js-setting-text-ribbon").val() ==""){
                    $(".mdp-ribbon").find(".text-ribbon").text('Text on ribbon');
                }
                else
                {
                    $(".mdp-ribbon").find(".text-ribbon").text($(".js-setting-text-ribbon").val());
                }
                $(".mdp-ribbon").find(".ribbon").addClass($(".js-sts-ribbon").val());
            });
            // On keyUp
            $(document).on('keyup',".js-setting-text-ribbon",function(){
                var color_text = $(".js-setting-color").val();
                var color_bg= $(".js-setting-color-bg").val();
                $(".mdp-ribbon").find(".ribbon").removeClass("top-left top-right burgee-left burgee-right flag-left flag-right top-ribbon bottom-ribbon");
                $(".mdp-ribbon").find(".text-ribbon").css("color",color_text);
                $(".mdp-ribbon").find(".ribbon").css("background",color_bg);
                if ($(".js-setting-text-ribbon").val() ==""){
                    $(".mdp-ribbon").find(".text-ribbon").text('Text on ribbon');
                }
                else
                {
                    $(".mdp-ribbon").find(".text-ribbon").text($(".js-setting-text-ribbon").val());
                }
                $(".mdp-ribbon").find(".ribbon").addClass($(".js-sts-ribbon").val());
            });
        },
        processDisableElements: function(){
            // SlideDow - SlideUp Check Ribbon
            $(document).on("click", ".js-ck-ribbon", function() {
                $.statusSetting = $('.js-ck-ribbon').prop('checked');
                if ($.statusSetting) {
                    $(".js-setting-ribbon").slideDown("200");
                    $.statusSetting = false;
                } else {
                    $(".js-setting-ribbon").slideUp("200");
                    $(".js-setting-ribbon").addClass('js-hidden');
                    $.statusSetting = true;

                }
            });
            // SlideDow - SlideUp Check Add Class
            $(document).on('click','.js-ck-add-class',function(){
                $.statusAddClass = $('.js-ck-add-class').prop('checked');
                if ($.statusAddClass) {
                    $(".class-add-setting").slideDown("200");
                    $.statusAddClass = false;
                } else {
                    $(".class-add-setting").slideUp("200");
                    $(".class-add-setting").addClass('js-hidden');
                    $.statusAddClass = true;

                }
            });
        },
        setData: function(){
            $(document).on("click", ".icon-pb-setting", function(event) {
                //reset element
                $(".js-sts-highlight").prop("checked", false);
                $(".js-ck-ribbon").prop("checked", false);
                $(".js-ck-add-class").prop("checked", false);
                $('.js-sts-ribbon option:eq(0)').prop('selected', true);
                $(".js-setting-text-ribbon").val("");
                $(".js-setting-color").val("#ffffff");
                $(".js-setting-color-bg").val("#EE5B30");
                $(".js-setting-add-class").val("");
                $(".js-setting-ribbon").addClass('js-hidden');
                $(".js-setting-ribbon").css('display','none');
                $(".class-add-setting").addClass('js-hidden');
                $(".class-add-setting").css('display','none');
                $(".ribbon-pos-hidden").css('overflow','hidden');
                // set color default
                var str_right = "<style type='text/css' media='all'>"+".burgee-right:before { border-color:"+"#EE5B30 "+" rgba(0, 0, 0, 0);}"+"</style>";
                var str_left = "<style type='text/css' media='all'>"+".burgee-left:before { border-color:"+"#EE5B30 "+" rgba(0, 0, 0, 0);}"+"</style>";
                $('head').append(str_right);
                $('head').append(str_left);
                //reset preview Ribbon
                $('.ribbon').find('.text-ribbon').css('color',"#FFF");
                $('.ribbon').find('.text-ribbon').text("Text on ribbon");
                $(".mdp-ribbon").find(".ribbon").css("background","#EE5B30");
                $(".mdp-ribbon").find(".ribbon").removeClass("top-left top-right burgee-left burgee-right flag-left flag-right top-ribbon bottom-ribbon");
                $(".mdp-ribbon").find(".ribbon").addClass($(".js-sts-ribbon").val());
                $("#pricing-pickercolor").spectrum({
                    color: "#ffffff", // Set initial color options
                    allowEmpty:true, // Clear Color
                    showInput: true, // True: show input
                    showInitial: true, // True : show initial color
                    showAlpha: true, // True: Allow alpha transparency selection
                    clickoutFiresChange: true,
                    containerClassName: "pricing-spectrum", // Add class "pricing-spectrum" to the just the container element to custom
                    move: function(color){
                        var color_text = color.toHexString();
                        var color_bg=$(".js-setting-color-bg").val();
                        $(".mdp-ribbon").find(".ribbon").removeClass("top-left top-right burgee-left burgee-right flag-left flag-right top-ribbon bottom-ribbon");
                        $(".mdp-ribbon").find(".text-ribbon").css("color",color_text);
                        $(".mdp-ribbon").find(".ribbon").css("background",color_bg);
                        $(".js-setting-color").val(color.toHexString());
                        $(".mdp-ribbon").find(".ribbon").addClass($(".js-sts-ribbon").val());
                    }
                });
                $("#pricing-pickercolor-bg").spectrum({
                    color: "#EE5B30", // Set initial color options
                    allowEmpty:true, // Clear Color
                    showInput: true, // True: show input
                    showInitial: true, // True : show initial color
                    showAlpha: true, // True: Allow alpha transparency selection
                    clickoutFiresChange: true,
                    containerClassName: "pricing-spectrum", // Add class "pricing-spectrum" to the just the container element to custom
                    move: function(color){
                        var color_text = $(".js-setting-color").val();
                        var color_bg= color.toHexString();
                        $(".mdp-ribbon").find(".ribbon").removeClass("top-left top-right burgee-left burgee-right flag-left flag-right top-ribbon bottom-ribbon");
                        $(".mdp-ribbon").find(".text-ribbon").css("color",color_text);
                        $(".mdp-ribbon").find(".ribbon").css("background",color_bg);
                        $(".js-setting-color-bg").val(color.toHexString());
                        var str_right = "<style type='text/css' media='all'>"+".burgee-right:before { border-color:"+color_bg+" rgba(0, 0, 0, 0);}"+"</style>";
                        var str_left = "<style type='text/css' media='all'>"+".burgee-left:before { border-color:"+color_bg+" rgba(0, 0, 0, 0);}"+"</style>";
                        $('head').append(str_right);
                        $('head').append(str_left);
                        $(".mdp-ribbon").find(".ribbon").addClass($(".js-sts-ribbon").val());
                    }
                });
                // set data for elements
                var arrSts = [];
                var idItem = $(this).parents(".md-pb-item").attr("id");// get id current
                $(".dynamic-id").attr("id", idItem);// set id to input hidden
                var arr = $(this).parents(".md-pb-item").find(".js-hd-json").data("pricingTable");
                if (typeof arr !== 'undefined' && arr !== null  && arr.length > 0) {
                    var arraySetting = arr[0].tbl_setting;
                    if (typeof arraySetting !== 'undefined' && arraySetting !== null && arraySetting!="") {
                        $(".js-sts-highlight").prop("checked", arraySetting.hight_light);
                        $(".js-ck-ribbon").prop("checked", arraySetting.check_ribbon);
                        $(".js-ck-add-class").prop("checked", arraySetting.check_add_class);
                        if (arraySetting.position_ribbon != "") {
                            $(".js-sts-ribbon option[value=" + arraySetting.position_ribbon + "]").prop('selected', 'selected');
                        }
                        $(".js-setting-text-ribbon").val(arraySetting.text_ribbon);
                        $(".js-setting-color").val(arraySetting.color_ribbon);
                        $(".js-setting-color-bg").val(arraySetting.color_ribbon_bg);
                        $(".js-setting-add-class").val(arraySetting.class_add);
                        //set ribbon-pos-hidden
                        if ($('.js-sts-ribbon').val()=='top-left'||$('.js-sts-ribbon').val()=='top-right'){
                            $(".ribbon-pos-hidden").css('overflow','hidden');
                        }
                        else{
                            $(".ribbon-pos-hidden").css('overflow','visible');
                        }
                        //set color burgee-right burgee-left
                        var str_right = "<style type='text/css' media='all'>"+".burgee-right:before { border-color:"+ arraySetting.color_ribbon_bg+" rgba(0, 0, 0, 0);}"+"</style>";
                        var str_left = "<style type='text/css' media='all'>"+".burgee-left:before { border-color:"+ arraySetting.color_ribbon_bg+" rgba(0, 0, 0, 0);}"+"</style>";
                        $('head').append(str_right);
                        $('head').append(str_left);
                        // set preview ribbon
                        $(".mdp-ribbon").find(".ribbon").removeClass("top-left top-right burgee-left burgee-right flag-left flag-right top-ribbon bottom-ribbon");
                        if (arraySetting.text_ribbon==""){
                            $(".mdp-ribbon").find(".text-ribbon").text("Text on ribbon");
                        }else
                            $(".mdp-ribbon").find(".text-ribbon").text(arraySetting.text_ribbon);
                        $(".mdp-ribbon").find(".text-ribbon").css("color",arraySetting.color_ribbon);
                        $(".mdp-ribbon").find(".ribbon").css("background",arraySetting.color_ribbon_bg);
                        $(".mdp-ribbon").find(".ribbon").addClass(arraySetting.position_ribbon);
                        $("#pricing-pickercolor").spectrum({
                            color: arraySetting.color_ribbon, // Set initial color options
                            allowEmpty:true, // Clear Color
                            showInput: true, // True: show input
                            showInitial: true, // True : show initial color
                            showAlpha: true, // True: Allow alpha transparency selection
                            clickoutFiresChange: true,
                            containerClassName: "pricing-spectrum",
                            move: function(color){
                                var color_text = color.toHexString();
                                var color_bg= $(".js-setting-color-bg").val();
                                $(".mdp-ribbon").find(".ribbon").removeClass("top-left top-right burgee-left burgee-right flag-left flag-right top-ribbon bottom-ribbon");
                                $(".mdp-ribbon").find(".text-ribbon").css("color",color_text);
                                $(".mdp-ribbon").find(".ribbon").css("background",color_bg);
                                $(".js-setting-color").val(color.toHexString());
                                if($(".js-setting-text-ribbon").val()==""){
                                    $(".mdp-ribbon").find(".text-ribbon").text("Text on ribbon");
                                }
                                $(".mdp-ribbon").find(".ribbon").addClass($(".js-sts-ribbon").val());
                            }
                        });
                        $("#pricing-pickercolor-bg").spectrum({
                            color: arraySetting.color_ribbon_bg,
                            allowEmpty:true, // Clear Color
                            showInput: true, // True: show input
                            showInitial: true, // True : show initial color
                            showAlpha: true, // True: Allow alpha transparency selection
                            clickoutFiresChange: true,
                            containerClassName: "pricing-spectrum",
                            move: function(color){
                                var color_text = $(".js-setting-color").val();
                                var color_bg= color.toHexString();
                                $(".mdp-ribbon").find(".ribbon").removeClass("top-left top-right burgee-left burgee-right flag-left flag-right top-ribbon bottom-ribbon");
                                $(".mdp-ribbon").find(".text-ribbon").css("color",color_text);
                                $(".js-setting-color-bg").val("#C66");
                                $(".mdp-ribbon").find(".ribbon").css("background",color_bg);
                                $(".js-setting-color-bg").val(color.toHexString());
                                if ($(".js-setting-text-ribbon").val()=="")
                                {
                                    $(".mdp-ribbon").find(".text-ribbon").text("Text on ribbon");
                                }
                                else
                                {
                                    $(".mdp-ribbon").find(".text-ribbon").text($(".js-setting-text-ribbon").val());
                                }

                                var str_right = "<style type='text/css' media='all'>"+".burgee-right:before { border-color:"+color.toHexString()+" rgba(0, 0, 0, 0);}"+"</style>";
                                var str_left = "<style type='text/css' media='all'>"+".burgee-left:before { border-color:"+color.toHexString()+" rgba(0, 0, 0, 0);}"+"</style>";
                                $('head').append(str_right);
                                $('head').append(str_left);
                                $(".mdp-ribbon").find(".ribbon").addClass($(".js-sts-ribbon").val());
                            }
                        });
                        // View SlideDow-slideUp for Checked ribbon
                        if($(".js-ck-ribbon").prop("checked")){
                            $('.js-setting-ribbon').removeClass('js-hidden');
                            $(".js-setting-ribbon").css('display','block');
                        }
                        else
                            $('.js-setting-ribbon').addClass('js-hidden');
                        // View SlideDow-SlideUp for Check Add Class
                        if($(".js-ck-add-class").prop("checked")){
                            $('.class-add-setting').removeClass('js-hidden');
                            $(".class-add-setting").css('display','block');
                        }
                        else
                            $('.class-add-setting').addClass('js-hidden');
                    }
                }
                $(this).parents(".md-pb-item").find(".js-hd-json").data("pricingTable");
                $(".md-pb-item").children().children().removeClass("active");
                $(this).addClass("active");
            });
        },

        saveData: function() {
            $(document).on("click", "#js-sts-save", function(event) {
                var arrSave = [], arrSettings = [];
                var hltValue = $('.js-sts-highlight').prop("checked"),
                    ribbonValue = $(".js-sts-ribbon").val(),
                    textRibbon = $(".js-setting-text-ribbon").val(),
                    colorRibbon = $(".js-setting-color").val(),
                    colorRibbonBg= $(".js-setting-color-bg").val(),
                    textClass= $(".js-setting-add-class").val(),
                    checkRibbon= $(".js-ck-ribbon").prop('checked'),
                    checkAddClass= $(".js-ck-add-class").prop('checked');
                var keyId = $(".dynamic-id").attr("id");
                // Check Data
//                if (ribbonValue=='top-left'&&hltValue==false &&textRibbon=="" && colorRibbon=="#ffffff"
//                    && colorRibbonBg== "#EE5B30" && checkRibbon== false &&checkAddClass == false && textClass=="")
//                {
//                    arrSettings[0] ="";
//                }
//                else
//                {
                    arrSettings.push({
                        setting_id: keyId,
                        position_ribbon: ribbonValue,
                        hight_light: hltValue,
                        text_ribbon : textRibbon,
                        color_ribbon : colorRibbon,
                        color_ribbon_bg: colorRibbonBg,
                        check_ribbon: checkRibbon
                    });
//                }
                var arr = $("input[name='" + keyId + "']").data("pricingTable");
                // check array request from tag hidden
                var result = $.checkExistArray(arr);
                var header = "", body = "", price = "", footer = "";
                if(result !=  ""){
                    header = result[0].tbl_header;
                    body = result[0].tbl_body;
                    price = result[0].tbl_price;
                    footer = result[0].tbl_footer;
                }
                arrSave.push({
                    id: keyId,
                    tbl_setting: arrSettings[0],
                    tbl_header: header,
                    tbl_body: body,
                    tbl_price: price,
                    tbl_footer: footer
                });
                console.log(arrSave);
                $("input[name='" + keyId + "']").data("pricingTable", arrSave);
                $(".js-popup-setting").dialog('close');
                $(".md-pb-backdrop").removeClass("js-backdrop");
                $(".md-pb-item").children().children().removeClass("active");
                event.preventDefault();
            });
        }
    };

})(jQuery);
