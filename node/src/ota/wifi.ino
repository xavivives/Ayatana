#include <FS.h>
#include <ArduinoJson.h>

String id = "none";
String ssid = "none";
String password = "none";

bool setWifiFromConfig()
{
    Serial.println("Reading... ");

    if (SPIFFS.begin())
    {
        Serial.println("SPIFFS initialized");
    }
    else
    {
        Serial.println("SPIFFS failed");
    }

    if (SPIFFS.exists(path))
    {
        File file = SPIFFS.open("/config.json", "r");

        StaticJsonBuffer<512> jsonBuffer;
        JsonObject &jsonConfig = jsonBuffer.parseObject(file);
        if (!jsonConfig.success())
        {
            Serial.println("Failed to read ");
            return false;
        }

        id = jsonConfig["id"].as<String>();

        int arraySize = jsonConfig["wifis"].size();

        for (int i = 0; i < arraySize; i++)
        {
            ssid = jsonConfig["wifis"][i]["ssid"].as<String>();
            password = jsonConfig["wifis"][i]["password"].as<String>();
            Serial.println("Failed to read file, using default jsonConfiguration");
        }

        file.close();
        return true;
    }
    Serial.println("\tFile Not Found");
    return false;
}