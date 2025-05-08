#pragma once

#include "RoadVehicle.h"

class Truck: public RoadVehicle {
    double cargoWeight;

    friend std::istream& operator>>(std::istream& is, Truck& truck);
    friend std::ostream& operator<<(std::ostream& os, const Truck& truck);
};

