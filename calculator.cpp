#include "calculator.h"

#include <iostream>

using namespace std;

void Cpu::receiveDigit(Digit number)
{

  if (this->quant_operation = 0)
  {
    switch (number)
    {
    case ZERO:
      this->operator1[this->quant_digits] = 0;
      break;
    case ONE:
      this->operator1[this->quant_digits] = 1;
      break;
    case TWO:
      this->operator1[this->quant_digits] = 2;
      break;
    case THRE:
      this->operator1[this->quant_digits] = 3;
      break;
    case FOUR:
      this->operator1[this->quant_digits] = 4;
      break;
    case FIVE:
      this->operator1[this->quant_digits] = 5;
      break;
    case SIX:
      this->operator1[this->quant_digits] = 6;
      break;
    case SEVEN:
      this->operator1[this->quant_digits] = 7;
      break;
    case EIGHT:
      this->operator1[this->quant_digits] = 8;
      break;
    case NINE:
      this->operator1[this->quant_digits] = 9;
      break;

    default:
      cout << "MATH ERROR";
      break;
    }

    this->quant_digits++;

  }else{

    switch (number)
    {
    case ZERO:
      this->operator2[this->quant_digits] = 0;
      break;
    case ONE:
      this->operator2[this->quant_digits] = 1;
      break;
    case TWO:
      this->operator2[this->quant_digits] = 2;
      break;
    case THRE:
      this->operator2[this->quant_digits] = 3;
      break;
    case FOUR:
      this->operator2[this->quant_digits] = 4;
      break;
    case FIVE:
      this->operator2[this->quant_digits] = 5;
      break;
    case SIX:
      this->operator2[this->quant_digits] = 6;
      break;
    case SEVEN:
      this->operator2[this->quant_digits] = 7;
      break;
    case EIGHT:
      this->operator2[this->quant_digits] = 8;
      break;
    case NINE:
      this->operator2[this->quant_digits] = 9;
      break;

    default:
      cout << "MATH ERROR";
      break;
    }

    this->quant_digits++;
  }
}

void Cpu::receiveOperation(Operation op){
  if (this->quant_operation == 0)
  {
    this->operation = op;
    this->quant_digits = 0;
  }

  if (this->operation > 0)
  {
    cout<<"MATH ERROR";
  }
}

void Cpu::receiveControl(Control control){
  if (control == EQUAL)
  {
    int numeber1 = 0;
    float res = 0;
    for (int i = 0; i < this->quant_digits ; i++)
    {
      res= numeber1 += this->operator1[i] * 10^i;
    }

    int numeber2 = 0;
    for (int i = 0; i < this->quant_digits ; i++)
    {
      res = numeber1 += this->operator1[i] * 10^i;
    }
    
    if (this->operation == ADDITION)
    {
      res = numeber1 + numeber2;
    }

    if (this->operation == SUBTRACTION)
    {
      res = numeber1 - numeber2;
    }

    if (this->operation == DIVISION)
    {
      res = numeber1 / numeber2;
    }
    
    if (this->operation == DIVISION)
    {
      res = numeber1 * numeber2;
    }

    this->quant_operation = 0;
    this->quant_digits = 0;
    cout << res;
  }
  
}