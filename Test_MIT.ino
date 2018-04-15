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
        
    This program also processes a momentary pushbutton on pin D4.  It publishes a button press event
    to the Particle cloud, for testing mobile app notifications.
        
    When the program is successfully loaded and running, the D7 LED will flash with a 1 second period.
    
    Version 2.2, 4/15/2018; (c) 2017, 2018 Bob Glicksman and Team Practical Projects
        
*/

const int LED_PIN = D7;
const int INDICATOR_PIN = D5;
const int BUTTON_PIN = D4;
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
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    myServo.attach(SERVO_PIN);
    
    digitalWrite(LED_PIN, LOW);
    digitalWrite(INDICATOR_PIN, LOW);
    
    Particle.function("on-off", ledRemote);
    Particle.function("move", servoRemote);
    Particle.variable("message", message);
    
}

void loop() {

    static int messNum = 0;  // message number for testing publication
    
    blinkLED(BLINK_TIME);  // blink the D7 LED to say all is running OK
    
    // publish button press event with name and incrementing value < 12
    if(readPushButton() == true) {
        if (messNum > 10) {
            messNum = 0;
        } else {
            messNum++;
        }
        Particle.publish("Alert_Test", String(messNum), PRIVATE);
    }
    
    
}

void blinkLED(int time) {
    static bool ledState = false;
    static unsigned long lastTime = millis();
    
    if( diff(millis(), lastTime) >= time) {
        ledState = !ledState;
        lastTime = millis();
    }
    
    if(ledState == TRUE) {
        digitalWrite(LED_PIN, HIGH);
    } else {
        digitalWrite(LED_PIN, LOW);
    }
    
    return;
} // end of blinkLED

boolean readPushButton() {
    const unsigned long DEBOUNCE_TIME = 10;  // 10 milliseconds

    // state variable states
    const byte OFF = 0;
    const byte DEBOUNCING = 1;
    const byte DEBOUNCED = 2;

    static byte lastState = OFF;
    static unsigned long beginTime;

    if(digitalRead(BUTTON_PIN) == LOW) {  // button has been pressed
        switch (lastState) {
            case OFF:       // new button press
                beginTime = millis();
                lastState = DEBOUNCING;
                return false;
                break;
            case DEBOUNCING:    // wait until debouncing time is over
                if(diff(millis(), beginTime) < DEBOUNCE_TIME) {
                    return false;
                } else {
                    lastState = DEBOUNCED;
                    return true;
                }
                break;
            case DEBOUNCED:     // stay in this state until button is released
                return false;
                break;
            default:
                return false;
        }

    } else {        // the button has been released
        lastState = OFF;
        return false;
    }
}  // end of readPushButton


/* diff(): function to measure time differences using millis() that corrects for millis() overflow.
    paramters:
        current - the current time value from millis(), as unsigned long
        last - the previous time value from millis(), as unsigned long
    return:
        the difference between current and last, as unsigned long
*/
unsigned long diff(unsigned long current, unsigned long last)  {
    const unsigned long MAX = 0xffffffff;  // an unsigned long is 4 bytes
    unsigned long difference;

    if (current < last) {       // overflow condition
        difference = (MAX - last) + current;
    } else {
        difference = current - last;
    }
    return difference;
}  // end of diff()



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
