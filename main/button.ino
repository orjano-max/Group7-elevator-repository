/*
  The button() function, returns HIGH if a button is pressed.
  This function is used to determine wich floor a button is pressed at
  The button function also reveses the numberation for the buttons: button(0) in the program = button 7 in real life
 */
bool button(int a)
{
  
  if (digitalRead(29 - a) == HIGH)
  {
    return HIGH;
  }
  else {
    return LOW;
  }
  
}
