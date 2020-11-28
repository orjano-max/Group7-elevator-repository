/*
   The callFloorDown() function checks if the floor "down" buttons are
  pressed and starts the sequence of sending the elevator to the right floor.
  It also determines if the elevator is moving, and what direction it is moving.
  This is done in order to determine how, or if ist should send the elevator to the floor that is requested.
  There is no real queuing strategy other than the ability to stop at second floor while moving.
  Button(4) and button(6) is the floor "down" buttons on 2nd and 3rd floor
*/
void callFloorDown()
{
  // If button(4) is pressed
  if (button(4) == HIGH)
  {

    // If- and else if-statements that checks if elevator is reserved,
    // and which direction it travels if reserved, then decides what to do
    if (request == 0)
    {
      request = 1;                    // Reserves elevator
      goToFloor = 2;                  // Decides where to send elevator
      floorLED = 2;                   // Variable to make LED for this button to light up
      elevatorMove();                 // Starts elevatorMove() function
      floorLED = 0;                   // Resets floorLED variable to turn off LED
      LED();                          // Starts LeD() function
      Serial.println("At 2nd Floor"); // Prints to serial monitor
      doorsOpenClose();               // Starts doorsOpenClose() function
      idle();                         // Going back to idle state
    }
    else if (motorDir == 0 && request == 1 && goToFloor != 2)
    {
      goToFloorDown = 2; // Decides where to stop elevator
      floorLED = 2;      // Variable to make LED for this button to light up (reset in elevatorMove() function)

      // Displaying "Stopping" message
      lcd.clear();
      lcd.print("Stopping at");
      lcd.setCursor(0, 1);
      lcd.print("Floor: ");
      lcd.print(goToFloorDown);
    }

  }


  // If button(6) is pressed and elevator isnt reserved
  else if (button(6) == HIGH && request == 0)
  {
    request = 1;                    // Reserves elevator
    goToFloor = 3;                  // Decides where to send elevator
    floorLED = 4;                   // Variable to make LED for this button to light up
    elevatorMove();                 // Starts elevatorMove() function
    floorLED = 0;                   // Resets floorLED variable to turn off LED
    LED();                          // Starts LeD() function
    Serial.println("At 3rd Floor"); // Prints to serial monitor
    doorsOpenClose();               // Starts doorsOpenClose() function
    idle();                         //Going back to idle state
  }
}
