/*
   The LED() function checks current floor, and lights up the right light indicating that floor
   It also lights up an LED representing target floor.
   If a button is pressed on a certain floor, this button lights up(like the 2nd. floor Up button)
*/

void LED() {

  //If- and else if-statements that ligths up LED for current floor
  if (currentFloor == 1) 
  {
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
  

  // If-statement that lights up led of floor the target floor(where the elevator is going)
  if (request == 1)
  {
    digitalWrite(41 + goToFloor, HIGH);
  } 

  
  // If-statement that lights up light in cabin if there is request to stop at a floor while moving UP
  if (motorDir == 1 && request == 1 && goToFloorUp != goToFloor) 
  {
    digitalWrite(41+goToFloorUp, HIGH);
  }


  //If statement that lights up light in cabin if there i request to stop at a floor while moving DOWN
  if (motorDir == 0 && request == 1 && goToFloorDown != goToFloor) 
  {
    digitalWrite(41+goToFloorDown, HIGH);
  }

  
  //If-statement that lights up an LED on floor that requests elevator UP
  if (request == 1 && floorLED != 0 && goToFloorUp == 0) {
    digitalWrite(44 + floorLED, HIGH);
    
  }

  
  //If-statement that lights up an LED on floor that requests elevator DOWN
  if (request == 1 && floorLED != 0 && goToFloorDown == 0) 
  {
    digitalWrite(44 + floorLED, HIGH);
  }

}
