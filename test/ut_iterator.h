#include "../src/compound_shape.h"
#include "../src/iterator/iterator.h"
#include "../src/iterator/compound_iterator.h"

TEST(CaseCompoundIterator, Creation) {
  CompoundShape* cs1 = new CompoundShape();
  ASSERT_NO_THROW(cs1->createIterator());
}

TEST(CaseCompoundIterator, CurrentItemShouldThrowExceptionWhenIsDone) {
  CompoundShape* cs1 = new CompoundShape();
  Iterator* it = cs1->createIterator();
  ASSERT_TRUE(it->isDone());
  ASSERT_ANY_THROW(it->currentItem());
}

TEST(CaseCompoundIterator, NextShouldThrowExceptionWhenIsDone) {
  CompoundShape* cs1 = new CompoundShape();
  Iterator* it = cs1->createIterator();
  ASSERT_TRUE(it->isDone());
  ASSERT_ANY_THROW(it->next());
}

// TEST(CaseCompoundIterator, CompoundIteratorIsDone) {
//   CompoundShape* cs1 = new CompoundShape();
//   cs1->addShape(new Circle(10.0));
//   Iterator* it = cs1->createIterator();
//   ASSERT_NEAR(314.159, it->currentItem()->area(), 0.001);
//   it->next();
//   ASSERT_ANY_THROW(it->isDone());
// }

TEST(CaseNullIterator, RectangleIsDoneIsTrue) {
  Shape* r1 = new Rectangle(3.14, 4);
  Iterator* it = r1->createIterator();
  ASSERT_TRUE(it->isDone());
}

TEST(CaseNullIterator, CircleIsDoneIsTrue) {
  Shape* c1 = new Circle(4.0);
  Iterator* it = c1->createIterator();
  ASSERT_TRUE(it->isDone());
}

TEST(CaseNullIterator, TriangleIsDoneIsTrue) {
  TwoDimensionalVector vec1(1, 2);
  TwoDimensionalVector vec2(3, 4);
  Shape* t1 = new Triangle(vec1, vec2);
  Iterator* it = t1->createIterator();
  ASSERT_TRUE(it->isDone());
}

TEST(CaseNullIterator, FirstShouldThrowException) {
  Shape* r1 = new Rectangle(3.14, 4);
  Iterator* it = r1->createIterator();
  ASSERT_TRUE(it->isDone());
  ASSERT_ANY_THROW(it->first());
}

TEST(CaseNullIterator, CurrentItemtShouldThrowException) {
  Shape* r1 = new Rectangle(3.14, 4);
  Iterator* it = r1->createIterator();
  ASSERT_TRUE(it->isDone());
  ASSERT_ANY_THROW(it->currentItem());
}
