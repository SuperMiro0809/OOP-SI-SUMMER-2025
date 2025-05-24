#include "RectangleParcel.h"

RectangleParcel::RectangleParcel(double a, double b) {
    this->a = a;
    this->b = b;
}

Parcel* RectangleParcel::clone() const {
    return new RectangleParcel(*this);
}

double RectangleParcel::getPerimeter() const {
    return 2 * a + 2 * b;
}

double RectangleParcel::getArea() const {
    return a * b;
}