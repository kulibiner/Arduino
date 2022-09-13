/* * * * * * * * * * * * * * * * * * * * * * * *
K U L I B I N E R - 2 0 2 2

Open and read file system

Referensi : 
- https://arduino-esp8266.readthedocs.io/en/latest/filesystem.html

https://github.com/kulibiner
* * * * * * * * * * * * * * * * * * * * * * * */

#include <ESP8266WiFi.h>
#include <FS.h>

// Nama File
const char* filename = "/wifi.json";


void setup(){
    delay(1000);
    Serial.begin(115200);

    // Cek SPIFFS
    if(SPIFFS.begin()) {
        Serial.println("Memulai file system");
    } else {
        Serial.println("Gagal memulai file system");
    }

    // Membuka file
    File f = SPIFFS.open(filename, "w");

    if(!f) {
        Serial.println("Gagal membuka file");
    } else {

        // Tulis ke file sistem
        f.print("Teks ini akan tersimpan pada file sistem.");

        // Menutup file
        f.close();
    }
}

void loop()
{
    
}
