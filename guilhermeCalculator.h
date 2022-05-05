#include "calculator.h"

class guilherme_display : public Display{
    protected:
        Digit convertToDigit(int);
    public:
        void add(Digit);
        void add(Control);
        void setDecimalSeparator();
        void setSignal(Signal);
        void setError();
        void clear();
};

class guilherme_Reciver : public Display{
    public:
    virtual void receiveDigit(Digit) = 0;
    virtual void receiveOperation(Operation) = 0;
    virtual void receiveControl(Control) = 0;
};

class guilherme_Cpu : public Cpu
{
    Operation operation;
    Signal signal = POSITIVE;
    int operator1[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int operator2[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int sinal = 1;
    int quant_operation = 0;
    int quant_digits1 = 0;
    int quant_digits2 = 0;
    int index_decimal1 = 0;
    int index_decimal2 = 0;
    int flagDec1 = 0;
    int flagDec2 = 0;
    float resultado = 0;

public:
    void setDisplay(Display *);
    void receiveDigit(Digit);
    void receiveOperation(Operation);
    void receiveControl(Control);
    void receiveSignal(Signal);
};

class guilherme_Keyboard : public Keyboard
{
    Key * keys[110];
    char keysCount = 0;

public:
    
    void setCpu(Cpu *);

    void addKey(Key *);

    void receiveDigit(Digit);
    void receiveOperation(Operation);
    void receiveControl(Control);
};

class  guilherme_Calculator : public Calculator
{   Display *display;
    Cpu *cpu;
    Keyboard *keyboard;
public:
    void setDisplay(Display *);
    void setCpu(Cpu *);
    void setKeyboard(Keyboard *);
};

