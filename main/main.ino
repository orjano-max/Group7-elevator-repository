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
const int startPinIn = 22;       //Start pin for buttons
const int startPinOut = 42;      //Start pin for LEDs
const int joyStick = A1;         //Potmeter wiper
const int overloadSwitch = 22;   //Overload switch for doors(simulation)
const int emergencyStopPin = 2;  // Emergency stop

//Variables
int request = 0;                 //request variable for elevator
int goToFloorUp = 0;
int goToFloorDown = 0;
int currentFloor = 1;
int goToFloor = 1;
const int motorSpeedSet = 255;  //Used to determine value of motorSpeed when motor moves
int doorPosition = 0;           //Used to store door position value (from potWiper, simulate door position)
int floorLED = 0;               //Used to light up LED at floor if floor button is pushed

//Initializing stepper motor
#include <dac.h>
const int stepPerRev = 50;
const int stepperRPM = 60;
const int stepperEnableA = 69;
const int stepperEnableB = 67;
const int stepperPhaseA = 68;
const int stepperPhaseB = 66;

//Initializing servo motor
int enable = 7;
int phase = 6;
int decoy = 5;
int motorSpeed = 0; // Initial motor speed is 0
int motorDir = 1;   // Determines direction of motor, 1 is up and 0 is down

//Initializing encoder pins
const int encPinA = 20;
const int encPinB = 21;                          //Interrupt pin
int countsPerFloor = 10000;                      //Set amount of count encoder needs to move one floor
unsigned long encoderPosition = countsPerFloor;  //Initial encoder position, 1st floor is 1x of counts per floor




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
  attachInterrupt (digitalPinToInterrupt(encPinB), readEncoder, CHANGE); //Interrupt when encPinB is activated
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
