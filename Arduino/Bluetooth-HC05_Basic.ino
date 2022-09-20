// Sketch by kulibiner a.k.a Muhammad Daffa
// Pi
// Malang, September 2022
/*
Sketch by kulibiner 

Pin Connection
-------------------
| Arduino | HC-05 |
|    2    |  TX   |
|    3    |  RX   |
|   VCC   |  VCC  |
|   GND   |  GND  |
-------------------

Malang, September 2022
*/

#include <SoftwareSerial.h>

char incomingChar;
String message = "";

int relay = 13;

// Inisiasi Bluetooth
SoftwareSerial daffaBT(2, 3); // RX, TX

void setup(){

    // Mulai komunikasi serial 
    Serial.begin(9600);

    // Mulai komunikasi bluetooth
    daffaBT.begin(9600);

    // Inisiasi GPIO
    pinMode(relay, OUTPUT);
    digitalWrite(relay, LOW);

    Serial.println("Started !...");    
}

void loop(){
    // Jika koneksi bluetooth tersedia
    if(daffaBT.available()) {
        // Membaca respon bluetooth
        incomingChar = daffaBT.read();

        // Salin ke string message
        message = incomingChar;
    }

    // Perintah lampu
    if(message == "1") {
        digitalWrite(relay, HIGH);
        Serial.println("Lampu murup");
    }
    else if(message == "0") {
        digitalWrite(relay, LOW);
        Serial.println("Lampu mati");
    }
}
