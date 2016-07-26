	<?php

	/**
	 * Implements hook_form().
	 * Admin form to configurable welcome message
	 */
	function hellofixit_settings_form($form, &$form_state) {
		$fSettings = hellofixit_settings();

		$form['tests'] = array	(
								'#type' => 'submit',
								'#value' => 'Run Tests',
								'#submit' => array('hellofixit_tests'),
								);

		$form['reset'] = array	(
								'#type' => 'submit',
								'#value' => 'Reset Settings',
								'#submit' => array('hellofixit_reset_settings'),
								);

		foreach($fSettings as $key => $setting){
			$form[$setting['name']] = array(
											'#default_value' => variable_get($setting['name']),
											'#title' => t($setting['title']),
											'#type' => $setting['field_type'],
											'#required' => TRUE,
											);
		}
	return system_settings_form($form);
	}
	
	function hellofixit_text_in_details_form($form, &$form_state) {
		$textInSettings = text_in_settings();

		foreach($textInSettings as $key => $setting){
			
			$form[$key] = array(
								'#default_value' => variable_get($key),
								'#title' => t($key)  . '-Level ' . $setting['level'],
								'#type' => 'checkbox',
								'#required' => TRUE,
								);
		}

	//return system_settings_form($form);
	return $form;
	}
	
	function hellofixit_job_details_form($form, &$form_state) {
		$jobsRelaySettings = jobs_relay_settings();

		foreach($jobsRelaySettings as $key => $setting){
			
			$form[$key] = array(
								'#default_value' => variable_get($key),
								'#title' => t($key)  . '-Level ' . $setting['level'],
								'#type' => 'checkbox',
								'#required' => TRUE,
								);
		}

	//return system_settings_form($form);
	return $form;
	}