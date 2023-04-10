#ifndef MOCKHEATINGDEVICE_H
#define MOCKHEATINGDEVICE_H

#include "ConcreteHeatingDevice.h"
#include <gmock/gmock.h>

class MockHeatingDevice : public ConcreteHeatingDevice {
public:
    MOCK_METHOD(void, turnOn, (), (override));
    MOCK_METHOD(void, turnOff, (), (override));
    MOCK_METHOD(bool, isOn, (), (const));
};

#endif // MOCKHEATINGDEVICE_H
