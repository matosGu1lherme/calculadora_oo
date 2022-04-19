#include "calculator.h"

#include <iostream>

using namespace std;
//********************************************************************************************
//******************funções auxiliares********************************************************
//********************************************************************************************

int expoente(int b, int expo){

  int res = 1;
  for (int i = 0; i < expo; i++)
  {
    res = res * b;
  }
  
  return res;
}

//**************************Implmentações*******************************************************
void Cpu::receiveDigit(Digit number)
{

  if (this->quant_operation == 0)
  {
      //cout<<"entrou";
    switch (number)
    {
    case ZERO:
      this->operator1[this->quant_digits1] = 0;
      break;
    case ONE:
      this->operator1[this->quant_digits1] = 1;
      break;
    case TWO:
      this->operator1[this->quant_digits1] = 2;
      break;
    case THRE:
      this->operator1[this->quant_digits1] = 3;
      break;
    case FOUR:
      this->operator1[this->quant_digits1] = 4;
      break;
    case FIVE:
      this->operator1[this->quant_digits1] = 5;
      break;
    case SIX:
      this->operator1[this->quant_digits1] = 6;
      break;
    case SEVEN:
      this->operator1[this->quant_digits1] = 7;
      break;
    case EIGHT:
      this->operator1[this->quant_digits1] = 8;
      break;
    case NINE:
      this->operator1[this->quant_digits1] = 9;
      break;

    default:
      cout << "MATH ERROR";
      break;
    }

    this->quant_digits1++;
  }

  if(this->quant_operation != 0){
    switch (number)
    {
    case ZERO:
      this->operator2[this->quant_digits2] = 0;
      break;
    case ONE:
      this->operator2[this->quant_digits2] = 1;
      break;
    case TWO:
      this->operator2[this->quant_digits2] = 2;
      break;
    case THRE:
      this->operator2[this->quant_digits2] = 3;
      break;
    case FOUR:
      this->operator2[this->quant_digits2] = 4;
      break;
    case FIVE:
      this->operator2[this->quant_digits2] = 5;
      break;
    case SIX:
      this->operator2[this->quant_digits2] = 6;
      break;
    case SEVEN:
      this->operator2[this->quant_digits2] = 7;
      break;
    case EIGHT:
      this->operator2[this->quant_digits2] = 8;
      break;
    case NINE:
      this->operator2[this->quant_digits2] = 9;
      break;

    default:
      cout << "MATH ERROR";
      break;
    }

    this->quant_digits2++;
    }
    
}

void Cpu::receiveOperation(Operation op){
  if (this->quant_operation > 0)
  {
    cout<<"MATH ERROR operation is ready";
  }

  if (this->quant_operation == 0)
  {
    this->operation = op;
    this->quant_operation++;
  }

}

void Cpu::receiveControl(Control control){
  if (control == EQUAL)
  {
    float res = 0;
    
    float numeber1 = 0;
    for (int i = 0; i < this->quant_digits1 ; i++)
    {
      numeber1 = numeber1 + this->operator1[i] * expoente(10,i);
    }
    cout<<numeber1<<"\n";
    
    float numeber2 = 0;
    for (int i = 0; i < this->quant_digits2 ; i++)
    {
      numeber2 = numeber2 + this->operator2[i] * expoente(10,i);
    }
    cout<<numeber2<<"\n";
    
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
    
    if (this->operation == MULTIPLICATION)
    {
      res = numeber1 * numeber2;
    }

    this->quant_operation = 0;
    this->quant_digits1 = 0;
    this->quant_digits2 = 0;
    
    cout<<res;
    this->resultado = res;
  }
  
  
}
