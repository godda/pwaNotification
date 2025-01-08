#include <WiFi.h>
#include "pwaNotification.h"

// Replace with your WiFi credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";


// Initialize the pwaNotification
pwaNotification notifier();

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected");

    // Send notification
    //sendNotification("รหัสพนักงาน", "token", "หัวข้อแจ้งเตือน", "เนื้อหาในการแจ้งเตือน", "send", "URL ลิงค์เมื่อมีการกดแจ้งเตือน");
    notifier.sendNotification("16315", "xxxxxxxxxxxxxxxx", "แจ้งเตือน", "[LL] ถังน้ำใส 500", "send", "https://www.xxx.co.th");
}

void loop() {
    // Add your repeated code here if needed
}
