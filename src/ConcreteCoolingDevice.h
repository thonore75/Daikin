#ifndef CONCRETECOOLINGDEVICE_H
#define CONCRETECOOLINGDEVICE_H

#include "TemperatureController.h"

class ConcreteCoolingDevice : public CoolingDevice {
public:
    void turnOn() override;
    void turnOff() override;
};

#endif //CONCRETECOOLINGDEVICE_H
