#ifndef TEMPERATURECONVERTER_H
#define TEMPERATURECONVERTER_H

#include <string>
using namespace std;

class TemperatureConverter {
    public:
        double fahrenheitToCelsius(double fahrenheit);
        double celsiusToFahrenheit(double celsius);
};
#endif 