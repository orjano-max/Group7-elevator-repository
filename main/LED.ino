
// Function that sets LEDs based on currentFloor and goToFloor
void LED () {

  //if and else if statements that ligths up LED for current floor
  if (currentFloor == 1) {
    digitalWrite(42, HIGH);
    digitalWrite(43, LOW);
    digitalWrite(44, LOW);
    digitalWrite(45, LOW);
    digitalWrite(46, LOW);
    digitalWrite(47, LOW);
    digitalWrite(48, LOW);
    digitalWrite(49, LOW);
  }
  else if (currentFloor == 2) {
    digitalWrite(42, LOW);
    digitalWrite(43, HIGH);
    digitalWrite(44, LOW);
    digitalWrite(45, LOW);
    digitalWrite(46, LOW);
    digitalWrite(47, LOW);
    digitalWrite(48, LOW);
    digitalWrite(49, LOW);
  }
  else if (currentFloor == 3) {
    digitalWrite(42, LOW);
    digitalWrite(43, LOW);
    digitalWrite(44, HIGH);
    digitalWrite(45, LOW);
    digitalWrite(46, LOW);
    digitalWrite(47, LOW);
    digitalWrite(48, LOW);
    digitalWrite(49, LOW);
  }
  else if (currentFloor == 4) {
    digitalWrite(42, LOW);
    digitalWrite(43, LOW);
    digitalWrite(44, LOW);
    digitalWrite(45, HIGH);
    digitalWrite(46, LOW);
    digitalWrite(47, LOW);
    digitalWrite(48, LOW);
    digitalWrite(49, LOW);
  }
  else if (currentFloor == 5)
  {
    digitalWrite(42, LOW);
    digitalWrite(43, LOW);
    digitalWrite(44, LOW);
    digitalWrite(45, LOW);
    digitalWrite(46, HIGH);
    digitalWrite(47, LOW);
    digitalWrite(48, LOW);
    digitalWrite(49, LOW);
  }


  //if statement that lights up led of floor the elevator are supposed to go to
  if (request == 1)
  {
    digitalWrite(41 + goToFloor, HIGH);
  } 
  
  //If statement tha lights up light in cabin if there i request to stop at a floor while moving up
  if (motorDir == 1 && request == 1 && goToFloorUp != goToFloor) 
  {
    digitalWrite(41+goToFloorUp, HIGH);
  }

  //If statement tha lights up light in cabin if there i request to stop at a floor while moving down
  if (motorDir == 0 && request == 1 && goToFloorDown != goToFloor) 
  {
    digitalWrite(41+goToFloorDown, HIGH);
  }
  
  //If statement tha lights up an LED on floor that requests elevator Up
  if (request == 1 && floorLED != 0 && goToFloorUp == 0) {
    digitalWrite(44 + floorLED, HIGH);
  }
  //If statement tha lights up an LED on floor that requests elevator Down
  if (request == 1 && floorLED != 0 && goToFloorDown == 0) {
    digitalWrite(44 + floorLED, HIGH);
  }

}
