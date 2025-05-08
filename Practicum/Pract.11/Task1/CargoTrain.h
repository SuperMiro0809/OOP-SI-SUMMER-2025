#pragma once

#include "RailVehicle.h"

class CargoTrain: public RailVehicle {
    unsigned depoNumber;

    friend std::istream& operator>>(std::istream& is, CargoTrain& train);
    friend std::ostream& operator<<(std::ostream& os, const CargoTrain& train);
};
