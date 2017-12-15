# MIT-App-Inventor-Particle-Photon-test
Hardware and software to learn to develop apps on MIT app inventor to interact with a Photon over the Internet.

The hardware for this app uses the WLD backlit pushbutton and servo for testing out apps developed with MIT app
inventor 2, albeit an LED on pin D5 and a servo on pin A5 are all that are needed for this testing. The .ino file
is flashed to the Photon for testing.  

You load the .aia file into MIT app inventor in order to work with the app.  This is a source code file and you must
enter your device ID and access token where indicated in order to communicate with your Photon.

The resulting app has two buttons -- one to trun the LED on and the other to trun the LED off.  It also has a slider
to move the servo and a text label to display the return from the Particle function calls.

As of this release, the following items work:
- the buttons turn the LED on and off, respectively.
- the slider moves the servo.
- the text box displays the complete return string from any cloud function call.

The following additional work is planned:
- parse and process the function return strings
- use the function return strings from LED on and off to color the LED on/off buttons appropriately.
- filter the slider (somehow) so that the servo does not jump around while thumbing the slider.
- use the funtion return string from the servo poitioning to display only the current servo position angle.
