#pragma once

#include <string>

#include "iterator.h"
#include "../shape.h"

class NullIterator : public Iterator {
public:
    void first() override {
        throw std::string("Method not allowed");
     }

    Shape* currentItem() const override {
        if (isDone()) {
            throw std::string("no current item");
        }
        return nullptr;
    }

    void next() override {
        throw std::string("Method not allowed");
    }

    bool isDone() const override {
        return true;
    }
};
