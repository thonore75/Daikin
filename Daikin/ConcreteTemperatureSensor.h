#ifndef _DAIKIN_CONCRETE_TEMPERATURE_SENSOR_H_
#define _DAIKIN_CONCRETE_TEMPERATURE_SENSOR_H_

#include "TemperatureController.h"

class ConcreteTemperatureSensor : public TemperatureSensor
{
public:
    ConcreteTemperatureSensor();

    double readTemperature() override;
};


#endif // !_DAIKIN_CONCRETE_TEMPERATURE_SENSOR_H_