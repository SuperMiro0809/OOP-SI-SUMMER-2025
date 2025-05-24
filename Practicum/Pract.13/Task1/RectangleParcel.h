#pragma once

#include "Parcel.h"

class RectangleParcel: public Parcel {
    double a;
    double b;

    public:
        RectangleParcel(double a, double b);

        Parcel* clone() const override;

        double getPerimeter() const override;

        double getArea() const override;
};
