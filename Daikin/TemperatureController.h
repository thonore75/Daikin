#ifndef _DAIKIN_TEMPERATURECONTROLOER_H
#define _DAIKIN_TEMPERATURECONTROLOER_H


#include <string>
#include <memory>
#include <fstream>
#include <chrono>

class TemperatureSensor
{
public:
    virtual double readTemperature() = 0;
};

class HeatingDevice
{
public:
    virtual void turnOn()  = 0;
    virtual void turnOff() = 0;
};

class CoolingDevice
{
public:
    virtual void turnOn()  = 0;
    virtual void turnOff() = 0;
};


class TemperatureController
{
public:
    TemperatureController( TemperatureSensor &p_sensor, HeatingDevice &p_heater, CoolingDevice &p_cooler, double p_min_temp, double p_max_temp, double p_hysteresis = 0.5 );

    void update();
    bool isTemperatureOutOfRange() const;

private:
    void logTemperature( double p_current_temp );
    void sendAlert( const std::string &p_message );

    TemperatureSensor                     &_sensor;
    HeatingDevice                         &_heater;
    CoolingDevice                         &_cooler;

    double                                 _min_temp;
    double                                 _max_temp;
    double                                 _hysteresis;

    std::ofstream                          _log_file;
    std::chrono::steady_clock::time_point  _last_log_time;

    const std::chrono::seconds             _log_interval{ 60 };
};


#endif // !_DAIKIN_TEMPERATURECONTROLOER_H
