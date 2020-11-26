
/*
 * The Stepper function turns the stepper motor
 * a given number of steps.
 * The stepper RPM is set in main
 */
void stepper(int steps) {

  int timerStep = 60 / stepperRPM * 5;

  if (steps > 0) {
    for (int i = 0; i < steps ; i++)
    {
      //Clockwise rotation
      //step 1
      digitalWrite(stepperEnableA, HIGH);
      digitalWrite(stepperEnableB, HIGH);
      digitalWrite(stepperPhaseA, LOW);
      digitalWrite(stepperPhaseB, LOW);
      delay(timerStep);

      //Step 2
      digitalWrite(stepperEnableA, HIGH);
      digitalWrite(stepperEnableB, HIGH);
      digitalWrite(stepperPhaseA, LOW);
      digitalWrite(stepperPhaseB, HIGH);
      delay(timerStep);

      //Step 3
      digitalWrite(stepperEnableA, HIGH);
      digitalWrite(stepperEnableB, HIGH);
      digitalWrite(stepperPhaseA, HIGH);
      digitalWrite(stepperPhaseB, HIGH);
      delay(timerStep);

      //Step 4
      digitalWrite(stepperEnableA, HIGH);
      digitalWrite(stepperEnableB, HIGH);
      digitalWrite(stepperPhaseA, HIGH);
      digitalWrite(stepperPhaseB, LOW);
      delay(timerStep);
    }
  }
  else {
    for (int i = 0; i > steps ; i--)
    {
      //Counter-clockwise rotation
      //Step 1
      digitalWrite(stepperEnableA, HIGH);
      digitalWrite(stepperEnableB, HIGH);
      digitalWrite(stepperPhaseA, HIGH);
      digitalWrite(stepperPhaseB, LOW);
      delay(timerStep);

      //Step 2
      digitalWrite(stepperEnableA, HIGH);
      digitalWrite(stepperEnableB, HIGH);
      digitalWrite(stepperPhaseA, HIGH);
      digitalWrite(stepperPhaseB, HIGH);
      delay(timerStep);

      //Step 3
      digitalWrite(stepperEnableA, HIGH);
      digitalWrite(stepperEnableB, HIGH);
      digitalWrite(stepperPhaseA, LOW);
      digitalWrite(stepperPhaseB, HIGH);
      delay(timerStep);

      //step 4
      digitalWrite(stepperEnableA, HIGH);
      digitalWrite(stepperEnableB, HIGH);
      digitalWrite(stepperPhaseA, LOW);
      digitalWrite(stepperPhaseB, LOW);
      delay(timerStep);
    }
  }

  //Turn off steppmotor at end of sequence
  digitalWrite(stepperEnableA, LOW);
  digitalWrite(stepperEnableB, LOW);
  digitalWrite(stepperPhaseA, LOW);
  digitalWrite(stepperPhaseB, LOW);

}
