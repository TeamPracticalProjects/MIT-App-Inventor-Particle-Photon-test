# MIT-App-Inventor-Particle-Photon-test
##Hardware and software to learn to develop apps on MIT app inventor to interact with a Photon over the Internet.

The hardware for this app uses the WLD (https://github.com/TeamPracticalProjects/WaterLeakSensor) 
backlit pushbutton and servo for testing out apps developed with MIT appinventor 2, albeit an LED on pin D5 
and a servo on pin A5 are all that are needed for this testing. The Test_MIT.ino file is flashed to the Photon for testing.  

You load the ParticleTest.aia file into MIT app inventor 2 in order to work with the app.  This is a source code file and you must
enter your device ID and access token where indicated in order to communicate with your Photon.

The resulting app has three buttons. A pair of buttons is used to turn the Photon D5 LED ON and OFF. 
The return value from the Particle web function "on-off" causes the appropriate button to turn green and 
the other button to turn white, indicating the actual state of the LED connected to the Photon.  This demonstates how to call a 
Particle cloud function and how to obtain the return value from the function call for the app to process further.

The third button (SET) sends a servo angle command to the Photon to control the servo position.  The servo angle sent is the number 
displayed in the text box (command) next to the slider control. This command text box can be populated with the servo angle number 
either by typing the number into it or by using the slider adjacent to it. The text label next to the SET button displays the actual
servo position using the return value from the "move" web function call to the Photon.

A String variable ("message") on the Photon is exposed to the cloud.  This variable contains information about the 
firmware version and the last reset time (in UTC) for the device.  The app reads this variable at startup and displays a notification 
dialog to the user to verify that the Photon is on-line and running the expected version of the firmware.

This project will soon be integrated with the Particle App Template at:
https://github.com/TeamPracticalProjects/Particle_App_Template

All materials contained in this repository are (c) 2018 by Bob Glicksman,
Jim Schrempp and Team Practical Projects and are distributed freely under
an open source, non-commercial license, see: https://creativecommons.org/licenses/by-nc/4.0/

Enjoy,
Team Practical Projects
