#pragma once

#include "Parcel.h"
#include "RectangleParcel.h"
#include "CircleParcel.h"
#include "TriangleParcel.h"

class ParcelFactory {
    public:
        static Parcel* create(const char* str);
};