void floorCallUp()
{
  if (button(3) == HIGH) {
    if (request == 0) {
      request = 1;
      goToFloor = 1;
      floorLED = 1;
      moveElevator(); //Move the motor
      floorLED = 0;
      LED();
      Serial.println("At 1st Floor");
      doorsOpenClose(); //Opening Doors
      idle();  //Going back to idle state
    }

  }
  else if (button(5) == HIGH) {

    if (request == 0) {
      request = 1;
      goToFloor = 2;
      floorLED = 3;
      moveElevator(); //Move the motor
      goToFloorUp = 0;
      floorLED = 0;
      LED();
      Serial.println("At 2nd Floor");
      doorsOpenClose(); //Opening Doors
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
