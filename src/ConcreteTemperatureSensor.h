#ifndef CONCRETETEMPERATURESENSOR_H
#define CONCRETETEMPERATURESENSOR_H

#include "TemperatureController.h"

class ConcreteTemperatureSensor : public TemperatureSensor
{
public:
    ConcreteTemperatureSensor( double initial_temperature );
    ConcreteTemperatureSensor() = default;

    double getTemperature() const override;

    void setTemperature( double temperature );

private:
    double current_temperature_;
};

#endif //CONCRETETEMPERATURESENSOR_H
