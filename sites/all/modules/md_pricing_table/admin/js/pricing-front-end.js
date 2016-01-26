
(function ($){
$(document).ready( function($){
    $.wle_pricing_set_map();
    $.wle_pricing_setting_equal();
//    wle_pricing_setting_equal();
});

$.wle_pricing_set_map= function(){

    var i= 0, j=0;
    var arr_setting_map = new Array();
    var arr_id_setting = new Array();
    // Get value input Map Setting
    $.each($('.setting-hidden-map'), function(){
        arr_setting_map[i] = $(this).attr('data');
        arr_setting_map[i] = jQuery.parseJSON(arr_setting_map[i]);
        i++;
    });
    // Get Value Id Map Setting
    $.each($('.rand-id-hidden-map'), function(){
        arr_id_setting[j]= $(this).attr('name');
        j++;
    });
    // Set Map Set CSS for Block Header
    i=0;j=0;
    $.each($('.mdp-header'), function(){
        if ($(this).children('.mdp-media').children('.setting-hidden-map').length>0)
        {
            var height =parseInt($(this).css('height'));
            var setting_height;
            if (arr_setting_map[j].height ==""){
                setting_height = 200;
            }
            else {
                setting_height = parseInt(arr_setting_map[j].height);
            }
            $.wle_pricing_map_load(arr_setting_map[j],arr_id_setting[j]); // Function API Google Map
            $(this).children('.mdp-media').children('.setting-active-map').css('height',setting_height );
            j++;
        }
    });
}
$.wle_pricing_map_load= function(t,id_map) {
    google.maps.event.addDomListener(window, 'load', $.wle_pricing_map_value(t,id_map));
}
$.wle_pricing_map_value= function(t,id_map) {
    //console.log(t);
    var wle_xy = new Array();
    wle_xy = t.long.split(',');
    var myLatlng = new google.maps.LatLng(wle_xy[0],wle_xy[1]);
    var mapOptions = {
        zoom: parseInt(t.zoom),
        center: myLatlng
    };
    var map = new google.maps.Map(document.getElementById(id_map), mapOptions);

    var contentString = '<h4 style="text-align: left;font-weight: 700; color: #999;">'+ t.title+'</h4><br><p style="text-align: left; color: #999999;">'+ t.descript+'</p>';

    var infowindow = new google.maps.InfoWindow({
        content: contentString
    });

    var marker = new google.maps.Marker({
        position: myLatlng,
        map: map,
        icon: t.map_url
    });
    google.maps.event.addListener(marker, 'click', function() {
        if(t.map_info == true) {
            infowindow.open(map,marker);
        }
        if(t.mDefault == true) {
            var wle_url = 'https://maps.google.com/maps?q='+ t.long+'&z='+ t.zoom+'&name='+ t.title;
            window.location.href = wle_url;
        }
    });
}
$.wle_pricing_setting_equal= function(){
    if($(".prtb-equal-height").length >0){
            $(".prtb-equal-height").each(function(index, value){
                var element_array = Array('mdp-header','mdp-price', 'mdp-body','mdp-footer');
                var child_row = $(this);
                $.each(child_row,function(index,values){
                    var md_height = $(this);
                    $.each(element_array,function(index,value){
                        var element = {};
                        element[value] = 0;
                        md_height.find('.'+value+'').each(function(index,values){
                            element[value] = (element[value] > values.clientHeight) ? element[value] : values.clientHeight;
                        });
                        md_height.find('.'+value+'').css({'height': element[value]});
                    });
                });
            });
        }
}

})(jQuery);
