#include "../src/rectangle.h"

TEST(CaseRectangle, Area) {
  Rectangle r(10.0, 20.0);
  ASSERT_NEAR(200, r.area(), 0.001);
}

TEST(CaseRectangle, Perimeter) {
  Rectangle r(10.0, 20.0);
  ASSERT_NEAR(60.00, r.perimeter(), 0.001);
}

TEST(CaseRectangle, Info1) {
  Rectangle r(10.234, 20.235);
  ASSERT_EQ("Rectangle (10.23 20.24)", r.info());
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
