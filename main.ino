
#include <WiFiNINA.h>
#include <ArduinoHttpClient.h>

#include "iftttWebhook.h"

WiFiSSLClient client;

#define SSID     "xxxxxxxxxx"             /* Wifi router SSID */
#define	PASSWORD "yyyyyyyyyy"          /* Wifi router password */


void setup() 
{
  Serial.begin(115200);   
 
  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) 
  {
    WiFi.begin(SSID, PASSWORD);   
    Serial.print(".");  
    delay(500);
  }

  Serial.println("\nWiFi connected");   /* Some debug information, it can be removed */
  Serial.print("IP address: ");     
  Serial.println(WiFi.localIP());
}

void loop() 
{
  SendIFTTTWebhookRequest(client, 55, 3.45, "someAlarmText!!!");
  delay(5000);
}
