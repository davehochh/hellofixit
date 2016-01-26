(function($) {
    Drupal.behaviors.fullscreen_export = {
        attach: function(context, settings) {
            $("#md-prtb-submit-export", context).click(function(e) {
                var wle_item = [];
                e.preventDefault();
                $("#md-prtb-items input[class=form-checkbox]:checked", context).each(function() {
                    wle_item.push($(this).val());
                });
                if(wle_item.length != 0) {
                    window.open(settings.basePath + '?q=/admin/structure/md-pricing-table/export/&prtb=' + wle_item.join());
                }
            });
        }
    }
})(jQuery);