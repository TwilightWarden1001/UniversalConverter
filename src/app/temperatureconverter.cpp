#include "temperatureconverter.h"

double TemperatureConverter::fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}