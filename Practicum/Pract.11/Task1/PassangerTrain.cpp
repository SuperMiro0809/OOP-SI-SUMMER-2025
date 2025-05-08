#include "PassangerTrain.h"

std::istream& operator>>(std::istream& is, PassangerTrain& train) {
  operator>>(is, (RailVehicle&)train);

  is >> train.passangersCount;

  return is;
}

std::ostream& operator<<(std::ostream& os, const PassangerTrain& train) {
    operator<<(os, (RailVehicle&)train);

    os << train.passangersCount;

    return os;
}
