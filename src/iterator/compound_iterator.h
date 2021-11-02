#pragma once

#include <string>

#include "../shape.h"
#include "iterator.h"

// you should define a template class or type `ForwardIterator`
template <class ForwardIterator>
class CompoundIterator : public Iterator{
public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end) {
        _begin = begin;
        _end = end;
        first();
    }

    void first() override {
        _current = _begin;
    }

    Shape* currentItem() const override {
        if (isDone()) {
          throw std::string("Current item should throw exception when is done.");
        }
        return *_current;
    }

    void next() override {
        if (isDone()) {
          throw std::string("Next should throw exception when is done.");
        }
        _current++;
    }

    bool isDone() const override {
        return _current == _end;
    }

private:
    ForwardIterator _begin;
    ForwardIterator _current;
    ForwardIterator _end;
};
