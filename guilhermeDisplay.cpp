#include "guilhermeCalculator.h"
#include <iostream>
#include <math.h>
using namespace std;
// imprimi os digitos na tela

void guilherme_display::add(Digit number)
{
  switch (number)
  {
  case ZERO:
    cout << 0;
    break;
  case ONE:
    cout << 1;
    break;
  case TWO:
    cout << 2;
    break;
  case THREE:
    cout << 3;
    break;
  case FOUR:
    cout << 4;
    break;
  case FIVE:
    cout << 5;
    break;
  case SIX:
    cout << 6;
    break;
  case SEVEN:
    cout << 7;
    break;
  case EIGHT:
    cout << 8;
    break;
  case NINE:
    cout << 9;
    break;

  default:
    setError();
    break;
  }
  cout << "\n";
}

void guilherme_display::add(Control ctrl)
{
  switch (ctrl)
  {
  case DECIMAL_SEPARATOR:
    cout << ".";
    break;
  default:
    break;
  }
  cout << "\n";
}

// imprimi um Decimal Separator
void guilherme_display::setDecimalSeparator()
{
  cout << ".";
}

// Imprimi um error no console
void guilherme_display::setError()
{
  cout << "MATH-ERROR";
}
// imprimi um sinal na tela
void guilherme_display::setSignal(Signal)
{
  cout << "-";
}
void guilherme_display::clear()
{
  cout << std::endl;
}