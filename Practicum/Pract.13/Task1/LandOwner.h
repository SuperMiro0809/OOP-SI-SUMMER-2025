#pragma once

#include "Parcel.h"

class LandOwner {
    Parcel** parcels;
    int size;
    int capacity;

    void resize(int newCapacity);

    void copyFromDynamic(const LandOwner& other);

    void freeDynamic();

    public:
        LandOwner();

        LandOwner(const LandOwner& other);

        ~LandOwner();

        LandOwner& operator=(const LandOwner& other);

        void add(const Parcel& p);

        void add(const char* str);

        void removeAt(int index);

        double getAllPerimeter() const;

        double getAllArea() const;
};