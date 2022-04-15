#include "calculator.h"

int mainCalculator(){
  Keyboard k1;
  KeyDigit key0(ZERO), key1(ONE), key2(TWO);

  k1.addKey(&key0);
  k1.addKey(&key1);
  k1.addKey(&key2);

  key1.press();
  key1.press();
  key1.press();
  key0.press();

  return 1;
}
