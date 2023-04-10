#include "TemperatureController.h"
#include <iostream>
#include <ctime>

TemperatureController::TemperatureController( TemperatureSensor &p_sensor, HeatingDevice &p_heater, CoolingDevice &p_cooler, double p_min_temp, double p_max_temp, double p_hysteresis )
    : _sensor( p_sensor ), _heater( p_heater ), _cooler( p_cooler ), _min_temp( p_min_temp ), _max_temp( p_max_temp ), _hysteresis( p_hysteresis )
{
    _log_file.open( "temperature_log.txt", std::ios::out | std::ios::app );
    _last_log_time = std::chrono::steady_clock::now();
}

void TemperatureController::update()
{
    double l_current_temp = _sensor.readTemperature();

    if ( l_current_temp < _min_temp - _hysteresis )
    {
        _heater.turnOn();
        _cooler.turnOff();
    }
    else if ( l_current_temp > _max_temp + _hysteresis )
    {
        _cooler.turnOn();
        _heater.turnOff();
    }
    else
    {
        _heater.turnOff();
        _cooler.turnOff();
    }

    auto l_current_time = std::chrono::steady_clock::now();
    if ( std::chrono::duration_cast<std::chrono::seconds>( l_current_time - _last_log_time ) >= _log_interval )
    {
        logTemperature( l_current_temp );
        _last_log_time = l_current_time;
    }

    if ( isTemperatureOutOfRange() )
    {
        sendAlert( "Temperature is out of range!" );
    }
}

bool TemperatureController::isTemperatureOutOfRange() const
{
    double l_current_temp = _sensor.readTemperature();

    return l_current_temp < _min_temp - 2 * _hysteresis || l_current_temp > _max_temp + 2 * _hysteresis;
}

void TemperatureController::logTemperature( double p_current_temp )
{
    std::time_t l_now = std::time( nullptr );
    char        l_time_buffer[ 100 ];

    std::strftime( l_time_buffer, sizeof( l_time_buffer ), "%Y-%m-%d %H:%M:%S", std::localtime( &l_now ) );

    _log_file << l_time_buffer << ": " << p_current_temp << "°C" << std::endl;
}

void TemperatureController::sendAlert( const std::string &p_message )
{
    std::cout << "ALERT: " << p_message << std::endl;
}
