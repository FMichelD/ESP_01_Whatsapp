#ifndef SEND_MESSAGE_H
#define SEND_MESSAGE_H

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <UrlEncode.h>

void sendMessage(String message);

#endif