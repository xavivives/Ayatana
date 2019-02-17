#include <FS.h>

void setup()
{
    Serial.begin(115200);
    delay(10);
    Serial.println('\n');
    read("config");
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

String parse(File f)
{
    String parsed = "";
    while (f.available())
    {
        parsed += char(f.read());
    }
    return parsed;
}