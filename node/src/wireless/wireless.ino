#include <ESP8266WiFi.h>

const char* ssid = "SSID";
const char* password = "password";

void setup(){
    Serial.begin(115200);
    delay(10);
    Serial.println('\n');

    WiFi.begin(ssid, password);
    Serial.println("Connecting to ");
    Serial.println(ssid);
    Serial.println(" ...");

    int i = 0;
    while (WiFi.status() != WL_CONNECTED){
        delay(1000);
        Serial.print(++i);
        Serial.print(' ');
    }

    Serial.println('\n');
    Serial.println('Connection stablished!');
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP());

}

void loop(){}