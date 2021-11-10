#include "../src/compound_shape.h"
#include "../src/iterator/iterator.h"
#include "../src/iterator/compound_iterator.h"

/* CompoundIterator */
TEST(CaseCompoundIterator, Creation) {
  ASSERT_NO_THROW(new CompoundShape());
}

TEST(CaseCompoundIterator, CompoundIteratorIsAIterator) {
  CompoundShape* cs1 = new CompoundShape();
  Iterator* it = cs1->createIterator();
  ASSERT_TRUE(typeid(it).name() == typeid(Iterator*).name());
  delete cs1;
}

TEST(CaseCompoundIterator, FirstNoException) {
  CompoundShape* cs1 = new CompoundShape();
  Iterator* it = cs1->createIterator();
  ASSERT_NO_THROW(it->first());
  delete cs1;
}

TEST(CaseCompoundIterator, CurrentItemIsCorrect) {
  CompoundShape* cs1 = new CompoundShape();
  Shape* c1 = new Circle(10);
  cs1->addShape(c1);
  Iterator* it = cs1->createIterator();
  ASSERT_EQ(it->currentItem(), c1);
  delete cs1;
  delete c1;

}

TEST(CaseCompoundIterator, CurrentItemShouldThrowExceptionWhenIsDone1) {
  CompoundShape* cs1 = new CompoundShape();
  Iterator* it = cs1->createIterator();
  ASSERT_TRUE(it->isDone());
  ASSERT_ANY_THROW(it->currentItem());
  delete cs1;
}

TEST(CaseCompoundIterator, CurrentItemShouldThrowExceptionWhenIsDone2) {
  CompoundShape* cs1 = new CompoundShape();
  cs1->addShape(new Circle(10));
  Iterator* it = cs1->createIterator();
  it->next();
  ASSERT_ANY_THROW(it->currentItem());
  delete cs1;
}

TEST(CaseCompoundIterator, NextNoException) {
  CompoundShape* cs1 = new CompoundShape();
  cs1->addShape(new Circle(10));
  Iterator* it = cs1->createIterator();
  ASSERT_NO_THROW(it->next());
  delete cs1;
}

TEST(CaseCompoundIterator, NextShouldThrowExceptionWhenIsDone) {
  CompoundShape* cs1 = new CompoundShape();
  Iterator* it = cs1->createIterator();
  ASSERT_ANY_THROW(it->next());
  delete cs1;
}

TEST(CaseCompoundIterator, IsDoneShouldBeCorrect1) {
  CompoundShape* cs1 = new CompoundShape();
  cs1->addShape(new Circle(10));
  Iterator* it = cs1->createIterator();
  ASSERT_FALSE(it->isDone());
  delete cs1;
}

TEST(CaseCompoundIterator, IsDoneShouldBeCorrect2) {
  CompoundShape* cs1 = new CompoundShape();
  Iterator* it = cs1->createIterator();
  ASSERT_TRUE(it->isDone());
  delete cs1;
}

// TEST(CaseCompoundIterator, CompoundIteratorIsDone) {
//   CompoundShape* cs1 = new CompoundShape();
//   cs1->addShape(new Circle(10.0));
//   Iterator* it = cs1->createIterator();
//   ASSERT_NEAR(314.159, it->currentItem()->area(), 0.001);
//   it->next();
//   ASSERT_ANY_THROW(it->isDone());
// }

/* NullIterator */
TEST(CaseNullIterator, NullIteratorIsAIterator) {
  Iterator* it = new NullIterator();
  ASSERT_TRUE(typeid(it).name() == typeid(Iterator*).name());
}

TEST(CaseNullIterator, RectangleIsDoneIsTrue) {
  Shape* r1 = new Rectangle(3.14, 4);
  Iterator* it = r1->createIterator();
  ASSERT_TRUE(it->isDone());
  delete r1;
}

TEST(CaseNullIterator, CircleIsDoneIsTrue) {
  Shape* c1 = new Circle(4.0);
  Iterator* it = c1->createIterator();
  ASSERT_TRUE(it->isDone());
  delete c1;
}

TEST(CaseNullIterator, TriangleIsDoneIsTrue) {
  TwoDimensionalVector vec1(1, 2);
  TwoDimensionalVector vec2(3, 4);
  Shape* t1 = new Triangle(vec1, vec2);
  Iterator* it = t1->createIterator();
  ASSERT_TRUE(it->isDone());
  delete t1;
}

TEST(CaseNullIterator, FirstShouldThrowException) {
  Shape* r1 = new Rectangle(3.14, 4);
  Iterator* it = r1->createIterator();
  ASSERT_ANY_THROW(it->first());
  delete r1;
}

TEST(CaseNullIterator, CurrentItemtShouldThrowException) {
  Shape* r1 = new Rectangle(3.14, 4);
  Iterator* it = r1->createIterator();
  ASSERT_ANY_THROW(it->currentItem());
  delete r1;
}

TEST(CaseNullIterator, NextShouldThrowException) {
  Shape* r1 = new Rectangle(3.14, 4);
  Iterator* it = r1->createIterator();
  ASSERT_ANY_THROW(it->next());
  delete r1;
}
