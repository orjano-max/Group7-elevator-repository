/*
   The doorsOpenClose() function makes an "open and close" door sequence to make it esay to implement when
   you want the cabin doors to open.
   It uses delay so that it doesnt open doors the same instance it reaches floors and so that people has time to exit
   elevator before they close.
   The stepper motor simulates the doors, it turns clockwise to open, and counter-clockwise to close.
   The joystick simulates "doors open" and "doors close" sensor(pull joystick to the left for close, and right for open).
   The stepper motor will turn until it gets feedback that it is closed/open.
*/
void doorsOpenClose() {

  delay(500);     //Waits for 0.5sec before opening door

  //Prints "Opening doors" message
  Serial.println("Opening Doors");
  lcd.clear();
  lcd.print("Opening Doors");

  doorsOpen();    //Runs doorsOpen() function
  request = 0;    //Clear request when door is fully open
  delay(3000);    //Wait for 3sec before closing doors again (So that people can run out)

  //Prints "Closing doors" message
  Serial.println("Closing Doors");
  lcd.clear();
  lcd.print("Closing Doors");

  doorsClose();   // Runs doorsClose() function
  
}
