#include "CargoTrain.h"

std::istream& operator>>(std::istream& is, CargoTrain& train) {
    operator>>(is, (RailVehicle&)train);

    is >> train.depoNumber;

    return is;
}

std::ostream& operator<<(std::ostream& os, const CargoTrain& train) {
  operator<<(os, (RailVehicle&)train);

  os << train.depoNumber;

  return os;
}
