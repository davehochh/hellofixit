/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
(function ($){
    window.pricing = {
        version: 1.0,
        name: 'pricing table',
        author: 'Megadrupal.com'
    };
    pricing.Main = function (){
        this.init();
    };
    pricing.Main.prototype = {
        constructor : pricing.Main,
        init : function (){
            var pricingTableObj = new pricing.PricingTable();
            var processBodyObj = new pricing.ProcessBody();
            var processHeaderObj = new pricing.ProcessHeader();
            var processSettingObj = new pricing.ProcessSetting();
            var processPriceObj = new pricing.ProcessPrice();
            var processFooterObj = new pricing.ProcessFooter();
            var json = new pricing.SaveDataJson();
            var requestDrupal = new pricing.ProcessRequestDrupal();
            requestDrupal.headerImageUpload();
            requestDrupal.headerMapUpload();
            requestDrupal.validateHeaderUrl();
        }
    };
    $(document).ready(function () {
        var main = new pricing.Main();
    });

})(jQuery, Drupal);

