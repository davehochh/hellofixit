
(function($){
		$(document).ready(function(){
				//var md_style_temp = Drupal.settings.md_style;
				//var md_loadmore_temp = Drupal.settings.md_portfolio_loadmore;
				//var md_style = jQuery.parseJSON(md_style_temp);
				//var md_loadmore = jQuery.parseJSON(md_loadmore_temp);
				//md_style.loadmore = md_loadmore;
				function md_portfolio(options) {
						// console.log(options);
						var gridContainer = $('#' + options['md_style_view']['grid_div_id']),//#grid-container
								filtersContainer = $('#' + options['md_style_view']['filter_div_id']);//#filters-container
						gridContainer.cubeportfolio({
								field_prefix: options['md_style_filter_count']['options']['field_prefix'],
								field_suffix: options['md_style_filter_count']['options']['field_suffix'],
								//
								defaultFilter: '*',
								animationType: options['md_style_animationType'],
								gapHorizontal: parseInt(options['md_style_gapHorizontal']),
								gapVertical: parseInt(options['md_style_gapVertical']),
								gridAdjustment: options['md_style_gridAdjustment'],
								caption: options['md_style_caption'],
								displayType: options['md_style_displayType'],
								displayTypeSpeed: parseInt(options['md_style_displayTypeSpeed']),

								// lightbox
								lightboxDelegate: '.cbp-lightbox',
								lightboxGallery: true,
								lightboxTitleSrc: 'data-title',
								lightboxShowCounter: true,

								// singlePage popup
								singlePageDelegate: '.cbp-singlePage',
								singlePageDeeplinking: true,
								singlePageStickyNavigation: true,
								singlePageShowCounter: true,
								singlePageCallback: function (url, element) {
										var t = this;

										$.ajax({
												url: url,
												type: 'GET',
												dataType: 'html',
												timeout: 5000
										})
												.done(function(result) {
														t.updateSinglePage(result);
												})
												.fail(function() {
														t.updateSinglePage("Error! Please refresh the page!");
												});
								},

								// singlePageInline
								singlePageInlineDelegate: '.cbp-singlePageInline',
								singlePageInlinePosition: options['inline_page_popup'],
								singlePageInlineShowCounter: true,
								singlePageInlineInFocus: true,
								singlePageInlineCallback: function(url, element) {
										var t = this;
										$.ajax({
												url: url,
												type: 'GET',
												dataType: 'html',
												timeout: 5000
										})
												.done(function(result) {
														console.log(result);
														t.updateSinglePageInline('<div class="cbp-l-inline">' + result + '</div>');

												})
												.fail(function() {
														t.updateSinglePageInline("Error! Please refresh the page!");
												});
								}
						});

						// add listener for filters click
						filtersContainer.on('click', '.cbp-filter-item', function (e) {

								var me = $(this), wrap;

								// get cubeportfolio data and check if is still animating (reposition) the items.
								if ( !$.data(gridContainer[0], 'cubeportfolio').isAnimating ) {

										if ( filtersContainer.hasClass('cbp-l-filters-dropdown') ) {
												wrap = $('.cbp-l-filters-dropdownWrap');

												wrap.find('.cbp-filter-item').removeClass('cbp-filter-item-active');

												wrap.find('.cbp-l-filters-dropdownHeader').text(me.text());

												me.addClass('cbp-filter-item-active');
										} else {
												me.addClass('cbp-filter-item-active').siblings().removeClass('cbp-filter-item-active');
										}

								}

								// filter the items
								gridContainer.cubeportfolio('filter', me.data('filter'), function () {});
						});

						// activate counter for filters
						gridContainer.cubeportfolio('showCounter', filtersContainer.find('.cbp-filter-item'));
				}

				function mdr_load_more (){
						$(document).delegate('.cbp-l-loadMore-button-link', 'click',function(e) {
								var gridContainer = $(this).closest('.view').find('.view-content').find('[id^="mdp-grid-"]');//#grid-container
								var options = $.parseJSON($(this).next('.mdr-data-load-hidden').data('mdp_data'));
								var md_this = $(this);
								e.preventDefault();
								var wle_page = md_this.attr('data-load');
								var clicks, me = $(this), oMsg;
								//console.log(clicks);
								if (me.hasClass('cbp-l-loadMore-button-stop')) return;

								// get the number of times the loadMore link has been clicked
								clicks = $.data(this, 'numberOfClicks');
								clicks = (clicks)? ++clicks : 1;
								$.data(this, 'numberOfClicks', clicks);

								// set loading status
								oMsg = me.text();
								me.text('LOADING...');
								// perform ajax request
								$.ajax({
										url: Drupal.settings.basePath + '?q=md-portfolio/loadmore/'+ options['md_style_view']['vname']+'/'+ options['md_style_view']['display_id']+'/' + wle_page,
										type: 'GET',
										dataType: 'HTML'
								})
										.done( function (result) {
												var items, itemsNext;
												items = $(result).filter( function () {
														return $(this).is('div' + '.cbp-loadMore-block');
												});

												gridContainer.cubeportfolio('appendItems', items.html(),
														function () {
																// put the original message back
																me.text(oMsg);
//                                if ($("li", items).length !== parseInt(options['loadmore']['items_per_page'])) {
																if ((parseInt(wle_page)) == parseInt(options['loadmore']['max_pager'])) {
																		me.text('NO MORE WORKS');
																		me.addClass('cbp-l-loadMore-button-stop');
																}
														});
												wle_page = parseInt(wle_page) + 1;
												md_this.attr({'data-load': wle_page});
										})
										.fail(function() {
												// error
										});
						});
				}
				function mdr_load_scroll (){
						$.each($('.cbp-l-loadMore-text-link'), function(){
								var gridContainer = $(this).closest('.view').find('.view-content').find('[id^="mdp-grid-"]');//#grid-container
								var options = $.parseJSON($(this).next('.mdr-data-load-hidden').data('mdp_data'));
								var loadMoreObject = {

												init: function () {

														var t = this;

														// the job inactive
														t.isActive = false;

														t.numberOfClicks = 0;

														// cache link selector
														t.loadMore = $('.cbp-l-loadMore-text-link');

														// cache window selector
														t.window = $(window);

														// add events for scroll
														t.addEvents();

														// trigger method on init
														t.getNewItems();

												},

												addEvents: function () {

														var t = this;

														t.window.on("scroll.loadMoreObject", function() {
																// get new items on scroll
																t.getNewItems();
														});
												},

												getNewItems: function () {

														var t = this, topLoadMore, topWindow, clicks;

														if ( t.isActive || t.loadMore.hasClass('cbp-l-loadMore-text-stop') ) return;

														topLoadMore = t.loadMore.offset().top;
														topWindow = t.window.scrollTop() + t.window.height();

														if (topLoadMore > topWindow) return;

														// this job is now busy
														t.isActive = true;

														// increment number of clicks
														t.numberOfClicks++;

														// perform ajax request
														var wle_page = $('.cbp-l-loadMore-text-link').attr('data-load');

														$.ajax({
																url: Drupal.settings.basePath + '?q=md-portfolio/loadmore/'+ options['md_style_view']['vname']+'/'+ options['md_style_view']['display_id']+'/' + wle_page,
																//url: t.loadMore.attr('data-href'),
																type: 'GET',
																dataType: 'HTML',
																cache: true
														})
																.done( function (result) {
																		var items, itemsNext;

																		// find current container
//                                        console.log(result);
																		items = $(result).filter( function () {
																				return $(this).is('div' + '.cbp-loadMore-block');
																				//return $(this).is('div' + '.cbp-loadMore-block' + t.numberOfClicks);
																		});

																		gridContainer.cubeportfolio('appendItems', items.html(),
																				function () {

																						// check if we have more works
																						itemsNext = $(result).filter( function () {
																								//return $(this).is('div' + '.cbp-loadMore-block' + (t.numberOfClicks + 1));
																								return $(this).is('div' + '.cbp-loadMore-block');
																						});
//                                                if ($("li", items).length !== parseInt(options['loadmore']['items_per_page'])) {
																						if ((parseInt(wle_page)) == parseInt(options['loadmore']['max_pager'])) {
																								t.loadMore.text('NO MORE ENTRIES');
																								t.loadMore.addClass('cbp-l-loadMore-text-stop');

																								t.window.off("scroll.loadMoreObject");

																						} else {
																								// make the job inactive
																								t.isActive = false;

																								topLoadMore = t.loadMore.offset().top;
																								topWindow = t.window.scrollTop() + t.window.height();

																								var wle_page_update = parseInt(wle_page) + 1;
																								$('.cbp-l-loadMore-text-link').attr({'data-load': wle_page_update});

																								if (topLoadMore <= topWindow) {
																										t.getNewItems();

																								}
																						}

																				});

																})
																.fail(function() {
																		// make the job inactive
																		t.isActive = false;
																});
												}
										},
										loadMore = Object.create(loadMoreObject);


								// Cube Portfolio is an event emitter. You can bind listeners to events with the on and off methods. The supported events are: 'initComplete', 'filterComplete'

								// when the plugin is completed
								gridContainer.on('initComplete', function () {
										loadMore.init();
								});

								// when the height of grid is changed
								gridContainer.on('filterComplete', function () {
										loadMore.window.trigger('scroll.loadMoreObject');
								});
						})
				}
				if($(".md-portfolio-content").length > 0) {
						var md_selector = $(".md-portfolio-content");
						var mdp_data = '';
						var mdp_loadmore = '';
						$.each(md_selector, function(index, md_data){
								//var md_view_load_more = $(this).closest('.view');
								mdp_data = $(this).find('.md-portfolio-data').attr('data-json');
								mdp_data = mdp_data.replace(/#MD#/g, '"');
								// console.log(mdp_data);
								mdp_data = $.parseJSON(mdp_data);
								var md_view_load_more = $(this).closest('.view').find('.mdp-portfolio-load-more');
								var md_view_load_scroll = $(this).closest('.view').find('.cbp-l-loadMore-text-link');
								if(md_view_load_more.length != 0){
										mdp_loadmore = md_view_load_more.attr('data-json');
										mdp_loadmore = $.parseJSON(mdp_loadmore);
										mdp_data.loadmore = mdp_loadmore;
										//console.log(md_view_load_more);
										var $data_load_more = '<input class="mdr-data-load-hidden" type="hidden"/>';
										md_view_load_more.append($data_load_more);
										$('.mdr-data-load-hidden', md_view_load_more).data('mdp_data',JSON.stringify(mdp_data));
								}
								if (md_view_load_scroll.length !=0){
										mdp_loadmore = md_view_load_more.attr('data-json');
										mdp_loadmore = $.parseJSON(mdp_loadmore);
										mdp_data.loadmore = mdp_loadmore;
										var $data_load_scroll = '<input class="mdr-data-scroll-hidden" type="hidden"/>';
										md_view_load_more.append($data_load_scroll);
										$('.mdr-data-scroll-hidden', $data_load_scroll).data('mdp_data',JSON.stringify(mdp_data));
								}
								md_portfolio(mdp_data);

						});
						mdr_load_more();
						mdr_load_scroll();
				}

		});
		$(window).trigger("resize");
})(jQuery)

