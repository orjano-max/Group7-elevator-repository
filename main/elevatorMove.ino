/*
   The moveElevator() function moves the elevator to the right floor
   and stops it
*/
void elevatorMove()
{

  lcd.clear();
  lcd.print("Going to");
  lcd.setCursor(0, 1);
  lcd.print("Floor nr: ");
  lcd.print(goToFloor);

  motorSpeed = motorSpeedSet; // Set motor Speed to value from main

  // Set motor Direction
  if (currentFloor < goToFloor) {
    motorDir = 1;
  }
  else {
    motorDir = 0;
  }



  while (true) {

    callCabin();
    callFloorUp();
    callFloorDown();
    driveMotor();
    LED();

    if (currentFloor == goToFloorUp && motorDir == 1 && goToFloor != goToFloorUp && goToFloorUp != 0)
    {
      LED();
      motorSpeed = 0;
      driveMotor();
      doorsOpenClose();
      request = 1;

      delay(500);

      lcd.clear();
      lcd.print("Proceeding to");
      lcd.setCursor(0, 1);
      lcd.print("Floor: ");
      lcd.print(goToFloor);

      motorSpeed = motorSpeedSet;
      driveMotor();
      goToFloorUp = 0;
      floorLED = 0;
    }

    if (currentFloor == goToFloorDown && motorDir == 0 && goToFloor != goToFloorDown && goToFloorDown != 0)
    {
      LED();
      motorSpeed = 0;
      driveMotor();
      doorsOpenClose();
      request = 1;

      delay(500);

      lcd.clear();
      lcd.print("Proceeding to");
      lcd.setCursor(0, 1);
      lcd.print("Floor: ");
      lcd.print(goToFloor);

      motorSpeed = motorSpeedSet;
      driveMotor();
      goToFloorDown = 0;
      floorLED = 0;
    }

    if (currentFloor >= goToFloor && motorDir == 1 ) {
      break;
    }
    else if (currentFloor <= goToFloor && motorDir == 0) {
      break;
    }

  }

  // Stop motor
  LED();
  motorSpeed = 0;
  driveMotor();

}
