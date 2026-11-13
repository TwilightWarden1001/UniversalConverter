#ifndef DISTANCE_H
#define DISTANCE_H
#include <string>

class DistanceConverter {
    private:
        const double TEN = 10.0;
        const double ONE_HUNDRED = 100.0;
        const double ONE_THOUSAND = 1000.0;
        const double ONE_MILLION = 1000000.0;
        const double ONE_BILLION = 1000000000.0;
        const double INCH_FACTOR = 0.0254;
        const double FOOT_FACTOR = 0.3048;
        const double YARD_FACTOR = 0.9144;
        const double MILE_FACTOR = 1609.344;
        const double FURLONG_FACTOR = 201.168;
    public:
        // Base Unit: Meters
        // Functions to convert TO meters
        double nanometersToMeters(double nanometers);
        double micrometersToMeters(double micrometers);
        double millimetersToMeters(double millimeters);
        double centimetersToMeters(double centimeters);
        double decimetersToMeters(double decimeters);
        double decametersToMeters(double decameters);
        double hectometersToMeters(double hectometers);
        double kilometersToMeters(double kilometers);
        double inchesToMeters(double inches);
        double feetToMeters(double feet);
        double yardsToMeters(double yards);
        double milesToMeters(double miles);
        double furlongsToMeters(double furlongs);

        // Functions to convert FROM meters
        double metersToNanometers(double meters);
        double metersToMicrometers(double meters);
        double metersToMillimeters(double meters);
        double metersToCentimeters(double meters);
        double metersToDecimeters(double meters);
        double metersToDecameters(double meters);
        double metersToHectometers(double meters);
        double metersToKilometers(double meters);
        double metersToInches(double meters);
        double metersToFeet(double meters);
        double metersToYards(double meters);
        double metersToMiles(double meters);
        double metersToFurlongs(double meters);

        // Function for calculating the final distance
        double convertDistance(double distance, std::string fromUnit, std::string toUnit);
};
#endif