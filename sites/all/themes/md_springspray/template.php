<?php

include_once './' . drupal_get_path('theme', 'md_springspray') . '/inc/front/template.process.inc';
/**
 * Global $base_url
 */
function base_url() {
    global $base_url;
    return $base_url;
}
/**
 * Implements theme_menu_tree().
 */
function md_springspray_menu_tree__main_menu($variables) {
	if(theme_get_setting('menu_style','md_springspray') == "default") {
		//get contact info from theme-settings
		$contact_arr = theme_get_setting('contact_info','md_springspray');
		$i = 0; $contact = "";
		if(isset($contact_arr)) {
			foreach($contact_arr as $key => $value) {
				if($i < count($contact_arr)-1) {
					$contact .= $contact_arr[$key]['detail'].'<br />';
				} else {
					$contact .= $contact_arr[$key]['detail'];
				}
				$i++;
			}
		}
		
		$contact = '<li><hr><p>'.$contact.'</p></li>';
		
		//get socials from theme-settings
		$ft_social = theme_get_setting('ft_social','md_springspray');
		$social = "";
		if(isset($ft_social)) {
			foreach($ft_social as $key => $value) {
				$social .= '<div class="link" data-href="'.$ft_social[$key]['link'].'">
								<div class="cube twitter">
									<div class="frontend">
										<i class="fa '.str_replace('md', 'fa', $ft_social[$key]['icon']['icon']).'"></i>
									</div>
									<div class="back">
										<i class="fa '.str_replace('md', 'fa', $ft_social[$key]['icon']['icon']).'"></i>
									</div>
								</div>
							 </div>';
			}
		}
		$social = '<li><div class="profile-social-wrapper text-center">'.$social.'</div></li>';
		
		if (theme_get_setting('menu_static_image_upload', 'md_springspray')) :
		  $file = json_decode(theme_get_setting('menu_static_image_upload', 'md_springspray'));
		endif;
		
		if (strpos($variables['tree'], '<ul') === FALSE) {
			return '<ul class="sub-menu">' . $variables['tree'] . '</ul>';
		}
		return '<ul class="cd-primary-nav" style="background-image:url('.$file->url.');">' . $variables['tree'] . $contact . $social . '</ul>';
	} else if(theme_get_setting('menu_style','md_springspray') == "nav-1") {
		return '<ul class="menu" id="menu-main-nav">' . $variables['tree'] . '</ul>';
	} else if(theme_get_setting('menu_style','md_springspray') == "nav-2") {
		if (strpos($variables['tree'], '<ul') === FALSE) {
			return '<ul class="dropdown-menu">' . $variables['tree'] . '</ul>';
		}
		return '<ul class="nav navbar-nav  navbar-right">' . $variables['tree'] . '</ul>';
	} else if(theme_get_setting('menu_style','md_springspray') == "nav-3") {
		return '<ul>' . $variables['tree'] . '</ul>';
	} else if(theme_get_setting('menu_style','md_springspray') == "nav-4") {
		return '<ul role="menu">' . $variables['tree'] . '</ul>';
	} else if(theme_get_setting('menu_style','md_springspray') == "nav-5") {
		return '<ul class="nav navbar-nav whitetext">' . $variables['tree'] . '</ul>';
	} else if(theme_get_setting('menu_style','md_springspray') == "nav-6") {
		return '<ul class="option-set clearfix" data-option-key="filter">' . $variables['tree'] . '</ul>';
	} else {
		return '<ul>' . $variables['tree'] . '</ul>';
	}
}

/**
 * Implements theme_menu_link__[MENU NAME].
 */
