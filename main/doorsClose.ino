//Function that closes the doors
void doorsClose() {
  while (true) {

    stepper(-1); //Runs the stepper motor

    // If statement tha opens up the doors again if overload switch is triggered
    if (digitalRead(overloadSwitch) == HIGH) {

      //Prints overload message
      lcd.clear();
      lcd.print("Overload!!");
      lcd.setCursor(0, 1);
      lcd.print("Opening Doors");

      doorsOpen(); //Runs the openDoors function

      //Waits for 2 seconds before trying to close doors again
      delay(2000);

      //Prints "Closing Doors" message
      lcd.clear();
      lcd.print("Closing Doors");
    }

    doorPosition = analogRead(joyStick);


    //If statement that stops door when potmeter is below threshold (simulating that doors are open)
    if (doorPosition < 1) {
      break;
    }
  }

  // Prints "Doors Closed" message
  Serial.println("Doors Closed");
  lcd.clear();
  lcd.print("Doors Closed");
}
