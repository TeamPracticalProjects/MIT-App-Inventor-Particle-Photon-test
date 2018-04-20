# MIT-App-Inventor-Particle-Photon-test
## Hardware and software to learn to develop apps on MIT App Inventor 2 to interact with a Photon or Electron over the Internet.

The hardware for this app uses the WLD (https://github.com/TeamPracticalProjects/WaterLeakSensor) 
backlit pushbutton and servo for testing out apps developed with MIT App Inventor 2, albeit an LED on pin D5, momentary pushbutton on pin D4, 
and a servo on pin A5 are all that are needed for this testing. The Test_MIT.ino file is flashed to the Photon for testing all of the features and functions described below.  

### What is here:
This repository contains sample app code (MIT App Inventor 2) to obtain data from a Particle device (from Particle.variable() declared in the firmware) and to call functions on a Particle device (using Particle.function() declared in the firmware).  This code is solid and may be used as a guide for people wishing to develop apps to interact with their Particle devices.  We have also created a template that can be used with your app to obtain a list of your Particle devices and select the device to be used with the app.  The template avoids the need to hard code the Particle user access_token and deviceID into your app, making the app more useful and able to be published in installable (.apk file) form.  See:  https://github.com/TeamPracticalProjects/Particle_App_Template

This repository contains the following directories:
### Documentation:
This directory contains a description of the MIT App Inventor 2 code that can obtain cloud variable information from your Particle device and can call cloud functions on your Particle device.

### Particle Firmware:
This directory contains source code that you can upload to the Particle Web IDE, compile there, and flash to your Particle device (Photon or Electron).  This firmware works with both versions of the MIT App Inventor 2 software (�ParticleTest� app) to demonstrate the functionality.

### Software_MIT_App_Inventor:
This directory contains two subdirectories for two versions of the app � a standalone version and a version that is integrated with our template.

#### Standalone App:  
This folder contains source code (.aia file) only for a version of the �ParticleTest� app that is not integrated with our template.  This version is provided because it is easy to read and to understand how to call Particle cloud functions and read Particle cloud variables from MIT App Inventor code.  You load the ParticleTest.aia file into the MIT App Inventor 2 IDE in order to work with the app.  This is a source code file and you must enter your device ID and access token where indicated in order to communicate with your Photon.  A description of the design is also provided in this folder.
 
#### Deployable App:
This folder contains source code (.aia file) and the compiled app (.apk file) for a version of the �ParticleTest� app that is integrated with our template (see: https://github.com/TeamPracticalProjects/Particle_App_Template). This version of the app allows the user to log in to their Particle account and select the device to use with the app.  There is no need to hardcode the user access_token or the deviceID.  

### MIT_Particle_Photon_Test App Description (standalone and deployable versions):
The app has three buttons. A pair of buttons is used to turn the Photon D5 LED ON and OFF. 
The return value from the Particle web function "on-off" causes the appropriate button to turn green and 
the other button to turn white, indicating the actual state of the LED connected to the Photon.  This demonstrates how to call a 
Particle cloud function and how to obtain the return value from the function call for the app to process further.

The third button (SET) sends a servo angle command to the Photon to control the servo position.  The servo angle sent is the number 
displayed in the text box (command) next to the slider control. This command text box can be populated with the servo angle number 
either by typing the number into it or by using the slider adjacent to it. The text label next to the SET button displays the actual
servo position using the return value from the "move" web function call to the Photon.

A String variable ("message") on the Photon is exposed to the cloud.  This variable contains information about the 
firmware version and the last reset time (in UTC) for the device.  The app reads this variable at startup and displays its content.  This feature works slightly differently on the standalone app and on the template integrated version.  On the standalone version, a notification dialog box pops up with the information from the device as well as the Particle web call response code so that the user knows that the device was communicated with properly.  On the integrated version, the template code provides the necessary information about the device being online, so the device provided status information is displayed near the bottom of the screen.

For more information about the Particle App Template, please see:
https://github.com/TeamPracticalProjects/Particle_App_Template


All materials contained in this repository are (c) 2018 by Bob Glicksman,
Jim Schrempp and Team Practical Projects and are distributed freely under
an open source, non-commercial license, see: https://creativecommons.org/licenses/by-nc/4.0/.  See the document �Terms_of_Use_License_and_Disclaimer� for complete information.

Enjoy,
Team Practical Projects
