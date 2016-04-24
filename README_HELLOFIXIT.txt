CONTENTS
--------
* Version
* Introduction
* User stories
* Program flow when a new message is received
* Program flow for jobs relay
* Requirements
* Submodules
* Installation
* Configuration
* Cron job
* Testing
* Future development (roadmap)
* Maintainers
* List of files in hellofixit_sms
* Functions, classes, and methods



VERSION
-------
1.1 - Update March 28, 2016
1.4 - Update April 13, 2016
1.5	- Update April 17, 2016

INTRODUCTION
------------
The Hellofixit (HF) module is a relay service for MMS and SMS messages using the 
Twilio API module. Most SMS services are autoresponders, i.e. users send a code 
and receive information back (like a bus stop for example), HF is more interactive. 
Homeowners send in a photo and short description of the home improvement job they 
want done and HF relays that to a list of contractors (Fixits) who have the option 
to ignore or accept the request.


USER STORIES
------------
* As a customer, I send a photo and description of my job, and the system 
responds back to me once a Fixit accepts the job

* As a Fixit I get jobs sent to me and when I accept one I get the details 
about the customer (name, address, cell phone)

* As an admin, I get notified of new messages coming in and I mark them as 
spam, job, new person, etc.


PROGRAM FLOW WHEN A NEW MESSAGE IS RECEIVED
-------------------------------------------
Check for...
1. Spam
Checks if we already have a person in the database with matching cell number and type = spammer

2. Fixit accepting a job
If cell number is a Fixit who we text a job to in the last 10m it is a take job
	
3. Feedback from customer
If cell matches a customer who had a job accepted in the past 24-48 hours it is feedback

* 4. New customer signup
If the message contains "hellofixit" and a five digit integer, it is a new customer signup

* 5. New Fixit signup
If the message contains "contractor" and a five digit integer, it is a new Fixit signup

6. New job (if it got this far it is a new job)
Build a new job node

7. Check if customer exists
See if there is a person with matching cell and type = customer

* Not yet built


PROGRAM FLOW FOR JOBS RELAY
---------------------------
Loop through all jobs in the database and perform actions based on job status

* - Needs customer zip code
If we don't have a zip for the customer who sent the job, ask for one

* - Needs approval
Send message to admin asking for approval

- Approved
Find a Fixit to relay the job to. If no fixits nearby, let customer know.

- Denied
Do nothing with job

- Taken (but not yet notified customer)
Send message to customer that their job was accepted and give them the Fixit's cell number

- Taken (already notified customer)
Send message to the Fixit with customer's cell number

- Taken (sent details to Fixit)
Request feedback between 24-48 hours later

- Feedback requested
Do nothing


REQUIREMENTS
------------
HF was built on Drupal 7.41. Please see the dependancies list below. 

Address Field
https://www.drupal.org/project/addressfield

Chaos tools
https://www.drupal.org/project/ctools

Date
https://www.drupal.org/project/date

Devel
https://www.drupal.org/project/devel

Entity API
https://www.drupal.org/project/entity

Entity Reference
https://www.drupal.org/project/entityreference

Features
https://www.drupal.org/project/features

Imagecache External
https://www.drupal.org/project/imagecache_external

Libraries
https://www.drupal.org/project/libraries

Phone
https://www.drupal.org/project/phone

Rules
https://www.drupal.org/project/rules

Twilio
https://www.drupal.org/project/twilio

Universally Unique ID
https://www.drupal.org/project/uuid

UUID Features (enabled)
https://www.drupal.org/project/uuid_features


Note that for Twilio you will need to setup an account first with a phone number 
for SMS and MMS service. Twilio also requires its library to be installed and 
it needs to be configured with API keys. You will also need shell access on your 
webhost to setup the cron job.

Note - as of this time I have not tested the module yet on shared hosting but I 
suspect that it could easily exceed the resources of a shared hosting account. 
The cron job is meant to run every minute. I will update this readme once I know 
more.


