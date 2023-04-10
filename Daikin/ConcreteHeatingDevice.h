#ifndef _DAIKIN_CONCRETE_HEATING_DEVICE_H_
#define _DAIKIN_CONCRETE_HEATING_DEVICE_H_

#include "TemperatureController.h"

class ConcreteHeatingDevice : public HeatingDevice
{
public:
    ConcreteHeatingDevice();

    void turnOn() override;
    void turnOff() override;
};

#endif // !_DAIKIN_CONCRETE_HEATING_DEVICE_H_
