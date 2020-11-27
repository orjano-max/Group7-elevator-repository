/*
   The elevatorMove() function moves the elevator to the right floo and stops it.
   It also detects if there are requests to stop at second floor while moving,
   and stops if the direction is right.
   The servo motor simulates the elevator.
   Elevator moves UP with Clockwise rotation and DOWN with counter-clockwise rotation.
*/
void elevatorMove()
{
  // Prints "Going to" message
  lcd.clear();
  lcd.print("Going to");
  lcd.setCursor(0, 1);
  lcd.print("Floor nr: ");
  lcd.print(goToFloor);

  motorSpeed = motorSpeedSet; // Set motor Speed to value from main

  // If-statement that decides which direction to move
  if (currentFloor < goToFloor)
  {
    motorDir = 1; //motorDir 1 is UP
  }
  else
  {
    motorDir = 0; //motorDir 0 is DOWN
  }


  // Enters whileloop to turn servo motor
  while (true)
  {
    // Checks call functions for input while moving
    callCabin();
    callFloorUp();
    callFloorDown();

    driveMotor(); // Starts driveMotor() function to move elevator
    LED();        // Starts LED() function to update LEDs

    // If statement with several conditions that has to be met for elevator to stop while going UP
    if (currentFloor == goToFloorUp && motorDir == 1 && goToFloor != goToFloorUp && goToFloorUp != 0)
    {
      LED();  // Starts LED() function to update LEDs

      // Stops motor by setting motorspeed to 0 and runnig driveMotor() function
      motorSpeed = 0;
      driveMotor();

      doorsOpenClose(); // Starts doorsOpenClose() function
      request = 1;      // doorsOpenClose() sets request to 0, therefore, request has to be set to 1 again.

      delay(500); // Wait for 0.5sec before moving elevator again

      //Prints "Proceeding to" message
      lcd.clear();
      lcd.print("Proceeding to");
      lcd.setCursor(0, 1);
      lcd.print("Floor: ");
      lcd.print(goToFloor);

      // Starts motor again by setting motorspeed to speed set in main and runnig driveMotor() function
      motorSpeed = motorSpeedSet;
      driveMotor();

      goToFloorUp = 0; // Set goToFloorUP back to 0 again
      floorLED = 0;    // Set floorLED back to 0 again
    }



    // If statement with several conditions that has to be met for elevator to stop while going UP
    if (currentFloor == goToFloorDown && motorDir == 0 && goToFloor != goToFloorDown && goToFloorDown != 0)
    {
      LED();// Starts LED() function to update LEDs

      // Stops motor by setting motorspeed to 0 and runnig driveMotor() function
      motorSpeed = 0;
      driveMotor();

      doorsOpenClose(); // Starts doorsOpenClose() function
      request = 1;      // doorsOpenClose() sets request to 0, therefore, request has to be set to 1 again.

      delay(500);       // Wait for 0.5sec before moving elevator again

      //Prints "Proceeding to" message
      lcd.clear();
      lcd.print("Proceeding to");
      lcd.setCursor(0, 1);
      lcd.print("Floor: ");
      lcd.print(goToFloor);

      // Starts motor again by setting motorspeed to speed set in main and runnig driveMotor() function
      motorSpeed = motorSpeedSet;
      driveMotor();


      goToFloorDown = 0; // Set goToFloorUP back to 0 again
      floorLED = 0;      // Set floorLED back to 0 again
    }

    // if- and else if-statement that breaks loop if elevator has reached right floor
    if (currentFloor >= goToFloor && motorDir == 1 )
    {
      break;
    }
    else if (currentFloor <= goToFloor && motorDir == 0)
    {
      break;
    }

  }


  LED(); // Starts LED() function to update LEDs

  // Stops motor by setting motorspeed to 0 and runnig driveMotor() function
  motorSpeed = 0;
  driveMotor();

}
