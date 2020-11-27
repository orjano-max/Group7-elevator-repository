/*
   The callCabin() function checks if the cabin buttons are
   pressed and starts the sequence of sending the
   elevator to the right floor.
   It also determines if the elevator is moving or not
   in order to determine how, or if ist should send the elevator to the floor that is requested.
   There is no real queuing trategy other than the ability to stop at second floor while moving.
   Button(0)-button(2) is the cabin buttons
*/

void callCabin()
{

  // If button(0) is pressed:
  if (button(0) == HIGH)
  {

    // Checks if elevator is reserved
    if (request == 0)
    {
      request = 1;                     // Reserves elevator
      goToFloor = 1;                   // Decides where to send elevator
      elevatorMove();                  // Starts elevatorMove() function
      Serial.println("At 1st Floor");  // Prints to serial monitor
      doorsOpenClose();                // Starts doorsOpenClose() function
      idle();                          // Going back to idle state
    }

  }


  // If button(1) is pressed:
  else if (button(1) == HIGH)
  {

    // If- and else if-statements that checks if elevator is reserved,
    // and which direction it travels if reserved, then decides what to do
    if (request == 0)
    {
      request = 1;                    // Reserves elevator
      goToFloor = 2;                  // Decides where to send elevator
      elevatorMove();                 // Starts elevatorMove() function
      Serial.println("At 2nd Floor"); // Prints to serial monitor
      doorsOpenClose();               // Starts doorsOpenClose() function
      idle();                         // Going back to idle state
    }
    else if (motorDir == 1 && request == 1 && goToFloor != 2)
    {
      goToFloorUp = 2;           // Decides where to send elevator
      LED();                     // Starts LED() function to light up LED

      // Displaying "Stopping" message
      lcd.clear();
      lcd.print("Stopping at");
      lcd.setCursor(0, 1);
      lcd.print("Floor: ");
      lcd.print(goToFloorUp);
    }
    else if (motorDir == 0 && request == 1 && goToFloor != 2)
    {
      goToFloorDown = 2;        // Decides where to send elevator
      LED();                    // Starts LED() function to light up LED

      //Displaying "Stopping" message
      lcd.clear();
      lcd.print("Stopping at");
      lcd.setCursor(0, 1);
      lcd.print("Floor: ");
      lcd.print(goToFloorDown);
    }

  }


  //If button(2) is pressed and elevator isnt reserved:
  else if (button(2) == HIGH && request == 0)
  {

    request = 1;                    // Reserves elevator
    goToFloor = 3;                  // Decides where to send elevator
    elevatorMove();                 // Starts elevatorMove() function
    Serial.println("At 3rd Floor"); // Prints message to serial monitor
    doorsOpenClose();               // Starts doorsOpenClose function
    idle();                         // Going back to idle state

  }

}
