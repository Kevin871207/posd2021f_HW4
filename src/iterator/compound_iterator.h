#pragma once

#include "iterator.h"
#include "../shape.h"

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
        return *_current;
    }

    void next() override {
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
