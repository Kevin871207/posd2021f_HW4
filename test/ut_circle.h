#include "../src/circle.h"

TEST(CaseCircle, Creation) {
  ASSERT_NO_THROW(Circle c(10.0));
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