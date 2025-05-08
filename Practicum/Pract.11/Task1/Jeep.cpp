#include "Jeep.h"

std::istream& operator>>(std::istream& is, Jeep& jeep) {
    operator>>(is, (RoadVehicle&)jeep);

    is >> jeep.isAllWheelDrive;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Jeep& jeep) {
    operator<<(os, (RoadVehicle&)jeep);

    os << jeep.isAllWheelDrive;
    return os;
}
