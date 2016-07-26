<?php
/**
 * @file
 * hellofixit_setup.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function hellofixit_setup_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'send_details_to_fixit',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '297e7b8d-564d-45ea-ae12-128be6cb772a',
    'vocabulary_machine_name' => 'text_out_types',
  );
  $terms[] = array(
    'name' => 'customer',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '305249cc-99d0-46ca-9c4a-b4613520b5cd',
    'vocabulary_machine_name' => 'person_types',
  );
  $terms[] = array(
    'name' => 'fixit',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '37ca10e5-cec3-4d00-9d5c-c50ea42565c8',
    'vocabulary_machine_name' => 'person_types',
  );
  $terms[] = array(
    'name' => 'taken_notified_customer',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3e1c7535-43c4-4830-8416-1623ba76faee',
    'vocabulary_machine_name' => 'job_status',
  );
  $terms[] = array(
    'name' => 'taken_details_sent_to_fixit',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '4084bc7f-151d-45fd-8905-d40516addefb',
    'vocabulary_machine_name' => 'job_status',
  );
  $terms[] = array(
    'name' => 'taken_not_notified_customer',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6a8a7da6-12d1-4852-ad9b-cac38b1b91cf',
    'vocabulary_machine_name' => 'job_status',
  );
  $terms[] = array(
    'name' => 'request_feedback',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6cce25d4-693c-45b6-b20e-ad60f314b537',
    'vocabulary_machine_name' => 'text_out_types',
  );
  $terms[] = array(
    'name' => 'approved',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '71a62f48-dc7e-4317-9d51-79e07b6ef05a',
    'vocabulary_machine_name' => 'job_status',
  );
  $terms[] = array(
    'name' => 'spammer',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '79421965-44c0-45a0-88c5-3aee0c2f8acc',
    'vocabulary_machine_name' => 'person_types',
  );
  $terms[] = array(
    'name' => 'request_approval',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '9cacd320-a974-444b-8e13-2ff607fa5543',
    'vocabulary_machine_name' => 'text_out_types',
  );
  $terms[] = array(
    'name' => 'denied',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a22a2f1a-675c-42dd-8e5c-0f5cb7795425',
    'vocabulary_machine_name' => 'job_status',
  );
  $terms[] = array(
    'name' => 'feedback_requested',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b58b8154-e1cb-4a2d-9d92-94dd6a26ca3a',
    'vocabulary_machine_name' => 'job_status',
  );
  $terms[] = array(
    'name' => 'needs_approval',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'bdb6ed29-257e-47b1-af63-e91dfaf0e67f',
    'vocabulary_machine_name' => 'job_status',
  );
  $terms[] = array(
    'name' => 'need_zip',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '23cedffc-0d54-466d-9f31-77c7e5594632',
    'vocabulary_machine_name' => 'job_status',
  );
  $terms[] = array(
    'name' => 'relay_to_fixit',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e2e8c9d6-d3d8-42c1-a87d-7a6ff896675e',
    'vocabulary_machine_name' => 'text_out_types',
  );
  $terms[] = array(
    'name' => 'request_zip',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '455de26b-3f5c-42ee-9b54-9327c541664e',
    'vocabulary_machine_name' => 'text_out_types',
  );  
  $terms[] = array(
    'name' => 'notify_customer_job_is_taken',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fad0cc09-ed17-43da-adf4-d379b895af23',
    'vocabulary_machine_name' => 'text_out_types',
  );
  return $terms;
}
