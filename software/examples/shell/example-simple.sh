#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Rotary Poti Bricklet 2.0

# Get current position
tinkerforge call rotary-poti-v2-bricklet $uid get-position
