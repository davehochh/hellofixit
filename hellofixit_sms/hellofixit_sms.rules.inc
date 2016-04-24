<?php

/**
 * Implements hook_rules_action_info().
 */
function hellofixit_sms_rules_action_info() {
$items = array('hellofixit_sms_action_incoming' => array( 

  'label' => t('Deals with incoming text message'),
  'group' => t('Hellofixit'),
  'parameter' => array(
    'number' => array(
		'default value' => 'sms:number',
		'type' => 'text',
		'label' => t('Number'),
        ),
    'message' => array(
		'default value' => 'sms:message',
		'type' => 'text',
		'label' => t('Message'),
        ),
    'media' => array(
		'default value' => 'sms:media',
		'type' => 'text',
		'label' => t('Media (MMS)'),
        ),
  ),
  )
  );
return $items;
}


/**
 * Calls hellofixit_text_in()
 */
function hellofixit_sms_action_incoming($cell,$sms,$mms){
	hellofixit_text_in($cell,$sms,$mms);
}
