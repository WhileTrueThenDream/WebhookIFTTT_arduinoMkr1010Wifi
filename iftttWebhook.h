#ifndef _H_IFTTTWEBHOOK_
#define _H_IFTTTWEBHOOK_

#include <WiFiNINA.h>

#define DEBUG_MSG 1

#define TRIGGER_NAME "xxxxxxxxxxxxxxxxx"                      /* IFTTT Trigger name */
#define KEY "yyyyyyyyyyy"                                     /* IFTTT Key */

#define SERVER_NAME "maker.ifttt.com"                        /* IFTTT server name */
#define HTTP_ "https://"
#define HTTP_PORT (uint16_t)443

#define IFTT_OK 0
#define IFTT_NOT_CONNECTED -1
#define IFTTT_ERRORS -2


int SendIFTTTWebhookRequest(WiFiSSLClient client, int value1, float value2, char* str_value3);

#endif