function md_springspray_menu_link__main_menu($variables) {

  $element = $variables['element'];
  $sub_menu = '';  

  // set the global variable in order to use it in hook_menu_tree()
  // I called it "level" to avoid confusing with the $depth
  global $level;
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  $arr = $element['#localized_options'] ;

  if ($element['#below']) {
    if(theme_get_setting('menu_style','md_springspray') == "default" || theme_get_setting('menu_style','md_springspray') == "nav-2") {
		$sub_menu = drupal_render($element['#below']);
	}
	else {
		$sub_menu = "";
	}
  }
  else {
    $level = $element['#original_link']['depth'];
  }
  if(drupal_is_front_page()) {
	if(isset($arr['fragment']) && $arr['fragment'] ) {
		if(theme_get_setting('menu_style','md_springspray') == "nav-4") {
			if($element['#original_link']['depth'] == 1) {
				if(isset($element['#attributes']['icon'])) {
					$output = l('<i class="fa '.$element['#attributes']['icon'][0].'"></i>', '',  array('fragment' => $arr['fragment'], 'external' => TRUE, 'html' => TRUE));
				}
				else {
					$output = l($element['#title'], '',  array('fragment' => $arr['fragment'], 'external' => TRUE));
				}
			}	
		} 
		else if (theme_get_setting('menu_style','md_springspray') == "nav-2") {
			if ($element['#below']) {
				$output = l('<span class="dropdown-toggle" data-toggle="dropdown">'.$element['#title'].' <b class="caret"></b></span>', '',  array('fragment' => '', 'external' => TRUE, 'html' => TRUE));
				return '<li class="dropdown">' . $output . $sub_menu . "</li>\n";
			} else {
				$output = l($element['#title'], '',  array('fragment' => $arr['fragment'], 'external' => TRUE));
			}
		}
		else {
			$output = l($element['#title'], '',  array('fragment' => $arr['fragment'], 'external' => TRUE));
		}
	}
  } else {
  	if (theme_get_setting('menu_style','md_springspray') == "nav-2") {
		if ($element['#below']) {
			$output = l('<span class="dropdown-toggle" data-toggle="dropdown">'.$element['#title'].' <b class="caret"></b></span>', '',  array('fragment' => '', 'external' => TRUE, 'html' => TRUE));
			return '<li class="dropdown">' . $output . $sub_menu . "</li>\n";
		}
	}
  }
  return '<li>' . $output . $sub_menu . "</li>\n";
}

function md_springspray_menu_link__menu_footer_menu($variables) {

  $element = $variables['element'];
  $sub_menu = '';  

  // set the global variable in order to use it in hook_menu_tree()
  // I called it "level" to avoid confusing with the $depth
  global $level;

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
	$sub_menu = str_replace('class="nav sf-menu"','',$sub_menu);
	$sub_menu = str_replace('id="mainmenu"','',$sub_menu);
    $level = 1; // set the level as first for each list with submenu
  }
  else {
    $level = $element['#original_link']['depth'];
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  $arr = $element['#localized_options'] ;
  if(drupal_is_front_page()) {
	if(isset($arr['fragment']) && $arr['fragment'] ) {
		$output = l($element['#title'], '',  array('fragment' => $arr['fragment'], 'external' => TRUE));
	}
  }
  return '<li>' . $output . $sub_menu . "</li>\n";
}

/**
 * Implements theme_field__field_type().
 */
function md_springspray_field__taxonomy_term_reference($variables) {
    $output = '';

    // Render the label, if it's not hidden.
    if (!$variables['label_hidden']) {
        $output .= '<h3 class="field-label">' . $variables['label'] . ': </h3>';
    }

    // Render the items.
    $output .= ($variables['element']['#label_display'] == 'inline') ? '<ul class="links inline">' : '<ul class="links">';
    foreach ($variables['items'] as $delta => $item) {
        $output .= '<li class="taxonomy-term-reference-' . $delta . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</li>';
    }
    $output .= '</ul>';

    // Render the top-level DIV.
    $output = '<div class="' . $variables['classes'] . (!in_array('clearfix', $variables['classes_array']) ? ' clearfix' : '') . '">' . $output . '</div>';

    return $output;
}

/**
 * Override of theme('textarea').
 * Deprecate misc/textarea.js in favor of using the 'resize' CSS3 property.
 */
function md_springspray_textarea($variables) {
    $element = $variables['element'];
    $element['#attributes']['name'] = $element['#name'];
    $element['#attributes']['id'] = $element['#id'];
    $element['#attributes']['cols'] = $element['#cols'];
    $element['#attributes']['rows'] = $element['#rows'];
    _form_set_class($element, array('form-textarea'));

    $wrapper_attributes = array(
        'class' => array('form-textarea-wrapper'),
    );

    // Add resizable behavior.
    if (!empty($element['#resizable'])) {
        $wrapper_attributes['class'][] = 'resizable';
    }

    $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
    $output .= '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
    $output .= '</div>';
    return $output;
}


