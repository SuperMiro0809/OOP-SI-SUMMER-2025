#include "RailVehicle.h"

#include <iostream>

void RailVehicle::freeDynamic() {
    delete[] driverName;
}

void RailVehicle::copyFromDynamic(const RailVehicle& other) {
    trailerCount = other.trailerCount;

    driverName = new char[strlen(other.driverName) + 1];
    strcpy(driverName, other.driverName);
}

RailVehicle::RailVehicle(const RailVehicle& other): Vehicle(other) {
    copyFromDynamic(other);
}

RailVehicle::~RailVehicle() {
    freeDynamic();
}

RailVehicle& RailVehicle::operator=(const RailVehicle& other) {
    if (this != &other) {
        Vehicle::operator=(other);
        freeDynamic();
        copyFromDynamic(other);
    }

    return *this;
}

std::istream& operator>>(std::istream& is, RailVehicle& vehicle) {
    operator>>(is, (Vehicle&)vehicle);

    char buffer[1024];
    is >> buffer;

    size_t inputLen = std::strlen(buffer);
    vehicle.driverName = new char[inputLen + 1];
    std::strcpy(vehicle.driverName, buffer);

    is >> vehicle.trailerCount;

    return is;
}

std::ostream& operator<<(std::ostream& os, const RailVehicle& vehicle) {
    operator<<(os, (Vehicle&)vehicle);

    os << vehicle.driverName << ' ' << vehicle.trailerCount;

    return os;
}
