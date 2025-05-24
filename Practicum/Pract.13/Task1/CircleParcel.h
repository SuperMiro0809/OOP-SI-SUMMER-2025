#pragma once

#include "Parcel.h"

class CircleParcel: public Parcel {
    double r;

    public:
        explicit CircleParcel(double r);

        Parcel* clone() const override;

        double getPerimeter() const override;

        double getArea() const override;
};