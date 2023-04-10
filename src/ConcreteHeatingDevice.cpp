#include "ConcreteHeatingDevice.h"
#include <iostream>

void ConcreteHeatingDevice::turnOn() {
    std::cout << "Heating device turned on." << std::endl;
}

void ConcreteHeatingDevice::turnOff() {
    std::cout << "Heating device turned off." << std::endl;
}
