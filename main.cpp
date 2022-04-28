#include "calculator.h"

int mainCalculator(){
  // Keyboard k1;
  // KeyDigit key0(ZERO), key1(ONE), key2(TWO);

  // k1.addKey(&key0);
  // k1.addKey(&key1);
  // k1.addKey(&key2);

  // key1.press();
  // key1.press();
  // key1.press();
  // key0.press();

  Cpu calc;
  calc.receiveDigit(ONE);
  calc.receiveDigit(TWO);
  calc.receiveControl(DECIMAL_SEPARATOR);
  calc.receiveDigit(THRE);
  calc.receiveDigit(FOUR);
  calc.receiveControl(EQUAL);


  return 0;
}