/**
 * @param $variables
 * @return Main menu
 */
function md_springspray_links__menu_header_navigation($variables) {
    $html = "<div class='link-holder fade'>\n";
    $html .= "  <ul>\n";

    foreach ($variables['links'] as $link) {

        if(isset($link['fragment'])) {
            $link['attributes']['class'] = array('scroll-link transition');
        } else {
            $link['attributes']['class'] = array('transition unscroll-link');
        }
        $html .= "<li>".l($link['title'], $link['href'], $link)."</li>";

    }
    //kpr($variables);die;
    $html .= "  </ul>\n";
    $html .= "</div>\n";

    return $html;
}

/**
 * @param $form
 * @param $form_state
 * @param $form_id
 */
function md_springspray_form_alter(&$form, &$form_state, $form_id) {
    if (strpos((string)($form_id),"webform_client_form") === false) {
        switch ($form_id) {
            case 'user_login':
                $form['name']['#attributes']['class'][] = '';
                $form['name']['#prefix'] = '<div class="control-group"><div class="controls">';
                $form['name']['#suffix'] = '</div></div>';
                $form['pass']['#attributes']['class'][] = '';
                $form['pass']['#prefix'] = '<div class="control-group"><div class="controls">';
                $form['pass']['#suffix'] = '</div></div>';
                $form['actions']['submit']['#value'] = t('Login');
                $form['actions']['submit']['#prefix'] = '';
                $form['actions']['submit']['#suffix'] = '';
                break;
            case 'user_register_form':
                $form['account']['name']['#attributes']['class'][] = '';
                $form['account']['name']['#prefix'] = '<div class="control-group"><div class="controls">';
                $form['account']['name']['#suffix'] = '</div></div>';
                $form['account']['mail']['#attributes']['class'][] = '';
                $form['account']['mail']['#prefix'] = '<div class="control-group"><div class="controls">';
                $form['account']['mail']['#suffix'] = '</div></div>';
                $form['actions']['submit']['#value'] = t('Create new account');
                $form['actions']['submit']['#prefix'] = '';
                $form['actions']['submit']['#suffix'] = '';
                break;
            case 'user_login_block':
                $form['name']['#attributes']['class'][] = '';
                $form['name']['#prefix'] = '<div class="control-group"><div class="controls">';
                $form['name']['#suffix'] = '</div></div>';
                $form['pass']['#attributes']['class'][] = '';
                $form['pass']['#prefix'] = '<div class="control-group"><div class="controls">';
                $form['pass']['#suffix'] = '</div></div>';
                $form['actions']['submit']['#value'] = t('Login');
                $form['actions']['submit']['#prefix'] = '';
                $form['actions']['submit']['#suffix'] = '';
                break;
            case 'user_pass':
                $form['name']['#attributes']['class'][] = '';
                $form['name']['#prefix'] = '<div class="control-group"><div class="controls">';
                $form['name']['#suffix'] = '</div></div>';
                $form['pass']['#attributes']['class'][] = '';
                $form['pass']['#prefix'] = '';
                $form['pass']['#suffix'] = '';
                $form['actions']['submit']['#value'] = t('Request new password');
                $form['actions']['submit']['#prefix'] = '';
                $form['actions']['submit']['#suffix'] = '';
                break;
            case 'search_block_form':
                $form['#attributes']['class'][] = 'searchform form-inline';
				$form['#prefix'] = '<div class="input-group">';
				$form['#suffix'] = '</div>';
				$form['search_block_form']['#attributes']['class'][] = 'form-control';
                $form['search_block_form']['#attributes']['placeholder'] = t('Search...');
                $form['actions']['submit']['#prefix'] = '<div class="input-group-btn">';
				$form['actions']['submit']['#suffix'] = '<button type="button" class="btn btn-primary submit-button"><i class="fa fa-search"></i></button></div>';
				$form['actions']['submit']['#attributes'] = array(
                    'class' => array('btn btn-primary'),
                );
                break;
            case 'search_form':
                //kpr($form);die;
                $form['basic']['submit']['#prefix'] = '<div class="form-submit"><div class="form-controls">';
                $form['basic']['submit']['#suffix'] = '</div></div>';
                $form['basic']['submit']['#attributes'] = array(
                    'class' => array('transition button'),
                );
                $form['advance']['#prefix'] = '<div class="row"><div class="container">';
                $form['advance']['#suffix'] = '</div></div>';
                $form['advance']['submit']['#prefix'] = '<div class="form-submit"><div class="form-controls">';
                $form['advance']['submit']['#suffix'] = '</div></div>';
                $form['advance']['submit']['#attributes'] = array(
                    'class' => array('transition button'),
                );
                break;
			case 'simplenews_block_form_13':
				$form['#attributes']['class'][] = 'cd-form';
				$form['mail']['#title_display'] = 'invisible';
				$form['mail']['#attributes']['placeholder'] = t('Enter your email address');
				$form['mail']['#attributes']['class'][] = t('cd-email');
				$form['mail']['#prefix'] = '<label class="cd-label">'.t('Newsletter').'</label>';
				
				$form['submit']['#attributes']['class'][] = 'cd-submit';
				$form['submit']['#value'] = t('Send');
				break;
        }
    } else {
        $form['#prefix'] = '<fieldset id="contact_form">';
        $form['#suffix'] = '</fieldset>';
        //$form['actions']['submit']['#value'] = t('Send Message');
        $form['actions']['submit']['#attributes']['class'][] = 'submit_btn transition';
        $form['actions']['submit']['#field_prefix'] = '<i class="fa fa-search transition"></i>';
        $form['actions']['submit']['#sufix'] = '';
    }

    if (strpos((string)($form_id),"commerce_cart_add_to_cart_form") !== false && current_path() == 'shop') {
      $form['submit']['#prefix'] = '<div class="md-btn md-btn-3 form-submit text-uppercase">';
      $form['submit']['#suffix'] = '</div>';
    }
}
/**
 * Process variables for comment.tpl.php.
 *
 * @see comment.tpl.php
 */
