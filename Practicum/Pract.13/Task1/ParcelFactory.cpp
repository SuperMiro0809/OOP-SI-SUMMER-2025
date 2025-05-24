#include "ParcelFactory.h"

#include <sstream>

Parcel* ParcelFactory::create(const char* str) {
    std::stringstream ss(str);
    char cmd[1024];
    ss >> cmd;

    if (std::strcmp(cmd, "rectangle") == 0) {
        double a, b;
        ss >> a >> b;
        return new RectangleParcel(a, b);
    } else if (std::strcmp(cmd, "circle") == 0) {
        double r;
        ss >> r;
        return new CircleParcel(r);
    } else if (std::strcmp(cmd, "triangle") == 0) {
         double a, b, c;
         ss >> a >> b >> c;
         return new TriangleParcel(a, b, c);
    }

    return nullptr;
}