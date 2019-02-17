#include <FS.h>
#include <ArduinoJson.h>

struct Config
{
    String ssid;
    String password;
    String id;
};

const char *configFilePath = "/config.json";
Config config;

void setup()
{
    Serial.begin(115200);
    delay(10);
    Serial.println('\n');
    SPIFFS.begin();
    read("/config.json");
    Serial.println('DOne reading');
}

void loop()
{
}

bool read(String path)
{ // send the right file to the client (if it exists)
    Serial.println("Reading... " + path);

    if (SPIFFS.exists(path))
    {                                       // If the file exists
        File file = SPIFFS.open(path, "r"); // Open it
        parseConfig(file);
        Serial.println(parsed);
        file.close(); // Then close the file again
        return true;
    }
    Serial.println("\tFile Not Found");
    return false; // If the file doesn't exist, return false
}

void parseConfig(File file)
{
    StaticJsonBuffer<512> jsonBuffer;
    JsonObject &jsonConfig = jsonBuffer.parseObject(file);
    if (!jsonConfig.success())
        Serial.println(F("Failed to read file, using default jsonConfiguration"));

    config.ssid = jsonConfig["wifi"]["ssid"].as<String>();
    config.password = jsonConfig["wifi"]["password"].as<String>();
    config.id = jsonConfig["id"].as<String>();

    Serial.println(config.ssid);
    Serial.println(config.password);
    Serial.println(config.id);

    Serial.println("Done");
}