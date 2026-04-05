#include "temperatureconverter.h"

// Functions to go to Kelvin for our base unit
double TemperatureConverter::fahrenheitToKelvin(double fahrenheit) {
    double celsius = (fahrenheit - FAHRENHEIT_OFFSET) * SCALE_FACTOR;
    return celsius + ABSOLUTE_ZERO_OFFSET;
}

double TemperatureConverter::celsiusToKelvin(double celsius) {
    return celsius + ABSOLUTE_ZERO_OFFSET;
}

double TemperatureConverter::rankineToKelvin(double rankine) { 
    return rankine * SCALE_FACTOR;
}

// Functions to go from Kelvin back to the other units
double TemperatureConverter::kelvinToFahrenheit(double kelvin) {
    double celsius = kelvin - ABSOLUTE_ZERO_OFFSET;
    return celsius * INVERSE_SCALE_FACTOR + FAHRENHEIT_OFFSET;
}

double TemperatureConverter::kelvinToCelsius(double kelvin) {
    return kelvin - ABSOLUTE_ZERO_OFFSET;
}

double TemperatureConverter::kelvinToRankine(double kelvin) {
    return kelvin * INVERSE_SCALE_FACTOR;
}

double TemperatureConverter::convertTemperature(double temp, std::string fromUnit, std::string toUnit) {
    // 1. Convert the temperature to kelvin
    if (fromUnit == "Fahrenheit") {
        temp = fahrenheitToKelvin(temp);
    }
    else if (fromUnit == "Celsius") {
        temp = celsiusToKelvin(temp);
    }
    else if (fromUnit == "Rankine") {
        temp = rankineToKelvin(temp);
    } 

    // 2. Convert the temperature to the unit we want
    if (toUnit == "Fahrenheit") {
        temp = kelvinToFahrenheit(temp);
    }
    else if (toUnit == "Celsius") {
        temp = kelvinToCelsius(temp);
    }
    else if (toUnit == "Rankine") {
        temp = kelvinToRankine(temp);
    }
    return temp;
}