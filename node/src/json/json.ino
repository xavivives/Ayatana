#include <FS.h>
#include <ArduinoJson.h>

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
        String parsed = parse(file);
        Serial.println(parsed);
        file.close(); // Then close the file again
        return true;
    }
    Serial.println("\tFile Not Found");
    return false; // If the file doesn't exist, return false
}

String parse(File file)
{
    StaticJsonBuffer<512> jsonBuffer;
    JsonObject &config = jsonBuffer.parseObject(file);
    if (!config.success())
        Serial.println(F("Failed to read file, using default configuration"));

    Serial.println(config["id"]);
    Serial.println(config["wifi"]["ssid"]);
    Serial.println(config["wifi"]["password"]);
    Serial.println(config["none"]);
    Serial.println("Done");
    
}