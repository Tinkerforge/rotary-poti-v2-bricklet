Imports System
Imports Tinkerforge

Module ExampleCallback
    Const HOST As String = "localhost"
    Const PORT As Integer = 4223
    Const UID As String = "XYZ" ' Change XYZ to the UID of your Rotary Poti Bricklet 2.0

    ' Callback subroutine for position callback
    Sub PositionCB(ByVal sender As BrickletRotaryPotiV2, ByVal position As Short)
        Console.WriteLine("Position: " + position.ToString() + " °")
    End Sub

    Sub Main()
        Dim ipcon As New IPConnection() ' Create IP connection
        Dim rp As New BrickletRotaryPotiV2(UID, ipcon) ' Create device object

        ipcon.Connect(HOST, PORT) ' Connect to brickd
        ' Don't use device before ipcon is connected

        ' Register position callback to subroutine PositionCB
        AddHandler rp.PositionCallback, AddressOf PositionCB

        ' Set period for position callback to 0.25s (250ms) without a threshold
        rp.SetPositionCallbackConfiguration(250, False, "x"C, 0, 0)

        Console.WriteLine("Press key to exit")
        Console.ReadLine()
        ipcon.Disconnect()
    End Sub
End Module
