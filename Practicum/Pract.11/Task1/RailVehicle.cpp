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
}
