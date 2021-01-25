#include <Arduino.h>
#include <RCSwitch.h>

RCSwitch switcher = RCSwitch();

#define RECEIVER_INTERRUPT 0

void setup() {
  Serial.begin(115200);
  switcher.enableReceive(RECEIVER_INTERRUPT);
}

void loop() {
  char buffer[50];

  if (switcher.available()) {
    sprintf(buffer, "Code: %lu", switcher.getReceivedValue());
    Serial.println(buffer);

    sprintf(buffer, "Bit Length: %d", switcher.getReceivedBitlength());
    Serial.println(buffer);

    sprintf(buffer, "Protocol: %d", switcher.getReceivedProtocol());
    Serial.println(buffer);

    sprintf(buffer, "Delay: %d", switcher.getReceivedDelay());
    Serial.println(buffer);

    switcher.resetAvailable();
  }
}