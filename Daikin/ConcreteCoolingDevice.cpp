#include "ConcreteCoolingDevice.h"
#include <iostream>

ConcreteCoolingDevice::ConcreteCoolingDevice()
{
    // Initialize cooling device or any other resources required
}

void ConcreteCoolingDevice::turnOn()
{
    // Turn on the real cooling device
    std::cout << "Cooling device turned on." << std::endl;
}

void ConcreteCoolingDevice::turnOff()
{
    // Turn off the real cooling device
    std::cout << "Cooling device turned off." << std::endl;
}
