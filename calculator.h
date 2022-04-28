enum Digit {ZERO, ONE, TWO, THRE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
enum Operation {ADDITION, SUBTRACTION, DIVISION, MULTIPLICATION, SQUARE_ROOT, PERCENTAGE};
enum Control {CLEAR, RESET, DECIMAL_SEPARATOR, MEMORY_READ_CLEAR, MEMORY_ADDITION, MEMORY_SUBTRACTION, EQUAL};
enum Signal {POSITIVE, NEGATIVE};

class Display{ 
    Digit convertToDigit(int);
  public:
    void add(Digit );
    void setDecimalSeparator();
    void setSignal(Signal );
    void setError();
    void clear();
};

class Receiver{
  public:
    virtual void receiveDigit(Digit ) = 0;
    virtual void receiveOperation(Operation ) = 0;
    virtual void receiveControl(Control ) = 0;

};
class Cpu: public Receiver{
  Display* display;
  Operation operation;
  Signal Signal = POSITIVE;
  int operator1 [8] = {0,0,0,0,0,0,0,0};
  int operator2 [8] = {0,0,0,0,0,0,0,0};
  int quant_operation = 0;
  int quant_decimal_separator1 = 0;
  int quant_decimal_separator2 = 0;
  int quant_digits1ds = 0;
  int quant_digits1 = 0;
  int quant_digits2 = 0;
  int escopo1 = 0;
  int escopo2 = 0;
  float resultado = 0;
  public:
    void setDisplay(Display* );
    void receiveDigit(Digit );
    void receiveOperation(Operation );
    void receiveControl(Control );
};

class Key; // Preset for early reference


//Keybord vai receber os comandos 
class Keyboard: public Receiver{
   Cpu* cpu;

   public:
      void setCpu(Cpu* );

      void addKey(Key* );

      void receiveDigit(Digit );
      void receiveOperation(Operation );
      void receiveControl(Control );
};

class Calculator{
  public:
    void setDisplay(Display* );
    void setCpu(Cpu* );
    void setKeyboard(Keyboard* );
};

class Key{
   protected:
     Receiver* receiver;
   public:
      void setReceiver(Receiver* );

      void press();
};

class KeyDigit: public Key{
     Digit digit;
   public:
      KeyDigit(Digit );
      void press();
};

class KeyOperation: public Key{
     Operation operation;
   public:
      KeyOperation(Operation );
      void press();
};

class KeyControl: public Key{
     Control control;
   public:
      KeyControl(Control );
      void press();
};