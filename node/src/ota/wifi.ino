#include <FS.h>
#include <ArduinoJson.h>



bool setWifiFromConfig()
{
    const char *path = "/wifi.json";
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
        File file = SPIFFS.open(path, "r");

        StaticJsonBuffer<512> jsonBuffer;
        JsonObject &jsonConfig = jsonBuffer.parseObject(file);
        if (!jsonConfig.success())
        {
            Serial.println("Failed to read ");
            return false;
        }

        id = jsonConfig["id"].as<String>();
        ssid = jsonConfig["ssid"].as<String>();
        password = jsonConfig["password"].as<String>();

        file.close();
        return true;
    }
    Serial.println("\tFile Not Found");
    return false;
}