/*
   The emergencyStop() function stops the motors at any time
   this is becaus the emergencyStopPin is an interrupt pin.
   request is set to 0.
   Reset elevator to go out of emergency
*/
void emergencyStop () {
  lcd.clear();
  lcd.print("EMERGENCY STOP!");
  lcd.setCursor(0,1);
  lcd.print("Press 'Reset'");

  //Set request to 0
  request = 0;

  //Stop Servo motor
  motorSpeed = 0;
  driveMotor();

  //Deactivate Step motor
  digitalWrite(stepperEnableA, LOW);
  digitalWrite(stepperEnableB, LOW);
  digitalWrite(stepperPhaseA, LOW);
  digitalWrite(stepperPhaseB, LOW);
  
  while(true){
    //Do nothing
    //Reset elevator to go out of emergency stop
  }
}
