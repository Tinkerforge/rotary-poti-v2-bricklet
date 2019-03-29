<?php

require_once('Tinkerforge/IPConnection.php');
require_once('Tinkerforge/BrickletRotaryPotiV2.php');

use Tinkerforge\IPConnection;
use Tinkerforge\BrickletRotaryPotiV2;

const HOST = 'localhost';
const PORT = 4223;
const UID = 'XYZ'; // Change XYZ to the UID of your Rotary Poti Bricklet 2.0

// Callback function for position callback
function cb_position($position)
{
    echo "Position: $position °\n";
}

$ipcon = new IPConnection(); // Create IP connection
$rp = new BrickletRotaryPotiV2(UID, $ipcon); // Create device object

$ipcon->connect(HOST, PORT); // Connect to brickd
// Don't use device before ipcon is connected

// Register position callback to function cb_position
$rp->registerCallback(BrickletRotaryPotiV2::CALLBACK_POSITION, 'cb_position');

// Set period for position callback to 0.25s (250ms) without a threshold
$rp->setPositionCallbackConfiguration(250, FALSE, 'x', 0, 0);

echo "Press ctrl+c to exit\n";
$ipcon->dispatchCallbacks(-1); // Dispatch callbacks forever

?>
