#ifndef _DAIKIN_CONCRETE_COOLING_DEVICE_H_
#define _DAIKIN_CONCRETE_COOLING_DEVICE_H_

#include "TemperatureController.h"

class ConcreteCoolingDevice : public CoolingDevice
{
public:
    ConcreteCoolingDevice();

    void turnOn() override;
    void turnOff() override;
};

#endif // !_DAIKIN_CONCRETE_COOLING_DEVICE_H_
