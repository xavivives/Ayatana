#!/usr/bin/env bash

USB_PORT="/dev/ttyUSB0"
FQBN="esp8266:esp8266:nodemcuv2"
DIR="ota"
MODE=$1

cd $DIR

if [ "$MODE" = "compile" ] || [ -z "$MODE" ]
then
    echo "Compiling..."
    arduino-cli compile --fqbn $FQBN
fi

if [ "$MODE" = "upload" ] || [ -z "$MODE" ]
then
    echo "Uploading..."
    arduino-cli upload -p $USB_PORT --fqbn $FQBN
fi

if [ "$MODE" = "spiffs" ]
then
    mkspiffs -c ~/Arduino/ds18b20/data/ -p 256 -b 8192 -s 1028096 /tmp/out.spiffs
    esptool -cd nodemcu -cb 460800 -cp $USB_PORT -ca 0x300000 -cf /tmp/out.spiffs
fi

cd ../

exit 1
