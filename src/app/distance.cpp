#include "distance.h"

// nanometer
// micrometer
// decimeter
// decameter
// whatever 100 meters are
// Furlongs? I think I hear my grandma say that once but I do not think that is standardized
// TECHNICALLY light years

// TO Meters
double DistanceConverter::millimetersToMeters(double millimeters) {
    return millimeters / ONE_THOUSAND;
}
double DistanceConverter::centimetersToMeters(double centimeters) {
    return centimeters / ONE_HUNDRED;
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

// FROM Meters
double DistanceConverter::metersToMillimeters(double meters) {
    return meters * ONE_THOUSAND;
}
double DistanceConverter::metersToCentimeters(double meters) {
    return meters * ONE_HUNDRED;
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

double DistanceConverter::convertDistance(double distance, std::string fromUnit, std::string toUnit) {
    // TO Meters
    if (fromUnit == "Millimeter") {
        distance = millimetersToMeters(distance);
    } else if (fromUnit == "Centimeter") {
        distance = centimetersToMeters(distance);
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
    }
    // FROM Meters
    if (toUnit == "Millimeter") {
        distance = metersToMillimeters(distance);
    } else if (toUnit == "Centimeter") {
        distance = metersToCentimeters(distance);
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
    }
    return distance;
}
