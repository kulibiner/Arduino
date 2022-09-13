/* * * * * * * * * * * * * * * * * * * * * * * *
K U L I B I N E R - 2 0 2 2

Open and read file system

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
    File f = SPIFFS.open(filename, "r");

    if(!f) {
        Serial.println("Gagal membuka file");
    } else {

        for (int i = 0; i < f.size(); i++){
            Serial.print((char)f.read());
        }

        f.close();
    }
}

void loop()
{
    
}
