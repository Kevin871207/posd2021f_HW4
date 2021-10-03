#include "../src/triangle.h"
#include "../src/two_dimensional_vector.h"

TEST(CaseTriangle, TwoVectorsAreParallelShouldThrowException1) {
  TwoDimensionalVector vec1(1, 2);
  TwoDimensionalVector vec2(3, 6);
  ASSERT_ANY_THROW(Triangle t(vec1, vec2););
}

TEST(CaseTriangle, TwoVectorsAreParallelShouldThrowException2) {
  TwoDimensionalVector vec1(0, 2);
  TwoDimensionalVector vec2(0, 6);
  ASSERT_ANY_THROW(Triangle t(vec1, vec2););
}

TEST(CaseTriangle, TwoVectorsAreParallelShouldThrowException3) {
  TwoDimensionalVector vec1(2, 0);
  TwoDimensionalVector vec2(3, 0);
  ASSERT_ANY_THROW(Triangle t(vec1, vec2););
}
TEST(CaseTriangle, Info) {
  TwoDimensionalVector vec1(3, 12.43);
  TwoDimensionalVector vec2(17.57, -4.00);
  Triangle t(vec1, vec2);
  std::cout << t.info() << std::endl;
  ASSERT_EQ("Triangle ([3.00,12.43] [17.57,-4.00])", t.info());
}
