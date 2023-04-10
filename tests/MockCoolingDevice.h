#ifndef MOCKCOOLINGDEVICE_H
#define MOCKCOOLINGDEVICE_H

#include "ConcreteCoolingDevice.h"
#include <gmock/gmock.h>

class MockCoolingDevice : public ConcreteCoolingDevice {
public:
    MOCK_METHOD(void, turnOn, (), (override));
    MOCK_METHOD(void, turnOff, (), (override));
    MOCK_METHOD(bool, isOn, (), (const));
};

#endif // MOCKCOOLINGDEVICE_H
