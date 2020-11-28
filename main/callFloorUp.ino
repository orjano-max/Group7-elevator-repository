/*
   The callFloorUp() function checks if the floor "up" buttons are
  pressed and starts the sequence of sending the elevator to the right floor.
  It also determines if the elevator is moving, and what direction it is moving.
  This is done in order to determine how, or if ist should send the elevator to the floor that is requested.
  There is no real queuing strategy other than the ability to stop at second floor while moving.
  Button(3) and button(5) is the floor "up" buttons on 2nd and 3rd floor
*/
void callFloorUp()
{
  // If button(3) is pressed and elevator isnt reserved
  if (button(3) == HIGH && request == 0)
  {
    request = 1;                    // Reserves elevator
    goToFloor = 1;                  // Decides where to send elevator
    floorLED = 1;                   // Variable to make LED for this button to light up
    elevatorMove();                 // Starts elevatorMove() function
    floorLED = 0;                   // Resets floorLED variable to turn off LED
    LED();                          // Starts LeD() function
    Serial.println("At 1st Floor"); // Prints to serial monitor
    doorsOpenClose();               // Starts doorsOpenClose() function
    idle();                         // Going back to idle state
  }


  // If button(5) is pressed
  else if (button(5) == HIGH) {


    // If- and else if-statements that checks if elevator is reserved,
    // and which direction it travels if reserved, then decides what to do
    if (request == 0)
    {
      request = 1;                    // Reserves elevator
      goToFloor = 2;                  // Decides where to send elevator
      floorLED = 3;                   // Variable to make LED for this button to light up
      elevatorMove();                 // Starts elevatorMove() function
      floorLED = 0;                   // Resets floorLED variable to turn off LED
      LED();                          // Starts LeD() function
      Serial.println("At 2nd Floor"); // Prints to serial monitor
      doorsOpenClose();               // Starts doorsOpenClose() function
      idle();                         // Going back to idle state
    }
    else if (motorDir == 1 && request == 1 && goToFloor != 2)
    {
      goToFloorUp = 2; // Decides where to send elevator
      floorLED = 3;    // Variable to make LED for this button to light up

      // Displaying "Stopping" message
      lcd.clear();
      lcd.print("Stopping at");
      lcd.setCursor(0, 1);
      lcd.print("Floor: ");
      lcd.print(goToFloorUp);
    }

  }
}
