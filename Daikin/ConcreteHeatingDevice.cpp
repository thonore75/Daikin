#include "ConcreteHeatingDevice.h"
#include <iostream>

ConcreteHeatingDevice::ConcreteHeatingDevice()
{
    // Initialize heating device or any other resources required
}

void ConcreteHeatingDevice::turnOn()
{
    // Turn on the real heating device
    std::cout << "Heating device turned on." << std::endl;
}

void ConcreteHeatingDevice::turnOff()
{
    // Turn off the real heating device
    std::cout << "Heating device turned off." << std::endl;
}
