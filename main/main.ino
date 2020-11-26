/*
   This is the elevator program for Group 7 in MAS220, Fall 2020
   the group consists of the members: Ørjan Øvsthus, Dan Albrigtsen and Hipolit Edward Wilczek.

*/
//Initializing LCD Display
#include <LiquidCrystal.h>
const int rs = 41, en = 40, d4 = 37, d5 = 36, d6 = 35, d7 = 34;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Initializing pins
const int startPinIn = 22;       //Start pin for buttons
const int startPinOut = 42;      //Start pin for LEDs
const int joyStick = A1;         //Potmeter wiper
const int overloadSwitch = 22;   //Overload switch for doors(simulation)
const int emergencyStopPin = 2;  // Emergency stop

//Variables
int request = 0;     //request variable, elevator
int goToFloorUp = 0;
int goToFloorDown = 0;
int currentFloor = 1;
int goToFloor = 1;
const int motorSpeedSet = 255;  //Used to determine value of motorSpeed when motor moves
int doorPosition = 0;           //Used to store door position value (from potWiper, simulate door position)
int floorLED = 0;               //Used to light up LED at floor if floor button is pushed

//Initializing step motor
#include <dac.h>
const int stepPerRev = 50;
const int stepperRPM = 60;
const int stepperEnableA = 69;
const int stepperEnableB = 67;
const int stepperPhaseA = 68;
const int stepperPhaseB = 66;

//Initialize servo motor
int enable = 7;
int phase = 6;
int decoy = 5;
int motorSpeed = 0; // Initial motor speed is 0
int motorDir = 1;   // Determines direction of motor, 1 is up and 0 is down

//Initializing encoder pins
const int encPinA = 20;
const int encPinB = 21;                          //Interrupt pin
int countsPerFloor = 10000;                      //Set amount of count encoder needs to move one floor
unsigned long encoderPosition = countsPerFloor; //Initial encoder position, 1st floor is 1x of counts per floor




void setup() {

  Serial.begin(9600); //Begin serial communication

  //Setup for LCD display
  lcd.begin(16, 2);    // Sets up the LCD's number of columns and rows
  analogWrite(4, 200);  // Set brigthness of display.

  //Setup for Servo motor
  pinMode(enable, OUTPUT);
  pinMode(phase, OUTPUT);
  pinMode(decoy, OUTPUT);
  digitalWrite(decoy, LOW);

  //Setup for Stepper motor
  dac_init();
  set_dac(4095 , 4095); // Allow 1A per motor phase

  //Setup for encoder
  attachInterrupt (digitalPinToInterrupt(encPinB), ReadEncoder, CHANGE); //Interrupt when encPinB is activated
  pinMode (encPinA, INPUT);
  pinMode (encPinB, INPUT);

  // Initializing emergency stop pin
  attachInterrupt (digitalPinToInterrupt(emergencyStopPin), emergencyStop, CHANGE); //Interrupt when emergency is activated
  pinMode(emergencyStopPin, INPUT);

  // Intitializing input and output pins in for loops
  for (int outDef = startPinOut; outDef < 70; outDef++) {
    pinMode(outDef, OUTPUT);
  }
  for (int inDef = startPinIn; inDef < 29; inDef++) {
    pinMode(inDef, INPUT);
  }

}




void loop() {

  idle(); //Start system, go to idle

}

/*
   The emergencyStop() function stops the motors at any time
   this is becaus the emergencyStopPin is an interrupt pin.
   request is set to 0.
   Reset elevator to go out of emergency
*/
void emergencyStop () {
  lcd.clear();
  lcd.print("EMERGENCY STOP!");
  lcd.setCursor(0,1);
  lcd.print("Press 'Reset'");

  //Set request to 0
  request = 0;

  //Stop Servo motor
  motorSpeed = 0;
  driveMotor();

  //Deactivate Step motor
  digitalWrite(stepperEnableA, LOW);
  digitalWrite(stepperEnableB, LOW);
  digitalWrite(stepperPhaseA, LOW);
  digitalWrite(stepperPhaseB, LOW);
  
  while(true){
    //Do nothing
    //Reset elevator to go out of emergency stop
  }
}



/*
   The readEncoder() function reads the encoder at any time
   because encPinB is sset up as an interrupt pin.
*/
void ReadEncoder () {

  if (digitalRead (encPinA)  ==  digitalRead (encPinB)) {
    encoderPosition --;
  }
  else if (digitalRead (encPinA) != digitalRead (encPinB)) {
    encoderPosition ++;
  }

  if (countsPerFloor > encoderPosition) {
    currentFloor = 0;
  }
  else if (countsPerFloor < encoderPosition && encoderPosition < countsPerFloor + (countsPerFloor / 10)) {
    currentFloor = 1;
  }
  else if (2 * countsPerFloor - (countsPerFloor / 20) < encoderPosition && encoderPosition < 2 * countsPerFloor + (countsPerFloor / 20)) {
    currentFloor = 2;
  }
  else if (3 * countsPerFloor - (countsPerFloor / 10) < encoderPosition && encoderPosition < 3 * countsPerFloor) {
    currentFloor = 3;
  }
  else if (3 * countsPerFloor <  encoderPosition) {
    currentFloor = 4;
  }


}
