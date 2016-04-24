<?php


function job_admin($a1, $a2){
		
		//if(!(is_numeric($a2))) return;
		
		$terms1 = new fixit_terms();
		$fTerms = $terms1->main();
		
		switch($a1){
			case 'new':
			$j1 = new job();
			$job_info = $j1->get_job_info($a2);
			if(!($job_info == FALSE)){
				echo($job_info['sms']);
				echo('<br>');
				echo('<img src = "' . $job_info['mms'] . '">');
				echo('<br>');
				
				$url_approve = $GLOBALS['base_path'] . 'jobadmin/approve/' . $a2;
				$url_deny = $GLOBALS['base_path'] . 'jobadmin/deny/' . $a2;
				$url_spam = $GLOBALS['base_path'] . 'jobadmin/spam/' . $a2;
				
				echo('<a href = "' . $url_approve . '">Approve</a>');
				echo('<br>');
				echo('<a href = "' . $url_deny . '">Deny</a>');
				echo('<br>');
				echo('<a href = "' . $url_spam . '">Spam</a>');
			}


			
			
			$blah = $GLOBALS['base_path'] . 'jobadmin/approve/' . $j1->job_nid;
			break;
		
			case 'approve':
			$job_status = $fTerms['job_statuses']['approved'];
			$j1 = new job();
			$j1->set_job_status($a2,$job_status);
			echo('ok approved');
			break;
			
			case 'deny':
			$job_status = $fTerms['job_statuses']['denied'];
			$j1 = new job();
			$j1->set_job_status($a2,$job_status);
			echo('ok denied');
			break;
			
			case 'spam':
			$job_status = $fTerms['job_statuses']['denied'];
			$j1 = new job();
			$j1->set_job_status($a2,$job_status);
			$person_type = $fTerms['person_types']['spammer'];
			
			$customer_nid = $j1->get_job_info($a2)['customer_nid'];
			if(!($customer_nid == FALSE or $customer_nid == '')){
				$p1 = new person();
				$p1->set_person_type($customer_nid,$person_type);
			}
			echo('ok spam');
			break;
		}
}