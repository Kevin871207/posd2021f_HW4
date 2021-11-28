#include "../src/circle.h"
#include "../src/shape.h"
#include "../src/iterator/iterator.h"
#include "../src/visitor/shape_info_visitor.h"

class CaseCircle : public ::testing::Test {
protected:
    Circle* c10;
    Circle* c20;
    Iterator* it;

    void SetUp() override {
        c10 = new Circle(10.0);
        c20 = new Circle(20.0);
        it = c10->createIterator();
    }

    void TearDown() override {
        delete c10;
        delete c20;
        delete it;
    }
};

TEST_F(CaseCircle, CircleCreation) {
    ASSERT_NO_THROW(Circle c(10.0));
}

TEST_F(CaseCircle, CircleShouldBeShape) {
    Shape* cirlcle = c10;
    ASSERT_TRUE(typeid(cirlcle).name() == typeid(Shape*).name());
}

TEST_F(CaseCircle, CircleAreaShouldBeCorrect) {
    ASSERT_NEAR(314.159, c10->area(), 0.001);
}

TEST_F(CaseCircle, CirclePerimeterShouldBeCorrect) {
    ASSERT_NEAR(62.831, c10->perimeter(), 0.001);
}

TEST_F(CaseCircle, CircleInfoDownShouldBeCorrect) {
    Circle c(10.2356);
    ASSERT_EQ("Circle (10.24)", c.info());
}

TEST_F(CaseCircle, CircleInfoUpShouldBeCorrect) {
    Circle c(10.2322);
     ASSERT_EQ("Circle (10.23)", c.info());
}

TEST_F(CaseCircle, RadiusIsZeroShouldThrowException) {
    ASSERT_ANY_THROW(Circle c(0));
}

TEST_F(CaseCircle, RadiusIsNegativeShouldThrowException) {
    ASSERT_ANY_THROW(Circle c(-5));
}

TEST_F(CaseCircle, CreateNullIterator) {
    ASSERT_TRUE(it->isDone());
}

TEST_F(CaseCircle, CurrentItemOfIteratorShouldThrowException) {
    ASSERT_ANY_THROW(it->currentItem());
}

TEST_F(CaseCircle, FirstOfIteratorShouldThrowException) {
    ASSERT_ANY_THROW(it->first());
}

TEST_F(CaseCircle, NextOfIteratorShouldThrowException) {
    ASSERT_ANY_THROW(it->next());
}

TEST_F(CaseCircle, AddShapeShouldThrowException) {
    ASSERT_ANY_THROW(c10->addShape(c20));
}

TEST_F(CaseCircle, DeleteShapeShouldThrowException) {
    ASSERT_ANY_THROW(c10->deleteShape(c20));
}

TEST_F(CaseCircle, AcceptShouldNoThrowException) {
    ShapeInfoVisitor visitor;
    ASSERT_NO_THROW(c10->accept(&visitor));
}
