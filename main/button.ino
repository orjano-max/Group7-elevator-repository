/*
 The button() function, returns HIGH if a button is pressed.
 This function is used to determine wich floor a button is pressed at
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
