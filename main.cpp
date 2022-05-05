#include <iostream>
#include <math.h>
#include "calculator.h"
#include "guilhermeCalculator.h"

using namespace std;

int main()
{
  Display *display = new guilherme_display();
  Cpu *cpu =  new guilherme_Cpu();
  Keyboard *k1 = new guilherme_Keyboard();
  Calculator *calc = new guilherme_Calculator();

  KeyDigit key0(ZERO), key1(ONE), key2(TWO), key3(THREE), key4(FOUR), key5(FIVE), key6(SIX), key7(SEVEN), key8(EIGHT), key9(NINE);
  KeyControl keyEqual(EQUAL), KeyClear(CLEAR), KeyDecimalSeparator(DECIMAL_SEPARATOR), KeyReset(RESET);
  KeyOperation keyADD(ADDITION), keySUB(SUBTRACTION), keyDIV(DIVISION), keyMULT(MULTIPLICATION), keyPERCE(PERCENTAGE), keySQR(SQUARE_ROOT);

  
  cpu->setDisplay(display);
  k1->setCpu(cpu);  

  k1->addKey(&keyEqual);
  k1->addKey(&KeyClear);
  k1->addKey(&KeyDecimalSeparator);
  k1->addKey(&KeyReset);

  k1->addKey(&keyADD);
  k1->addKey(&keySUB);
  k1->addKey(&keyDIV);
  k1->addKey(&keyMULT);
  k1->addKey(&keyPERCE);
  k1->addKey(&keySQR);

  k1->addKey(&key0);
  k1->addKey(&key1);
  k1->addKey(&key2);
  k1->addKey(&key3);
  k1->addKey(&key4);
  k1->addKey(&key5);
  k1->addKey(&key6);
  k1->addKey(&key7);
  k1->addKey(&key8);
  k1->addKey(&key9);


  key1.press();
  key2.press();
  KeyDecimalSeparator.press();
  key3.press();
  key4.press();
  keyADD.press();
  key1.press();
  key4.press();
  KeyDecimalSeparator.press();
  key6.press();
  keyEqual.press();


  return 0;
}