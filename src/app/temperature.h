#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include <string>

class TemperatureConverter {
    private:
        const double ABSOLUTE_ZERO_OFFSET = 273.15;
        const double FAHRENHEIT_OFFSET = 32.0;
        const double SCALE_FACTOR = 5.0 / 9.0;
        const double INVERSE_SCALE_FACTOR = 9.0 / 5.0;
    public:
        // Base Unit: Kelvin
        // Functions to convert TO Kelvin
        double fahrenheitToKelvin(double fahrenheit);
        double celsiusToKelvin(double celsius);
        double rankineToKelvin(double rankine);
        
        // Functions to convert FROM Kelvin
        double kelvinToFahrenheit(double kelvin);
        double kelvinToCelsius(double kelvin);
        double kelvinToRankine(double kelvin);

        // Function for calculating the final temperature
        double convertTemperature(double temp, std::string fromUnit, std::string toUnit);
};
#endif 