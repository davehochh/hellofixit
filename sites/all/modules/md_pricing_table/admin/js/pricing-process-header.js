/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
(function($) {
    pricing.ProcessHeader = function() {
        this.init();
    };
    pricing.ProcessHeader.prototype = {
        constructor: pricing.ProcessHeader,
        // method constructor
        init: function() {
            this.displayForm();
            this.hiddenForm();
            this.processDisableElements();
            this.setData();
            this.saveData();
            this.deletePreview();
            this.exportHtml();
        },
        displayForm: function(){
            $(document).on('click', '.md-pb-title:contains(Header)', function(){
                $(".js-popup-header").dialog({
                    autoOpen: false,
                    width: "auto",
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
                                $(".js-popup-header").dialog('close');
                                $(".md-pb-backdrop").removeClass("js-backdrop");
                                $(".md-pb-item").children().children().removeClass("active");
                                // reset error check form
                                $(".js-error-header-map-height").empty();
                                $(".js-error-header-video-height").empty();
                                $(".js-header-save").attr("id", "js-header-save");
                            }
                        });
                    },
                    dialogClass: "no-close ",
                    closeOnEscape: false
                });
                $('.js-popup-header').dialog("open");
                $(".md-pb-backdrop").addClass("js-backdrop");
                // remove property default jquery ui
                $(".ui-dialog").css({"background" : "none", "border" : "none", "width" : "auto"});
                $(".ui-dialog-titlebar ").remove();
                $(".js-popup-setting").removeClass("ui-dialog-content ui-widget-content");
            });
        },
        hiddenForm: function(){
            $(document).on('click', '#js-icon-delete-header', function() {
                $(".js-popup-header").dialog('close');
                $(".md-pb-backdrop").removeClass("js-backdrop");
                $(".md-pb-item").children().children().removeClass("active");
                // reset element images
                $(".js-header-img-preview").children().remove();
                $(".js-header-image-id").val("");
                $(".js-header-source-images").val("");
                $(".js-header-hd-preview").val("");
                // reset error check form
                $(".js-error-header-map-height").empty();
                $(".js-error-header-video-height").empty();
                $(".js-header-save").attr("id", "js-header-save");
            });
        },
        processDisableElements: function() {
            $.status = true;
            $(document).on("click", ".js-header-cutom", function() {
                var $content = "";
                if ($.status) {
                    $(".js-header-custom").slideDown("200");
                    $.status = false;
                } else {
                    $(".js-header-custom").slideUp("200");
                    $.countMedia = 0;
                    $(".header-media").children().children().removeClass("active");
                    $(this).parents(".popup-setting").removeClass("extend");
                    $(this).parents(".js-header-add-extend").find(".block-content-extend").addClass("js-hidden");
                    // $(".ui-dialog").css({"width" : "340px"});
                    $( ".js-popup-header" ).dialog( "option", "position", {  my: "center", at: "center", of: window } );
                    $.status = true;
                    $(".js-header-hidden-media").val("");
                }
            });
            // custom header css elenments
            $(document).on("click", "#js-header-bt-css", function(event) {
                $("#js-custom-element-css").removeClass("js-hidden");
                $("#js-custom-elements-html").hide("slow");
                $("#js-header-bt-css").removeClass("pb-button-dark");
                $("#js-header-bt-css").removeClass("js-header-bt-color");
                event.preventDefault();
            });
            $.countMedia = 0;
            $(document).on("click", ".js-header-click-media", function(event) {
                var idSelected = $(this).children().attr("id"),
                    idHidden = $(".js-header-hidden-media").val();
                if(idSelected === idHidden){
                    $.countMedia = 0;
                    $(".js-header-add-extend").find(".block-content-extend").addClass("js-hidden");//reset media
                    $(this).parents(".popup-setting").removeClass("extend");
                    $(".header-media").children().children().removeClass("active");
                    $( ".js-popup-header" ).dialog( "option", "position", {  my: "center", at: "center", of: window } );
                    $(".js-header-hidden-media").val("");
                }else{
                    $(".js-header-add-extend").find(".block-content-extend").addClass("js-hidden");//reset media
                    $(this).parents(".popup-setting").addClass("extend");
                    $(".header-media").children().children().removeClass("active");
                    $(this).addClass("active");
                    $(".js-header-hidden-media").val(idSelected);
                    var rand = Date.now();
                    if(idSelected == "extend-map"){
                        $(".js-header-map-info").attr("id", rand);
                        $(".js-header-map-label-info").attr("for", rand);
                        $(".js-header-map-open-default").attr("id", rand + "1");
                        $(".js-header-map-label-default").attr("for", rand + "1");
                    }
                    $("." + idSelected).removeClass("js-hidden");
                    if($.countMedia == 0){
                        $( ".js-popup-header" ).dialog( "option", "position", {  my: "center", at: "center", of: window } );
                    }
                    $(".js-error-header-video-height").empty();
                    $(".js-error-header-map-height").empty();
                    $(".js-header-save").attr("id", "js-header-save");
                    $.countMedia = 1;
                }
                event.preventDefault();
            });
        },
        deletePreview: function(){
            $(document).on("click", ".preview-del", function(){
                $(this).parent().find(".js-header-img-preview").empty();
                $(this).parent().find(".js-header-image-id").val("");
                $(this).parent().find(".js-header-image-url").val("");
            });
            $(document).on("click", ".js-map-preview-delete", function(){
                $(this).parent().find(".js-header-map-preview").empty();
                $(this).parent().find(".js-header-map-fid").val("");
                $(this).parent().find(".js-header-map-url").val("");
            });
        },

        setData: function(){
            $(document).on("click", ".md-pb-title:contains(Header)", function() {
                // set data for elements
                var idItem = $(this).parents(".md-pb-item").attr("id");// get id current
                $(".dynamic-id").attr("id", idItem);// set id to input hidden
                var arr = $(this).parents(".md-pb-item").find(".js-hd-json").data("pricingTable");
                // reset element
                $(".js-header-add-extend").find(".block-content-extend").addClass("js-hidden");//reset media
                $(".popup-setting").removeClass("extend");
                $(".js-header-custom-class").val("");
                $(".js-header-img-preview").empty();
                $(".js-header-image-id").val("");
                $(".js-header-hidden-media").val("");
                $.countMedia = 0;
                $(".js-header-img-style option").eq(0).attr('selected', 'selected');
                //reset video
                $("#js-header-video-select").val("");
                $("#js-header-video-url").val("");
                $(".js-header-video-id").val("");
                $("#js-header-video-height").val("");
                $("#js-header-video-custom-class").val("");
                $(".video-img-bg").empty();
                //reset map
                $("#js-header-map-long").val("");
                $("#js-header-map-select option").eq(0).attr('selected', 'selected');
                $("#js-header-map-zoom option").eq(0).attr('selected', 'selected');
                $(".js-header-map-info").prop("checked", false);
                $("#js-header-map-title").val("");
                $("#js-header-map-descript").val("");
                $(".js-header-map-open-default").prop("checked", false);
                $("#js-header-map-height").val("");
                $(".js-header-map-preview").empty();
                $(".js-header-map-fid").val("");
                $(".js-header-map-url").val("");
                var rand = Date.now();
                $(".js-header-map-info").attr("id", rand);
                $(".js-header-map-label-info").attr("for", rand);
                $(".js-header-map-open-default").attr("id", rand + "1");
                $(".js-header-map-label-default").attr("for", rand + "1");
                // reset custom html
                $(".js-header-extend-html-area").val("");
                if ($.checkExistArray(arr) !== "" && $.checkExistObj(arr[0].tbl_header) !== "") {
                    var arrHeader = arr[0].tbl_header;
                    $("#tf-header-title").val(arrHeader.title);
                    $(".js-ck-custom").prop("checked", arrHeader.custom);
                    $(".js-header-extend-html-area").val(arrHeader.custom_html);
                    //reset active for media
                    $(".header-media").children().children().removeClass("active");
                    var image = arrHeader.images;
//                    console.log(image.length);
                    var video = arrHeader.video;
                    var map = arrHeader.map;
                    if ($.checkExistObj(image) !== "") {
                        $(".js-header-img-style option[value=" + image.img_style + "]").prop('selected', 'selected');
                        $(".js-header-custom-class").val(image.img_custom_class);
                        $(".js-header-img-preview").append(image.preview);
                        $(".js-header-image-id").val(image.fid);
                        $(".js-header-image-url").val(image.img_url);
                    }
                    if ( $.checkExistObj(video) !== "") {
                        //$("#js-header-video-select option[value=" + video[0].video_select + "]").prop('selected', 'selected');
                        $(".js-header-video-select").val(video.video_select);
                        $(".js-header-video-id").val(video.video_id);
                        $("#js-header-video-url").val(video.video_url);
                        $("#js-header-video-height").val(video.height);
                        $("#js-header-video-custom-class").val(video.custom_class);
                        $(".video-img-bg").empty().append(video.video_img);
                    }
                    if ( $.checkExistObj(map) !== "") {
                        $("#js-header-map-long").val(map.long);
                        $("#js-header-map-select option[value = " + map.map_select + "]").prop("selected", "selected");
                        $("#js-header-map-zoom option[value = " + map.zoom + "]").prop("selected", "selected");
                        $(".js-header-map-info").prop("checked", map.map_info);
                        $("#js-header-map-title").val(map.title);
                        $("#js-header-map-descript").val(map.descript);
                        $(".js-header-map-open-default").prop("checked", map.mDefault);
                        $("#js-header-map-height").val(map.height);
                        $(".js-header-map-preview").empty().append(map.map_preview);
                        $(".js-header-map-fid").val(map.map_fId);
                        $(".js-header-map-url").val(map.map_url);
                        $(".js-header-map-info").attr("id", rand);
                        $(".js-header-map-label-info").attr("for", rand);
                        $(".js-header-map-open-default").attr("id", rand + "1");
                        $(".js-header-map-label-default").attr("for", rand + "1");
                    }
                    $(".ui-dialog").css({"background" : "none", "border" : "none"});
                    //$( ".js-popup-header" ).dialog( "option", "position", {  my: "center", at: "center", of: window } );
                    $("#tf-header-custom-class").val(arrHeader.class_add);
                    $("#area-header-custom-css").val(arrHeader.custom_css);
                    var extend = arrHeader.header_extend;
                    $(".js-header-hidden-media").val(extend);
                    if (arrHeader.custom == true) {
                        $(".js-header-custom").slideDown();
                        $.status = false;
                        if(extend !== ""){
                            $(".popup-setting").addClass("extend");
                            $("#" + extend).parent().addClass("active");
                            $("." + extend).removeClass("js-hidden");
                            $( ".js-popup-header" ).dialog( "option", "position", {  my: "center", at: "center", of: window } );
                        }else{
                            $(".popup-setting").remove("extend");
                            $(".header-media").children().children().removeClass("active");
                            $( ".js-popup-header" ).dialog( "option", "position", {  my: "center", at: "center", of: window } );
                        }
                    }else{
                        $(".js-header-custom").slideUp();
                        $(".popup-setting").remove("extend");
                        $(".header-media").children().children().removeClass("active");
                        $(".ui-dialog").css({"background" : "none", "border" : "none"});
                        $( ".js-popup-header" ).dialog( "option", "position", {  my: "center", at: "center", of: window } );
                        $.status = true;
                    }
                } else {
                    $(".js-header-custom").hide();
                    $.status = true;
                    $("#tf-header-title").val("");
                    $(".js-ck-custom").prop("checked", false);
                    $("#tf-header-custom-class").val("");
                    $("#area-header-custom-css").val("");
                    $("#area-header-custom-html").val("");
                    $(".header-media").children().children().removeClass("active");
                    $("#js-header-bt-css").removeClass("js-header-bt-color");
                    $(".ui-dialog").css({"background" : "none", "border" : "none"});
                    $( ".js-popup-header" ).dialog( "option", "position", {  my: "center", at: "center", of: window } );
                }
                // remove property default jquery ui
                $(".ui-dialog-titlebar ").remove();
                //$(".ui-resizable-handle").remove();
                $(".js-popup-header").removeClass("ui-dialog-content ui-widget-content");
                // process active for pricing table
                $(".md-pb-item").children().children().removeClass("active");
                $(this).parent().addClass("active");
            });
        },
        saveData: function() {
            $(document).on("click", "#js-header-save", function(event) {
                var arrSaveheader = [], arrImage = [], arrVideo = [], arrMap = [] ;
                var titleRequest = $("#tf-header-title").val(),
                    ckCustom = $(".js-ck-custom").prop("checked"),
                    classRequest = $("#tf-header-custom-class").val(),
                    cssRequest = $("#area-header-custom-css").val();
                var keyId = $(".dynamic-id").attr("id");
                var idSelected = "";
                idSelected = $(".js-header-click-media.active").children().attr("id");
                if(typeof idSelected === 'undefined' ){
                    idSelected  = '';
                }
                var $selector = $(".js-header-add-extend");
                // get value Images
                var imgStyle = $selector.find(".js-header-img-style").val(),
                    imgCustomClass = $selector.find(".js-header-custom-class").val(),
                    fId = $selector.find(".js-header-image-id").val(),
                    imgPreview = $selector.find(".js-header-img-preview").html(),
                    imgUrl = $selector.find(".js-header-image-url").val();
                    arrImage.push({
                        preview : imgPreview,
                        fid : fId,
                        img_url : imgUrl,
                        img_style: imgStyle,
                        img_custom_class: imgCustomClass
                    });
                // get value Map
                var mapLong = $selector.find("#js-header-map-long").val(),
                    mapZoom = $selector.find("#js-header-map-zoom").val(),
                    mapInfo = $selector.find(".js-header-map-info").prop("checked"),
                    mapTitle = $selector.find("#js-header-map-title").val(),
                    mapDescript = $selector.find("#js-header-map-descript").val(),
                    mapDefault = $selector.find(".js-header-map-open-default").prop("checked"),
                    mapHeight = $selector.find("#js-header-map-height").val(),
                    mapFId = $selector.find(".js-header-map-fid").val(),
                    mapUrl = $selector.find(".js-header-map-url").val(),
                    mapPreview = $selector.find(".js-header-map-preview").html();
                // check & set data Map
                if (mapLong==""&&mapZoom =="1"&&mapInfo==false&&mapTitle==""&&mapDescript==""
                    &&mapDefault==false&&mapHeight==""&&mapFId==""&&mapUrl==""&&mapPreview=="")
                {
                    arrMap[0]="";
                }
                else {
                    arrMap.push({
                        long: mapLong,
                        zoom: mapZoom,
                        map_info: mapInfo,
                        title: mapTitle,
                        descript: mapDescript,
                        mDefault: mapDefault,
                        height: mapHeight,
                        map_fId : mapFId,
                        map_url : mapUrl,
                        map_preview : mapPreview
                    });
                }
                // get value Video
                var videoSelect = $selector.find(".js-header-video-select").val();
                var videoUrl = $selector.find("#js-header-video-url").val();
                var videoId = $selector.find(".js-header-video-id").val();
                var videoHeight = $selector.find("#js-header-video-height").val();
                var videoCustomClass = $selector.find("#js-header-video-custom-class").val();
                var videoImg = $selector.find(".video-img-bg").html();
                // Check & set data Video
                if (videoId==""&&videoUrl==""&&videoSelect==""&&videoHeight==""&&videoCustomClass==""&&videoImg==""){
                    arrVideo[0]="";
                }
                else
                {
                    arrVideo.push({
                        video_id: videoId,
                        video_url : videoUrl,
                        video_select: videoSelect,
                        height: videoHeight,
                        custom_class: videoCustomClass,
                        video_img : videoImg
                    });
                }
                var customHtml = $selector.find(".js-header-extend-html-area").val();
                var arrHeader = [], idRandom = "";
                if(cssRequest !== ""){
                    idRandom = "prtb_" + Date.now();
                }
                // Check & Set Data Header
                if (idSelected==""&&titleRequest==""&&ckCustom== false &&idRandom==""&&cssRequest==""
                    &&classRequest==""&&arrImage[0]==""&&arrVideo[0]==""&&arrMap[0]==""&&customHtml=="" )
                {
                    arrHeader[0]="";
                }
                else{
                    arrHeader.push({
                        header_id: keyId,
                        header_extend: idSelected,
                        title: titleRequest,
                        custom: ckCustom,
                        custom_class: idRandom,
                        custom_css: cssRequest,
                        class_add: classRequest,
                        images: arrImage[0],
                        video: arrVideo[0],
                        map: arrMap[0],
                        custom_html: customHtml
                    });
                }
                var arr = $("input[name='" + keyId + "']").data("pricingTable");
                var setting = "", body = "", price = "", footer = "";
                var result = $.checkExistArray(arr);
                if (result != "") {
                    setting = result[0].tbl_setting;
                    body = result[0].tbl_body;
                    price = result[0].tbl_price;
                    footer = result[0].tbl_footer;
                }
                arrSaveheader.push({
                    id: keyId,
                    tbl_setting: setting,
                    tbl_header: arrHeader[0],
                    tbl_body: body,
                    tbl_price: price,
                    tbl_footer: footer
                });
                $("input[name='" + keyId + "']").data("pricingTable", arrSaveheader);
                $(".js-popup-header").dialog('close');
                $(".md-pb-backdrop").removeClass("js-backdrop");
                $(".md-pb-item").children().children().removeClass("active");
                event.preventDefault();
            });
        },
        exportHtml : function(){
            $(".js-header-export-html").click(function(event){
                var url = $(".js-header-image-url").val(),
                    content = "<img src=\"" + url + "\" width=\"100%\" height=\"150px\">";
                $(".js-header-extend-html-area").val(content);
                $(".js-header-add-extend").find(".block-content-extend").addClass("js-hidden");//reset media
                $(".header-media").children().children().removeClass("active");
                $(".js-header-click-media:last").addClass("active");
                $(".js-header-hidden-media").val("extend-html");
                $(".extend-html").removeClass("js-hidden");
                event.preventDefault();
            });
        }
    };
})(jQuery);


