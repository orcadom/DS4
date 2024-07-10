/*
Change boards.txt for your board for proper usb emulation:
vid.0=0x054C
pid.0=0x05C4
*/

#include <DS4.h>

DS4 ds4;

void setup() {
  ds4.begin();
  //ds4.setAutoSend(false);
  //ds4.setBatteryLevel(100, true); // Level & Charger Connected
}

void loop() {
  ds4.setButton(DS4_X, true);
  ds4.setAxis(0, 160);
  ds4.setHat(7);
  ds4.setTrigger(1, 50);
  ds4.send();
}
