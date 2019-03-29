package main

import (
	"fmt"
	"github.com/Tinkerforge/go-api-bindings/ipconnection"
	"github.com/Tinkerforge/go-api-bindings/rotary_poti_v2_bricklet"
)

const ADDR string = "localhost:4223"
const UID string = "XYZ" // Change XYZ to the UID of your Rotary Poti Bricklet 2.0.

func main() {
	ipcon := ipconnection.New()
	defer ipcon.Close()
	rp, _ := rotary_poti_v2_bricklet.New(UID, &ipcon) // Create device object.

	ipcon.Connect(ADDR) // Connect to brickd.
	defer ipcon.Disconnect()
	// Don't use device before ipcon is connected.

	rp.RegisterPositionCallback(func(position int16) {
		fmt.Printf("Position: %d °\n", position)
	})

	// Set period for position callback to 0.25s (250ms) without a threshold.
	rp.SetPositionCallbackConfiguration(250, false, 'x', 0, 0)

	fmt.Print("Press enter to exit.")
	fmt.Scanln()
}
