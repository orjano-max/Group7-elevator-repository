//Function that closes door
void doorsOpen() {
  while (true) {

    stepper(1); //Runs Stepper motor

    //Reads door position
    doorPosition = analogRead(joyStick);

    //Stops door when potmeter is above threshold (simulating that doors are open))
    if (doorPosition >= 10) {
      break;
    }
  }

  //Prints "Doors Open" message
  Serial.println("Doors Open");
  lcd.clear();
  lcd.print("Doors Open");
}
