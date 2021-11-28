#include "../src/two_dimensional_vector.h"
#include "../src/shape.h"
#include "../src/iterator/iterator.h"
#include "../src/visitor/shape_info_visitor.h"

class CaseTwoDimensionalVector : public ::testing::Test {
protected:
    
    void SetUp() override {
        
    }

    void TearDown() override {
       
    }
};

TEST_F(CaseTwoDimensionalVector, TwoDimensionalVectorCreation) {
    ASSERT_NO_THROW(TwoDimensionalVector vec1(3.00, 12.433));
}

TEST_F(CaseTwoDimensionalVector, XShouldBeCorrect) {
    TwoDimensionalVector vec1(3, 12.433);
    ASSERT_NEAR(3, vec1.x(), 0.001);
}

TEST_F(CaseTwoDimensionalVector, YShouldBeCorrect) {
    TwoDimensionalVector vec1(3, 12.433);
    ASSERT_NEAR(12.433, vec1.y(), 0.001);
}

TEST_F(CaseTwoDimensionalVector, Length1) {
    TwoDimensionalVector vec1(3, 4);
    ASSERT_NEAR(5, vec1.length(), 0.001);
}

TEST_F(CaseTwoDimensionalVector, Length2) {
    TwoDimensionalVector vec1(-3, -4);
    ASSERT_NEAR(5, vec1.length(), 0.001);
}

TEST_F(CaseTwoDimensionalVector, Dot1) {
    TwoDimensionalVector vec1(3, 4);
    TwoDimensionalVector vec2(1, 2);
    ASSERT_NEAR(11, vec1.dot(vec2), 0.001);
}

TEST_F(CaseTwoDimensionalVector, Dot2) {
  TwoDimensionalVector vec1(-3, -4);
  TwoDimensionalVector vec2(1, 2);
  ASSERT_NEAR(-11, vec1.dot(vec2), 0.001);
}

TEST_F(CaseTwoDimensionalVector, DotProductOfTwoOrthogonalVectorsShouldBeZero) {
  TwoDimensionalVector vec1(0, 5);
  TwoDimensionalVector vec2(1, 0);
  ASSERT_NEAR(0, vec1.dot(vec2), 0.001);
}

TEST_F(CaseTwoDimensionalVector, Cross) {
  TwoDimensionalVector vec1(3, 4);
  TwoDimensionalVector vec2(1, 2);
  ASSERT_NEAR(2, vec1.cross(vec2), 0.001);
}

TEST_F(CaseTwoDimensionalVector, CrossProductOfTwoParallelVectorsShouldBeZero) {
  TwoDimensionalVector vec1(2, 4);
  TwoDimensionalVector vec2(4, 8);
  ASSERT_NEAR(0, vec1.cross(vec2), 0.001);
}

TEST_F(CaseTwoDimensionalVector, Subtract) {
  TwoDimensionalVector vec1(3, 4);
  TwoDimensionalVector vec2(1, 2);
  TwoDimensionalVector vec3(2, 2);
  ASSERT_EQ(vec3.length(), vec1.subtract(vec2).length());
}

TEST_F(CaseTwoDimensionalVector, Info1) {
  TwoDimensionalVector vec1(3.004, 12.433);
  ASSERT_EQ("[3.00,12.43]", vec1.info());
}

TEST_F(CaseTwoDimensionalVector, Info2) {
  TwoDimensionalVector vec1(3.005, 12.438);
  ASSERT_EQ("[3.01,12.44]", vec1.info());
}
