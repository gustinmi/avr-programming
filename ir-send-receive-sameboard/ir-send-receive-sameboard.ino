#include <IRremote.h>

#define PIN_DETECT 11
IRsend irsend;

void setup()
{ 
    pinMode(PIN_DETECT, INPUT); 

    Serial.begin(9600);
    Serial.println("READY 123");

    attachInterrupt(digitalPinToInterrupt(PIN_DETECT), checkIRBeamBreak, RISING);

    // Note : the IR emitter is on PIN #3
    irsend.enableIROut(38);
    IREmitterOn();
    Serial.println("emitter on ");
}

// Use this function instead of delay() as delay() does not work in interrupt callbacks
void pause(int ms) { 
    // We need a loop as the largest value for delayMicroseconds that will produce an accurate delay is 16383
    for (int i = 0; i < ms; i++) {
        delayMicroseconds(1000);
    }
}

void IREmitterOff() {
    irsend.space(0);
    pause(60); // 60 ms is OK for my TSOP but should be tuned
}

void IREmitterOn() {
    irsend.mark(0);
    pause(10);
}

void switchOffOnIREmitter() {
    IREmitterOff();
    IREmitterOn();
    Serial.println("Ion off!!"); 
}

void checkIRBeamBreak() { 
    int val = digitalRead(PIN_DETECT);
    Serial.println("IR BEAM BREAK routine !!!!"); 
    // LOW : no beam break
    // HIGH : beam break
    if (val == LOW)
        return;

    detachInterrupt(digitalPinToInterrupt(PIN_DETECT));
    switchOffOnIREmitter();
    if (digitalRead(PIN_DETECT) == HIGH) {
        Serial.println("IR BEAM BREAK !!!!"); 
    }
    attachInterrupt(digitalPinToInterrupt(PIN_DETECT), checkIRBeamBreak, RISING);
}


void loop() {

}
