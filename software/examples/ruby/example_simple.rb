#!/usr/bin/env ruby
# -*- ruby encoding: utf-8 -*-

require 'tinkerforge/ip_connection'
require 'tinkerforge/bricklet_rotary_poti_v2'

include Tinkerforge

HOST = 'localhost'
PORT = 4223
UID = 'XYZ' # Change XYZ to the UID of your Rotary Poti Bricklet 2.0

ipcon = IPConnection.new # Create IP connection
rp = BrickletRotaryPotiV2.new UID, ipcon # Create device object

ipcon.connect HOST, PORT # Connect to brickd
# Don't use device before ipcon is connected

# Get current position
position = rp.get_position
puts "Position: #{position} °"

puts 'Press key to exit'
$stdin.gets
ipcon.disconnect
