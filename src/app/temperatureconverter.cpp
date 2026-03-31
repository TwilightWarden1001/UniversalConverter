#include "temperatureconverter.h"

double TemperatureConverter::fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}

double TemperatureConverter::celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 1.8) + 32;
    return fahrenheit;
}

double TemperatureConverter::kelvinToCelsius(double kelvin) {
    double celsius = kelvin - 273.15;
    return celsius;
}

double TemperatureConverter::celsiusToKelvin(double celsius) {
    double kelvin = celsius + 273.15;
    return kelvin;
}

double TemperatureConverter::fahrenheitToKelvin(double fahrenheit) {
    double celsius = fahrenheitToCelsius(fahrenheit);
    double kelvin = celsiusToKelvin(celsius);
    return kelvin;
}

double TemperatureConverter::kelvinToFahrenheit(double kelvin) {
    double celsius = kelvinToCelsius(kelvin);
    double fahrenheit = celsiusToFahrenheit(celsius);
    return fahrenheit;
}