/*
   The emergencyStop() function stops the motors at any time.
   This is because the emergencyStopPin is an interrupt pin.
   Request is set to 0.
   Reset the elevator with the "Reset" button to go out of emergency mode
*/
void emergencyStop ()
{
  // Prints "EMERGENCY STOP" message
  lcd.clear();
  lcd.print("EMERGENCY STOP!");
  lcd.setCursor(0, 1);
  lcd.print("Press 'Reset'");

  request = 0; //Set request to 0

  // Stops servo motor by setting motorspeed to 0 and runnig driveMotor() function
  motorSpeed = 0;
  driveMotor();

  //Deactivate Step motor by turning off phases and enable
  digitalWrite(stepperEnableA, LOW);
  digitalWrite(stepperEnableB, LOW);
  digitalWrite(stepperPhaseA, LOW);
  digitalWrite(stepperPhaseB, LOW);

  // Go into while loop
  while (true)
  {
    //Do nothing
    //Reset elevator to go out of emergency stop
  }
  
}
