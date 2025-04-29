#pragma once

#include <iostream>

class Vehicle {
    protected:
        int year;
        double weight;
        int maxSpeed;

    public:
        int getYear();
        double getWeight();
        int getMaxSpeed();

        friend std::istream& operator>>(std::istream& is, Vehicle& vehicle);
        friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);
};

