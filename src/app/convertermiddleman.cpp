#include "convertermiddleman.h"
#include "temperatureconverter.h"
#include <stdexcept>

string ConverterMiddleman::route(string tabName, string input, string fromUnit, string toUnit) 
{
    string output;
    string error_string = "ERROR: ";

    if (tabName == "Temperature") {
        TemperatureConverter tempConverter;
        double temp;

        try {
            temp = stod(input);

            if (fromUnit == "Fahrenheit" && toUnit == "Celsius") {
                double finalTemp = tempConverter.fahrenheitToCelsius(temp);
                output = to_string(finalTemp);
            }
            else if (fromUnit == "Celsius" && toUnit == "Fahrenheit") {
                double finalTemp = tempConverter.celsiusToFahrenheit(temp);
                output = to_string(finalTemp);
            }
            else if (fromUnit == "Celsius" && toUnit == "Kelvin") {
                double finalTemp = tempConverter.celsiusToKelvin(temp);
                output = to_string(finalTemp);
            }
            else if (fromUnit == "Kelvin" && toUnit == "Celsius") {
                double finalTemp = tempConverter.kelvinToCelsius(temp);
                output = to_string(finalTemp);
            }
            else if (fromUnit == "Fahrenheit" && toUnit == "Kelvin") {
                double finalTemp = tempConverter.fahrenheitToKelvin(temp);
                output = to_string(finalTemp);
            }
            else if (fromUnit == "Kelvin" && toUnit == "Fahrenheit") {
                double finalTemp = tempConverter.kelvinToFahrenheit(temp);
                output = to_string(finalTemp);
            }
        } catch (const std::invalid_argument& e) {
            output = error_string.append("Please enter a valid number.");
            return output;
        } catch (const std::out_of_range& e) {
            output = error_string.append("Your number is too large.");
            return output;
        }
    }

    return output;
}