#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=XYZ # Change XYZ to the UID of your Rotary Poti Bricklet 2.0

# Handle incoming position callbacks
tinkerforge dispatch rotary-poti-v2-bricklet $uid position &

# Set period for position callback to 0.25s (250ms) without a threshold
tinkerforge call rotary-poti-v2-bricklet $uid set-position-callback-configuration 250 false threshold-option-off 0 0

echo "Press key to exit"; read dummy

kill -- -$$ # Stop callback dispatch in background
