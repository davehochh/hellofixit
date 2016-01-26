/**
 * Created by DinhTu on 4/1/14.
 */
(function($){
    DrupalOutPricing.ProcessConfirm = function(){
        this.init();
    };
    DrupalOutPricing.ProcessConfirm.prototype = {
        constructor : DrupalOutPricing.ProcessConfirm,
        init : function(){
            this.trashConfirm();
        },
        trashConfirm : function(){
            var href = $(".md_prtb_confirm_js_delete").attr("href");
            $(".md_prtb_confirm_js_delete").attr("href", "#");
            $(document).on("click", ".md_prtb_confirm_js_delete", function(){

                $( "#js-dialog-trash-confirm" ).dialog({
                    resizable: false,
                    height:220,
                    width : 350,
                    modal: true,
                    buttons: {
                        "Delete all items": function() {
                            window.location.href = href;
                        },
                        Cancel: function() {
                            $( this ).dialog( "close" );
                        }
                    }
                    //dialogClass: "no-close"
                });
                //$(".ui-button-icon-only").remove();
            });
        },
        deleteConfirm : function(){

        }

    }
})(jQuery);