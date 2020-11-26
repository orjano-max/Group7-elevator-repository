void floorCallDown()
{

  if (button(4) == HIGH) {

    if (request == 0) {
      goToFloor = 2;
      request = 1;
      floorLED = 2;
      moveElevator(); //Move the motor
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
      moveElevator(); //Move the motor
      floorLED = 0;
      LED();
      Serial.println("At 3rd Floor");
      doorsOpenClose(); //Opening Doors
      idle();  //Going back to idle state
    }
  }
}
