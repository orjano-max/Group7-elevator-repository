
/*
   The moveElevator() function moves the elevator to the right floor
   and stops it
*/
void moveElevator()
{

  lcd.clear();
  lcd.print("Going to");
  lcd.setCursor(0, 1);
  lcd.print("Floor nr: ");
  lcd.print(goToFloor);

  motorSpeed = motorSpeedSet; // Set motor Speed to value from main

  motorDir = upOrDown(); // Set motor Direction

  Serial.println(motorDir);

  while (true) {

    cabinCall();
    floorCallUp();
    floorCallDown();
    driveMotor();
    LED();

    if (currentFloor == goToFloorUp && motorDir == 1 && goToFloor != goToFloorUp && goToFloorUp != 0)
    {
      LED();
      motorSpeed = 0;
      driveMotor();
      door();
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
    }

    if (currentFloor == goToFloorDown && motorDir == 0 && goToFloor != goToFloorDown && goToFloorDown != 0)
    {
      LED();
      motorSpeed = 0;
      driveMotor();
      door();
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


/*
   The upOrDown() function checks whether the elevator has to go up or down
*/
int upOrDown() {
  if (currentFloor < goToFloor) {
    return 1;
  }
  else {
    return 0;
  }
}


/*
   The driveMotor() turns the motor at speed set in main
   and in the given direction
*/
void driveMotor() {
  digitalWrite(phase, motorDir);
  analogWrite(enable, motorSpeed);
}
