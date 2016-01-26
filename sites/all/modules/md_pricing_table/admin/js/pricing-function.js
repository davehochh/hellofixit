/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
(function($) {
    $.objectFindByKey = function(array, key, value) {
        var size = $.arraySize(array);
        if (size > 0) {
            for (var i = 0; i < size; i++) {
                if (array[i][key] === value) {
                    return array[i];
                }
            }
        }
        return "";
    }
    ;

    $.removeArray = function(array, id) {
        var size = $.arraySize(array);
        if (size > 0) {
            for (var i = 0; i < size; i++) {
                if (array[i]["id"] === id) {
                    array.splice(i, 1);
                    return true;
                }
            }
        }
        return false;
    };

    $.arraySize = function (obj) {
        var size = 0, key;
        for (key in obj) {
            if (obj.hasOwnProperty(key))
                size++;
        }
        return size;
    };
    $.checkExistArray = function(arr){
        if(typeof arr !== 'undefined' && arr !== null  && arr.length > 0){
            return arr;
        }
        return "" ;
    };
    $.checkExistObj = function(obj){
        if (typeof obj !== 'undefined' && obj !=null){
            return obj;
        }
        return "";
    };
    $.returnCustomCss = function(arr){
        var str_css="";
        if (arr.custom_css!=""){
            str_css+= ".";
            str_css+= arr.custom_class;
            str_css+= "{";
            str_css+= arr.custom_css;
            str_css+= "} ";
        }
        return str_css;
    };
    $.checkTypeof = function(value){
        if (typeof value == 'string'){
            return value;
        }
        else if (typeof value == 'object'){
            return value[0];
        }
        else return value;
    };
    $.getYouTubeVideoImage = function(url, size){
        if(url === null){ return ""; }
        size = (size === null) ? "big" : size;
        var vid, results ;
        results = url.match("[\\?&]v=([^&#]*)");
        vid = ( results === null ) ? url : results[1];
        if(size == "small"){
            return "http://img.youtube.com/vi/"+vid+"/2.jpg";
        }else {
            return "http://img.youtube.com/vi/"+vid+"/0.jpg";
        }
    };
})(jQuery);

