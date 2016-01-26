(function ($){
    $(document).ready(function(){
        function md_prtb_color(str_element){
            if($("."+str_element).length >0){
                $("."+str_element).spectrum({
                    color: $('#'+$(this).attr('id')).val(), // Set initial color options
                    allowEmpty:true, // Clear Color
                    showInput: true, // True: show input
                    showInitial: true, // True : show initial color
                    showAlpha: true, // True: Allow alpha transparency selection
                    clickoutFiresChange: true,
                    move: function(color){
                        var id ="",color_default="#FFF";
                        id =$(this).attr('id');
                        $('#'+id).val(color);
                    }
                })
            }
        }
        function md_prtb_slide_width(e) {
            $.each($("."+e), function(){
                var default_width = $(this).prev('.md-prtb-slide-width').val();
                var max_width = $(this).prevAll('.md-prtb-slide-width').attr('data-max-width');
                $(this).prevAll('label').children('.md-prtb-slide-px').text(default_width);
                //console.log($(this))
                $(this).slider({
                    range: "min",
                    value: default_width,
                    min: 0,
                    max: max_width,
                    slide: function( event, ui ) {
                        $(this).prev('.md-prtb-slide-width').val(ui.value);
                        $(this).prevAll('label').children('.md-prtb-slide-px').text(ui.value);
                    }
                });
            });
        }
        function export_data(){
            $(document).on('click', '#md-prtb-submit-export', function(e){
                var str ="";
                $.each($('.form-type-checkbox'), function(){
                    var id = $(this).children().attr('id');
                    if ($(this).children('#'+id).prop('checked')){
                        str+=$(this).children('#'+id).val()+",";
                    }
                });
                e.preventDefault();
                $.ajax({
                    type: "POST",
                    url: Drupal.settings.basePath + '?q=admin/structure/md-pricing-table/export/&md_export=' + str
                });
            });
        }
        md_prtb_slide_width('md-prtb-slide-load');
        md_prtb_color('md-prtb-color');
        export_data();

    });
})(jQuery, Drupal);