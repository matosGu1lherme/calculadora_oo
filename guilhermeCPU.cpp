#include "guilhermeCalculator.h"
#include <iostream>
#include <math.h>
using namespace std;

void guilherme_Cpu::receiveDigit(Digit number)
{
  this->display->add(number);
  //  faz a convercao de um DIGIT para um INT e grava os INDEX do vetor de 8 digitos da caulculadora
  if (this->quant_operation == 0)
  {
    // cout<<"entrou";
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
    case THREE:
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
      this->display->setError();

      break;
    }

    this->quant_digits1++;
  }

  if (this->quant_operation != 0)
  {
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
    case THREE:
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
      this->display->setError();
      break;
    }
    this->quant_digits2++;
  }
}

void guilherme_Cpu::receiveOperation(Operation op)
{
  if (this->quant_operation > 0)
  {
    cout << "MATH ERROR operation is ready";
  }

  if (this->quant_operation == 0)
  {
    this->operation = op;
    this->quant_operation++;
    cout << "\n";
  }

  if (op == ADDITION)
  {
    cout << "+\n\n";
  }
  if (op == SUBTRACTION)
  {
    cout << "-\n\n";
  }
  if (op == DIVISION)
  {
    cout << "/\n\n";
  }
  if (op == MULTIPLICATION)
  {
    cout << "X\n\n";
  }
  if (op == SQUARE_ROOT)
  {
    cout << "Raiz\n\n";
  }
  if (op == PERCENTAGE)
  {
    cout << "%\n\n";
  }
}

void guilherme_Cpu::receiveSignal(Signal sig)
{
  if (sig == NEGATIVE)
  {
    this->signal == sig;
    this->sinal = -1;
    cout << "- \n";
  }
  if (sig == POSITIVE)
  {
    this->signal == sig;
    this->sinal = 1;
  }
}
void guilherme_Cpu::receiveControl(Control control)
{
  //this->display->add(control);
  // marca a posição do ponto flutuanse (DECIMAL SEPARATOR) e sinaliza aonde deve ser feita convercao de base

  if (control == DECIMAL_SEPARATOR)
  {
    if (this->quant_operation == 0)
    {
      this->index_decimal1 = quant_digits1 - 1;
      this->flagDec1++;
    }
    else
    {
      this->index_decimal2 = quant_digits2 - 1;
      this->flagDec2++;
    }
  }

  if (control == EQUAL)
  {
    float res = 0;
    // Transforma o numero em decimal por meio de multiplicacao da base 10
    float number1 = 0;
    int j = this->quant_digits1 - 1;
    if (this->flagDec1 > 0)
      j = index_decimal1;
    for (int i = 0; i <= this->quant_digits1 - 1; i++)
    {
      number1 = number1 + this->operator1[i] * pow(10, j);
      j--;
    }
    number1 *= this->sinal;
    receiveSignal(POSITIVE);

    float number2 = 0;
    j = this->quant_digits2 - 1;
    if (this->flagDec2 > 0)
      j = index_decimal2;
    for (int i = 0; i <= this->quant_digits2 - 1; i++)
    {
      number2 = number2 + this->operator2[i] * pow(10, j);
      j--;
    }
    number2 *= this->sinal;
    receiveSignal(POSITIVE);

    if (this->operation == ADDITION)
    {
      res = number1 + number2;
    }

    if (this->operation == SUBTRACTION)
    {
      res = number1 - number2;
    }

    if (this->operation == DIVISION)
    {
      res = number1 / number2;
    }

    if (this->operation == MULTIPLICATION)
    {
      res = number1 * number2;
    }

    if (this->operation == PERCENTAGE)
    {
      res = (number1 / 100) * number2;
    }

    if (this->operation == SQUARE_ROOT)
    {
      res = sqrt(number1);
    }

    this->quant_operation = 0;
    this->quant_digits1 = 0;
    this->quant_digits2 = 0;

    // imprimi o resultado
    cout << res;
    // guarda resultado num temporario
    this->resultado = res;
  }

  if (control == CLEAR)
  {
    this->quant_operation = 0;
    this->quant_digits1 = -1;
    this->quant_digits2 = -1;
    this->index_decimal1 = 0;
    this->index_decimal2 = 0;
    this->resultado = 0;
  }

  if (control == RESET)
  {
    this->quant_operation = 0;
    this->quant_digits1 = -1;
    this->quant_digits2 = -1;
    this->index_decimal1 = 0;
    this->index_decimal2 = 0;
    this->resultado = 0;
    receiveSignal(POSITIVE);
  }
}