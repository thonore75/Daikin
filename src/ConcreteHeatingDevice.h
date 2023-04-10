#ifndef CONCRETEHEATINGDEVICE_H
#define CONCRETEHEATINGDEVICE_H

#include "TemperatureController.h"

class ConcreteHeatingDevice : public HeatingDevice {
public:
    void turnOn() override;
    void turnOff() override;
};

#endif //CONCRETEHEATINGDEVICE_H
