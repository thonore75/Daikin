set(GOOGLETEST_ROOT lib/googletest/googletest CACHE STRING "Google Test source root")

include_directories(${GOOGLETEST_ROOT}/include ${GOOGLETEST_ROOT})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

add_executable(TemperatureControllerTests TemperatureControllerTests.cpp MockTemperatureSensor.h MockCoolingDevice.h MockHeatingDevice.h)

target_link_libraries(TemperatureControllerTests
        TemperatureControllerLib
        gtest
        gtest_main
        pthread)
