#include "Vehicle.h"

int Vehicle::getYear() {
  return year;
}

double Vehicle::getWeight() {
  return weight;
}

int Vehicle::getMaxSpeed() {
  return maxSpeed;
}

std::istream& operator>>(std::istream& is, Vehicle& vehicle) {
  is >> vehicle.year >> vehicle.weight >> vehicle.maxSpeed;
  return is;
}

std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle) {
  os << vehicle.year << ' ' << vehicle.weight << ' ' << vehicle.maxSpeed;
  return os;
}