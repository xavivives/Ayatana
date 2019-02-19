#include <FS.h>
#include <ArduinoJson.h>

struct Wifi
{
    String ssid;
    String password;
};

struct Config
{
    Wifi wifis[];
    String id;
};

typedef void (*ReadFileCallback)(const File file);

bool readFile(String path, ReadFileCallback callback)
{ // send the right file to the client (if it exists)
    Serial.println("Reading... " + path);

    if (SPIFFS.exists(path))
    {                                       // If the file exists
        File file = SPIFFS.open(path, "r"); // Open its
        callback(file);
        file.close(); // Then close the file again
        return true;
    }
    Serial.println("\tFile Not Found");
    return false; // If the file doesn't exist, return false
}

Config parseConfig(File file)
{

    StaticJsonBuffer<512> jsonBuffer;
    JsonObject &jsonConfig = jsonBuffer.parseObject(file);
    if (!jsonConfig.success())
        Serial.println(F("Failed to read file, using default jsonConfiguration"));

    Config config;
    config.id = jsonConfig["id"].as<String>();

    //JsonArray& jsonWifis = jsonConfig["wifis"];
    int arraySize = jsonConfig["wifis"].size();

    for (int i = 0; i < arraySize; i++)
    {
        Wifi wifi;
        wifi.ssid = jsonConfig["wifis"][i]["ssid"].as<String>();
        wifi.password = jsonConfig["wifis"][i]["password"].as<String>();
        config.wifis[i] = wifi;
    }

    Serial.println("Done");

    return config;
}