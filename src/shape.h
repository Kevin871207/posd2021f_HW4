#pragma once

#include <string>

#include "./iterator/iterator.h"

class Iterator;
class ShapeVisitor;

class Shape {
public:
    virtual ~Shape() {};

    virtual double area() const = 0;

    virtual double perimeter() const = 0;

    virtual std::string info() const = 0;

    virtual Iterator* createIterator() = 0;

    virtual void addShape(Shape* shape) {
      throw std::string("Method addShape not allowed.");
    }

    virtual void deleteShape(Shape* shape) {
      throw std::string("Method deleteShape not allowed.");
    }

    virtual void accept(ShapeVisitor* visitor) = 0;
};
