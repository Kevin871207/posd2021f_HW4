#pragma once

#include <list>
#include <sstream>
#include <string>

#include "./iterator/compound_iterator.h"
#include "./iterator/iterator.h"
#include "shape.h"

class CompoundShape : public Shape {
public:
    ~CompoundShape() {
        _shapes.clear();
     }

    double area() const override {
        double totalArea = 0.0;
        for(auto shape : _shapes) {
            totalArea += shape->area();
        }
        return totalArea;
    }

    double perimeter() const override {
        double totalPerimeter = 0.0;
        for(auto shape : _shapes) {
            totalPerimeter += shape->perimeter();
        }
        return totalPerimeter;
     }

    std::string info() const override {
        std::stringstream ss;
        std::list<Shape*> ::const_iterator it;
        ss << "CompoundShape\n{";
        for (it = _shapes.begin(); it != _shapes.end(); it++) {
          ss << "\n" << (*it)->info();
        }
        ss << "\n}";
        return ss.str();
    }

    Iterator* createIterator() override {
        return new CompoundIterator<std::list<Shape *>::const_iterator>(_shapes.begin(), _shapes.end());
     }

    void addShape(Shape* shape) override {
        _shapes.push_back(shape);
    }

    void deleteShape(Shape* shape) override {
        _shapes.remove(shape);
    }

private:
    std::list<Shape *> _shapes;
};
