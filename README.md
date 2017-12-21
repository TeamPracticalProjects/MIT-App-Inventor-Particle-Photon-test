# MIT-App-Inventor-Particle-Photon-test
Hardware and software to learn to develop apps on MIT app inventor to interact with a Photon over the Internet.

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

The following additional work is planned:
- process a file(s) on the phone with a list picker to select the device to use (i.e. device ID and access token are in file(s)
    and not hardcoded).
- Change the opening notification.  Wait for the user to select the device and then perform a cloud query to Particle to see if 
    the device is on line or not and notify the user accordingly.
- (TBD) create an app to remotely (REST) login to the Particle cloud and obtain the user's access token and a list of the user's
    devices (device name, firmware running on it, deviceID) and store this in a file on the phone that apps such as this one
    can user for the user to select the device to use without hardcoding access tokens and device IDs into apps like this one.

