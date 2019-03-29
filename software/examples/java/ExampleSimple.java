import com.tinkerforge.IPConnection;
import com.tinkerforge.BrickletRotaryPotiV2;

public class ExampleSimple {
	private static final String HOST = "localhost";
	private static final int PORT = 4223;

	// Change XYZ to the UID of your Rotary Poti Bricklet 2.0
	private static final String UID = "XYZ";

	// Note: To make the example code cleaner we do not handle exceptions. Exceptions
	//       you might normally want to catch are described in the documentation
	public static void main(String args[]) throws Exception {
		IPConnection ipcon = new IPConnection(); // Create IP connection
		BrickletRotaryPotiV2 rp = new BrickletRotaryPotiV2(UID, ipcon); // Create device object

		ipcon.connect(HOST, PORT); // Connect to brickd
		// Don't use device before ipcon is connected

		// Get current position
		int position = rp.getPosition(); // Can throw com.tinkerforge.TimeoutException
		System.out.println("Position: " + position + " °");

		System.out.println("Press key to exit"); System.in.read();
		ipcon.disconnect();
	}
}
