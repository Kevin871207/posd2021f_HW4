#include "../src/triangle.h"
#include "../src/shape.h"
#include "../src/two_dimensional_vector.h"
#include "../src/iterator/iterator.h"
#include "../src/visitor/shape_info_visitor.h"

class CaseTriangle : public ::testing::Test {
protected:
    Triangle* tri;
    Triangle* triNegative;
    Iterator* it;

    void SetUp() override {
        TwoDimensionalVector vec1(1, 2);
        TwoDimensionalVector vec2(3, 4);
        TwoDimensionalVector vec3(-1, -2);
        TwoDimensionalVector vec4(-3, -4);
        tri = new Triangle(vec1, vec2);
        triNegative = new Triangle(vec3, vec4);
        it = tri->createIterator();
    }

    void TearDown() override {
        delete tri;
        delete triNegative;
        delete it;
    }
};

TEST_F(CaseTriangle, TriangleCreation) {
    TwoDimensionalVector vec1(1, 2);
    TwoDimensionalVector vec2(3, 4);
    ASSERT_NO_THROW(Triangle tri(vec1, vec2));
}

TEST_F(CaseTriangle, TriangleShouldBeShape) {
    Shape* triangle = tri;
    ASSERT_TRUE(typeid(triangle).name() == typeid(Shape*).name());
}

TEST_F(CaseTriangle, TriangleAreaVectorPositiveShouldBeCorrect) {
    ASSERT_NEAR(1, tri->area(), 0.001);
}

TEST_F(CaseTriangle, TriangleAreaVectorNegativeShouldBeCorrect) {
    ASSERT_NEAR(1, triNegative->area(), 0.001);
}

TEST_F(CaseTriangle, TrianglePerimeterShouldBeCorrect) {
    ASSERT_NEAR(10.064, tri->perimeter(), 0.001);
}

TEST_F(CaseTriangle, TriangleInfoDownShouldBeCorrect) {
    TwoDimensionalVector vec1(3.002, 12.432);
    TwoDimensionalVector vec2(17.574, -4.001);
    Triangle t(vec1, vec2);
    ASSERT_EQ("Triangle ([3.00,12.43] [17.57,-4.00])", t.info());
}

TEST_F(CaseTriangle, TriangleInfoUpShouldBeCorrect) {
    TwoDimensionalVector vec1(3.006, 12.437);
    TwoDimensionalVector vec2(17.578, -4.009);
    Triangle t(vec1, vec2);
    ASSERT_EQ("Triangle ([3.01,12.44] [17.58,-4.01])", t.info());
}

TEST_F(CaseTriangle, TwoVectorsAreParallelShouldThrowException1) {
    TwoDimensionalVector vec1(1, 2);
    TwoDimensionalVector vec2(3, 6);
    ASSERT_ANY_THROW(Triangle t(vec1, vec2));
}

TEST_F(CaseTriangle, TwoVectorsAreParallelShouldThrowException2) {
    TwoDimensionalVector vec1(0, 2);
    TwoDimensionalVector vec2(0, 6);
    ASSERT_ANY_THROW(Triangle t(vec1, vec2));
}

TEST_F(CaseTriangle, TwoVectorsAreParallelShouldThrowException3) {
    TwoDimensionalVector vec1(2, 0);
    TwoDimensionalVector vec2(3, 0);
    ASSERT_ANY_THROW(Triangle t(vec1, vec2));
}

TEST_F(CaseTriangle, CreateNullIterator) {
    ASSERT_TRUE(it->isDone());
}

TEST_F(CaseTriangle, CurrentItemOfIteratorShouldThrowException) {
    ASSERT_ANY_THROW(it->currentItem());
}

TEST_F(CaseTriangle, FirstOfIteratorShouldThrowException) {
    ASSERT_ANY_THROW(it->first());
}

TEST_F(CaseTriangle, NextOfIteratorShouldThrowException) {
    ASSERT_ANY_THROW(it->next());
}

TEST_F(CaseTriangle, AddShapeShouldThrowException) {
    ASSERT_ANY_THROW(tri->addShape(triNegative));
}

TEST_F(CaseTriangle, DeleteShapeShouldThrowException) {
    ASSERT_ANY_THROW(tri->deleteShape(triNegative));
}

TEST_F(CaseTriangle, AcceptShouldNoThrowException) {
    ShapeInfoVisitor visitor;
    ASSERT_NO_THROW(tri->accept(&visitor));
}
