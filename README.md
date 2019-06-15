# WebhookIFTTT
******************************************************************************************************************************
Last revision : 15.06.2019

HW:  arduino Wifi mkr1010
******************************************************************************************************************************
## Features
- This sources provide a method to send an e-mail when the arduino triggers an event. 
- The mail is sent via the IFTT service.
- It is required to open an IFTT account and configure a "Webhook" that sends an e-mail when an event is triggered
- Arduino just makes a HTTP request to IFTT server and there 

- Code is c-oriented although files are .cpp 
******************************************************************************************************************************
## Dependencies:

 <WiFiNINA.h>
 <ArduinoHttpClient.h>

******************************************************************************************************************************
## Configuration, defines
In file main.ino, defines to be changed:

- #define SSID     "xxxxxxxxxx"             /* Wifi router SSID */
- #define	PASSWORD "yyyyyyyyyy"             /* Wifi router password */

In file iftttWebhook.cpp

- #define TRIGGER_NAME "xxxxxxxxxxxxxxxxx"                      /* IFTTT Trigger name */
- #define KEY "yyyyyyyyyyy"                                     /* IFTTT Key */


(*)
IFTT Key:
press "documentation" in 
https://ifttt.com/maker_webhooks 

IFTT Trigger:
https://ifttt.com/applets/ 
Select the "Webhook"

(*)IFTT Webhook to be configured in iftt site, see instructions there
******************************************************************************************************************************
## API

int SendIFTTTWebhookRequest(WiFiSSLClient client, int value1, float value2, char* str_value3);
Values to be received in your e-mail triggered by a Webhook event:
value1: integer value to be sent 
value2: float value to be sent
value3: text to be sent3

******************************************************************************************************************************
## DISCLAIMER: 
- These are the sources for my hobby project
- Not fully tested
- If you find bugs I'm eager to receive your feedback
******************************************************************************************************************************
## Contact
 whiletruethendream@gmail.com
 ******************************************************************************************************************************
 amaia
