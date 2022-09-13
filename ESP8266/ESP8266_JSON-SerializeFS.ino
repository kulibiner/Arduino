/* * * * * * * * * * * * * * * * * * * * * * * *
K U L I B I N E R - 2 0 2 2

> Open File System
> Json Serialize (Use ArduinoJson 6 library !!)

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

    // doc["JSON_KEY"] = "VALUE_KEY";
    doc["ssid"] = "Hanya WiFi Biasa";
    doc["pswd"] = "tidakadabos";

    // Membuka file sistem
    File configFile = SPIFFS.open("/wifi.json", "w");

    // Cek apakah file berhasil dibuka
    if(!configFile) {
        Serial.println("Gagal membuka file sistem");
    } else {
        Serial.println("Berhasil membuka file sistem");
    }

    // Generate file json dan masukkan kedalam configFile
    serializeJson(doc, configFile);

    // Menutup file config
    configFile.close();
}

void loop()
{
    
}
