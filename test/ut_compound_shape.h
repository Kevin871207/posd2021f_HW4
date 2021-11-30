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
    Shape* r34;
    Shape* cs1;
    Shape* cs2;
    Iterator* it;

    void SetUp() override {
        c10 = new Circle(10.0);
        c20 = new Circle(20.0);
        r34 = new Rectangle(3, 4);
        cs1 = new CompoundShape();
        cs1->addShape(c10);
        cs1->addShape(c20);
        cs2 = new CompoundShape();
        cs2->addShape(r34);
        cs2->addShape(cs1);
        TwoDimensionalVector vec1(1, 2);
        TwoDimensionalVector vec2(3, 4);
        cs2->addShape(new Triangle(vec1, vec2));

        it = cs2->createIterator();
    }

    void TearDown() override {
        delete cs2;
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
    ASSERT_NEAR(1570.7963, cs1->area(), 0.001);
}

TEST_F(CaseCompoundShape, AreaTwoCompoundShape) {
    ASSERT_NEAR(1583.7963, cs2->area(), 0.001);
}

TEST_F(CaseCompoundShape, PerimeterOneCompoundShape) {
    ASSERT_NEAR(188.4955, cs1->perimeter(), 0.001);
}

TEST_F(CaseCompoundShape, PerimeterTwoCompoundShape) {
    ASSERT_NEAR(212.560054, cs2->perimeter(), 0.001);
}

TEST_F(CaseCompoundShape, InfoShouldBeCorrect) {
    ASSERT_EQ("CompoundShape", cs1->info());
    ASSERT_EQ("CompoundShape", cs2->info());
}

TEST_F(CaseCompoundShape, CreateIteratorShouldNoThrow) {
    ASSERT_NO_THROW(cs1->createIterator());
}

TEST_F(CaseCompoundShape, AddShapeShouldNotThrow) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* cs = new CompoundShape();
    ASSERT_NO_THROW(cs->addShape(c1));
    delete cs;
}

TEST_F(CaseCompoundShape, DeleteShapeShouldNotThrow) {
    Shape* c1 = new Circle(1.0);
    Shape* c2 = new Circle(1.0);
    Shape* cs = new CompoundShape();
    cs->addShape(c1);
    cs->addShape(c2);
    ASSERT_NO_THROW(cs->deleteShape(c2));
    ASSERT_NEAR(3.141, cs->area(), 0.001);
    delete cs;
}