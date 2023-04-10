#include "TemperatureController.h"

TemperatureController::TemperatureController( std::shared_ptr<TemperatureSensor> sensor,
                                              std::shared_ptr<HeatingDevice> heater,
                                              std::shared_ptr<CoolingDevice> cooler,
                                              double min_temperature,
                                              double max_temperature )
    : sensor_( sensor ),
    heater_( heater ),
    cooler_( cooler ),
    min_temperature_( min_temperature ),
    max_temperature_( max_temperature ),
    target_temperature_( min_temperature )
{}

void TemperatureController::update()
{
    double current_temperature = sensor_->getTemperature();
    if ( current_temperature < target_temperature_ )
    {
        heater_->turnOn();
        cooler_->turnOff();
    }
    else if ( current_temperature > target_temperature_ )
    {
        heater_->turnOff();
        cooler_->turnOn();
    }
    else
    {
        heater_->turnOff();
        cooler_->turnOff();
    }
}

void TemperatureController::setTargetTemperature( double target_temperature )
{
    target_temperature_ = target_temperature;
}

void TemperatureController::controlTemperature()
{
    double current_temperature = sensor_->getTemperature();
    if ( current_temperature < min_temperature_ )
    {
        heater_->turnOn();
        cooler_->turnOff();
    }
    else if ( current_temperature > max_temperature_ )
    {
        heater_->turnOff();
        cooler_->turnOn();
    }
    else
    {
        heater_->turnOff();
        cooler_->turnOff();
    }
}

double TemperatureController::getCurrentTemperature() const
{
    return sensor_->getTemperature();
}

double TemperatureController::getTargetTemperature() const
{
    return target_temperature_;
}
