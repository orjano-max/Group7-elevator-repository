
//Function that opens and closes door
void doorsOpenClose() {

  delay(500);  //Wait for 0.5sec before opening door

  //Prints "Opening doors" message
  Serial.println("Opening Doors");
  lcd.clear();
  lcd.print("Opening Doors");

  doorsOpen();    //Runs function that opens doors
  request = 0;    //Clear request when door is fully open
  delay(3000);   //Wait for 3sec before closing doors again (So that people can run out)

  //Prints "Closing doors" message
  Serial.println("Closing Doors");
  lcd.clear();
  lcd.print("Closing Doors");

  doorsClose();
}
