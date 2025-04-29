#include "RoadVehicle.h"

#include <iostream>

void RoadVehicle::freeDynamic() {
    delete[] ramaNumber;
}

void RoadVehicle::copyFromDynamic(const RoadVehicle& other) {
    tireCount = other.tireCount;

    ramaNumber = new char[strlen(other.ramaNumber) + 1];
    strcpy(ramaNumber, other.ramaNumber);
}

RoadVehicle::RoadVehicle(const RoadVehicle& other): Vehicle(other) {
    copyFromDynamic(other);
}

RoadVehicle::~RoadVehicle() {
    freeDynamic();
}

RoadVehicle& RoadVehicle::operator=(const RoadVehicle& other) {
    if (this != &other) {
        Vehicle::operator=(other);
        freeDynamic();
        copyFromDynamic(other);
    }
}

std::istream& operator>>(std::istream& is, RoadVehicle& vehicle) {
   // operator>>(is, (Vehicle)vehicle);

    return is;
}

std::ostream& operator<<(std::ostream& os, const RoadVehicle& vehicle) {
    operator<<(os, (Vehicle)vehicle); // os<<(Vehicle)vehicle;

    os << vehicle.ramaNumber << ' ' << vehicle.tireCount;

    return os;
}
