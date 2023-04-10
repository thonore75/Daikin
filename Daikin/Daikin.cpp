// Daikin.cpp : Defines the entry point for the application.
//


#include "TemperatureController.h"
#include "ConcreteTemperatureSensor.h"
#include "ConcreteHeatingDevice.h"
#include "ConcreteCoolingDevice.h"

int main()
{
    ConcreteTemperatureSensor l_sensor;
    ConcreteHeatingDevice     l_heater;
    ConcreteCoolingDevice     l_cooler;

    TemperatureController l_controller( l_sensor, l_heater, l_cooler, 20.0, 25.0 );

    l_controller.update();

    return 0;
}
