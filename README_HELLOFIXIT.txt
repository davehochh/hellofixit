CONTENTS
--------
* Version
* Introduction
* User stories
* Text-in filters
* Jobs relay filters
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
1.6	- Update July 25, 2016
	- Check distance between customer and Fixit by zip code
	- Make incoming text message logic more expandable by making it easy to add filters
	- Make jobs relay logic more flexible by making it easier to add filters


INTRODUCTION
------------
The Hellofixit (HF) module is a relay service for MMS and SMS messages using the 
Twilio API module. Most SMS services are autoresponders, i.e. users send a code 
and receive information back (like bus routes, for example), HF is more interactive. 
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

* As an admin, I want the system to automatically recognize what kind of message
just came in, and react accordingly. To do this, I can set filters.


TEXT-IN FILTERS
---------------
The module figures out what an incoming text message says and what to do with by 
by using filters. These are defined in the hellofixit.settings file under function 
text_in_settings(). Each one has a corresponding check method and react method,
located in the text_in class. Each setting (or filter) has three elements:

Level
Level 1 means you can decide if it is true by making an observation. If you
can decide whether "contains zip" is true by checking to see if the message contains
a 5-digit numerical string, for example, then it is a Level 1. On the other hand,
if you can only infer whether something is true, then it is a Level 2 filter. For
example, you can only determine if a message is a new job by eliminating it as spam,
take_job, and feedback; this means it is a Level 2 filter.

Active
Whether the module will run the check and react methods associated with the filter.

Value
Set to zero by default. The check method sets the value to one if it determines that
the filter is true. The react method will run only if the value is set to one.


JOBS RELAY FILTERS
------------------
Very similar to text-in filters, these examine each job in the database to decide 
what to do with it next. For example, make sure the customer has a zip code, and 
request one if not. By default, there are no level 2 filters.


PROGRAM FLOW WHEN A NEW MESSAGE IS RECEIVED
-------------------------------------------
Check for...

1. Spam
Checks if we already have a person in the database with matching cell number and type = spammer

2. Fixit accepting a job
If cell number is a Fixit who we text a job to in the last 10m it is a take job
	
3. Feedback from customer
If cell matches a customer who had a job accepted in the past 24-48 hours it is feedback

4. New customer signup
If the message contains "hellofixit" and a five digit integer, it is a new customer signup

5. New Fixit signup
If the message contains "contractor" and a five digit integer, it is a new Fixit signup

6. New job (if it got this far it is a new job)
Build a new job node

7. Check if customer exists
See if there is a person with matching cell and type = customer


PROGRAM FLOW FOR JOBS RELAY
---------------------------
Loop through all jobs in the database and perform actions based on job status

- needs_approval
Send message to admin asking for approval

- Needs customer zip code
If we don't have a zip for the customer who sent the job, ask for one

- Approved
Find a Fixit to relay the job to. If no fixits nearby, let customer know.

- Denied
Do nothing with job

- Taken (but not yet notified customer)
Send message to customer that their job was accepted and give them the Fixit's cell number

- Taken (already notified customer)
Send message to the Fixit with customer's cell number

- Taken (sent details to Fixit)
request_feedback between 24-48 hours later

- Feedback_requested
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
5. Modfiy Twilio module


MODIFY TWILIO MODULE
--------------------
Twilio API module, version 7.x-1.11
File: twilio.module
Function: twilio_receive_message()
Remove "&& !empty($_REQUEST['Body'])" from line 291 (the first line of the function).

This will prevent pictures from being ignored if they arrive separately from text
messages. As long as they arrive within the number of seconds specified in 
add_to_job, Hellofixit will merge them together in the job.


CONFIGURATION
-------------
1. Configure Twilio with API keys and your Twilio phone number
2. Send a test SMS to yourself from the Twilio module
3. Change the default cron job password on the Hellofixit settings page
4. Enter your admin phone number (must be able to receive text messages)
5. Adjust additional HF settings as needed
6. Run tests from the HF settings page
7. Setup cron job


CRON JOB
--------
From the shell interface, enter crontab -e and configure with the following code:

* * * * * curl http://www.sampleurl.net/admin/hellofixit/cron/password

