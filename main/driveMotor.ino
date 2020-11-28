/*
  The driveMotor() turns the motor at speed set in main and in the given direction.
  This function is made to make it easy to implement in the program where it is needed
  Set motorSpeed to 0 and run this function in order to stop motor
*/
void driveMotor() {
  digitalWrite(phase, motorDir);
  analogWrite(enable, motorSpeed);
}
