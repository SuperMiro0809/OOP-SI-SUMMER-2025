#pragma once

#include "RoadVehicle.h"

class Jeep: public RoadVehicle {
    bool isAllWheelDrive;

    friend std::istream& operator>>(std::istream& is, Jeep& jeep);
    friend std::ostream& operator<<(std::ostream& os, const Jeep& jeep);
};