Make sure to replace sampleurl with your own, and change 
'password' to match the password you configured on the settings page.

If using nano text editor, save with Ctl-O and exit with Ctl-X.


FUTURE DEVELOPMENT ROADMAP
--------------------------
- Admin
	Add view to show fixits without zip code
	Add bulk operation to text fixits requesting zip code		

- Messages
	Add message to settings to tell customer no fixits available
	Add message to settings to tell customer no fixits responded

- Jobs relay
	If no fixits available, change job status and notify customer
	Put real data validation on mms in jobs relay

- Quality control and testing
	Test with not truncating to 160 characters
	Test with a real cell phone for fixit and customer (not Google voice)
	
- Possible bugs
	Sends two sms to customer asking for zip code
	Zip codes don't display in UI when populated programmatically
	
- Settings
	Make a setting for the word that Fixits have to reply with to take a job
	Put messages on their own tab apart from the other settings
	Settings checkboxes are not currently functional - they only display settings
	Kill switch for relay and text in
	Button to reset to default settings
	Make a setting for the time interval that a fixit has to respond
	Make a setting for add to job interval
	Setting for don't send same job to same fixit more than x times
	String to check for for new customer and new fixit (hardcoded currently)
	Time interval where it won't create new job for same customer

- Logs
	Add nid to watchdog messages

- Text in
	Check for message with "help" string and respond with link to readme?

- Tests
	More tests for jobs relay

- Misc
	Add job ref field to feedback node
	Check for admin cell phone in hellofixit_cron
	If no admin cell phone, display error or something
	Views for admin to see usage data
	Installation message
	Setup ability for Fixits to pay to be on top of the list
	Phone number validation
	Review the default SMS messages to make sure they make sense
	Get rid of body field in feedback node
	Add data validation to new person node so that it won't allow duplicate cell numbers
	Add data validation to new feedback node
	

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
** fixit_terms.class
	Retrieves the taxonomy terms from the database. These terms were created when
	the module was initally installed. If it can't get all the terms, it fails, and
	the module can't run.


** fixit_test.class
	- function
	- function
	- function

	
** jobadmin.inc
	Populates the /admin/hellofixit/jobadmin page
	
	This page is used by the admin when he receives a message that a new job
	need to be approved or denied


** jobs_relay.class
	- function main
		calls get_jobs_to_relay
		calls relay_jobs
		
	- function get_jobs_to_relay
		Sql query for jobs in the database, sort by job nid desc, time of text desc
		We sort by time descending so that we can use to only the record with the latest time and ignore the others
		
		Copy results to an array, jobs
		But only take the instance of each job nid (the one which is the most recent text out)
		And only copy a row if the last text time is greater than 10m old 
		(or whatever the delay is set to)

	- function relay_jobs
		input: jobs array

		set default time zone
		check if time now is during quiet hours, don't send any texts

		For each job in array, check the job status (in the array) and react accordingly

	- function get_fixit
		query database for fixits who have not gotten any texts in the past 10m
		pick one at random
		(later we'll have a way to pick the paid up fixits first)


** hellofixit_sms.module
	- function hellofixit_settings
	Contains default settings.
	Gets settings from db (variable table)
	If no settings are in db, save the default values to the db
	Returns an array fSettings
	
	
** text_in.class
	This is triggered by a rule when a new SMS is received

	- function main
	Reformats the cell as (555) 111-2222 because of the phone module
	Calls the what_is_this_text_in method
	Calls the react_to_text_in method

	- function what_is_this_text_in
	Makes an array detailsItems; these are the things we want to find out about
	the incoming text message.
	
	Details are either level 1 or level 2. Level 1 is something you can find out
	about the text without knowing any other information. For example: does it
	contain a zip code? Level is is something you can only decide if you have to
	already know two or more things about the message. For example, to decide if
	it is a new customer, you have to know whether the person is already in the
	database, and you have to know that it is not a new Fixit.
	
	We now put the detailsItems into the textInDetails array, and the value of
	each one is initially set to zero.
	
	- function checkText
	Next, we run various tests on the message in the checkText method. This
	will populate the textInDetails array.
	
