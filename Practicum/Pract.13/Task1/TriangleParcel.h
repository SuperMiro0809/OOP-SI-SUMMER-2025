#pragma once

#include "Parcel.h"

class TriangleParcel: public Parcel {
    double a;
    double b;
    double c;

    public:
        TriangleParcel(double a, double b, double c);

        Parcel* clone() const override;

        double getPerimeter() const override;

        double getArea() const override;
};
