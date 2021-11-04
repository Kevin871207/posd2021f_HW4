#include "../src/circle.h"
#include "../src/shape.h"
#include "../src/iterator/iterator.h"

TEST(CaseCircle, Creation) {
  ASSERT_NO_THROW(Circle c(10.0));
}

TEST(CaseCircle, CircleShouldBeShape) {
  Shape* c1 = new Circle(10.0);
  ASSERT_TRUE(typeid(c1).name() == typeid(Shape*).name());
  delete c1;
}

TEST(CaseCircle, Area) {
  Circle c(10.0);
  ASSERT_NEAR(314.159, c.area(), 0.001);
}

TEST(CaseCircle, Perimeter) {
  Circle c(10.0);
  ASSERT_NEAR(62.831, c.perimeter(), 0.001);
}

TEST(CaseCircle, Info1) {
  Circle c(10.2356);
  ASSERT_EQ("Circle (10.24)", c.info());
}

TEST(CaseCircle, Info2) {
  Circle c(10.2322);
  ASSERT_EQ("Circle (10.23)", c.info());
}

TEST(CaseCircle, RadiusIsZeroShouldThrowException) {
  ASSERT_ANY_THROW(Circle c(0));
}

TEST(CaseCircle, RadiusIsNegativeShouldThrowException) {
  ASSERT_ANY_THROW(Circle c(-5));
}

TEST(CaseCircle, CreateNullIterator) {
  Circle c(10.2322);
  Iterator* it = c.createIterator();
  ASSERT_TRUE(it->isDone());
  delete it;
}

TEST(CaseCircle, CurrentItemOfIteratorShouldThrowException) {
  Circle c(10.2322);
  Iterator* it = c.createIterator();
  ASSERT_ANY_THROW(it->currentItem());
  delete it;
}

TEST(CaseCircle, FirstOfIteratorShouldThrowException) {
  Circle c(10.2322);
  Iterator* it = c.createIterator();
  ASSERT_ANY_THROW(it->first());
  delete it;
}

TEST(CaseCircle, NextOfIteratorShouldThrowException) {
  Circle c(10.2322);
  Iterator* it = c.createIterator();
  ASSERT_ANY_THROW(it->next());
  delete it;
}

TEST(CaseCircle, AddShapeShouldThrowException) {
  Circle c(10.2322);
  try {
    c.addShape(new Circle(10.0));
    FAIL();
  } catch (std::string ss) {
    ASSERT_EQ(ss, "Method addShape not allowed.");
  }
}

TEST(CaseCircle, DeleteShapeShouldThrowException) {
  Circle c(10.2322);
  try {
    c.deleteShape(new Circle(10.0));
    FAIL();
  } catch (std::string ss) {
    ASSERT_EQ(ss, "Method deleteShape not allowed.");
  }
}
