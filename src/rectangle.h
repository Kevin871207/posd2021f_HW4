#pragma once
#include <sstream>
#include <string>
#include "shape.h"

class Rectangle : public Shape {
public:
    Rectangle(double length, double width) {
        if (length <= 0.0 || width <= 0.0) {
            throw std::invalid_argument("(length, width) should be positive.\n");
        }
        _length = length;
        _width = width;
    }

    double area() const {
        return _length * _width;
    }

    double perimeter() const {
        return (_length + _width) * 2.0;
    }

    std::string info() const {
        std::stringstream ss;
        ss.setf(std::ios::fixed);
        ss.precision(2);
        ss << "Rectangle (" << _length << " " << _width << ")\n";
        return ss.str();
    }

private:
    double _length = 0.0;
    double _width = 0.0;
};
