#include <cmath>
#include <string>

#include "../src/circle.h"

TEST(CaseCircle, Area) {
  Circle c(10.0);
  ASSERT_NEAR(314.159, c.area(), 0.001);
}

TEST(CaseCircle, Perimeter) {
  Circle c(10.0);
  ASSERT_NEAR(62.831, c.perimeter(), 0.001);
}

TEST(CaseCircle, Info) {
  Circle c(10.2356);
  std::cout << c.info() << std::endl;
  ASSERT_EQ("Circle (10.24)", c.info());
}

TEST(CaseCircle, RadiusIsZeroShouldThrowException) {
  ASSERT_ANY_THROW(Circle c(0));
}
