using System;
using Tinkerforge;

class Example
{
	private static string HOST = "localhost";
	private static int PORT = 4223;
	private static string UID = "XYZ"; // Change XYZ to the UID of your Rotary Poti Bricklet 2.0

	// Callback function for position callback
	static void PositionCB(BrickletRotaryPotiV2 sender, short position)
	{
		Console.WriteLine("Position: " + position + " °");
	}

	static void Main()
	{
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletRotaryPotiV2 rp = new BrickletRotaryPotiV2(UID, ipcon); // Create device object

		ipcon.Connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Register position callback to function PositionCB
		rp.PositionCallback += PositionCB;

		// Set period for position callback to 0.25s (250ms) without a threshold
		rp.SetPositionCallbackConfiguration(250, false, 'x', 0, 0);

		Console.WriteLine("Press enter to exit");
		Console.ReadLine();
		ipcon.Disconnect();
	}
}
