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

            // We have to do it IN here to make sure it doesn't display
            // an invalid input BEFORE we have checked if the input is valid
            if (fromUnit == toUnit) {
                output = input;
                return output;
            }

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
            output = error_string + "Please enter a valid number. Your number may include decimals but not letters.";
            return output;
        } catch (const std::out_of_range& e) {
            output = error_string + "Your number is too large. Please enter a smaller one";
            return output;
        }
    }

    return output;
}