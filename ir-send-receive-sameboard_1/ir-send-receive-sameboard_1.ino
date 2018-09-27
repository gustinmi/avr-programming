#include <IRremote.h>

#define PIN_IR 3
#define PIN_DETECT 11

IRsend irsend;
void setup()
{
  pinMode(PIN_DETECT, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  irsend.enableIROut(38);
  irsend.mark(0);
}

void loop() {
  digitalWrite(LED_BUILTIN, !digitalRead(PIN_DETECT));
}
