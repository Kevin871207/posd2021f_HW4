#pragma once

#include <cmath>
#include <iostream>

#include "./iterator/null_iterator.h"
#include "./shape.h"
#include "./two_dimensional_vector.h"
#include "./visitor/shape_visitor.h"

class Triangle : public Shape {
   public:
    Triangle(TwoDimensionalVector vec1, TwoDimensionalVector vec2) {
        if (vec1.cross(vec2) == 0.0) {
            throw std::invalid_argument("(vec1, vec2) should not be parallel.\n");
        }
        _vec1 = new TwoDimensionalVector(vec1.x(), vec1.y());
        _vec2 = new TwoDimensionalVector(vec2.x(), vec2.y());
    }

    double area() const override {
        return abs(_vec1->cross(*_vec2)) / 2.0;
    }

    double perimeter() const override {
        return _vec1->length() + _vec2->length() +
               _vec1->subtract(*_vec2).length();
    }

    std::string info() const override {
        std::stringstream ss;
        ss.setf(std::ios::fixed);
        ss.precision(2);
        ss << "Triangle (["
           << round(_vec1->x() * 100.0) / 100.0 << ","
           << round(_vec1->y() * 100.0) / 100.0 << "] ["
           << round(_vec2->x() * 100.0) / 100.0 << ","
           << round(_vec2->y() * 100.0) / 100.0 << "])";
        return ss.str();
    }

    void accept(ShapeVisitor* visitor) override {
        visitor->visitTriangle(this);
    }

    Iterator* createIterator() override {
        return new NullIterator();
    }

   private:
    TwoDimensionalVector *_vec1;
    TwoDimensionalVector *_vec2;
};
