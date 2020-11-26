
/*
   The driveMotor() turns the motor at speed set in main
   and in the given direction
*/
void driveMotor() {
  digitalWrite(phase, motorDir);
  analogWrite(enable, motorSpeed);
}
