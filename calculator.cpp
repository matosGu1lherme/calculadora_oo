#include "calculator.h"

#include <iostream>

void Cpu::setDisplay(Display* d){
  this->display = d;  
}

void Keyboard::setCpu(Cpu *cpu){
  this->cpu = cpu;
}

void Key::setReceiver(Receiver* receiver){
  this->receiver = receiver;
}

KeyDigit::KeyDigit(Digit d):digit(d){}
void KeyDigit::press(){
  this->receiver->receiveDigit(this->digit);
}

KeyOperation::KeyOperation(Operation o):operation(o){}
void KeyOperation::press(){
  this->receiver->receiveOperation(this->operation);
}

KeyControl::KeyControl(Control c):control(c){}
void KeyControl::press(){
  this->receiver->receiveControl(this->control);
}