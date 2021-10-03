#pragma once

#include <cmath>
#include <sstream>
#include <string>

#include "shape.h"

class Circle : public Shape {
public:
    Circle(double radius) {
        if (radius <= 0.0) {
            throw std::invalid_argument("(radius) should be positive.\n");
        }
        _radius = radius;
     }

    double area() const {
        return _radius * _radius * M_PI;
    }

    double perimeter() const {
        return 2.0 * _radius * M_PI;
    }

    std::string info() const {
        std::stringstream ss;
        ss.setf(std::ios::fixed);
        ss.precision(2);
        ss << "Circle (" << round(_radius * 100.0) / 100.0 << ")";
        return ss.str();
     }

private:
    double _radius = 0.0;
};
