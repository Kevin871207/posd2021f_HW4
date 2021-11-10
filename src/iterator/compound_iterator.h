#pragma once

#include <string>

#include "../article.h"
#include "iterator.h"

template <class ForwardIterator>
class CompoundIterator : public Iterator {
   public:
    CompoundIterator(ForwardIterator begin, ForwardIterator end) {
        _begin = begin;
        _end = end;
        first();
    }

    void first() override {
        _current = _begin;
    }

    Article* currentItem() const override {
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
