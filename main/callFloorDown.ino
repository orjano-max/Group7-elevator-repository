/*
   The callFloorDown() function checks if the floor "down" buttons are
   pressed and starts the sequence of sending the elevator to the right floor.
   It also determines if the elevator is moving or not
   in order to determine how, or if ist should send the elevator to the floor that is requested.
   There is no real queuing trategy other than the ability to stop at second floor while moving.
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
      goToFloor = 2;
      request = 1;
      floorLED = 2;
      elevatorMove(); //Move the motor
      goToFloorDown = 0;
      floorLED = 0;
      LED();
      Serial.println("At 2nd Floor");
      doorsOpenClose(); //Opening Doors
      idle();  //Going back to idle state
    }
    else if (motorDir == 0 && request == 1 && goToFloor != 2) {
      goToFloorDown = 2;
      floorLED = 2;
      lcd.clear();
      lcd.print("Stopping at");
      lcd.setCursor(0, 1);
      lcd.print("Floor: ");
      lcd.print(goToFloorDown);
    }

  }

  else if (button(6) == HIGH) {
    if (request == 0)
    {
      request = 1;
      goToFloor = 3;
      floorLED = 4;
      elevatorMove(); //Move the motor
      floorLED = 0;
      LED();
      Serial.println("At 3rd Floor");
      doorsOpenClose(); //Opening Doors
      idle();  //Going back to idle state
    }
  }
}
