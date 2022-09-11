#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

// WiFi Parameter
const char* ssid = "SSID_WIFI_MU";
const char* pswd = "PASSWORD_WIFI_MU";

// HTML Parameter
const char* PARAM_VALUE = "value1";

// Value
String VALUE_1;

AsyncWebServer server(80);

// Frontend Web
const char index_html[] PROGMEM = R"rawliteral(
    <!DOCTYPE HTML><html>
        <head>
            <title>Muhammad Daffa</title>
        </head>
        <body>
            <form action="/get">
                <input type="text" name="value1">
                <input type="submit" value="Submit">
            </form>
        </body>
    </html>
)rawliteral";

// Jembatan antara MCU dengan Web
// Menampilkan variable ke Web
String processor(const String& var) {
    if(var == "ssid") {
        return ssid;
    }
}

void setup(){
    // Memulai Serial
    Serial.begin(115200);

    Serial.println();
    Serial.print("Connecting to : ");
    Serial.println(ssid);

    WiFi.begin(ssid, pswd);

    while(WiFi.status() != WL_CONNECTED){
        Serial.print(".");
        delay(500);
    }    

    Serial.println();
    Serial.println("Connected !");
    Serial.print("IP Address : ");
    Serial.println(WiFi.localIP());

    // Ketika user membuka link
    server.on("/", HTTP_GET, [](AsyncWebServerRequest  *request){
        request->send_P(200, "text/html", index_html, processor);
    });

    server.on("/get", HTTP_GET, [](AsyncWebServerRequest  *request){
        if(request->hasParam(PARAM_VALUE)) {
            //Ambil value dari web dan masukkan kedalam variable
            VALUE_1 = request->getParam(PARAM_VALUE)->value();

            Serial.print("Value : ");
            Serial.println(VALUE_1);

            // Respon
            request->send_P(200, "text/plain", "Berhasil");
        }
    });

    server.begin();
}

void loop(){
    
}
