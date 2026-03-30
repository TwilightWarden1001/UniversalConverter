#include "temperatureconverter.h"

double TemperatureConverter::fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}

double TemperatureConverter::celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 1.8) + 32;
    return fahrenheit;
}