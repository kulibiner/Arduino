#include <ESP8266WiFi.h>

const char* AP_ssid = "ESP Tes";
const char* AP_pswd = "88888888";

const char* STA_ssid = "Interpol";
const char* STA_pswd = "bayardulu";

WiFiServer server(80);

void setup(){
    Serial.begin(115200);

    Serial.println("");
    Serial.println("Starting Up ...");

    //Mode Dual
    WiFi.mode(WIFI_AP_STA);

    //Konfigurasi ESP sebagai Access Point
    WiFi.softAP(AP_ssid, AP_pswd);
    
    //Konfigurasi ESP sebagai client
    WiFi.begin(STA_ssid, STA_pswd);

    while(WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(500);    
    }

    Serial.println();
    Serial.println("Connected to AP");

    // Tampilkan IP Address Access Point
    Serial.print("AP IPAddress : ");
    Serial.println(WiFi.softAPIP());
    
    // Tampilkan IP Address Client
    Serial.print("STA IPAddress : ");
    Serial.print(WiFi.localIP());

    server.begin();

}

void loop(){
    
}
