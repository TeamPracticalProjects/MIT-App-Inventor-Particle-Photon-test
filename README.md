# MIT-App-Inventor-Particle-Photon-test
## Hardware and software to learn to develop apps on MIT App Inventor 2 to interact with a Photon over the Internet.

The hardware for this app uses the WLD (https://github.com/TeamPracticalProjects/WaterLeakSensor) 
backlit pushbutton and servo for testing out apps developed with MIT Appinventor 2, albeit an LED on pin D5, momentary pushbutton on pin D4, 
and a servo on pin A5 are all that are needed for this testing. The Test_MIT.ino file is flashed to the Photon for testing.  

There are three subfolders in this repository:
### Standalone App:  
This folder contains source code (.aia file) only for a version of the “ParticleTest” app that is not integrated with our template.  This version is provided because it is easy to read and to understand how to call Particle cloud functions and read Particle cloud variables from MIT App Inventor code.  You load the ParticleTest.aia file into MIT App Inventor 2 in order to work with the app.  This is a source code file and you must
enter your device ID and access token where indicated in order to communicate with your Photon.  A description of the design is also provided in this folder.
 
### Deployable App:
This folder contains source code (.aia file) and the compiled app (.apk file) for a version of the “ParticleTest” app that is integrated with our template (see: https://github.com/TeamPracticalProjects/Particle_App_Template). This version of the app allows the user to log in to their Particle account and select the device to use with the app.  There is no need to hardcode the user access_token or the deviceID.  

### Notification Test App: 
This folder contains two subfolders.  The /src folder contains the complete source code file (.aia)for the “Alert_Test” app.  The /compiled folder contains a deployable (.apk) file that you can upload to your Android device and install directly, without the need to compile anything in MIT app inventor.  

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


### Alert_Test App Description:
This app implements a notification on the mobile device that it is installed on whenever a specific Particle.publish() event is triggered on a Particle device.  A Particle Webhook and a Firebase Real-Time Database are also needed to make the connection between the Particle Firmware and the mobile device.

The “Alert_Test” app has three labels.  When data in an associated Firebase Real-Time Database changes, the app (running in foreground or background) will fire off a notification to the mobile device on which it is running.  The user can tap on the notification to open the app, at which point the app will display the data associated with the notification:  the event name of the notification, the data sent with the notification event, and a timestamp for the event.  A Firebase Real-Time Database and a Particle Webhook must be properly set up and configured in order that Particle.publish() events in your Particle device will trigger a notification on your mobile device.  Complete documentation about how to do this is forthcoming.

The work documented here for generating a mobile alert from Particle.publish() is based heavily upon pioneering work done by members of the Particle developer community:

“rhino” (https://community.particle.io/badges/2/member?username=rhino)

“rickkas7” (https://community.particle.io/u/rickkas7/summary); tutorial at: https://github.com/rickkas7/firebase_tutorial

The “Alert_Test” app requires an MIT App Inventor 2 extension from Pura Vida Apps called “Simple Notification Extension” (https://puravidaapps.com/notification.php).  You must download this extension into your MIT App Inventor 2 project, unless you import our .aia file as the starting point (it contains this extension).  While you are at puravidaapps.com, please make a small PayPal donation to them for their exceptional work in providing useful extensions to the developer community.  Team Practical Projects has no relation to Pura Vida apps, but we respect their work immensely and we believe that the entire developer community benefits greatly from their work.


All materials contained in this repository are (c) 2018 by Bob Glicksman,
Jim Schrempp and Team Practical Projects and are distributed freely under
an open source, non-commercial license, see: https://creativecommons.org/licenses/by-nc/4.0/

Enjoy,
Team Practical Projects
