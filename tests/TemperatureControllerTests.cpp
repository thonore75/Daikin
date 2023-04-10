#include "TemperatureController.h"

#include "API.h"

#include "MockTemperatureSensor.h"
#include "MockHeatingDevice.h"
#include "MockCoolingDevice.h"
#include <gtest/gtest.h>


TEST( TemperatureControllerTests, ShouldHeatWhenTemperatureIsLow )
{
    auto tempSensor = std::make_shared<testing::NiceMock<MockTemperatureSensor>>();
    auto heatingDevice = std::make_shared<testing::NiceMock<MockHeatingDevice>>();
    auto coolingDevice = std::make_shared<testing::NiceMock<MockCoolingDevice>>();

    auto controller = std::make_shared<TemperatureController>( tempSensor, heatingDevice, coolingDevice, 20.0, 24.0 );

    API api( controller );
    httplib::Server server;
    setup_api( server, *controller );
    api.setup();

    EXPECT_CALL( *tempSensor, getTemperature() ).WillOnce( testing::Return( 18.0 ) );
    EXPECT_CALL( *heatingDevice, turnOn() ).Times( 1 );
    EXPECT_CALL( *coolingDevice, turnOff() ).Times( 1 );

    controller->controlTemperature();
}

TEST( TemperatureControllerTests, ShouldCoolWhenTemperatureIsHigh )
{
    auto tempSensor = std::make_shared<testing::NiceMock<MockTemperatureSensor>>();
    auto heatingDevice = std::make_shared<testing::NiceMock<MockHeatingDevice>>();
    auto coolingDevice = std::make_shared<testing::NiceMock<MockCoolingDevice>>();

    auto controller = std::make_shared<TemperatureController>( tempSensor, heatingDevice, coolingDevice, 20.0, 24.0 );

    API api( controller );
    httplib::Server server;
    setup_api( server, *controller );
    api.setup();

    EXPECT_CALL( *tempSensor, getTemperature() ).WillOnce( testing::Return( 28.0 ) );
    EXPECT_CALL( *heatingDevice, turnOff() ).Times( 1 );
    EXPECT_CALL( *coolingDevice, turnOn() ).Times( 1 );

    controller->controlTemperature();
}

TEST( TemperatureControllerTests, ShouldDoNothingWhenTemperatureIsNormal )
{
    auto tempSensor = std::make_shared<testing::NiceMock<MockTemperatureSensor>>();
    auto heatingDevice = std::make_shared<testing::NiceMock<MockHeatingDevice>>();
    auto coolingDevice = std::make_shared<testing::NiceMock<MockCoolingDevice>>();

    auto controller = std::make_shared<TemperatureController>( tempSensor, heatingDevice, coolingDevice, 20.0, 24.0 );

    API api( controller );
    httplib::Server server;
    setup_api( server, *controller );
    api.setup();

    EXPECT_CALL( *tempSensor, getTemperature() ).WillOnce( testing::Return( 23.0 ) );
    EXPECT_CALL( *heatingDevice, turnOff() ).Times( 1 );
    EXPECT_CALL( *coolingDevice, turnOff() ).Times( 1 );

    controller->controlTemperature();
}

int main( int argc, char **argv )
{
    testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
