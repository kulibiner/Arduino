/* * * * * * * * * * * * * * * * * * * * * * * *
K U L I B I N E R - 2 0 2 2

> Open File System
> Json Parse (Use ArduinoJson 6 library !!)

Referensi : 
- https://arduino-esp8266.readthedocs.io/en/latest/filesystem.html
- https://arduinojson.org/v6/doc/

https://github.com/kulibiner
* * * * * * * * * * * * * * * * * * * * * * * */

#include <ESP8266WiFi.h>
#include <FS.h>
#include <ArduinoJson.h>


void setup(){
    delay(1000);
    Serial.begin(115200);

    // Cek SPIFFS
    if(SPIFFS.begin()) {
        Serial.println("Memulai File sistem");
    } else {
        Serial.println("Gagal memulai File sistem");
    }

    // Deklarasi variabel untuk key file json
    // Angka dalam <braket> menunjukkan kapasitas maksimal
    // arduinojson.org/v6/assistant
    StaticJsonDocument<200> doc;

    // Membuka file sistem
    File configFile = SPIFFS.open("/wifi.json", "r");

    // Memecah file json kedalam variabel
    DeserializationError error = deserializeJson(doc, configFile);

    const char* ssid = doc["ssid"];
    const char* pswd = doc["pswd"];

    Serial.println(ssid);
    Serial.println(pswd);
}

void loop()
{
    
}
