#include <FS.h>
#include <ArduinoJson.h>

struct Config
{
    String ssid;
    String password;
    String id;
};

typedef void (*ReadFileCallback) (const File file);

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
    config.ssid = jsonConfig["wifi"]["ssid"].as<String>();
    config.password = jsonConfig["wifi"]["password"].as<String>();
    config.id = jsonConfig["id"].as<String>();

    Serial.println(config.ssid);
    Serial.println(config.password);
    Serial.println(config.id);

    Serial.println("Done");

    return config;
}