(function($){
    $(document).ready(function(){
        if($(".md-pricing-table-block-equal-height").length >0){
            $(".md-pricing-table-block-equal-height").each(function(index, value){
                var element_array = Array('mdp-header','mdp-price', 'mdp-body','mdp-footer','mdp-html');
                var child_row = $(this).find('.row');
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
    });
})(jQuery)