#include <VirtualWire.h>

///////////////////////////////////////////////////

const int led_pin = LED_BUILTIN;
const int transmit_pin = 12;
const int receive_pin = 2;
const int transmit_en_pin = 3;

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting to transmit");
  // Initialise the IO and ISR
  vw_set_tx_pin(transmit_pin);
  vw_set_rx_pin(receive_pin);
  vw_set_ptt_pin(transmit_en_pin);
  vw_setup(2000);  // Bits per sec
}

byte count = 1;

void loop()
{
  char msg[4] = {'t','e','j', 'a'};

  msg[6] = count;
  digitalWrite(led_pin, HIGH); // Flash a light to show transmitting
  vw_send((uint8_t *)msg, 4);
  //vw_wait_tx(); // Wait until the whole message is gone
  digitalWrite(led_pin, LOW);
  delay(200);
  count = count + 1;
}
