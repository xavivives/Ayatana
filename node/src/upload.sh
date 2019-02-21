#!/usr/bin/env bash

USB_PORT="/dev/ttyACM0"
FQBN="esp8266:esp8266:nodemcu"
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
cd ../

exit 1