function md_springspray_preprocess_comment(&$variables) {
    $comment = $variables['elements']['#comment'];
    $node = $variables['elements']['#node'];
    $variables['comment']   = $comment;
    $variables['node']      = $node;
    $variables['author']    = theme('username', array('account' => $comment));

    $variables['created']   = date('d F Y',$comment->created);

    // Avoid calling format_date() twice on the same timestamp.
    if ($comment->changed == $comment->created) {
        $variables['changed'] = $variables['created'];
    }
    else {
        $variables['changed'] = format_date($comment->changed);
    }

    $variables['new']       = !empty($comment->new) ? t('new') : '';
    $variables['picture']   = theme_get_setting('toggle_comment_user_picture') ? theme('user_picture', array('account' => $comment)) : '';
    $variables['signature'] = $comment->signature;

    $uri = entity_uri('comment', $comment);
    $uri['options'] += array('attributes' => array('class' => 'permalink', 'rel' => 'bookmark'));

    $variables['title']     = l($comment->subject, $uri['path'], $uri['options']);
    $variables['permalink'] = l(t('Permalink'), $uri['path'], $uri['options']);
    $variables['submitted'] = t('!username  on !datetime', array('!username' => $variables['author'], '!datetime' => date('d F Y',$comment->created)));

    // Preprocess fields.
    field_attach_preprocess('comment', $comment, $variables['elements'], $variables);

    // Helpful $content variable for templates.
    foreach (element_children($variables['elements']) as $key) {
        $variables['content'][$key] = $variables['elements'][$key];
    }

    // Set status to a string representation of comment->status.
    if (isset($comment->in_preview)) {
        $variables['status'] = 'comment-preview';
    }
    else {
        $variables['status'] = ($comment->status == COMMENT_NOT_PUBLISHED) ? 'comment-unpublished' : 'comment-published';
    }

    // Gather comment classes.
    // 'comment-published' class is not needed, it is either 'comment-preview' or
    // 'comment-unpublished'.
    if ($variables['status'] != 'comment-published') {
        $variables['classes_array'][] = $variables['status'];
    }
    if ($variables['new']) {
        $variables['classes_array'][] = 'comment-new';
    }
    if (!$comment->uid) {
        $variables['classes_array'][] = 'comment-by-anonymous';
    }
    else {
        if ($comment->uid == $variables['node']->uid) {
            $variables['classes_array'][] = 'comment-by-node-author';
        }
        if ($comment->uid == $variables['user']->uid) {
            $variables['classes_array'][] = 'comment-by-viewer';
        }
    }
}

