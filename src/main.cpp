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
    Serial.println(printf("Code: %d", switcher.getReceivedValue()));
    Serial.println(printf("Bit Length: %d", switcher.getReceivedBitlength()));
    Serial.println(printf("Protocol: %d", switcher.getReceivedProtocol()));
    Serial.println(printf("Delay: %d", switcher.getReceivedDelay()));

    switcher.resetAvailable();
  }
}