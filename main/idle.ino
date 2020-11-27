/*
   The idle() function prints a message that the elevator is idle
   and runs the call funtions to check for requests.
   It also has a feature that makes the elevator readjust itself if it is below 1st floor or above 3rd floor
*/
void idle()
{
  // If- statement that checks if there is any requests
  // won't print message if there is pending requests
  // Prints message if request is 0
  if (request == 0)
  {
    // Prints "EMERGENCY STOP" message
    Serial.println("Idle, waiting for input");
    lcd.clear();
    lcd.print("Idle");
    lcd.setCursor(0, 1);
    lcd.print("Current Floor: ");
    lcd.setCursor(15, 1);
  }

  // Whole loop to check for inputs while there are no requests
  while (request == 0)
  {
    //Wait for input
    callCabin();
    callFloorUp();
    callFloorDown();

    // Prints floor number on LCD. In while loop so that it is continuously updated
    lcd.print(" ");
    lcd.setCursor(15, 1);
    lcd.print(currentFloor);
    delay(50); // Display had low refresh rate, 50millisecond delay to stop display "flickering"

    LED();     // Starts LED() function to update LEDs

    // If-statement that checks if elevator is below 1st floor, prints warning message
    // and moves the elevator up to 1st floor again
    if (currentFloor < 1)
    {
      //Prints "Elevator under 1st floor!!" message
      lcd.clear();
      lcd.print("Elevator under");
      lcd.setCursor(0, 1);
      lcd.print("1st Floor!!");

      // While loop that moves elevator up while under 1st floor
      while (currentFloor < 1)
      {
        // Makes servo motor "Creep" UP by setting motorDir to 1,
        // motorspeed to 50 and runnig driveMotor() function
        motorDir = 1;
        motorSpeed = 50;
        driveMotor();
      }

      // Stops servo motor after jumping out of while-loop
      // by setting motorspeed to 0 and runnig driveMotor() function
      motorSpeed = 0;
      driveMotor();

      // Prints "Idle" message again, since this message is originally
      // printed outside the while-loop
      // This message is inside the if statement to prevent display "flickering"
      lcd.clear();
      lcd.print("Idle");
      lcd.setCursor(0, 1);
      lcd.print("Current Floor: ");
      lcd.setCursor(15, 1);
    }


    // If-statement that checks if elevator is above 3rd floor, prints warning message
    // and moves the elevator down to 3rd floor again
    if (currentFloor > 3)
    {
      //Prints "Elevator above 3rd floor!!" message
      lcd.clear();
      lcd.print("Elevator above");
      lcd.setCursor(0, 1);
      lcd.print("3rd Floor!!");

      // While loop that moves elevator down while above 3rd floor
      while (currentFloor > 3)
      {
        // Makes servo motor "Creep" DOWN by setting motorDir to 0,
        // motorspeed to 50 and runnig driveMotor() function
        motorDir = 0;
        motorSpeed = 50;
        driveMotor();
      }

      // Stops servo motor after jumping out of while-loop
      // by setting motorspeed to 0 and runnig driveMotor() function
      motorSpeed = 0;
      driveMotor();

      // Prints "Idle" message again, since this message is originally
      // printed outside the while-loop
      // This message is inside the if statement to prevent display "flickering"
      lcd.clear();
      lcd.print("Idle");
      lcd.setCursor(0, 1);
      lcd.print("Current Floor: ");
      lcd.setCursor(15, 1);
    }

  }
  
}
