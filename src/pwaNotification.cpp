#include "pwaNotification.h"

pwaNotification::pwaNotification()
{
    // Server URL
    const char *serverUrl = "https://smartoffice.pwa.co.th/api/noti_api.php";
    _serverUrl = String(serverUrl);
}

void pwaNotification::sendNotification(const String &uid, const String &token, const String &title, const String &body, const String &action, const String &url)
{
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("WiFi not connected");
        return;
    }

    HTTPClient http;
    http.begin(_serverUrl.c_str());
    http.addHeader("Content-Type", "application/json");

    String jsonPayload = "{";
    jsonPayload += "\"uid\":\"" + uid + "\",";
    jsonPayload += "\"token\":\"" + token + "\",";
    jsonPayload += "\"title\":\"" + title + "\",";
    jsonPayload += "\"body\":\"" + body + "\",";
    jsonPayload += "\"action\":\"" + action + "\",";
    jsonPayload += "\"url\":\"" + url + "\"";
    jsonPayload += "}";

    int httpResponseCode = http.POST(jsonPayload);
    if (httpResponseCode > 0)
    {
        String response = http.getString();
        Serial.println("Response: " + response);
    }
    else
    {
        Serial.println("Error in sending POST: " + String(httpResponseCode));
    }
    http.end();
}
