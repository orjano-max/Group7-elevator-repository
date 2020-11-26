

/*
   The cabinCall() function checks if the cabin buttons are
   pressed and starts the sequence
   of sending elevators to the right floor
*/

void cabinCall()
{

  if (Button(0) == HIGH)
  {
    if (request == 0) {
      request = 1;
      goToFloor = 1;
      moveElevator(); //Move the motor
      Serial.println("At 1st Floor");
      door(); //Opening Doors
      idle();  //Going back to idle state
    }
  }

  else if (Button(1) == HIGH)
  {
    if (request == 0)
    {
      request = 1;
      goToFloor = 2;
      moveElevator();
      Serial.println("At 2nd Floor");
      door(); //Opening Doors
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

  else if (Button(2) == HIGH)
  {
    if (request == 0)
    {
      request = 1;
      goToFloor = 3;
      moveElevator();
      Serial.println("At 3rd Floor");
      door(); //Opening Doors
      idle();  //Going back to idle state
    }
  }
}

void floorCallUp()
{
  if (Button(3) == HIGH) {
    if (request == 0) {
      request = 1;
      goToFloor = 1;
      floorLED = 1;
      moveElevator(); //Move the motor
      floorLED = 0;
      LED();
      Serial.println("At 1st Floor");
      door(); //Opening Doors
      idle();  //Going back to idle state
    }

  }
  else if (Button(5) == HIGH) {

    if (request == 0) {
      request = 1;
      goToFloor = 2;
      floorLED = 3;
      moveElevator(); //Move the motor
      goToFloorUp = 0;
      floorLED = 0;
      LED();
      Serial.println("At 2nd Floor");
      door(); //Opening Doors
      idle();  //Going back to idle state
    }

    else if (motorDir == 1 && request == 1 && goToFloor != 2) {
      goToFloorUp = 2;
      floorLED = 3;
      lcd.clear();
      lcd.print("Stopping at");
      lcd.setCursor(0, 1);
      lcd.print("Floor: ");
      lcd.print(goToFloorUp);
    }

  }
}


void floorCallDown()
{

  if (Button(4) == HIGH) {

    if (request == 0) {
      goToFloor = 2;
      request = 1;
      floorLED = 2;
      moveElevator(); //Move the motor
      goToFloorDown = 0;
      floorLED = 0;
      LED();
      Serial.println("At 2nd Floor");
      door(); //Opening Doors
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

  else if (Button(6) == HIGH) {
    if (request == 0)
    {
      request = 1;
      goToFloor = 3;
      floorLED = 4;
      moveElevator(); //Move the motor
      floorLED = 0;
      LED();
      Serial.println("At 3rd Floor");
      door(); //Opening Doors
      idle();  //Going back to idle state
    }
  }
}
