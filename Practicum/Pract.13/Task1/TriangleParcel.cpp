#include "TriangleParcel.h"

#include "math.h"

TriangleParcel::TriangleParcel(double a, double b, double c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

Parcel* TriangleParcel::clone() const {
    return new TriangleParcel(*this);
}

double TriangleParcel::getPerimeter() const {
    return a + b + c;
}

double TriangleParcel::getArea() const {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}