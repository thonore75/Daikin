#ifndef API_H
#define API_H

#include "TemperatureController.h"
#include "httplib.h"

void setup_api( httplib::Server &server, TemperatureController &controller );

class API
{
    public:
    API( std::shared_ptr<TemperatureController> controller );
    void setup();
};

#endif //API_H
