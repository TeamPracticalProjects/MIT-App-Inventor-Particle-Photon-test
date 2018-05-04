# MIT-App-Inventor-Particle-Photon-test
## Hardware and software to learn to develop apps on MIT App Inventor 2 to interact with a Particle Photon or Electron over the Internet.

The hardware for this app uses the WLD (https://github.com/TeamPracticalProjects/WaterLeakSensor) 
backlit pushbutton and servo for testing out apps developed with MIT App Inventor 2, albeit an LED on pin D5, momentary pushbutton on pin D4, 
and a servo on pin A5 are all that are needed for this testing. The Test_MIT.ino file is flashed to the Photon for testing all of the features and functions described below.  

### What is here:
This repository contains sample app code (MIT App Inventor 2) to obtain data from a Particle device (from Particle.variable() declared in the firmware) and to call functions on a Particle device (using Particle.function() declared in the firmware).  This code is solid and may be used as a guide for people wishing to develop apps to interact with their Particle devices.  We have integrated this code with our Particle_App_Template.  This template is used with the app to obtain a list of your Particle devices and select the device to be used with the app.  The template avoids the need to hard code the Particle user access_token and deviceID into your app, making the app more useful and able to be published in installable (.apk file) form.  See:  https://github.com/TeamPracticalProjects/Particle_App_Template

This repository contains the following directories:
### Documentation:
This directory contains two files:  An Installation and User Manual and a technical description of the MIT App Inventor 2 source code that integrates with our template and can obtain cloud variable information from your Particle device and can call cloud functions on your Particle device.

### Particle Firmware/src:
This directory contains source code that you can upload to the Particle Web IDE, compile there, and flash to your Particle device (Photon or Electron).  This firmware works with the MIT App Inventor 2 software (“CommunicateWithParticleDemoApp.apk” app) to demonstrate the functionality.  

### Software_MIT_App_Inventor/Deployable App:
This directory contains source code (CommunicateWithParticleDemoApp.aia file) and the compiled app (CommunicateWithParticleDemoApp.apk file) for a version of the app that is integrated with our template (see: https://github.com/TeamPracticalProjects/Particle_App_Template). This version of the app allows the user to log in to their Particle account and select the device to use with the app.  There is no need to hardcode the user access_token or the deviceID.  


### Legacy/Standalone App:  
This folder contains source code (.aia file) only for a version of the “ParticleTest” app that is not integrated with our template.  It is superseded by the version of the app that integrates with our Particle_App_Template.  A legacy description of the design is also provided in this folder.
 
For more information about the Particle App Template, please see:
https://github.com/TeamPracticalProjects/Particle_App_Template


All materials contained in this repository are (c) 2018 by Bob Glicksman,
Jim Schrempp and Team Practical Projects and are distributed freely under
an open source, non-commercial license, see: https://creativecommons.org/licenses/by-nc/4.0/.  See the document “Terms_of_Use_License_and_Disclaimer” for complete information.

Enjoy,
Team Practical Projects
