

/*
   The cabinCall() function checks if the cabin buttons are
   pressed and starts the sequence
   of sending elevators to the right floor
*/

void cabinCall()
{

  if (button(0) == HIGH)
  {
    if (request == 0) {
      request = 1;
      goToFloor = 1;
      moveElevator(); //Move the motor
      Serial.println("At 1st Floor");
      doorsOpenClose(); //Opening Doors
      idle();  //Going back to idle state
    }
  }

  else if (button(1) == HIGH)
  {
    if (request == 0)
    {
      request = 1;
      goToFloor = 2;
      moveElevator();
      Serial.println("At 2nd Floor");
      doorsOpenClose(); //Opening Doors
      idle();  //Going back to idle state
    }
    else if (motorDir == 1 && request == 1 && goToFloor != 2)
    {
      goToFloorUp = 2;
      LED();
      lcd.clear();
      lcd.print("Stopping at");
      lcd.setCursor(0, 1);
      lcd.print("Floor: ");
      lcd.print(goToFloorUp);
    }
    else if (motorDir == 0 && request == 1 && goToFloor != 2)
    {
      goToFloorDown = 2;
      LED();
      lcd.clear();
      lcd.print("Stopping at");
      lcd.setCursor(0, 1);
      lcd.print("Floor: ");
      lcd.print(goToFloorDown);
    }
  }

  else if (button(2) == HIGH)
  {
    if (request == 0)
    {
      request = 1;
      goToFloor = 3;
      moveElevator();
      Serial.println("At 3rd Floor");
      doorsOpenClose(); //Opening Doors
      idle();  //Going back to idle state
    }
  }
}
