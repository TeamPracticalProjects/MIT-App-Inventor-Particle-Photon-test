# MIT-App-Inventor-Particle-Photon-test
Hardware and software to learn to develop apps on MIT app inventor to interact with a Photon over the Internet.

The hardware for this app uses the WLD backlit pushbutton and servo for testing out apps developed with MIT app
inventor 2, albeit an LED on pin D5 and a servo on pin A5 are all that are needed for this testing. The Test_MIT.ino file
is flashed to the Photon for testing.  

You load the ParticleTest.aia file into MIT app inventor 2 in order to work with the app.  This is a source code file and you must
enter your device ID and access token where indicated in order to communicate with your Photon.

The resulting app has three buttons -- a pair of buttons is used to turn the LED ON and OFF. The third button (SET) 
sends a servo angle to the Photon to control the servo position.  The servo angle sent is the number displayed in the text 
box (Command).The Command text box can be populated with the servo angle number either by typing the number into it
or by using the slider adjacent to it. The text label next to the SET button is intended to display the actual servo position
from the return of the function call to Particle.  Currently, however, this label box displays the complete return string from 
all Particle function calls (both the LED on-off and the SERVI move function calls).

As of this release, the following items work:
- the LED ON and LED OFF buttons send commands to the Photon to turn the LED on and off, respectively.
- the slider sets its value into a text box (Command), overwriting any value in it.
- pressing the SET button sends the number in the text box (Command) to the Photon to move the servo.
- the web response text box displays the Particle.function() return value only.

The following additional work is planned:
- separate LED ON/OFF from Servo position posts to process responses separately..
- use the function return value from LED on and off to color the LED on/off buttons appropriately..
- clean up procedures calls to get rid of globals and use arguments instead.
- process a file(s) with a list picker to select the device to use (i.e. device ID and access token are in file(s)
    and not hardcoded).
