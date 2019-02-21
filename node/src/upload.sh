#!/usr/bin/env bash

USB_PORT ="/dev/ttyACM0"
FQBN="esp8266:esp8266:nodemcu"

echo "Uploading..."

arduino-cli upload -p $USB_PORT --fqbn $FQBN