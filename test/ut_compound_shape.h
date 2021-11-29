#include "../src/compound_shape.h"
#include "../src/circle.h"
#include "../src/rectangle.h"
#include "../src/shape.h"
#include "../src/iterator/iterator.h"
#include "../src/visitor/shape_info_visitor.h"

class CaseCompoundShape : public ::testing::Test {
protected:
    Shape* c10;
    Shape* c20;
    Shape * r34;
    Shape * r22;
    Shape * cs1;
    Shape * cs2;
    Iterator* it;

    void SetUp() override {
        c10 = new Circle(10.0);
        c20 = new Circle(20.0);
        r34 = new Rectangle(3, 4);
        r22 = new Rectangle(2, 2);
        cs1 = new CompoundShape();
        cs1->addShape(c10);
        cs1->addShape(c10);
        cs2 = new CompoundShape();
        cs2->addShape(c10);
        cs2->addShape(cs1);
        TwoDimensionalVector vec1(1, 2);
        TwoDimensionalVector vec2(3, 4);
        cs2->addShape(new Triangle(vec1, vec2));

        it = cs1->createIterator();
    }

    void TearDown() override {
        delete c10;
        delete c20;
        delete r34;
        delete r22;
        // delete cs1;
        // delete cs2;
        delete it;
    }
};

TEST_F(CaseCompoundShape, CompoundShapeCreation) {
  ASSERT_NO_THROW(new CompoundShape());
}

TEST_F(CaseCompoundShape, CompoundShapeShouldBeShape) {
    Shape* compoundShape = cs1;
    ASSERT_TRUE(typeid(compoundShape).name() == typeid(Shape*).name());
}

TEST_F(CaseCompoundShape, AreaOneCompoundShape) {
    ASSERT_NEAR(628.318, cs1->area(), 0.001);
}

TEST_F(CaseCompoundShape, AreaTwoCompoundShape) {
    ASSERT_NEAR(943.477, cs2->area(), 0.001);
}

TEST_F(CaseCompoundShape, PerimeterOneCompoundShape) {
    ASSERT_NEAR(125.6637, cs1->perimeter(), 0.001);
}

TEST_F(CaseCompoundShape, PerimeterTwoCompoundShape) {
    ASSERT_NEAR(198.56005, cs2->perimeter(), 0.001);
}

TEST_F(CaseCompoundShape, InfoShouldBeCorrect) {
    ASSERT_EQ("CompoundShape", cs1->info());
    ASSERT_EQ("CompoundShape", cs2->info());
}

TEST_F(CaseCompoundShape, CreateIteratorShouldNoThrow) {
    ASSERT_NO_THROW(cs1->createIterator());
}

TEST_F(CaseCompoundShape, AddShapeShouldNotThrow) {
    ASSERT_NO_THROW(cs1->addShape(c10););
}

TEST_F(CaseCompoundShape, DeleteShapeShouldNotThrow) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* cs = new CompoundShape();
    cs->addShape(c1);
    cs->addShape(c2);
    ASSERT_NO_THROW(cs->deleteShape(c2));
    ASSERT_NEAR(3.141, cs->area(), 0.001);
    delete c1;
}