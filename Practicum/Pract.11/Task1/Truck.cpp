#include "Truck.h"

std::istream& operator>>(std::istream& is, Truck& truck) {
    operator>>(is, (RoadVehicle&)truck);

    is >> truck.cargoWeight;

    return is;
}

std::ostream& operator<<(std::ostream& os, const Truck& truck) {
    operator<<(os, (RoadVehicle&)truck);

    os << truck.cargoWeight;

    return os;
}
