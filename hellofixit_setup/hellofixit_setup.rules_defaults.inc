<?php
/**
 * @file
 * hellofixit_setup.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function hellofixit_setup_default_rules_configuration() {
  $items = array();
  
  $items['rules_hellofixit_sms'] = entity_import('rules_config', '{ "rules_hellofixit_sms" : {
      "LABEL" : "hellofixit",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "hellofixit_sms", "twilio" ],
      "ON" : { "twilio_sms_incoming" : [] },
      "DO" : [
        { "hellofixit_sms_action_incoming" : {
            "number" : "[sms:number]",
            "message" : "[sms:message]",
            "media" : "[sms:media]"
          }
        }
      ]
    }
  }');
  
  $items['rules_hellofixit_jobs_relay'] = entity_import('rules_config', '{ "rules_hellofixit_jobs_relay" : {
      "LABEL" : "hellofixit jobs relay",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "twilio", "rules" ],
      "ON" : { "node_insert--text_out" : { "bundle" : "text_out" } },
      "DO" : [
        { "twilio_send_sms_to_number" : {
            "country" : "1",
            "number" : [ "node:field-cell-phone" ],
            "message" : [ "node:field-sms" ],
            "media" : [ "node:field-mms" ]
          }
        }
      ]
    }
  }');
  
  return $items;
}
