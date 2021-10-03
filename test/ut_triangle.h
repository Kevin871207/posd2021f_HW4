#include "../src/triangle.h"
#include "../src/two_dimensional_vector.h"

TEST(CaseTriangle, TwoVectorsAreParallelShouldThrowException) {
  TwoDimensionalVector vec1(1, 2);
  TwoDimensionalVector vec2(2, 4);
  ASSERT_ANY_THROW(Triangle t(vec1, vec2););
}

TEST(CaseTriangle, Info) {
  TwoDimensionalVector vec1(3, 12.43);
  TwoDimensionalVector vec2(17.57, -4.00);
  Triangle t(vec1, vec2);
  std::cout << t.info() << std::endl;
  ASSERT_EQ("Triangle ([3.00,12.43] [17.57,-4.00])", t.info());
}
