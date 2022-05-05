#include "guilhermeCalculator.h"
#include <iostream>
using namespace std;
void guilherme_Keyboard::receiveDigit(Digit n)
{

  this->cpu->receiveDigit(n);
}

void guilherme_Keyboard::addKey(Key * k){
  this->keys[this->keysCount++] = k;
  k->setReceiver(this);
}

void guilherme_Keyboard::setCpu(Cpu *cpu)
{
  this->cpu = cpu;
}

void guilherme_Keyboard::receiveOperation(Operation op)
{

  this->cpu->receiveOperation(op);
}

void guilherme_Keyboard::receiveControl(Control control)
{

  this->cpu->receiveControl(control);
}