/**
 * template_preprocess_user_picture()
 */
function md_springspray_preprocess_user_picture(&$variables) {
    $variables['user_picture'] = '';
    if (variable_get('user_pictures', 0)) {
        $account = $variables['account'];
        if (!empty($account->picture)) {
            // @TODO: Ideally this function would only be passed file objects, but
            // since there's a lot of legacy code that JOINs the {users} table to
            // {node} or {comments} and passes the results into this function if we
            // a numeric value in the picture field we'll assume it's a file id
            // and load it for them. Once we've got user_load_multiple() and
            // comment_load_multiple() functions the user module will be able to load
            // the picture files in mass during the object's load process.
            if (is_numeric($account->picture)) {
                $account->picture = file_load($account->picture);
            }
            if (!empty($account->picture->uri)) {
                $filepath = $account->picture->uri;
            }
        }
        elseif (variable_get('user_picture_default', '')) {
            $filepath = variable_get('user_picture_default', '');
        }
        if (isset($filepath)) {
            $alt = t("@user's picture", array('@user' => format_username($account)));
            // If the image does not have a valid Drupal scheme (for eg. HTTP),
            // don't load image styles.
            if (module_exists('image') && file_valid_uri($filepath) && $style = variable_get('user_picture_style', '')) {
                $variables['user_picture'] = theme('image_style', array('style_name' => $style, 'path' => $filepath, 'alt' => $alt, 'title' => $alt, 'attributes' => array('class' => array('thumb img-rounded'))));
            }
            else {
                $variables['user_picture'] = theme('image', array('path' => $filepath, 'alt' => $alt, 'title' => $alt));
            }
            if (!empty($account->uid) && user_access('access user profiles')) {
                $attributes = array(
                    'attributes' => array('title' => t('View user profile.')),
                    'html' => TRUE,
                );
                $variables['user_picture'] = l($variables['user_picture'], "user/$account->uid", $attributes);
            }
        }
    }

}

/**
 * @param $theme_registry
 * An implementation of hook_theme_registry_alter() Substitute our own custom version of the standard 'theme_form_element' function. If the theme has overridden it, we'll be bypassed, but in most cases this will work nicely..
 */
function md_springspray_theme_registry_alter(&$theme_registry) {
    if (!empty($theme_registry['form_element'])) {
        $theme_registry['form_element']['function'] = 'md_springspray_form_element';
    }
}
/**
 * Returns HTML for a form element.
 *
 * Each form element is wrapped in a DIV container having the following CSS
 * classes:
 * - form-item: Generic for all form elements.
 * - form-type-#type: The internal element #type.
 * - form-item-#name: The internal form element #name (usually derived from the
 *   $form structure and set via form_builder()).
 * - form-disabled: Only set if the form element is #disabled.
 *
 * In addition to the element itself, the DIV contains a label for the element
 * based on the optional #title_display property, and an optional #description.
 *
 * The optional #title_display property can have these values:
 * - before: The label is output before the element. This is the default.
 *   The label includes the #title and the required marker, if #required.
 * - after: The label is output after the element. For example, this is used
 *   for radio and checkbox #type elements as set in system_element_info().
 *   If the #title is empty but the field is #required, the label will
 *   contain only the required marker.
 * - invisible: Labels are critical for screen readers to enable them to
 *   properly navigate through forms but can be visually distracting. This
 *   property hides the label for everyone except screen readers.
 * - attribute: Set the title attribute on the element to create a tooltip
 *   but output no label element. This is supported only for checkboxes
 *   and radios in form_pre_render_conditional_form_element(). It is used
 *   where a visual label is not needed, such as a table of checkboxes where
 *   the row and column provide the context. The tooltip will include the
 *   title and required marker.
 *
 * If the #title property is not set, then the label and any required marker
 * will not be output, regardless of the #title_display or #required values.
 * This can be useful in cases such as the password_confirm element, which
 * creates children elements that have their own labels and required markers,
 * but the parent element should have neither. Use this carefully because a
 * field without an associated label can cause accessibility challenges.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #title, #title_display, #description, #id, #required,
 *     #children, #type, #name.
 *
 * @ingroup themeable
 */
