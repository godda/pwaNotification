# pwaNotification Library

## ภาพรวม
ไลบรารี `pwaNotification` ถูกออกแบบมาเพื่อส่งการแจ้งเตือนผ่าน HTTP POST ไปยังเซิร์ฟเวอร์ที่กำหนด โดยช่วยลดความซับซ้อนในการสร้างและส่งข้อมูลในรูปแบบ JSON สำหรับการใช้งานใน IoT หรือแอปพลิเคชันที่เชื่อมต่อกับเว็บ ซึ่งเหมาะสำหรับการใช้งานร่วมกับ PWA Notification API

## คุณสมบัติ
- ขนาดเล็ก ใช้งานง่าย
- ส่งการแจ้งเตือนในรูปแบบ JSON
- รองรับบอร์ด ESP32 หรือบอร์ดไมโครคอนโทรลเลอร์ที่เชื่อมต่อ WiFi ได้

## ความต้องการ
- Arduino IDE
- ESP32 หรือบอร์ดที่รองรับ WiFi
- เครือข่าย WiFi
- Endpoint API สำหรับการส่งการแจ้งเตือน

## การติดตั้ง
1. ดาวน์โหลดหรือ clone repository นี้
2. คัดลอกโฟลเดอร์ `pwaNotification` ไปยังไดเรกทอรีไลบรารีของ Arduino:
   - Windows: `Documents/Arduino/libraries`
   - macOS: `~/Documents/Arduino/libraries`
   - Linux: `~/Arduino/libraries`
3. รีสตาร์ท Arduino IDE

## การใช้งาน

### เพิ่มไลบรารีในโค้ด
ในสเก็ตช์ Arduino ของคุณ เพิ่มไลบรารี:

```cpp
#include <WiFi.h>
#include "pwaNotification.h"
```

### เชื่อมต่อ WiFi
ตั้งค่า WiFi ของคุณ:

```cpp
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected");
}
```

### ส่งการแจ้งเตือน
เริ่มต้นไลบรารีและส่งการแจ้งเตือน:

```cpp

pwaNotification notifier();

void loop() {
    notifier.sendNotification("16315", "YOUR_TOKEN", "แจ้งเตือน", "[LL] ถังน้ำใส 500", "send", "https://www.xxx.co.th");
    delay(60000); // ส่งทุก 60 วินาที (ตัวอย่าง)
}
```

## ตัวอย่าง
นี่คือตัวอย่างโค้ดแบบสมบูรณ์:

```cpp
#include <WiFi.h>
#include "pwaNotification.h"

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

pwaNotification notifier();

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected");

    notifier.sendNotification("16315", "YOUR_TOKEN", "แจ้งเตือน", "[LL] ถังน้ำใส 500", "send", "https://www.xxx.co.th");
}

void loop() {
    // ไม่มีการทำซ้ำในตัวอย่างนี้
}
```



