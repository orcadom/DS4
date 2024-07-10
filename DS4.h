/*
DS4.h - Dualshock 4 wired controller emulator
Created by Dominic Houghton, 10th July, 2024.
Released into the public domain.
Change boards.txt for you board for proper usb emulation:
vid.0=0x054C
pid.0=0x05C4
*/

#ifndef DS4_h
#define DS4_h

#include "Arduino.h"
#include "HID.h"

#define DS4_BUTTONS 14
#define DS4_AXES 4
#define DS4_TRIGGERS 2
#define DS4_REPORT_SIZE 467
#define DS4_OUTPUT_SIZE 63

#define DS4_TRIANGLE 0
#define DS4_CIRCLE 1
#define DS4_X 2
#define DS4_SQUARE 3
#define DS4_L1 4
#define DS4_R1 5
#define DS4_L2 6
#define DS4_R2 7
#define DS4_SHARE 8
#define DS4_OPTIONS 9
#define DS4_L3 10
#define DS4_R3 11
#define DS4_PS 10
#define DS4_TRACKPAD 11

class DS4
{
  public:
    DS4(void);
    void begin(void);
    void send(void);
    void setAutoSend(bool autoSend);
    void setButton(uint8_t button, bool state);
    void setHat(uint8_t direction);
    void setAxis(uint8_t axis, uint8_t position);
    void setTrigger(uint8_t trigger, uint8_t position);
    void setBattery(uint8_t level, bool plugConnected);
  private:
    int _count;
    bool _autoSend;
    bool _buttonState[DS4_BUTTONS];
    uint8_t _hatDirection;
    uint8_t _axisPosition[DS4_AXES];
    uint8_t _triggerPosition[DS4_TRIGGERS];
    uint8_t _batteryLevel;
    bool _plugConnected;
};

#endif