#ifndef TEMPERATURECONTROLLER_H
#define TEMPERATURECONTROLLER_H

#include <memory>

class TemperatureSensor {
public:
    virtual ~TemperatureSensor() = default;
    virtual double getTemperature() const = 0;
};

class HeatingDevice {
public:
    virtual ~HeatingDevice() = default;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

class CoolingDevice {
public:
    virtual ~CoolingDevice() = default;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
};

class TemperatureController {
public:
    TemperatureController(std::shared_ptr<TemperatureSensor> sensor, std::shared_ptr<HeatingDevice> heater, std::shared_ptr<CoolingDevice> cooler, double min_temperature, double max_temperature);
    TemperatureController() = default;

    void update();
    void setTargetTemperature(double targetTemperature);
    void controlTemperature();
    double getCurrentTemperature() const;
    double getTargetTemperature() const;

private:
    std::shared_ptr<TemperatureSensor> sensor_;
    std::shared_ptr<HeatingDevice> heater_;
    std::shared_ptr<CoolingDevice> cooler_;
    double min_temperature_;
    double max_temperature_;
    double target_temperature_;
};

#endif //TEMPERATURECONTROLLER_H
