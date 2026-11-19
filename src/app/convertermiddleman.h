#ifndef CONVERTERMIDDLEMAN_H
#define CONVERTERMIDDLEMAN_H
#include <string>

class ConverterMiddleman {
public:
    std::string route(std::string tab, std::string input, std::string fromUnit, std::string toUnit);
private:
    const std::string error_string = "ERROR: ";
    std::string routeTemperature(std::string input, std::string fromUnit, std::string toUnit);
    std::string routeDistance(std::string input, std::string fromUnit, std::string toUnit);
};

#endif