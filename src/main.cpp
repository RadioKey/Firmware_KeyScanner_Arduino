#include <Arduino.h>
#include <RCSwitch.h>

RCSwitch switcher = RCSwitch();

#define RECEIVER_INTERRUPT 0

void setup() {
  Serial.begin(9600);
  switcher.enableReceive(RECEIVER_INTERRUPT);
}

void loop() {
  if (switcher.available()) {
    Serial.println(switcher.getReceivedValue());
    Serial.println(switcher.getReceivedBitlength());
    Serial.println(switcher.getReceivedProtocol());
    Serial.println(switcher.getReceivedDelay());

    switcher.resetAvailable();
  }
}