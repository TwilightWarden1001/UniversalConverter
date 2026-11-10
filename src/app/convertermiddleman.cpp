#include "convertermiddleman.h"
#include "temperature.h"
#include "distance.h"
#include <stdexcept>
string error_string = "ERROR: ";

string ConverterMiddleman::route(string tabName, string input, string fromUnit, string toUnit) 
{
    string output;

    if (fromUnit == toUnit) {
        return input; // Edge case so that we don't waste time looking AND the functions don't have to deal with it
    } else if (tabName == "Temperature") {
        output = routeTemperature(input, fromUnit, toUnit);
    } else if (tabName == "Distance") {
        output = routeDistance(input, fromUnit, toUnit);
    }
    return output;
}

string ConverterMiddleman::routeTemperature(string input, string fromUnit, string toUnit) { 
    TemperatureConverter tempConverter;
    double temp;

    try {
        // Attempt to convert the string to a double
        temp = stod(input);
        temp = tempConverter.convertTemperature(temp, fromUnit, toUnit);
        input = to_string(temp);
        return input;
    } catch (const std::invalid_argument& e) {
        input = error_string + "Please enter a valid number. Your number may include decimals but not letters.";
        return input;
    } catch (const std::out_of_range& e) {
        input = error_string + "Your number is too large. Please enter a smaller one";
        return input;
    }
}

string ConverterMiddleman::routeDistance(string input, string fromUnit, string toUnit) {
    DistanceConverter distConverter;
    double distance;

    try {
        // Attempt to convert the string to a double
        distance = stod(input);
        distance = distConverter.convertDistance(distance, fromUnit, toUnit);
        input = to_string(distance);
        return input;
    } catch (const std::invalid_argument& e) {
        input = error_string + "Please enter a valid number. Your number may include decimals but not letters.";
        return input;
    } catch (const std::out_of_range& e) {
        input = error_string + "Your number is too large. Please enter a smaller one";
        return input;
    }
}