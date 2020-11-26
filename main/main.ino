/*
   This is the elevator program for Group 7 in MAS220, Fall 2020
   the group consists of the members: Ørjan Øvsthus, Dan Albrigtsen and Hipolit Edward Wilczek.
   the main tab contains global variables and includes, setup() and loop().
*/

//Initializing LCD Display
#include <LiquidCrystal.h>
const int rs = 41, en = 40, d4 = 37, d5 = 36, d6 = 35, d7 = 34;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Initializing pins
const int startPinIn = 22;       // Start pin for buttons (except for emergency stop)
const int emergencyStopPin = 2;  // Emergency stop pin
const int startPinOut = 42;      // Start pin for outputs
const int joyStick = A1;         // Joystick x-axis
const int overloadSwitch = 22;   // Overload switch for doors(simulation)


//Variables
int request = 0;         // used to know if the elevator has a request
int goToFloorUp = 0;     // used to stop at 2nd floor when going up
int goToFloorDown = 0;   // used to stop at 2nd floor when going down
int currentFloor = 1;    // used to determine current floor, initial floor is 1st floor
int goToFloor = 1;       // used to determine wich floor elevator has to go to
int doorPosition = 0;    // Used to store door position value (from potWiper, simulate door position)
int floorLED = 0;        // Used to light up LED at floor if floor button is pushed

//Initializing stepper motor
#include <dac.h>           // Library to set amount of current on each phase
const int stepPerRev = 50; // Amount of "step sequences" per revolution, not currently in use, but can be used to turn stepper 1 rotation
const int stepperRPM = 60; // Set RPM for stepper motor
//Stepper motor pins:
const int stepperEnableA = 69;
const int stepperEnableB = 67;
const int stepperPhaseA = 68;
const int stepperPhaseB = 66;

//Initializing servo motor
const int motorSpeedSet = 255; // Used to determine speed of the motor when it moves
int motorSpeed = 0;            // Initial motor speed is 0
int motorDir = 1;              // Determines direction of motor, 1 is up and 0 is down
//Servo motor pins:
int enable = 7;
int phase = 6;
int decoy = 5;

//Initializing encoder
int countsPerFloor = 10000;                      //Set amount of counts encoder needs to move one floor
unsigned long encoderPosition = countsPerFloor;  //Initial encoder position, 1st floor is 1x of counts per floor
//Encoder pins:
const int encPinA = 20;
const int encPinB = 21;                          //Interrupt pin



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
  dac_init();           // Initiate dac library
  set_dac(4095 , 4095); // Allow 1A per motor phase

  //Setup for encoder
  attachInterrupt (digitalPinToInterrupt(encPinB), readEncoder, CHANGE); //Interrupt when encPinB is activated
  pinMode (encPinA, INPUT);
  pinMode (encPinB, INPUT);

  // Initializing emergency stop pin
  attachInterrupt (digitalPinToInterrupt(emergencyStopPin), emergencyStop, CHANGE); //Interrupt when emergencyStopPin is activated
  pinMode(emergencyStopPin, INPUT);

  // Intitializing output pins in for loop
  for (int outDef = startPinOut; outDef < 70; outDef++)
  {
    pinMode(outDef, OUTPUT);
  }
  
  // Intitializing input pins in for loop
  for (int inDef = startPinIn; inDef < 29; inDef++)
  {
    pinMode(inDef, INPUT);
  }

}


void loop() {

  idle(); //Start system, go to idle

}
