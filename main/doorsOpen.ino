/*
   The doorsClose() function is used to close the doors.
   The stepper motor simulates the doors, it turns clockwise to open, and counter-clockwise to close.
   The joystick simulates "doors open" and "doors close" sensor(pull joystick to the left for close, and right for open).
   The stepper motor will turn until it gets feedback that it is open.
*/
void doorsOpen() 
{
  
  //Enters while loop to turn motor
  while (true) {

    stepper(1); //Starts stepper() function (input "1" will rotate motor 1 "step sequence" in clockwise rotation)

    
    doorPosition = analogRead(joyStick); // Reads door position

    //If statement that stops door when joystic x-axis potmeter is above threshold (simulating that doors are open)
    if (doorPosition >= 10)
    {
      break;
    }
    
  }

  // Prints "Doors Open" message
  Serial.println("Doors Open");
  lcd.clear();
  lcd.print("Doors Open");
}
