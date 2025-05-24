#include "LandOwner.h"
#include "ParcelFactory.h"
#include <iostream>

void LandOwner::copyFromDynamic(const LandOwner& other) {
    parcels = new Parcel*[other.capacity];

    for (int i = 0; i < other.size; i++) {
        parcels[i] = other.parcels[i]->clone();
    }
}

void LandOwner::freeDynamic() {
    for (int i = 0; i < size; i++) {
        delete parcels[i];
    }

    delete[] parcels;
}

void LandOwner::resize(int newCapacity) {
    capacity = newCapacity;
    Parcel** temp = new Parcel*[capacity];

    for (int i = 0; i < size; i++) {
        temp[i] = parcels[i];
    }

    delete[] parcels;
    parcels = temp;
}

LandOwner::LandOwner() {
    size = 0;
    capacity = 8;
    parcels = new Parcel*[capacity];
}

LandOwner::LandOwner(const LandOwner& other) {
    size = other.size;
    capacity = other.capacity;
    copyFromDynamic(other);
}

LandOwner::~LandOwner() {
    freeDynamic();
}

LandOwner& LandOwner::operator=(const LandOwner& other) {
    if (this != &other) {
        size = other.size;
        capacity = other.capacity;
        copyFromDynamic(other);
    }

    return *this;
}

void LandOwner::add(const Parcel& p) {
    if (size == capacity) {
        resize(capacity * 2);
    }

    parcels[size++] = p.clone();
}

void LandOwner::add(const char* str) {
    if (size == capacity) {
        resize(capacity * 2);
    }

    parcels[size++] = ParcelFactory::create(str);
}

void LandOwner::removeAt(int index) {
    if (index < 0 || index >= size) {
        std::cout << "error" << std::endl;
        return;
    }

    delete parcels[index];
    for (int i = index; i < size - 1; i++) {
        parcels[i] = parcels[i + 1];
    }

    size--;
}

double LandOwner::getAllPerimeter() const {
    double all = 0;

    for (int i = 0; i < size; i++) {
        all += parcels[i]->getPerimeter();
    }

    return all;
}

double LandOwner::getAllArea() const {
    double all = 0;

    for (int i = 0; i < size; i++) {
        all += parcels[i]->getArea();
    }

    return all;
}
