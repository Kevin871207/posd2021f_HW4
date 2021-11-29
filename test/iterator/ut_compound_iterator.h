#include "../../src/compound_shape.h"
#include "../../src/iterator/iterator.h"
#include "../../src/iterator/compound_iterator.h"

class CaseCompoundIterator : public ::testing::Test {
protected:
    Iterator* compoundIterator1;
    Iterator* compoundIterator2;

    std::list<Shape*> _shapes;
    Shape* c10;
    void SetUp() override {
        c10 = new Circle(10);
        _shapes.push_back(c10);
        compoundIterator1 = new CompoundIterator<std::list<Shape*>::iterator>(_shapes.begin(), _shapes.end());
    }

    void TearDown() override {
        delete compoundIterator1;

        for(Shape* s : _shapes) {
            delete s;
        }
    }
};

TEST_F(CaseCompoundIterator, CompoundIteratorIsAIterator) {
    Iterator* c = compoundIterator1;
    ASSERT_TRUE(typeid(c).name() == typeid(Iterator*).name());
}

TEST_F(CaseCompoundIterator, FirstNoException) {
    ASSERT_NO_THROW(compoundIterator1->first());
}

TEST_F(CaseCompoundIterator, CurrentItemIsCorrect) {
    ASSERT_EQ(compoundIterator1->currentItem(), c10);
}

TEST_F(CaseCompoundIterator, NextNoException) {
    ASSERT_NO_THROW(compoundIterator1->next());
}

TEST_F(CaseCompoundIterator, IsDoneShouldBeTrue) {
    ASSERT_FALSE(compoundIterator1->isDone());
}

TEST_F(CaseCompoundIterator, CurrentItemShouldThrowExceptionWhenIsDone) {
    compoundIterator1->next();
    ASSERT_ANY_THROW(compoundIterator1->currentItem());
}

TEST_F(CaseCompoundIterator, NextShouldThrowExceptionWhenIsDone ) {
    compoundIterator1->next();
    ASSERT_ANY_THROW(compoundIterator1->next());
}
