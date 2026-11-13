#include "distance.h"
// Light Years

// TO Meters
double DistanceConverter::nanometersToMeters(double nanometers) {
    return nanometers / ONE_BILLION;
}
double DistanceConverter::micrometersToMeters(double micrometers) {
    return micrometers / ONE_MILLION;
}
double DistanceConverter::millimetersToMeters(double millimeters) {
    return millimeters / ONE_THOUSAND;
}
double DistanceConverter::centimetersToMeters(double centimeters) {
    return centimeters / ONE_HUNDRED;
}
double DistanceConverter::decimetersToMeters(double decimeters) {
    return decimeters / TEN;
}
double DistanceConverter::decametersToMeters(double decameters) {
    return decameters * TEN;
}
double DistanceConverter::hectometersToMeters(double hectometers) {
    return hectometers * ONE_HUNDRED;
}
double DistanceConverter::kilometersToMeters(double kilometers) {
    return kilometers * ONE_THOUSAND;
}
double DistanceConverter::inchesToMeters(double inches) {
    return inches * INCH_FACTOR;
}
double DistanceConverter::feetToMeters(double feet) {
    return feet * FOOT_FACTOR;
}
double DistanceConverter::yardsToMeters(double yards) {
    return yards * YARD_FACTOR;
}
double DistanceConverter::milesToMeters(double miles) {
    return miles * MILE_FACTOR;
}
double DistanceConverter::furlongsToMeters(double furlongs) {
    return furlongs * FURLONG_FACTOR;
}

// FROM Meters
double DistanceConverter::metersToNanometers(double meters) {
    return meters * ONE_BILLION;
}
double DistanceConverter::metersToMicrometers(double meters) {
    return meters * ONE_MILLION;
}
double DistanceConverter::metersToMillimeters(double meters) {
    return meters * ONE_THOUSAND;
}
double DistanceConverter::metersToCentimeters(double meters) {
    return meters * ONE_HUNDRED;
}
double DistanceConverter::metersToDecimeters(double meters) {
    return meters * TEN;
}
double DistanceConverter::metersToDecameters(double meters) {
    return meters / TEN;
}
double DistanceConverter::metersToHectometers(double meters) {
    return meters / ONE_HUNDRED;
}
double DistanceConverter::metersToKilometers(double meters) {
    return meters / ONE_THOUSAND;
}
double DistanceConverter::metersToInches(double meters) {
    return meters / INCH_FACTOR;
}
double DistanceConverter::metersToFeet(double meters) {
    return meters / FOOT_FACTOR;
}
double DistanceConverter::metersToYards(double meters) {
    return meters / YARD_FACTOR;
}
double DistanceConverter::metersToMiles(double meters) {
    return meters / MILE_FACTOR;
}
double DistanceConverter::metersToFurlongs(double meters) {
    return meters / FURLONG_FACTOR;
}

double DistanceConverter::convertDistance(double distance, std::string fromUnit, std::string toUnit) {
    // TO Meters
    if (fromUnit == "Nanometer") {
        distance = nanometersToMeters(distance);
    } else if (fromUnit == "Micrometer") {
        distance = micrometersToMeters(distance);
    } else if (fromUnit == "Millimeter") {
        distance = millimetersToMeters(distance);
    } else if (fromUnit == "Centimeter") {
        distance = centimetersToMeters(distance);
    } else if (fromUnit == "Decimeter") {
        distance = decimetersToMeters(distance);
    } else if (fromUnit == "Decameter") {
        distance = decimetersToMeters(distance);
    } else if (fromUnit == "Hectometer") {
        distance = decimetersToMeters(distance);
    } else if (fromUnit == "Kilometer") {
        distance = kilometersToMeters(distance);
    } else if (fromUnit == "Inch") {
        distance = inchesToMeters(distance);
    } else if (fromUnit == "Foot") {
        distance = feetToMeters(distance);
    } else if (fromUnit == "Yard") {
        distance = yardsToMeters(distance);
    } else if (fromUnit == "Mile") {
        distance = milesToMeters(distance);
    } else if (fromUnit == "Furlong") {
        distance = furlongsToMeters(distance);
    } 

    // FROM Meters
    if (toUnit == "Nanometer") {
        distance = metersToNanometers(distance);
    } else if (toUnit == "Micrometer") {
        distance = metersToMicrometers(distance);
    } else if (toUnit == "Millimeter") {
        distance = metersToMillimeters(distance);
    } else if (toUnit == "Centimeter") {
        distance = metersToCentimeters(distance);
    } else if (toUnit == "Decimeter") {
        distance = metersToDecimeters(distance);
    } else if (toUnit == "Decameter") {
        distance = metersToDecameters(distance);
    } else if (toUnit == "Hectometer") {
        distance = metersToHectometers(distance);
    } else if (toUnit == "Kilometer") {
        distance = metersToKilometers(distance);
    } else if (toUnit == "Inch") {
        distance = metersToInches(distance);
    } else if (toUnit == "Foot") {
        distance = metersToFeet(distance);
    } else if (toUnit == "Yard") {
        distance = metersToYards(distance);
    } else if (toUnit == "Mile") {
        distance = metersToMiles(distance);
    } else if (toUnit == "Furlong") {
        distance = metersToFurlongs(distance);
    }

    return distance;
}
