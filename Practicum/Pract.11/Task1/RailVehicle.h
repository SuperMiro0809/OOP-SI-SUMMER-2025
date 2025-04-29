#pragma once

#include "Vehicle.h"

class RailVehicle: public Vehicle {
    void freeDynamic();

    void copyFromDynamic(const RailVehicle& other);

    protected:
        int trailerCount;
        char* driverName;

    public:
        RailVehicle() = default;

        RailVehicle(const RailVehicle& other);

        ~RailVehicle();

        RailVehicle& operator=(const RailVehicle& other);
};

