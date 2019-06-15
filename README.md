# WebhookIFTTT
******************************************************************************************************************************
Last revision : 15.06.2019

HW:  arduino Wifi mkr1010
******************************************************************************************************************************
What does code do?
- This sources provide a method to send an e-mail when the arduino triggers an event. 
- The mail is sent via the IFTT service.
- It is required to open an IFTT account and configure a "Webhook" that sends an e-mail when an event is triggered
- Arduino just makes a HTTP request to IFTT server and there 

- Code is c-oriented although files are .cpp 
******************************************************************************************************************************
Dependencies:

 <WiFiNINA.h>
 <ArduinoHttpClient.h>

******************************************************************************************************************************
In file main.c, defines to be changed:

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
amaia if you wanna contact me: whiletruethendream@gmail.com
