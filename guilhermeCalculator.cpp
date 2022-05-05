#include "guilhermeCalculator.h"

void guilherme_Calculator::setDisplay(Display *disp){
    this->display = disp;
}
void guilherme_Calculator::setCpu(Cpu *cpu){
    this->cpu = cpu;
}
void guilherme_Calculator::setKeyboard(Keyboard *kboard){
    this->keyboard = kboard;
}