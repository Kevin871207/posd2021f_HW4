#include "../src/two_dimensional_vector.h"

// TEST(CaseCircle, Area) {
//   Circle c(10.0);
//   ASSERT_NEAR(314.159, c.area(), 0.001);
// }

// TEST(CaseCircle, Perimeter) {
//   Circle c(10.0);
//   ASSERT_NEAR(62.831, c.perimeter(), 0.001);
// }

TEST(CaseTwoDimensionalVector, Info) {
  TwoDimensionalVector vec1(3, 12.433);
  ASSERT_EQ("[3.00,12.43]", vec1.info());
}
