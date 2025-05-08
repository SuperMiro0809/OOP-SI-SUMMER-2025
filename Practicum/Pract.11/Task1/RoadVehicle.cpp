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

    return *this;
}

std::istream& operator>>(std::istream& is, RoadVehicle& vehicle) {
    operator>>(is, (Vehicle&)vehicle);

    char buffer[1024];
    is >> buffer;

    size_t inputLen = std::strlen(buffer);
    vehicle.ramaNumber = new char[inputLen + 1];
    std::strcpy(vehicle.ramaNumber, buffer);

    is >> vehicle.tireCount;

    return is;
}

std::ostream& operator<<(std::ostream& os, const RoadVehicle& vehicle) {
    operator<<(os, (Vehicle&)vehicle); // os<<(Vehicle)vehicle;

    os << vehicle.ramaNumber << ' ' << vehicle.tireCount;

    return os;
}
