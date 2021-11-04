#include "../src/rectangle.h"
#include "../src/shape.h"
#include "../src/iterator/iterator.h"

TEST(CaseRectangle, Creation) {
  ASSERT_NO_THROW(Rectangle r(10.0, 20.0));
}

TEST(CaseRectangle, RectangleShouldBeShape) {
  Shape* r1 = new Rectangle(10.0, 20.0);
  ASSERT_TRUE(typeid(r1).name() == typeid(Shape*).name());
}

TEST(CaseRectangle, Area) {
  Rectangle r(10.0, 20.0);
  ASSERT_NEAR(200, r.area(), 0.001);
}

TEST(CaseRectangle, Perimeter) {
  Rectangle r(10.0, 20.0);
  ASSERT_NEAR(60.00, r.perimeter(), 0.001);
}

TEST(CaseRectangle, Info1) {
  Rectangle r(10.234, 20.234);
  ASSERT_EQ("Rectangle (10.23 20.23)", r.info());
}

TEST(CaseRectangle, Info2) {
  Rectangle r(10.235, 20.235);
  ASSERT_EQ("Rectangle (10.24 20.24)", r.info());
}

TEST(CaseRectangle, LengthIsZeroShouldThrowException) {
  ASSERT_ANY_THROW(Rectangle r(0, 20.235));
}

TEST(CaseRectangle, LengthIsNegativeShouldThrowException) {
  ASSERT_ANY_THROW(Rectangle r(-5, 5));
}

TEST(CaseRectangle, WidthIsZeroShouldThrowException) {
  ASSERT_ANY_THROW(Rectangle r(5, 0));
}

TEST(CaseRectangle, WidthIsNegativeShouldThrowException) {
  ASSERT_ANY_THROW(Rectangle r(5, -5));
}

TEST(CaseRectangle, CreateNullIterator) {
  Rectangle r(10.0, 20.0);
  Iterator* it = r.createIterator();
  ASSERT_TRUE(it->isDone());
}

TEST(CaseRectangle, CurrentItemOfIteratorShouldThrowException) {
  Rectangle r(10.0, 20.0);
  Iterator* it = r.createIterator();
  ASSERT_ANY_THROW(it->currentItem());
}

TEST(CaseRectangle, FirstOfIteratorShouldThrowException) {
  Rectangle r(10.0, 20.0);
  Iterator* it = r.createIterator();
  ASSERT_ANY_THROW(it->first());
}

TEST(CaseRectangle, NextOfIteratorShouldThrowException) {
  Rectangle r(10.0, 20.0);
  Iterator* it = r.createIterator();
  ASSERT_ANY_THROW(it->next());
}

TEST(CaseRectangle, AddShapeShouldThrowException) {
  Rectangle r(10.0, 20.0);
  try {
    r.addShape(new Rectangle(10.0, 20.0));
    FAIL();
  } catch (std::string ss) {
    ASSERT_EQ(ss, "Method addShape not allowed.");
  }
}

TEST(CaseRectangle, DeleteShapeShouldThrowException) {
  Rectangle r(10.0, 20.0);
  try {
    r.deleteShape(new Rectangle(10.0, 20.0));
    FAIL();
  } catch (std::string ss) {
    ASSERT_EQ(ss, "Method deleteShape not allowed.");
  }
}
