
/*Function that lights up an LED and returns a HIGH value if pressed.
 this is used for cabin buttons, to request elevator at floor.*/
bool button(int a)
{
  if (digitalRead(29 - a) == HIGH) {
    return HIGH;
  }
  else {
    return LOW;
  }
}
