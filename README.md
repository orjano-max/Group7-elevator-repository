
# Group7-elevator-repository
This is the readme file describing the elevator code for group 7 in MAS220, fall 2020.
The group consists of the members: Ørjan Øvsthus, Dan Albrigtsen and Hipolit Edward Wilczek.
To open the program, use the Arduino IDE and open the "main.ino" file in the "main" folder. 
The other ".ino" files will show up as tabs in the Arduino IDE

The elavetor program contains descriptions and comments that describe how it is made.
All functions are divided into its own "tab", except for the initialization, setup() and loop(), these are gathered in the "main" tab.


The servo motor simulates the elevator and the stepper motor simulates the door.

The joystick x-axis simulates a "door sensor". the door wont stop turning before it gets feedback,
-x direction is closed and +x direction is open.


Button 0 under the LCD display simulates a "door overload" switch, which would become high if
for example someone gets their foor stuck in the door while it is closing


The LCD display shows different messages like current floor and where the elevator is heading.


The buttons under the LCD display, except button 0, are used to call the elevator.

Buttons 7-5 are the call buttons inside the cabin, where:
button 7 is 1st floor.
button 6 is 2nd floor.
button 5 is 3rd floor.

Buttons 4 and 2 are the "call UP" buttons on 1st and 2nd floor, where:
button 4 is 1st floor UP button.
button 2 is 2nd floor Up button.

Buttons 3 and 1 are the "call Down" buttons on 2nd and 3rd floow, where:
button 3 is 2nd floor UP button
button 1 is 3rd floor DOWN button.


THe elevator will stop at 2nd floor if it is called at second floor while moving from 1st to 3rd floor or from 3rd to 1st floor.
This will only happen if the direction for the call request is the same as the direction the elevator is moving.
For the elevator cabin buttons, this will allways be true, but not for the floor buttons.

The encoder "pushbutton" is used as an emergency stop. this stops the servo and steppermotor.
Use the "reset" button on the servo lab to reset. This will restart th program.




Overview of the different tabs in the program (this is the same text that you will find on the top of each tab in the program):


Main:

The main tab contains global variables, includes, setup() and loop().
This is where most input and output pins are initialized and where the setup of servo motor, stepper motor,
LCD display, encoder are initialized and set up.

Vaiables that affect the programs behaviour can be set here. Initialization of different components
are placed near each other and described in the program.
You can for example change the RPM of the steppermotor or the servo motor by manipulation the "stepperRPM"(stepper RPM)
and"motorSpeedSet"(servo RPM) variables, and the countsPerFloor variable for the encoder, sets the "spacing" between the floors.
Other variables and their purpose are well described in the program.

The Setup() loop contains setup for different components like the LCD display and Stepper motor.
This loop is well documented in the program.

The loop(), starts the program, sends it to idle() function.



LED:

The LED() function checks current floor, and lights up the right light indicating that floor
It also lights up an LED representing target floor.
If a button is pressed on a certain floor, this button lights up(example: the 2nd. floor Up button)



button:

The button() function, returns HIGH if a button is pressed.
This function is used to determine wich floor a button is pressed at
The button function also reveses the numberation for the buttons: button(0) in the program = button 7 in real life



callCabin:

The callCabin() function checks if the cabin buttons are pressed and starts the sequence of sending the
elevator to the right floor.
It also determines if the elevator is moving or not in order to determine how,
or if ist should send the elevator to the floor that is requested.
There is no real queuing trategy other than the ability to stop at second floor while moving.
Button(0)-button(2) is the cabin buttons.


callFloorDown:

The callFloorDown() function checks if the floor "down" buttons are
pressed and starts the sequence of sending the elevator to the right floor.
It also determines if the elevator is moving, and what direction it is moving.
This is done in order to determine how, or if ist should send the elevator to the floor that is requested.
There is no real queuing strategy other than the ability to stop at second floor while moving.
Button(4) and button(6) is the floor "down" buttons on 2nd and 3rd floor


