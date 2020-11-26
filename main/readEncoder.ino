/*
   The readEncoder() function reads the encoder at any time
   because encPinB is sset up as an interrupt pin.
*/
void readEncoder () {

  if (digitalRead (encPinA)  ==  digitalRead (encPinB)) {
    encoderPosition --;
  }
  else if (digitalRead (encPinA) != digitalRead (encPinB)) {
    encoderPosition ++;
  }

  if (countsPerFloor > encoderPosition) {
    currentFloor = 0;
  }
  else if (countsPerFloor < encoderPosition && encoderPosition < countsPerFloor + (countsPerFloor / 10)) {
    currentFloor = 1;
  }
  else if (2 * countsPerFloor - (countsPerFloor / 20) < encoderPosition && encoderPosition < 2 * countsPerFloor + (countsPerFloor / 20)) {
    currentFloor = 2;
  }
  else if (3 * countsPerFloor - (countsPerFloor / 10) < encoderPosition && encoderPosition < 3 * countsPerFloor) {
    currentFloor = 3;
  }
  else if (3 * countsPerFloor <  encoderPosition) {
    currentFloor = 4;
  }
}
