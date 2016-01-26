//$('body').show();
//NProgress.start();
var $ = jQuery.noConflict();
$(document).ready(function(){
  $('.main_wrap').css('visibility', 'visible');
  NProgress.start();
  // Animate loader off screen
  NProgress.done();
  setTimeout(function() { $('.hider').fadeOut(); }, 600);
  $('.blank').addClass('hider');
});