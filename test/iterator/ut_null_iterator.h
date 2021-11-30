#include "../../src/iterator/iterator.h"
#include "../../src/iterator/null_iterator.h"

class CaseNullIterator : public ::testing::Test {
protected:
    Iterator* nullIterator;

    void SetUp() override {
        nullIterator = new NullIterator();
    }

    void TearDown() override {
        delete nullIterator;
    }
};

TEST_F(CaseNullIterator, NullIteratorIsAIterator) {
    Iterator* n = nullIterator;
    ASSERT_TRUE(typeid(n).name() == typeid(Iterator*).name());
}

TEST_F(CaseNullIterator, FirstShouldThrowException) {
    ASSERT_ANY_THROW(nullIterator->first());
}

TEST_F(CaseNullIterator, CurrentItemShouldThrowException) {
    ASSERT_ANY_THROW(nullIterator->currentItem());
}

TEST_F(CaseNullIterator, NextShouldThrowException) {
    ASSERT_ANY_THROW(nullIterator->next());
}

TEST_F(CaseNullIterator, IsDoneShouldBeTrue) {
    ASSERT_TRUE(nullIterator->isDone());
}
