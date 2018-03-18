# MIT-App-Inventor-Particle-Photon-test
## Hardware and software to learn to develop apps on MIT app inventor to interact with a Photon over the Internet.

The hardware for this app uses the WLD (https://github.com/TeamPracticalProjects/WaterLeakSensor) 
backlit pushbutton and servo for testing out apps developed with MIT appinventor 2, albeit an LED on pin D5 
and a servo on pin A5 are all that are needed for this testing. The Test_MIT.ino file is flashed to the Photon for testing.  

There are two subfolders in this repository:
### Standalone App:  
This folder contains source code (.aia file) only for a version of this app that is not integrated with our template.  This version is provided because it is easy to read and understand how to call Particle cloud functions and read Particle cloud variables from MIT app inventor code.  You load the ParticleTest.aia file into MIT app inventor 2 in order to work with the app.  This is a source code file and you must
enter your device ID and access token where indicated in order to communicate with your Photon.  A description of the design is also provided in this folder.
### Deployable App:
This folder contains source code (.aia file) and the compile code (.apk file) for a version of this app that is integrated with our template (see: https://github.com/TeamPracticalProjects/Particle_App_Template). This verison of the app allows the user to log in to their Particle account and select the device to use with the app.  There is no need to hardcode the user access_token or the deviceID.  

This folder contains two subfolders.  The /src folder contains the complete source code file (.aia).  The /compiled folder contains a deployable (.apk) file that you can upload to your Android device and install directly, without the need to compile anything in MIT app inventor.

### App Description:
The app has three buttons. A pair of buttons is used to turn the Photon D5 LED ON and OFF. 
The return value from the Particle web function "on-off" causes the appropriate button to turn green and 
the other button to turn white, indicating the actual state of the LED connected to the Photon.  This demonstrates how to call a 
Particle cloud function and how to obtain the return value from the function call for the app to process further.

The third button (SET) sends a servo angle command to the Photon to control the servo position.  The servo angle sent is the number 
displayed in the text box (command) next to the slider control. This command text box can be populated with the servo angle number 
either by typing the number into it or by using the slider adjacent to it. The text label next to the SET button displays the actual
servo position using the return value from the "move" web function call to the Photon.

A String variable ("message") on the Photon is exposed to the cloud.  This variable contains information about the 
firmware version and the last reset time (in UTC) for the device.  The app reads this variable at startup and displays its content.  This feature works slightly differently on the standalone app and on the template integrated version.  On the standalone version, a notification dialog box pops up with the information from the device as well as the paticle web call response code so that the user knows that the device was communicated with properly.  On the integrated version, the template code provides the necessary information about the device being online, so the device provided status information is displayed near the bottom of the screen.

For more information about the Particle App Template, please see:
https://github.com/TeamPracticalProjects/Particle_App_Template

All materials contained in this repository are (c) 2018 by Bob Glicksman,
Jim Schrempp and Team Practical Projects and are distributed freely under
an open source, non-commercial license, see: https://creativecommons.org/licenses/by-nc/4.0/

Enjoy,
Team Practical Projects
