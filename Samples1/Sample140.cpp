#include <iostream>
#include <cmath>

using namespace std;

double convertLitersToKg(double liters) { 
    return liters * 0.8; 
}

double calculateFuelRate(double fuelConsumed, double time) {
    return fuelConsumed / (time * 3600);
}

int main() {
    double fuelLiters = 720000;
    double timeHours = 2;

    double fuelKg = convertLitersToKg(fuelLiters);
    double fuelRate = calculateFuelRate(fuelKg, timeHours);

    cout << "Fuel Rate: " << fuelRate << " kg/s" << endl;
}