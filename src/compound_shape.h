#pragma once

#include <iostream>
#include <list>
#include <sstream>
#include <string>

#include "./shape.h"
#include "./iterator/compound_iterator.h"
#include "./iterator/iterator.h"
#include "./visitor/shape_visitor.h"


class CompoundShape : public Shape {
   public:
    ~CompoundShape() {
        for(Shape* s : _shapes) {
            delete s;
        }
    }

    double area() const override {
        double result = 0;
        for(Shape* s : _shapes){
            result += s->area();
        }
        return result;
    }

    double perimeter() const override {
        double result = 0;
        for(Shape* s : _shapes){
            result += s->perimeter();
        }
        return result;
    }

    std::string info() const override {
        return "CompoundShape";
    }

    void accept(ShapeVisitor* visitor) override {
        visitor->visitCompoundShape(this);
    }

    Iterator* createIterator() override {
        return new CompoundIterator<std::list<Shape*>::iterator>(_shapes.begin(), _shapes.end());
    }

    void addShape(Shape* shape) override {
        _shapes.push_back(shape);
    }

    void deleteShape(Shape* shape) override {
        for(auto it = _shapes.begin() ; it != _shapes.end() ; it++){
            if(*it == shape){
                delete *it;
                _shapes.erase(it);
                break;
            }else{
                Iterator *shapeIt = (*it)->createIterator();
                if(!shapeIt->isDone())
                    (*it)->deleteShape(shape);
                delete shapeIt;
            }
        }
    }

   private:
    std::list<Shape*> _shapes;
};