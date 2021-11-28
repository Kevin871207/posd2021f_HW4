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
TEST_F(CaseNullIterator, first) {
    Iterator* nullIterator = new NullIterator();
    ASSERT_ANY_THROW(nullIterator->first());
}

TEST_F(CaseNullIterator, currentItem) {
    ASSERT_ANY_THROW(nullIterator->currentItem());
}

TEST_F(CaseNullIterator, next) {
    ASSERT_ANY_THROW(nullIterator->next());
}

TEST_F(CaseNullIterator, isDone) {
    ASSERT_TRUE(nullIterator->isDone());
}
