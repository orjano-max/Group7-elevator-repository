
/*
   The idle() function prints a message that the elevator is idle
   and runs the call funtion to check for inputs
*/
void idle()
{
  Serial.println(request);
  if (request == 0) {

    Serial.println("Idle, waiting for input");
    lcd.clear();
    lcd.print("Idle");
    lcd.setCursor(0, 1);
    lcd.print("Current Floor: ");
    lcd.setCursor(15, 1);


  }

  while (request == 0) {
    //Wait for input
    cabinCall();
    floorCallUp();
    floorCallDown();

    lcd.print(" ");
    lcd.setCursor(15, 1);
    lcd.print(currentFloor);
    LED();
    delay(50);  //Delay to stop screen flickering

    if (currentFloor < 1)
    {
      lcd.clear();
      lcd.print("Elevator under");
      lcd.setCursor(0, 1);
      lcd.print("1st Floor!!");
      
      while (currentFloor < 1) {
        motorDir = 1;
        motorSpeed = 50;
        driveMotor();  
      }

      motorSpeed = 0;
      driveMotor();
      
      lcd.clear();
      lcd.print("Idle");
      lcd.setCursor(0, 1);
      lcd.print("Current Floor: ");
      lcd.setCursor(15, 1);
    }
    
    
    if (currentFloor > 3) {
      lcd.clear();
      lcd.print("Elevator above");
      lcd.setCursor(0, 1);
      lcd.print("3rd Floor!!");

      while (currentFloor > 3) {
        motorDir = 0;
        motorSpeed = 50;
        driveMotor();   
      }

      motorSpeed = 0;
      driveMotor();

      lcd.clear();
      lcd.print("Idle");
      lcd.setCursor(0, 1);
      lcd.print("Current Floor: ");
      lcd.setCursor(15, 1);   
    }
    
  }
}
