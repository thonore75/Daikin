#include "ConcreteCoolingDevice.h"
#include <iostream>

void ConcreteCoolingDevice::turnOn() {
    std::cout << "Cooling device turned on." << std::endl;
}

void ConcreteCoolingDevice::turnOff() {
    std::cout << "Cooling device turned off." << std::endl;
}