SUBMODULES
----------
* Hellofixit setup
Builds the content types and default settings

* Hellofixit sms
Handles the sms and mms relay functionality


INSTALLATION
------------
1. On a Drupal 7 installation, copy the Hellofixit folder to the /sites/all/modules/custom folder
2. Copy all the required contrib modules to /sites/all/modules/contrib
3. Activate the HF module (this will automatically take care of the submodules and dependancies)
4. Place the Twilio library from /hellofixit/lib in /sites/all/libraries


CONFIGURATION
-------------
1. Configure Twilio with API keys and your Twilio phone number
2. Send a test SMS to yourself from the Twilio module
3. Change the default cron job password on the Hellofixit settings page
4. Enter your admin phone number (must be able to receive text messages)
5. Adjust additional HF settings as needed
6. Run tests from the HF settings page
7. 
7. Setup cron job


CRON JOB
--------
From the shell interface, enter crontab -e and configure with the following code:

* * * * * curl http://www.sampleurl.net/admin/hellofixit/cron/password

Make sure to replace sampleurl with your own, and change 
'password' to match the password you configured on the settings page.

If using nano text editor, save with Ctl-O and exit with Ctl-X.


TESTING CLASS
-------------
** text_in
	- make test results array... $testResults = array()
	- prepopulate test results array with zeros
	- make a test customer
	- make a test fixit
	- make a test job with customer set to test customer and job status set to needs approval
	
	- spam
		1. call text in with a sms and cell number that matches spammer
		2. make sure that $textInDetails['spam'] = 1, set $testResults['text_in']['spam'] = 1

	- take_job
		1. make a text out node with job ref = test job nid, 
			cell phone = text fixit cell, text type = relay to fixit
		2. simulate a text in with sms containing 'fixit' and cell = test fixit cell
		3. delete the text out node
		4. make sure $textInDetails['take_job'] = 1, set test result to 1
		
	- feedback
	- existing_person
	- add_to_job
	- contains_zip
	- contains_contractor
	- new_fixit
	- new_customer
	- new_job


FUTURE DEVELOPMENT ROADMAP
--------------------------

test with not truncating to 160 characters
test with a real cell phone for fixit and customer
when a customer sends just a photo, it seems to not create a job (when sms is null)
make a setting for the time interval that a fixit has to respond
make a setting for add to job interval
test sending a job from iphone with sms and mms
confirmation that we got your job message
button to reset to default settings
setting for don't send same job to same fixit more than x times
kill switch for relay and text in
add nid to watchdog messages
put real data validation on mms in jobs relay

- Send message to admin asking to approve job

- Text in - Create new customer person via text "hellofixit" and five digit integer
- Text in - Create new fixit person via text "contractor" and five digit integer
- Text in - Check for message with "help" string and respond with link to readme?
- Text in - if created a job from the same number within 1 min add it to the last job created
- Text in - add to job - see if sms or mms is blank on existing job
- Text in - If job is from customer we don't have zip code then ask for zip code

- Relay - calculate distance between zip codes to figure out what Fixits to relay jobs to
- Relay - Need a way for admin to approve jobs: approved, denied, spam, need customer address
- Relay - Texts to admin need a url to approve jobs because they are going to be sent every 10m in batches

- Tests - jobs relay


- Cron callback password in settings
- Add job ref field to feedback node
- Relay - Only relay jobs to Fixits with same first 3 digits in zip code
- Relay - send confirmation that we got the customer's job
- Relay - send confirmation when new job is approved
- Check for admin cell phone in hellofixit_cron
- If no admin cell phone, display error or something
- Views for admin to see usage data
- Settings should have time interval where it won't create new job for same customer
- Installation message
- Setup ability for Fixits to pay to be on top of the list
- Get rid of else ifs in person and text out validation
- Phone number validation
- Review the default SMS messages to make sure they make sense
- Get rid of body field in feedback node
- Add data validation to new person node so that it won't allow duplicate cell numbers
- Add data validation to new feedback node
- Double check that public variables are no longer used - e.g. cell_formatted


