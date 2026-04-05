#ifndef TEMPERATURECONVERTER_H
#define TEMPERATURECONVERTER_H

#include <string>

class TemperatureConverter {
    private:
        const double ABSOLUTE_ZERO_OFFSET = 273.15;
        const double FAHRENHEIT_OFFSET = 32.0;
        const double SCALE_FACTOR = 5.0 / 9.0;
        const double INVERSE_SCALE_FACTOR = 9.0 / 5.0;
    public:
        // Functions to convert to Kelvin (chosen base unit)
        double fahrenheitToKelvin(double fahrenheit);
        double celsiusToKelvin(double celsius);
        double rankineToKelvin(double rankine);
        
        // Functions to convert from Kelvin to the unit chosen
        double kelvinToFahrenheit(double kelvin);
        double kelvinToCelsius(double kelvin);
        double kelvinToRankine(double kelvin);

        // Function for calculating the final temperature
        double convertTemperature(double temp, std::string fromUnit, std::string toUnit);
};
#endif 