function md_springspray_form_element($variables) {
    $element = &$variables['element'];

    // This function is invoked as theme wrapper, but the rendered form element
    // may not necessarily have been processed by form_builder().
    $element += array(
        '#title_display' => 'before',
    );

    // Add element #id for #type 'item'.
    if (isset($element['#markup']) && !empty($element['#id'])) {
        $attributes['id'] = $element['#id'];
    }
    // Add element's #type and #name as class to aid with JS/CSS selectors.
    $attributes['class'] = array('form-item');
    if (!empty($element['#type'])) {
        $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
    }
    if (!empty($element['#name'])) {
        $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
    }
    // Add a class for disabled elements to facilitate cross-browser styling.
    if (!empty($element['#attributes']['disabled'])) {
        $attributes['class'][] = 'form-disabled';
    }
    $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

    // If #title is not set, we don't display any label or required marker.
    if (!isset($element['#title'])) {
        $element['#title_display'] = 'none';
    }
    $prefix = isset($element['#field_prefix']) ? '' . $element['#field_prefix'] . '' : '';
    $suffix = isset($element['#field_suffix']) ? '' . $element['#field_suffix'] . '' : '';

    switch ($element['#title_display']) {
        case 'before':
        case 'invisible':
            $output .= ' ' . theme('form_element_label', $variables);
            $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
            break;

        case 'after':
            $output .= ' ' . $prefix . $element['#children'] . $suffix;
            $output .= ' ' . theme('form_element_label', $variables) . "\n";
            break;

        case 'none':
        case 'attribute':
            // Output no label and no required marker, only the children.
            $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
            break;
    }

    if (!empty($element['#description'])) {
        $output .= '<div class="description">' . $element['#description'] . "</div>\n";
    }

    $output .= "</div>\n";

    return $output;
}

/**
 * Theme textfield
 */
function md_springspray_textfield($variables) {
    $element = $variables['element'];
    $element['#attributes']['type'] = 'text';
    element_set_attributes($element, array('id', 'name', 'value', 'size', 'maxlength'));
    _form_set_class($element, array('form-text '));

    $extra = '';
    if ($element['#autocomplete_path'] && drupal_valid_path($element['#autocomplete_path'])) {
        drupal_add_library('system', 'drupal.autocomplete');
        $element['#attributes']['class'][] = 'form-autocomplete';

        $attributes = array();
        $attributes['type'] = 'hidden';
        $attributes['id'] = $element['#attributes']['id'] . '-autocomplete';
        $attributes['value'] = url($element['#autocomplete_path'], array('absolute' => TRUE));
        $attributes['disabled'] = 'disabled';
        $attributes['class'][] = 'autocomplete';
        $extra = '<input' . drupal_attributes($attributes) . ' />';
    }

    $output = '<input' . drupal_attributes($element['#attributes']) . ' />';

    return $output . $extra;
}
/**
 * Theme_button
 */
