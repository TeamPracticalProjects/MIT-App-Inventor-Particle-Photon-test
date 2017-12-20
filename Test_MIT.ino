/* TEST_MIT:  program to test out MIT app inventor to control a Particle device.

    This program exposes two functions to the cloud:
    
    "on-off": accepts a string argument, which is case insensitive.  "ON" or "on" turns an
        indicator LED on pin D5 on.  "OFF" or "off" turn the LED off.  The function returns
        an int: 1 of the LED is ON, 0 if the LED is off, -1 for any invalid command.
        
    "move":  accepts a string argument which is the angle of a servo attached to pin A5.
        The argument must be a number.  If not a number, no servo action will be taken and
        the function returns -1.  The servo angle is clamped between SERVO_MAX and SERVO_MIN.
        If a valid number string is the argument, the servo will move to the angle of the argument
        if it is withing range or to the MAX or MIN clamp limits.  The furntion returns the
        angle that is actually sent to the servo.
        
    When the program is successfully loaded and running, the D7 LED will flash with a 1 second period.
    
    Version 1.0, 12/19/2017; (c) 2017, 2018 Bob Glicksman and Team Practical Projects
        
*/

const int LED_PIN = D7;
const int INDICATOR_PIN = D5;
const int SERVO_PIN = A5;
const int BLINK_TIME = 500;
const int SERVO_MAX = 175;
const int SERVO_MIN = 5;
const String version = "firmware version 1.0; last reset at:";

String message = version + Time.timeStr() + "Z\n";

Servo myServo;


void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(INDICATOR_PIN, OUTPUT);
    pinMode(SERVO_PIN, OUTPUT);
    myServo.attach(SERVO_PIN);
    
    digitalWrite(LED_PIN, LOW);
    digitalWrite(INDICATOR_PIN, LOW);
    
    Particle.function("on-off", ledRemote);
    Particle.function("move", servoRemote);
    Particle.variable("message", message);
    
}

void loop() {

    blinkLED(BLINK_TIME);
}

void blinkLED(int time) {
    static bool ledState = false;
    static unsigned long lastTime = millis();
    
    if( (millis() - lastTime) >= time) {
        ledState = !ledState;
        lastTime = millis();
    }
    
    if(ledState == TRUE) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }
    
    return;
}

// remote control functions

int ledRemote(String ledCommand) {
    String convertedCommand = ledCommand.toUpperCase();
    
    if(convertedCommand == "ON") {
        digitalWrite(INDICATOR_PIN, HIGH);
        return(1);
    } else if(convertedCommand == "OFF") {
        digitalWrite(INDICATOR_PIN, LOW);
        return(0);        
    } else {
        return(-1);
    }
}

int servoRemote(String angle) {
    int command = angle.toInt();
    
    // test ofr non numerical input
    if(command == 0) {
        return(-1);
    }
    
    // input was a number, so clamp between limits and move the servo
    if(command > SERVO_MAX) {
        command = SERVO_MAX;
    } else if(command < SERVO_MIN) {
        command = SERVO_MIN;
    }
    
    myServo.write(command);
    
    return (command);
}
