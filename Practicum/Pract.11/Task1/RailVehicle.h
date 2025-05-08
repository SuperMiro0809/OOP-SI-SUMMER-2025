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

        friend std::istream& operator>>(std::istream& is, RailVehicle& vehicle);
        friend std::ostream& operator<<(std::ostream& os, const RailVehicle& vehicle);
};

