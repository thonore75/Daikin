#include "ConcreteTemperatureSensor.h"

ConcreteTemperatureSensor::ConcreteTemperatureSensor(double initial_temperature)
    : current_temperature_(initial_temperature) {}

double ConcreteTemperatureSensor::getTemperature() const {
    return current_temperature_;
}

void ConcreteTemperatureSensor::setTemperature(double temperature) {
    current_temperature_ = temperature;
}
