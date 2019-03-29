<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletRotaryPotiV2.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletRotaryPotiV2;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change XYZ to the UID of your Rotary Poti Bricklet 2.0

$ipcon = new IPConnection(); // Create IP connection
$rp = new BrickletRotaryPotiV2(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Get current position
$position = $rp->getPosition();
echo "Position: $position °\n";

echo "Press key to exit\n";
fgetc(fopen('php://stdin', 'r'));
$ipcon->disconnect();

?>
