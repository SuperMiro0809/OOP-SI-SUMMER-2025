#pragma once

#include "RailVehicle.h"

class PassangerTrain: public RailVehicle {
    int passangersCount;

    friend std::istream& operator>>(std::istream& is, PassangerTrain& train);
    friend std::ostream& operator<<(std::ostream& os, const PassangerTrain& train);
};