callFloorUp:

The callFloorUp() function checks if the floor "up" buttons are
pressed and starts the sequence of sending the elevator to the right floor.
It also determines if the elevator is moving, and what direction it is moving.
This is done in order to determine how, or if ist should send the elevator to the floor that is requested.
There is no real queuing strategy other than the ability to stop at second floor while moving.
Button(3) and button(5) is the floor "up" buttons on 2nd and 3rd floor


doorsClose:

The doorsClose() function is used to close the doors.
It has a safety feature which makes it open the doors if an "overload switch" is pressed.
This "overload switch" is supposed to represent the for example a foot that gets stuck between the doors.
The overload switch is the button marked as "0" on the "All In One Servo lab".
The stepper motor simulates the doors, it turns clockwise to open, and counter-clockwise to close.
The joystick simulates "doors open" and "doors close" sensor(pull joystick to the left for close, and right for open).
The stepper motor will turn until it gets feedback that it is closed/open.


doorsOpen:

The doorsOpen() function is used to open the doors.
The stepper motor simulates the doors, it turns clockwise to open, and counter-clockwise to close.
The joystick simulates "doors open" and "doors close" sensor(pull joystick to the left for close, and right for open).
The stepper motor will turn until it gets feedback that it is open.


doorOpenClose:

The doorsOpenClose() function makes an "open and close" door sequence to make it esay to implement when you want the cabin doors to open.
It uses delay so that it doesnt open doors the same instance it reaches floors and so that people has time to exit elevator before they close.
The stepper motor simulates the doors, it turns clockwise to open, and counter-clockwise to close.
The joystick simulates "doors open" and "doors close" sensor(pull joystick to the left for close, and right for open).
The stepper motor will turn until it gets feedback that it is closed/open.


driveMotor:

The driveMotor() turns the motor at speed set in main and in the given direction.
This function is made to make it easy to implement in the program where it is needed
Set motorSpeed to 0 and run this function in order to stop motor


elevatorMove:

The elevatorMove() function moves the elevator to the right floo and stops it.
It also detects if there are requests to stop at second floor while moving, and stops if the direction is right.
The servo motor simulates the elevator.
Elevator moves UP with Clockwise rotation and DOWN with counter-clockwise rotation.


emergencyStop:

The emergencyStop() function stops the motors at any time.
This is because the emergencyStopPin is an interrupt pin.
Request is set to 0.
Reset the elevator with the "Reset" button to go out of emergency mode


idle:

The idle() function prints a message that the elevator is idle and runs the call funtions to check for requests.
It also has a feature that makes the elevator readjust itself if it is below 1st floor or above 3rd floor.


readEncoder:

The readEncoder() function reads the encoder at any time because encPinB is set up as an interrupt pin.
The function starts at any time it detects a high input on the encB pin.
The funftion decides which direction the servo motor is turning by checking if both inputs are HIGH at the same time.
If encPinA is LOW the moment encPinB turns HIGH, servo turns counter-clockwise.
If encPinB is HIGH the moment encPinB turns HIGH, servo turns clockwise.


stepper:

The Stepper function takes in number of steps and RPM and turns the stepMotor.
It turns clockwise if it is told to go a positive number of steps, and counter-clockwise if it is told to go a negative number of steps.
This function is made based on "Tabell 1.5: Eksempel for kjøring i fullstep" on page "C-15" in the "All In One Servo Lab report"
This table describes how you can turn the motor in a fullstep configuration.
In this configuration, the motor has a resolution of 200 steps per turn, but we do a stepsequence of 4 steps every time the motor turns.
This means tha we, in reality, have a "resolution" of 50 steps per turn.
The stepper RPM is set in main and this value is used to calculate the delay time between the steps.
This function does not ramp the stepper motor which is not ideal, but we have tested it up to 60RPM and it works fine.
Would not reccomend going over 60RPM as the motor might struggle to accellerate up to a high enough speed to follow the magnetic field.