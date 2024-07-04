class Button{
  private:
    int pin;
    int state;
    int lastState;

  public: 
    Button(int buttonPin) {
      pin = buttonPin;
      pinMode(pin,INPUT);
      state = LOW;
      lastState = LOW;
    }

    int check() {
      state = digitalRead(pin);
      if (state == LOW && lastState == HIGH) {
        delay(50);
        lastState = state;
        return 1;
      }

      lastState = state;
      return 0;
    }
};