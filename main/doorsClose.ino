/*
   The doorsClose() function is used to close the doors.
   It has a safety feature which makes it open the doors if an "overload switch" is pressed.
   This "overload switch" is supposed to represent the for example a foot that gets stuck between the doors.
   The overload switch is the button marked as "0" on the "All In One Servo lab".
   The stepper motor simulates the doors, it turns clockwise to open, and counter-clockwise to close.
   The joystick simulates "doors open" and "doors close" sensor(pull joystick to the left for close, and right for open).
   The stepper motor will turn until it gets feedback that it is closed/open.
*/
void doorsClose()
{

  //Enters while loop to turn motor
  while (true)
  {
    stepper(-1); //Starts stepper() function (input "-1" will rotate motor 1 "step sequence" in counter-clockwise rotation)

    // If statement that opens up the doors again if overload switch is triggered
    if (digitalRead(overloadSwitch) == HIGH) {

      //Prints overload message
      lcd.clear();
      lcd.print("Overload!!");
      lcd.setCursor(0, 1);
      lcd.print("Opening Doors");

      doorsOpen(); //Runs the openDoors() function
      delay(2000); //Waits for 2 seconds before trying to close doors again

      //Prints "Closing Doors" message
      lcd.clear();
      lcd.print("Closing Doors");
    }

    doorPosition = analogRead(joyStick); // Reads door position


    //If statement that stops door when joystic x-axis potmeter is below threshold (simulating that doors are open)
    if (doorPosition < 1)
    {
      break;
    }

  }

  // Prints "Doors Closed" message
  Serial.println("Doors Closed");
  lcd.clear();
  lcd.print("Doors Closed");
}
