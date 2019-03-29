#!/usr/bin/perl

use strict;
use Tinkerforge::IPConnection;
use Tinkerforge::BrickletRotaryPotiV2;

use constant HOST => 'localhost';
use constant PORT => 4223;
use constant UID => 'XYZ'; # Change XYZ to the UID of your Rotary Poti Bricklet 2.0

my $ipcon = Tinkerforge::IPConnection->new(); # Create IP connection
my $rp = Tinkerforge::BrickletRotaryPotiV2->new(&UID, $ipcon); # Create device object

$ipcon->connect(&HOST, &PORT); # Connect to brickd
# Don't use device before ipcon is connected

# Get current position
my $position = $rp->get_position();
print "Position: $position °\n";

print "Press key to exit\n";
<STDIN>;
$ipcon->disconnect();
