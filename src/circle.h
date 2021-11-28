#pragma once

#include <cmath>
#include <sstream>
#include <string>

#include "./iterator/null_iterator.h"
#include "./shape.h"
#include "./visitor/shape_visitor.h"

class Circle : public Shape {
   public:
    Circle(double radius) : _radius(radius) {
        if (radius <= 0.0) {
            throw std::invalid_argument("(radius) should be positive.\n");
        }
        _radius = radius;
    }

    double area() const override {
        return _radius * _radius * M_PI;
    }

    double perimeter() const override {
        return 2.0 * _radius * M_PI;
    }

    std::string info() const override {
        std::stringstream ss;
        ss.setf(std::ios::fixed);
        ss.precision(2);
        ss << "Circle ("
           << round(_radius * 100.0) / 100.0 << ")";
        return ss.str();
    }

    void accept(ShapeVisitor* visitor) override {
        visitor->visitCircle(this);
    }

    Iterator* createIterator() override {
        return new NullIterator();
    }

   private:
    double _radius = 0.0;
};