MAINTAINERS
-----------

David Hochhaus
https://www.drupal.org/u/davehochh
https://github.com/hochh1707
http://www.hochh.com/
Twitter: hochh1707


LIST OF FILES IN HELLOFIXIT_SMS
-------------------------------
feedback.class
fixit_terms.class
fixit.test.class
hellofixit_sms.module
hellofixit_sms.rules
job.class
jobs_relay.class
person.class
text_in.class
text_out.class
jobadmin.inc

FUNCTIONS, CLASSES, AND METHODS
-------------------------------
** hellofixit_sms.module

- function hellofixit_main

	This is not meant to do anything in production but is useful in development


- function hellofixit_text_in

	This is triggered by a rule when a new SMS is received


- function hellofixit_cron

	Cron job to call this function every minute.

	1. Retrieve settings
	2. Run status checks (tests)
	3. Gets taxonomy terms array
	4. Starts jobs relay


- function hellofixit_sms_menu

	Creates admin menu link to Hellofixit settings page
	Creates a menu callback URL for admin to approve or deny jobs

- function hellofixit_form

	Defines settings page

- function hellofixit_reset_settings

	Deletes the settings out of the database so that they will be replaced by defaults

- function hellofixit_settings

	Contains default settings

	Get settings from db (variable table)
	
	If no settings are in db, save the default values to the db

	- setting:	admin_cell_formatted
	- setting:	job_relay_time
	- setting:	relay_start_time
	- setting:	relay_stop_time
	- setting:	delay_request_feedback_min
	- setting:	delay_request_feedback_max
	- setting:	sms_job_needs_approval
	- setting:	sms_job_relay_to_fixit
	- setting:	sms_job_taken_notify_customer
	- setting:	sms_job_taken_details_to_fixit
	- setting:	sms_job_request_feedback




** fixit_test.class

- main

- function fixit_terms_test

- function check_for_zeros




** fixit_terms.class

- function get_fixit_terms_from_db
	declare one variable and three arrays, with the taxonomy terms inside them, set each to zero:
	exist = 0
	job status
	person type
	text out type

	combine exist and all three arrays in one array: taxonomy

	see if the taxonomies exist in the database
	copy the term ids to the arrays as you go

	check to see if there are any zeros left
	if no zeros, set exist to 1

	return taxonomy array

- function check_for_zeros
	Checks for zeros in fTerms array




** text_in.class


- function main
	decides whether to call production or test methods


- function what_is_this_text_in
	Create an array to classify the message we just received
	new array() text_in
		spammer = 0	
		take job = 0
		job nid = 0
		feedback = 0
		customer nid = 0
		fixit nid = 0
		new job = 0
		existing customer = 0
		new customer = 0
		cell formatted = 0

	parse cell()
	convert 111222333 to (111) 222-3333 because that's how the phone module stores it in the database

	check if spammer()
	if yes, spammer = 1 and return

	check is take job()
	if yes, take job = 1
	set job nid (query database for the last sms that sent to the Fixit that we heard back from)
	return

	check is feedback()
	if yes, feedback = 1, set customer nid and fixit nid and return

	if you got this far, set new job = 1

	check if from existing customer()
	if no, set new customer = 1 and return
	if yes, existing customer = 1, set customer nid, and return


- function react_to_text_in 
	do stuff based on the text_in array we got earlier
	input: text_in array

	if it is a take job text, set job taken

	if it is a feedback text, create a feedback node

	if it is a new customer, create a new customer

	if you just created a new customer, get the nid for it and put it in the text_in array

	if it is a new job, create a job node


- function check_if_spam
	check if sender number belongs to spammer
	if yes, return spam = 1
	otherwise return spam = 0


- function check_is_take_job
	set take job = 0
	query for text node to person with matching cell number in last 10 min, where person is type = fixit
	if there is a result AND sms contains string "fixit" then
	take job[0] = 1
	take job[1] = job nid

	return take job


