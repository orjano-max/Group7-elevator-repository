/*
   The upOrDown() function checks whether the elevator has to go up or down.
   Up is clockwise rotation, down is counter-clockwise rotation
*/

int upOrDown() {
  if (currentFloor < goToFloor) {
    return 1;
  }
  else {
    return 0;
  }
}
