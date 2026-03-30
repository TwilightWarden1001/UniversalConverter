#include "ConverterMiddleman.h"
#include "temperatureconverter.h"

string ConverterMiddleman::route(string tabName, string input, string fromUnit, string toUnit) 
{
    string output;

    if (tabName == "Temperature") {
        TemperatureConverter tempConverter;
        double temp = stod(input);

        if (fromUnit == "Fahrenheit" && toUnit == "Celsius") {
            double finalTemp = tempConverter.fahrenheitToCelsius(temp);
            output = to_string(finalTemp);
        }
        else if (fromUnit == "Celsius" && toUnit == "Fahrenheit") {
            double finalTemp = tempConverter.celsiusToFahrenheit(temp);
            output = to_string(finalTemp);
        }
    }

    return output;
}