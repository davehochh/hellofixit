/**
 * Created by DinhTu on 3/28/14.
 */
(function($){

    pricing.ProcessRequestDrupal = function(){
        this.init();

    };

    pricing.ProcessRequestDrupal.prototype = {
        constructor : pricing.ProcessRequestDrupal,
        init : function(){
            //invoke in class main

        },
        headerImageUpload : function(){
            $(document).on("click", ".js-header-bt-upload", function(e){
                var objDrupal = new pricing.ProcessRequestDrupal();
                Drupal.media.popups.mediaBrowser(objDrupal.wleValueImage);//write by walle
                e.preventDefault();
            });
        },
        headerMapUpload : function(){
            $(document).on("click", ".js-header-map-upload", function(e){
                var objDrupal = new pricing.ProcessRequestDrupal();
                Drupal.media.popups.mediaBrowser(objDrupal.wleValueMap);//write by walle
                e.preventDefault();
            });
        },
        wleValueImage : function(e){
            var str = $(e[0].preview).find(".label-wrapper").remove().end();
            $(".js-header-img-preview").empty().append(str);
            $(".js-header-image-id").val(e[0].fid);
            $(".js-header-image-url").val(e[0].url);
        },
        wleValueMap : function(e){
            var str = $(e[0].preview).find(".label-wrapper").remove().end();
            $(".js-header-map-preview").empty().append(str);
            $(".js-header-map-fid").val(e[0].fid);
            $(".js-header-map-url").val(e[0].url);
        },
        validateHeaderUrl : function(){
            $("#js-header-video-url").on('change, keyup',function(){
                var regYoutube = /^(?:https?:\/\/)?(?:www\.)?(?:youtu\.be\/|youtube\.com\/(?:embed\/|v\/|watch\?v=|watch\?.+&v=))((\w|-){11})(?:\S+)?$/;
                var regVimeo = /^.*(vimeo\.com\/)((channels\/[A-z]+\/)|(groups\/[A-z0-9]+\/videos\/))?([0-9]+)/;
                var url = ($(this).val());
                var videoCategory = "", error = "", img = "", id = "";
                if(regYoutube.test(url)) {
                    try{
                        var src = $.getYouTubeVideoImage(url, "big");
                        img = "<img src='"+ src +"' width = '200px'>";
                        $(".video-img-bg").empty().append(img);
                        videoCategory = 'youtube';
                        error = "";
                        var arr = src.split("/");
                        id = arr[arr.length - 2];
                    }catch (exception){
                        error = "<span class='error'>Url no support.</span>";
                    }
                }else if(regVimeo.test(url)) {
                    var arrUrl = url.split("/");
                    id = arrUrl[arrUrl.length - 1];
                    $.ajax({
                        type:'GET',
                        url: 'http://vimeo.com/api/v2/video/' + id + '.json',
                        jsonp: 'callback',
                        dataType: 'jsonp',
                        success: function(data){
                            var thumbnail_src = data[0].thumbnail_large;
                            img = "<img src='"+ thumbnail_src +"' width = '250px'>";
                            $(".video-img-bg").empty().append(img);
                        }
                    });
                    videoCategory = "vimeo";
                    error = "";
                }else{
                    error = "<span class='error'>Url no support.</span>";
                }
                if(error !== ""){
                    $("#js-header-video-id").focus();
                    $(".js-header-video-error").empty().append(error);
                    $(".js-header-video-select").val("");
                    $(".video-img-bg").empty();
                    $(".js-header-video-id").val("");
                }else{
                    $(".js-header-video-error").empty();
                    $(".js-header-video-select").val(videoCategory);
                    $(".js-header-video-id").val(id);
                }
            });
        }
    }
})(jQuery);