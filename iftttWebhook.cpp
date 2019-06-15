#include <WiFiNINA.h>
#include <ArduinoHttpClient.h>
#include "iftttWebhook.h"

char buf1[150];
char buf2[150];

static void clearBuf(char *buf);


int SendIFTTTWebhookRequest(WiFiSSLClient client, int value1, float value2, char* str_value3)
{
  int i = 0, ret = IFTTT_ERRORS;
  
  clearBuf(buf1);
  clearBuf(buf2);
  
  if (client.connect(SERVER_NAME, HTTP_PORT))
  {
    #ifdef DEBUG_MSG
    /* Some debug information, it can be removed */
    Serial.println("connected to: \n");
    Serial.print(SERVER_NAME);
    Serial.print(": ");
    Serial.println(HTTP_PORT, DEC);
    #endif

    /* build HTTP GET Request */
    sprintf(buf1,"/trigger/%s/with/key/%s?value1=%d&value2=%.2f&value3=%s", TRIGGER_NAME, KEY, value1,value2,str_value3);
    sprintf(buf2, "GET %s HTTP/1.1", buf1);  
    client.println(buf2);

    #ifdef DEBUG_MSG
    Serial.println(buf2);   /* Some debug information, it can be removed */
    #endif

    clearBuf(buf2);
    sprintf(buf2, "Host: %s", SERVER_NAME );
    client.println(buf2);

    #ifdef DEBUG_MSG
    Serial.println(buf2);  /* Some debug information, it can be removed */
    #endif

    client.println("Connection: close");
    client.println();    
  
    clearBuf(buf2);
   
    while(((client.read((uint8_t*)buf2, sizeof(buf2))) == 0)&&(i < 100)) /* wait till http response ready or 5 seconds */
    {
      delay(50);
      i++;
    }

    #ifdef DEBUG_MSG
    Serial.println();
    Serial.println("HTTP Response:");
    Serial.println(buf2); /* Some debug information, it can be removed */
    Serial.println();
    #endif

    for(int i = 0 ; i < 50; i++) /* check in response we received a 200, i.e, an "OK" http status */
    {
      if((buf2[i] == '2')&&(buf2[i+1] == '0')&&(buf2[i+2] == '0'))
      {
              ret = IFTT_OK;
              break; /* You received a http code 200 == success !*/
      }
    }          
    client.stop(); 
    
  }
  else
  {
    ret = IFTT_NOT_CONNECTED;
  }

  return ret;
}

/* fill buffer with 0s */
static void clearBuf(char *buf)
{
  for(int i = 0 ; i< sizeof(buf); i++)
  {
    buf[i] = 0x00;
  }
}
