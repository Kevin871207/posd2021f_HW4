#pragma once

#include <string>

#include "iterator.h"
#include "../shape.h"

class NullIterator : public Iterator {
public:
    void first() override {
      throw std::string("Method null iterator first not allowed");
    }

    Shape* currentItem() const override {
      if (isDone()) {
        throw std::string("Method null iterator no current item");
      }
      return nullptr;
    }

    void next() override {
      throw std::string("Method null iterator next not allowed");
    }

    bool isDone() const override {
      return true;
    }
};
