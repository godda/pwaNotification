#ifndef _pwaNotification_H__
#define _pwaNotification_H__

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

class pwaNotification
{
public:
    pwaNotification();
    void sendNotification(const String &uid, const String &token, const String &title, const String &body, const String &action, const String &url);

private:
    String _serverUrl;
};

#endif
