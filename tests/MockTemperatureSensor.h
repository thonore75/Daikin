#ifndef MOCKTEMPERATURESENSOR_H
#define MOCKTEMPERATURESENSOR_H

#include "gmock/gmock.h"
#include "ConcreteTemperatureSensor.h"

class MockTemperatureSensor : public TemperatureSensor {
public:
    MOCK_CONST_METHOD0(getTemperature, double());
};

#endif //MOCKTEMPERATURESENSOR_H
