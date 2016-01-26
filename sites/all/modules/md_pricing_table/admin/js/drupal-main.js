/**
 * Created by DinhTu on 4/1/14.
 */
/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
(function ($){
    window.DrupalOutPricing = {
        version: 1.0,
        name: 'pricing table',
        author: 'Megadrupal.com'
    };
    DrupalOutPricing.Main = function (){
        this.init();
    };
    DrupalOutPricing.Main.prototype = {
        constructor : DrupalOutPricing.Main,
        init : function (){
            var confirmObj = new DrupalOutPricing.ProcessConfirm();

        }
    };
    $(document).ready(function () {
        var main = new DrupalOutPricing.Main();
    });

})(jQuery);

