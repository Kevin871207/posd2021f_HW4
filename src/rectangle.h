#pragma once

#include <iostream>
#include <sstream>
#include <string>

#include "./iterator/null_iterator.h"
#include "./shape.h"
#include "./visitor/shape_visitor.h"

class Rectangle : public Shape {
   public:
    Rectangle(double length, double width) : _length(length), _width(width) {
        if (length <= 0.0 || width <= 0.0) {
            throw std::invalid_argument("(length, width) should be positive.\n");
        }
        _length = length;
        _width = width;
    }

    double area() const override {
        return _length * _width;
    }

    double perimeter() const override {
        return (_length + _width) * 2.0;
    }

    std::string info() const override {
        std::stringstream ss;
        ss.setf(std::ios::fixed);
        ss.precision(2);
        ss << "Rectangle ("
           << round(_length * 100.0) / 100.0 << " "
           << round(_width * 100.0) / 100.0 << ")";
        return ss.str();
    }

    void accept(ShapeVisitor* visitor) override {
        visitor->visitRectangle(this);
    }

    Iterator* createIterator() override {
        return new NullIterator();
    }

   private:
    double _length= 0.0, _width= 0.0;
};
