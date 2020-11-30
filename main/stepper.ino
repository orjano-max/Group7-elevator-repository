/*
  The Stepper function takes in number of steps and RPM and turns the stepMotor.
  It turns clockwise if it is told to go a positive number of steps, and counter-clockwise if it is told to go a negative number of steps.
  This function is made based on "Tabell 1.5: Eksempel for kjøring i fullstep" on page "C-15" in the "All In One Servo Lab report"
  This table describes how you can turn the motor in a fullstep configuration.
  In this configuration, the motor has a resolution of 200 steps per turn, but we do a stepsequence of 4 steps every time the motor turns.
  This means tha we, in reality, have a "resolution" of 50 steps per turn.
  The stepper RPM is set in main and this value is used to calculate the delay time between the steps.
  This function does not ramp the stepper motor which is not ideal, but we have tested it up to 60RPM and it works fine.
  Would not reccomend going over 60RPM as the motor might struggle to accellerate up to a high enough speed to follow the magnetic field.
*/
void stepper(int steps) {

  int timerStep = 60 / stepperRPM * 5;

  if (steps > 0)
  {
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
  else
  {
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
