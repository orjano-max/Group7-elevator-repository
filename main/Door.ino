
//Function that opens and closes door
void door() {

  delay(500);  //Wait for 0.5sec before opening door

  //Prints "Opening doors" message
  Serial.println("Opening Doors");
  lcd.clear();
  lcd.print("Opening Doors");

  openDoors();    //Runs function that opens doors
  request = 0;    //Clear request when door is fully open
  delay(3000);   //Wait for 3sec before closing doors again (So that people can run out)

  //Prints "Closing doors" message
  Serial.println("Closing Doors");
  lcd.clear();
  lcd.print("Closing Doors");

  closeDoors();
}


//Function that closes door
void openDoors() {
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



//Function that closes the doors
void closeDoors() {
  while (true) {

    stepper(-1); //Runs the stepper motor

    // If statement tha opens up the doors again if overload switch is triggered
    if (digitalRead(overloadSwitch) == HIGH) {

      //Prints overload message
      lcd.clear();
      lcd.print("Overload!!");
      lcd.setCursor(0, 1);
      lcd.print("Opening Doors");

      openDoors(); //Runs the openDoors function

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
