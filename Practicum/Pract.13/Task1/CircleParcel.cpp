#include "CircleParcel.h"

#include <math.h>

CircleParcel::CircleParcel(double r) {
    this->r = r;
}

Parcel* CircleParcel::clone() const {
    return new CircleParcel(*this);
}

double CircleParcel::getPerimeter() const {
    return 2 * M_PI * r;
}

double CircleParcel::getArea() const {
    return M_PI * r * r;
}