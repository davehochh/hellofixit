<?php

	function jobs_relay_settings(){
		//1st, populate an array with default values
		
		//Array structure: name, level, active, value
		//Level is the decision tree level. If you can decide if it's true without any
		//other information, then it is level 1. Level 2 details depend on level 1 details.
		//Active is whether the system is set to check for that detail when a new text arrives
		//Value is whether the detail is true about a text message. It always starts out zero
		//and is changed to 1 only after a text message arrives.
		
		$jobsRelaySettings['job_missing_zip'] = array('level' => 1, 'active' => 1, 'value' => 0);
		$jobsRelaySettings['job_status_needs_approval'] = array('level' => 1, 'active' => 1, 'value' => 0);
		$jobsRelaySettings['job_status_approved'] = array('level' => 1, 'active' => 1, 'value' => 0);
		$jobsRelaySettings['job_status_denied'] = array('level' => 1, 'active' => 1, 'value' => 0);
		$jobsRelaySettings['job_status_taken_not_notified_customer'] = array('level' => 1, 'active' => 1, 'value' => 0);
		$jobsRelaySettings['job_status_taken_notified_customer'] = array('level' => 1, 'active' => 1, 'value' => 0);
		$jobsRelaySettings['job_status_taken_details_sent_to_fixit'] = array('level' => 1, 'active' => 1, 'value' => 0);
		$jobsRelaySettings['job_status_feedback_requested'] = array('level' => 1, 'active' => 1, 'value' => 0);
		
		//2nd, set value in database if it is not there already
		//3rd, overwrite array values if they already exist in database
		foreach($jobsRelaySettings as $key => $d){
			$dbSetting = variable_get($key);
			
			if($dbSetting == ''){
				variable_set($key, $d['active']);
			}else{
				$jobsRelaySettings[$key]['active'] = $dbSetting;
			}
		}
	return $jobsRelaySettings;
	}

	function text_in_settings(){
		//1st, populate an array with default values
		
		//Array structure: name, level, active, value
		//Level is the decision tree level. If you can decide if it's true without any
		//other information, then it is level 1. Level 2 details depend on level 1 details.
		//Active is whether the system is set to check for that detail when a new text arrives
		//Value is whether the detail is true about a text message. It always starts out zero
		//and is changed to 1 only after a text message arrives.
		
		$textInSettings['spam'] = array('level' => 1, 'active' => 1, 'value' => 0);
		$textInSettings['take_job'] = array('level' => 1, 'active' => 1, 'value' => 0);		
		$textInSettings['from_fixit'] = array('level' => 1, 'active' => 1, 'value' => 0);		
		$textInSettings['feedback'] = array('level' => 1, 'active' => 1, 'value' => 0);
		$textInSettings['existing_person'] = array('level' => 1, 'active' => 1, 'value' => 0);
		$textInSettings['add_to_job'] = array('level' => 1, 'active' => 1, 'value' => 0);
		$textInSettings['contains_zip'] = array('level' => 1, 'active' => 1, 'value' => 0);
		$textInSettings['contains_contractor'] = array('level' => 1, 'active' => 1, 'value' => 0);
		$textInSettings['update_zip'] = array('level' => 2, 'active' => 1, 'value' => 0);
		$textInSettings['new_fixit'] = array('level' => 2, 'active' => 1, 'value' => 0);
		$textInSettings['new_customer'] = array('level' => 2, 'active' => 1, 'value' => 0);
		$textInSettings['new_job'] = array('level' => 2, 'active' => 1, 'value' => 0);
		
		//2nd, set value in database if it is not there already
		//3rd, overwrite array values if they already exist in database
		foreach($textInSettings as $key => $d){
			$dbSetting = variable_get($key);
			
			if($dbSetting == ''){
				variable_set($key, $d['active']);
			}else{
				$textInSettings[$key]['active'] = $dbSetting;
			}
		}
	return $textInSettings;
	}

	
	function hellofixit_reset_settings(){
		$fSettings = hellofixit_settings();

		foreach($fSettings as $i){
			$dSettings = db_delete('variable')
			->condition('name',$i['name'])
			->execute();
		}
		
		drupal_flush_all_caches();
	}

	
	function hellofixit_settings(){
		$fSettings = array();

		$name = 'url';
		$default = 'www.notforsissies.net';
		$title = 'URL of your Drupal site';
		$value = variable_get($name);
		if($value == ''){
			variable_set($name,$default);
			$value = $default;
		} 
		$fSettings[$name] = array(	'name' => $name,
									'default' => $default,
									'title' => $title,
									'value' => $value,
									'field_type' => 'textfield'
									);

		$name = 'cron_pw';
		$default = 'turtle19342spoon';
		$title = 'Password used for cron job';
		$value = variable_get($name);
		if($value == ''){
			variable_set($name,$default);
			$value = $default;
		} 
		$fSettings[$name] = array(	'name' => $name,
									'default' => $default,
									'title' => $title,
									'value' => $value,
									'field_type' => 'textfield'
									);

		$name = 'admin_cell_formatted';
		$default = '';
		$title = 'Admin cell phone - formatted (111) 222-3333';
		$value = variable_get($name);
		if($value == ''){
			variable_set($name,$default);
			$value = $default;
		} 
		$fSettings[$name] = array(	'name' => $name,
									'default' => $default,
									'title' => $title,
									'value' => $value,
									'field_type' => 'textfield'								
									);

		$name = 'zipcode_api_key';
		$default = '';
		$title = 'Zipcodeapi.com API key';
		$value = variable_get($name);
		if($value == ''){
			variable_set($name,$default);
			$value = $default;
		} 
		$fSettings[$name] = array(	'name' => $name,
									'default' => $default,
									'title' => $title,
									'value' => $value,
									'field_type' => 'textfield'								
									);
									
		$name = 'max_distance_to_fixit';
		$default = '3';
		$title = 'Max distance to Fixit (mi)';
		$value = variable_get($name);
		if($value == ''){
			variable_set($name,$default);
			$value = $default;
		} 
		$fSettings[$name] = array(	'name' => $name,
									'default' => $default,
									'title' => $title,
									'value' => $value,
									'field_type' => 'textfield'								
									);

		$name = 'job_relay_time';
		$default = 600;
		$title = 'Time interval between relaying a job to the next fixit (seconds)';
		$value = variable_get($name);
		if($value == ''){
			variable_set($name,$default);
			$value = $default;
		} 
		$fSettings[$name] = array(	'name' => $name,
									'default' => $default,
									'title' => $title,
									'value' => $value,
									'field_type' => 'textfield'								
									);

		$name = 'relay_start_time';
		$default = '04:00';
		$title = 'Time of day to begin allowing texts to be sent (PST)';
		$value = variable_get($name);
		if($value == ''){
			variable_set($name,$default);
			$value = $default;
		} 
		$fSettings[$name] = array(	'name' => $name,
									'default' => $default,
									'title' => $title,
									'value' => $value,
									'field_type' => 'textfield'								
									);
								
		$name = 'relay_stop_time';
		$default = '19:00';
		$title = 'Time of day to stop allowing texts to be sent (PST)';
		$value = variable_get($name);
		if($value == ''){
			variable_set($name,$default);
			$value = $default;
		} 
		$fSettings[$name] = array(	'name' => $name,
									'default' => $default,
									'title' => $title,
									'value' => $value,
									'field_type' => 'textfield'								
									);
								
		$name = 'delay_request_feedback_min';
		$default = '24';
		$title = 'Min. number of hours to wait to ask for feedback';
		$value = variable_get($name);
		if($value == ''){
			variable_set($name,$default);
			$value = $default;
		} 
		$fSettings[$name] = array(	'name' => $name,
									'default' => $default,
									'title' => $title,
									'value' => $value,
									'field_type' => 'textfield'								
									);
								
		$name = 'delay_request_feedback_max';
		$default = '48';
		$title = 'Max. number of hours to wait to ask for feedback';
		$value = variable_get($name);
		if($value == ''){
			variable_set($name,$default);
			$value = $default;
		} 
		$fSettings[$name] = array(	'name' => $name,
									'default' => $default,
									'title' => $title,
									'value' => $value,
									'field_type' => 'textfield'								
									);

		$name = 'sms_received_job';
		$default = "We got your job! Thanks and we will get started finding your Fixit.";
		$title = "SMS sent when we get a new job";
		$value = variable_get($name);
		if($value == ''){
			variable_set($name,$default);
			$value = $default;
		} 
		$fSettings[$name] = array(	'name' => $name,
									'default' => $default,
									'title' => $title,
									'value' => $value,
									'field_type' => 'textarea'								
									);

		$name = 'sms_need_customer_zip';
		$default = "Hi, we noticed that we don't have your zip code. Please reply "
					. "with your five digit zip so that we can process your job! Thanks!";
		$title = "SMS sent when to request a customer's zip";
		$value = variable_get($name);
		if($value == ''){
			variable_set($name,$default);
			$value = $default;
		} 
		$fSettings[$name] = array(	'name' => $name,
									'default' => $default,
									'title' => $title,
									'value' => $value,
									'field_type' => 'textarea'								
									);

		$name = 'sms_job_needs_approval';
		$default = 'New job needs_approval: ';
		$title = 'SMS sent when new job needs_approval by admin';
		$value = variable_get($name);
		if($value == ''){
			variable_set($name,$default);
			$value = $default;
		} 
		$fSettings[$name] = array(	'name' => $name,
									'default' => $default,
									'title' => $title,
									'value' => $value,
									'field_type' => 'textarea'								
									);
								
		$name = 'sms_job_relay_to_fixit';
		$default = 'Here is a job you might be interested in taking a look at. If you are available to go look at it within 3 hours reply "fixit" in the next 10min: ';
		$title = 'SMS sent when job is relayed to fixits';
		$value = variable_get($name);
		if($value == ''){
			variable_set($name,$default);
			$value = $default;
		} 
		$fSettings[$name] = array(	'name' => $name,
									'default' => $default,
									'title' => $title,
									'value' => $value,
									'field_type' => 'textarea'
									);

		$name = 'sms_job_taken_notify_customer';
		$default = 'We found a fixit who wants to come look at your job! They are supposed to arrive within 3 hours. You need to call or text them with your location. Here is their cell: ';
		$title = 'SMS sent to notify a customer that his/her job has been accepted by a fixit';
		if(variable_get($name) == '') variable_set($name,$default);
		$value = variable_get($name);
		$fSettings[$name] = array(	'name' => $name,
									'default' => $default,
									'title' => $title,
									'value' => $value,
									'field_type' => 'textarea'								
									);

		$name = 'sms_job_taken_details_to_fixit';
		$default = 'Here is the cell number for the job you are going to look at. Please get in touch! They are expecting you within 3 hours.';
		$title = 'SMS sent to give fixit details about a job after they accept it';
		$value = variable_get($name);
		if($value == ''){
			variable_set($name,$default);
			$value = $default;
		} 
		$fSettings[$name] = array(	'name' => $name,
									'default' => $default,
									'title' => $title,
									'value' => $value,
									'field_type' => 'textarea'
									);

		$name = 'sms_job_request_feedback';
		$default = 'Hi we would like to find out how it went with your fixit. Please text us back and tell us know!';
		$title = 'SMS sent to ask a customer for feedback after a fixit accepts their job';
		$value = variable_get($name);
		if($value == ''){
			variable_set($name,$default);
			$value = $default;
		} 
		$fSettings[$name] = array(	'name' => $name,
									'default' => $default,
									'title' => $title,
									'value' => $value,
									'field_type' => 'textarea'									
									);

	return $fSettings;
	}