function md_springspray_button($variables) {
    $element = $variables['element'];
    $element['#attributes']['type'] = 'submit';
    element_set_attributes($element, array('id', 'name', 'value'));

    $element['#attributes']['class'][] = 'form-' . $element['#button_type'] . ' transition button';
    if (!empty($element['#attributes']['disabled'])) {
        $element['#attributes']['class'][] = 'form-button-disabled';
    }

    return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

function md_springspray_css_alter(&$css) {
  unset($css[drupal_get_path('module', 'system') . '/system.menus.css']);
  unset($css[drupal_get_path('module', 'commerce') . '/modules/line_item/theme/commerce_line_item.theme.css']);
}

/**
 * @see template_preprocess_panels_pane().
 */
function md_springspray_preprocess_panels_pane(&$vars) {
  $pane = $vars['pane'];
  $display = $vars['display'];
  $vars['subtitle'] = variable_get("subtitle__{$display->uuid}_{$pane->subtype}", '');
  $vars['alt_text'] = variable_get("sep_content__{$display->uuid}_{$pane->subtype}", '');
  $vars['section_link'] = variable_get("sep_link__{$display->uuid}_{$pane->subtype}", '');
  $vars['vcode'] = variable_get("video_content__{$display->uuid}_{$pane->subtype}", '');
  $vars['bg_style'] = variable_get("bg_style__{$display->uuid}_{$pane->subtype}", '');
  $vars['bg_image'] = variable_get("bg_image__{$display->uuid}_{$pane->subtype}", '');
  $vars['bg_effect'] = variable_get("bg_effect__{$display->uuid}_{$pane->subtype}", '');
  $bg_image = variable_get("bg_image__{$display->uuid}_{$pane->subtype}", '');
  if($bg_image) {
  	$vars['bg_image'] = md_springspray_theme_setting_check_path($bg_image['bg_image_path']);
  } else {
  	$vars['bg_image'] = "";
  }
}

function md_springspray_form_comment_form_alter(&$form, &$form_state) {
	unset($form['actions']['preview']);
	unset($form['subject']);
	
	$form['author']['name']['#attributes'] = array('placeholder' => t('Name'));
	$form['author']['_author']['#title_display'] = 'invisible';
	$form['author']['name']['#title_display'] = 'invisible';
	$form['author']['name']['#attributes']['class'][] = 'form-control';
	$form['author']['name']['#prefix'] = '<div class="col-md-6">';
	$form['author']['name']['#suffix'] = '</div>';
	
	$form['field_comment_email']['und'][0]['email']['#attributes'] = array('placeholder' => t('Email'));
	$form['field_comment_email']['und'][0]['email']['#title_display'] = 'invisible';
	$form['field_comment_email']['und'][0]['email']['#attributes']['class'][] = 'form-control';
	$form['field_comment_email']['und'][0]['email']['#prefix'] = '<div class="col-md-6">';
	$form['field_comment_email']['und'][0]['email']['#suffix'] = '</div>';
	
	$form['comment_body']['und'][0]['value']['#attributes'] = array('placeholder' => t('Message'));
	$form['comment_body']['und'][0]['value']['#title_display'] = 'invisible';
	$form['comment_body']['und'][0]['value']['#attributes']['class'][] = 'form-control';
	$form['comment_body']['und'][0]['value']['#prefix'] = '<div class="col-md-12">';
	$form['comment_body']['und'][0]['value']['#suffix'] = '</div>';
	
	$form['actions']['submit']['#value'] = 'Comments';
	$form['actions']['submit']['#attributes']['class'][] = 'submit';
	$form['actions']['submit']['#prefix'] = '<div class="clearfix"></div><div class="col-md-12">';
	$form['actions']['submit']['#suffix'] = '</div>';
	
}

/**
 * Override contact form template
 */
function md_springspray_form_webform_client_form_49_alter(&$form, &$form_state) {
  
	$form['#attributes']['class'][] = 'contact-form';
	$form['submitted']['name']['#title_display'] = 'invisible';
	$form['submitted']['name']['#attributes'] = array('placeholder' => t('Name'), 'required' => 'required');
	$form['submitted']['name']['#attributes']['contenteditable'][] = 'true';
	$form['submitted']['name']['#attributes']['class'][] = 'form-control';
	$form['submitted']['name']['#prefix'] = '<div class="col-md-6">';
	$form['submitted']['name']['#suffix'] = '</div>';
  
	$form['submitted']['email']['#title_display'] = 'invisible';
	$form['submitted']['email']['#attributes'] = array('placeholder' => t('Email'), 'required' => 'required');
	$form['submitted']['email']['#attributes']['contenteditable'][] = 'true';
	$form['submitted']['email']['#attributes']['class'][] = 'form-control';
	$form['submitted']['email']['#prefix'] = '<div class="col-md-6">';
	$form['submitted']['email']['#suffix'] = '</div>';
	
	$form['submitted']['phone']['#title_display'] = 'invisible';
	$form['submitted']['phone']['#attributes'] = array('placeholder' => t('Phone'), 'required' => 'required');
	$form['submitted']['phone']['#attributes']['contenteditable'][] = 'true';
	$form['submitted']['phone']['#attributes']['class'][] = 'form-control';
	$form['submitted']['phone']['#prefix'] = '<div class="col-md-12">';
	$form['submitted']['phone']['#suffix'] = '</div>';
  
	$form['submitted']['message']['#title_display'] = 'invisible';
	$form['submitted']['message']['#attributes'] = array('placeholder' => t('Message'), 'required' => '');
	$form['submitted']['message']['#attributes']['contenteditable'][] = 'true';
	$form['submitted']['message']['#attributes']['class'][] = 'form-control text-center';
	$form['submitted']['message']['#prefix'] = '<div class="col-md-12">';
	$form['submitted']['message']['#suffix'] = '</div>';
  
	$form['actions']['submit']['#value'] = 'Send Message';
	$form['actions']['submit']['#attributes']['class'][] = 'submit';
	$form['actions']['submit']['#prefix'] = '<div class="col-md-12">';
	$form['actions']['submit']['#suffix'] = '</div>';
}

function md_springspray_form_user_login_alter(&$form, &$form_state) {
	
	$form['name']['#attributes']['class'][] = 'form-control';	
	$form['pass']['#attributes']['class'][] = 'form-control';
	$form['actions']['submit']['#attributes']['class'][] = 'theme_button';
}

function md_springspray_form_user_register_form_alter(&$form, &$form_state) {

	$form['account']['name']['#attributes']['class'][] = 'form-control';
	$form['account']['mail']['#attributes']['class'][] = 'form-control';
	$form['actions']['submit']['#attributes']['class'][] = 'theme_button';
}

function md_springspray_form_user_pass_alter(&$form, &$form_state) {
	
	$form['name']['#attributes']['class'][] = 'form-control';
	$form['actions']['submit']['#attributes']['class'][] = 'theme_button';

}

function md_springspray_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
  );
  foreach (drupal_get_messages($display) as $type => $messages) {
    switch($type) {
		case "status" :
			$output .= '<div class="alert alert-success" role="alert">';
			$output .= '<button type="button" class="close" data-dismiss="alert"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>';
			if (count($messages) > 1) {
			  $output .= " <ul>\n";
			  foreach ($messages as $message) {
				$output .= '  <li>' . $message . "</li>\n";
			  }
			  $output .= " </ul>\n";
			}
			else {
			  $output .= $messages[0];
			}
			$output .= "</div>\n";
		break;
		case "error" :
			$output .= '<div class="alert alert-danger" role="alert">';
			$output .= '<button type="button" class="close" data-dismiss="alert"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>';
			if (count($messages) > 1) {
			  $output .= " <ul>\n";
			  foreach ($messages as $message) {
				$output .= '  <li>' . $message . "</li>\n";
			  }
			  $output .= " </ul>\n";
			}
			else {
			  $output .= $messages[0];
			}
			$output .= "</div>\n";
		break;
		case "warning" :
			$output .= '<div class="alert alert-warning" role="alert">';
			$output .= '<button type="button" class="close" data-dismiss="alert"><span aria-hidden="true">&times;</span><span class="sr-only">Close</span></button>';
			if (count($messages) > 1) {
			  $output .= " <ul>\n";
			  foreach ($messages as $message) {
				$output .= '  <li>' . $message . "</li>\n";
			  }
			  $output .= " </ul>\n";
			}
			else {
			  $output .= $messages[0];
			}
			$output .= "</div>\n";
		break;
	}
  }
  return $output;
}

/**
 * Implements hook_theme().
 */
function md_springspray_theme() {
  return array(
    'author' => array(
      'template' => 'template/custom/author',
      'variables' => array('content' => NULL)
    ),
  );
}

function md_springspray_preprocess_block(&$vars) {
	$vars['logo_path']="";
    if(theme_get_setting('default_logo', 'md_springspray')) {
        $vars['logo_path'] = '';
    }else{
        if(theme_get_setting('logo_normal_upload','md_springspray')) {
            $file_upload = json_decode(theme_get_setting('logo_normal_upload','md_springspray'));
            if($file_upload->fid != 0) {
                $vars['logo_path'] = $file_upload->url;
            } else {
                $vars['logo_path'] = '';
            }
        }
    }
}