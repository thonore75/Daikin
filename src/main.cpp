#include "api.h"

#include "ConcreteTemperatureSensor.h"
#include "ConcreteHeatingDevice.h"
#include "ConcreteCoolingDevice.h"

int main()
{
    auto sensor = std::make_shared<ConcreteTemperatureSensor>();
    auto heater = std::make_shared<ConcreteHeatingDevice>();
    auto cooler = std::make_shared<ConcreteCoolingDevice>();

    double min_temperature = 18.0;
    double max_temperature = 24.0;

    TemperatureController controller( sensor, heater, cooler, min_temperature, max_temperature );

    httplib::Server server;
    setup_api( server, controller );
    server.listen( "0.0.0.0", 8080 );

    return 0;
}
