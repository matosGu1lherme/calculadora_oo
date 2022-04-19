#include <iostream>
#include "calculator.h"

using namespace std;

int main(){
    Cpu calculadora;

    calculadora.receiveDigit(ONE);
    calculadora.receiveDigit(TWO);
    calculadora.receiveOperation(ADDITION);
    calculadora.receiveDigit(ONE);
    calculadora.receiveDigit(FIVE);
    calculadora.receiveControl(EQUAL);
    
    
}