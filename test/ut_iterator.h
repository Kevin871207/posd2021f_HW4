#include "../src/compound_shape.h"
#include "../src/iterator/iterator.h"
#include "../src/iterator/compound_iterator.h"

TEST(CaseCompoundIterator, Creation) {
  CompoundShape* cs1 = new CompoundShape();
  ASSERT_NO_THROW(cs1->createIterator());
}

// TEST(CaseCompoundIterator, CurrentItemShouldThrowExceptionWhenIsDone) {
//   CompoundShape* cs1 = new CompoundShape();
//   Iterator* it = cs1->createIterator();
//   ASSERT_THROW(it->currentItem()->area());
// }

// // NextShouldThrowExceptionWhenIsDone

// TEST(CaseCompoundIterator, CompoundIteratorIsDone) {
//   CompoundShape* cs1 = new CompoundShape();
//   cs1->addShape(new Circle(10.0));
//   Iterator* it = cs1->createIterator();
//   ASSERT_NEAR(314.159, it->currentItem()->area(), 0.001);
//   it->next();
//   ASSERT_THROW(it->isDone());
// }

TEST(CaseNullIterator, NullIterator) {
  Shape* r1 = new Rectangle(3.14, 4);
  Iterator* it = r1->createIterator();
  ASSERT_TRUE(it->isDone());
}
