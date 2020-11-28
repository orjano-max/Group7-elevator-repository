/*
  The readEncoder() function reads the encoder at any time because encPinB is set up as an interrupt pin.
  The function starts at any time it detects a high input on the encB pin.
  The funftion decides which direction the servo motor is turning by checking if both inputs are HIGH at the same time.
  If encPinA is LOW the moment encPinB turns HIGH, servo turns counter-clockwise.
  If encPinB is HIGH the moment encPinB turns HIGH, servo turns clockwise.
*/
void readEncoder () {

  // If-statement and else-if statement that checks if encPinA is HIGH or LOW when encPinB turns HIGH.
  if (digitalRead (encPinA)  ==  digitalRead (encPinB))
  {
    encoderPosition --; // EncPinA is HIGH, counter-clockwise rotation, count down.
  }
  else if (digitalRead (encPinA) != digitalRead (encPinB))
  {
    encoderPosition ++; // EncPinA is LOW, clockwise rotation, count up.
  }

  // If- and else if-statements that checks the position of the encoder and
  // determines what floor the elevator's at.
  // Each floor has a tolerance of 1/10 the value of counts per floor.
  // if you want a slow moving elevator, you can turn down the "countsPeerFloor" variable to make the
  // gap between floors shrink, the tolerance will follow the speed as a slower elevator would coast less.
  if (countsPerFloor > encoderPosition)
  {
    currentFloor = 0; // currentFloor = 0 means that the elevator is under 1st floor, which shouldn't happen
  }
  else if (countsPerFloor < encoderPosition && encoderPosition < countsPerFloor + (countsPerFloor / 10))
  {
    currentFloor = 1;// Sets currentFloor to 1st floor
  }
  else if (2 * countsPerFloor - (countsPerFloor / 20) < encoderPosition && encoderPosition < 2 * countsPerFloor + (countsPerFloor / 20))
  {
    currentFloor = 2; // Sets currentFloor to 2nd
  }
  else if (3 * countsPerFloor - (countsPerFloor / 10) < encoderPosition && encoderPosition < 3 * countsPerFloor)
  {
    currentFloor = 3; // Sets currentFloor to 3rd
  }
  else if (3 * countsPerFloor <  encoderPosition)
  {
    currentFloor = 4; // currenFloor = 4 means that the elevator is above 3rd floor, which shouldnt happen
  }
}