- function check_is_feedback
	feedback = 0

	query for text node where the recipient is a customer with matching cell number and text out type = request feedback
	if yes, feedback = 1

	return feedback



- function check_is_existing_customer
	Query database for person of type customer with matching cell number
	

- function parse_cell
	Changes from 10 digit string to format like (111) 222-3333 because of how phone module stores numbers in the database

- function test
	Testing




** text_out.class
- create text node
	inputs: cell number, person nid, message type, message, text_type_ref (taxonomy ref)
	builds a new node of type text out




** job.class
- new job node
	inputs: customer ref, sms, mms, job status ref (taxonomy ref)
	builds a new node of type = job with status = needs approval
- set job status
	inputs: job nid, status (taxonomy ref)
	changes the job status to take-not notified customer (taxonomy ref)




** person.class
- new person node
	inputs: person type, cell, first name, last name
- set person type
	inputs: person nid, type ref
- set contractor status (paid / not paid)
	inputs: person nid, status




** feedback.class
- new feedback node
	inputs: job nid, customer (person) nid, fixit (person) nid




** jobs_relay.class
- function main
	calls either:
	test, or
	get jobs to relay
	relay jobs



- function get_jobs_to_relay
	sql query for job nid, status, customer ref, fixit ref (if any), time of text (if any)
	also these fields: job sms, mms, customer cell, fixit cell, customer first/last name
	sort by job nid desc, time of text desc
	we sort by time descending so that we can use to only the record with the latest time and ignore the others

	copy results to an array,
	but only take the first row for each job nid (which is the most recent text out)
	and only copy a row if the last text time is greater than 10m old

	return $jobs


- function relay_jobs
	input: jobs array

	set default time zone
	check if time now is during quiet hours, don't send any texts

	for each job in array,

		- if job status is needs approval
			we need to get approval from the admin to make sure it is not spam
			create text out node
			inputs: cell number, person nid, message type, message, text_type_ref (taxonomy ref)
			send to:	admin
			sms:		job sms
			text out type:	request approval

		- if job status is approved
			we need to relay this job to a fixit. we're trying to find someone to take the job.
	
			call private function get fixit so we have someone to relay the job to			

			create text out node
			inputs: cell number, person nid, message type, message, text_type_ref (taxonomy ref)
			send to:	the fixit we picked at random
			sms:		"here is a job you might be interested in taking a look at. if you are available to go look at it within 3 hours reply "fixit" in 						the next 10m" ... job sms
			text out type:	relay to fixit

		- if job status is denied
			do nothing

		- if job status is taken-not notified customer
			we need to notify the customer of who took their job

			create text out node
			inputs: cell number, person nid, message type, message, text_type_ref (taxonomy ref)
			sms:		"you found a fixit for your job! they are supposed to arrive within 3 hours. here is their number:"
			text out type:	notify customer job is taken

		- if job status is taken-notified customer
			we need to send details of the job to the fixit
			
			create text out node
			inputs: cell number, person nid, message type, message, text_type_ref (taxonomy ref)
			sms:		"here are the location and the customer for the job you are going to look at"
			text out type:	send details to fixit

			set job status to taken-sent details to fixit

		- if the job status is taken-details sent to fixit (taxonomy term 27)
			we need to request feedback

			make sure the last text was between 24-48 hours ago

			create text out node
			inputs: cell number, person nid, message type, message, text_type_ref (taxonomy ref)
			sms:		Hi we'd like to find out how it went with your fixit. Please text us back and tell us."
			text out type:	request feedback

			set job status to feedback requested

		- if job status is feedback requested
			do nothing
		
								


- function get_fixit
	query database for fixits who have not gotten any texts in the past 10m
	pick one at random
	(later we'll have a way to pick the paid up fixits first)




** jobadmin.inc
- Inputs: $a1 and $a2
	$a1 is the approve/deny
	$a2 is the nid
- approve
	sets job status to approved	
- deny
	sets job status to denied
- spam
	sets job status to denied
	sets person type to spammer
