#pragma once

#include "Vehicle.h"
#include <iostream>

class RoadVehicle: public Vehicle {
    void freeDynamic();

    void copyFromDynamic(const RoadVehicle& other);

    protected:
        int tireCount;
        char* ramaNumber;

    public:
        RoadVehicle() = default;

        RoadVehicle(const RoadVehicle& other);

        ~RoadVehicle();

        RoadVehicle& operator=(const RoadVehicle& other);

        friend std::istream& operator>>(std::istream& is, RoadVehicle& vehicle);
        friend std::ostream& operator<<(std::ostream& os, const RoadVehicle& vehicle);
};

