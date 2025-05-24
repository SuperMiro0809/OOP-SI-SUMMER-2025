#pragma once

class Parcel {
    public:
        virtual double getPerimeter() const = 0;

        virtual double getArea() const = 0;

        virtual Parcel* clone() const = 0;

        virtual ~Parcel() = default;
};