#include "../src/two_dimensional_vector.h"

TEST(CaseTwoDimensionalVector, ReturnX) {
  TwoDimensionalVector vec1(3, 12.433);
  ASSERT_NEAR(3, vec1.x(), 0.001);
}

TEST(CaseTwoDimensionalVector, ReturnY) {
  TwoDimensionalVector vec1(3, 12.433);
  ASSERT_NEAR(12.433, vec1.y(), 0.001);
}

TEST(CaseTwoDimensionalVector, Length) {
  TwoDimensionalVector vec1(3, 4);
  ASSERT_NEAR(5, vec1.length(), 0.001);
}

TEST(CaseTwoDimensionalVector, Dot) {
  TwoDimensionalVector vec1(3, 4);
  TwoDimensionalVector vec2(1, 2);
  ASSERT_NEAR(11, vec1.dot(vec2), 0.001);
}

TEST(CaseTwoDimensionalVector, Cross) {
  TwoDimensionalVector vec1(3, 4);
  TwoDimensionalVector vec2(1, 2);
  ASSERT_NEAR(2, vec1.cross(vec2), 0.001);
}

TEST(CaseTwoDimensionalVector, Subtract) {
  TwoDimensionalVector vec1(3, 4);
  TwoDimensionalVector vec2(1, 2);
  TwoDimensionalVector vec3(2, 2);
  ASSERT_EQ(vec3.length(), vec1.subtract(vec2).length());
}

TEST(CaseTwoDimensionalVector, Info) {
  TwoDimensionalVector vec1(3.005, 12.433);
  ASSERT_EQ("[3.01,12.43]", vec1.info());
}
