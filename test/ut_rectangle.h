#include <string>

#include "../src/rectangle.h"

TEST(CaseRectangle, Area) {
  Rectangle r(10.0, 20.0);
  ASSERT_NEAR(200, r.area(), 0.001);
}

TEST(CaseRectangle, Perimeter) {
  Rectangle r(10.0, 20.0);
  ASSERT_NEAR(60.00, r.perimeter(), 0.001);
}

TEST(CaseRectangle, Info) {
  Rectangle r(10.234, 20.235);
  std::cout << r.info() << std::endl;
  ASSERT_EQ("Rectangle (10.23 20.24)", r.info());
}

TEST(CaseRectangle, RadiusIsZeroShouldThrowException) {
  ASSERT_ANY_THROW(Rectangle r(0, 20.235));
}
