#pragma once

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

class TwoDimensionalVector {
   public:
    TwoDimensionalVector(double x, double y) : _x(x), _y(y) {}

    double x() const { return _x; }

    double y() const { return _y; }

    double length() const {
        return sqrt(pow(_x, 2.0) + pow(_y, 2.0));
    }

    double dot(TwoDimensionalVector vec) const {
        return _x * vec.x() + _y * vec.y();
    }

    double cross(TwoDimensionalVector vec) const {
        return _x * vec.y() - _y * vec.x();
    }

    TwoDimensionalVector subtract(TwoDimensionalVector vec) const {
        return TwoDimensionalVector(_x - vec.x(), _y - vec.y());
    }

    std::string info() const {
        std::stringstream ss;
        ss.setf(std::ios::fixed);
        ss.precision(2);
        ss << "["
           << round(_x * 100.0) / 100.0 << ","
           << round(_y * 100.0) / 100.0 << "]";
        return ss.str();
    }

   private:
    double _x= 0.0, _y= 0.0;
};
