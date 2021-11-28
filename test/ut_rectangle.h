#include "../src/rectangle.h"
#include "../src/shape.h"
#include "../src/iterator/iterator.h"
#include "../src/visitor/shape_info_visitor.h"

class CaseRectangle : public ::testing::Test {
protected:
    Rectangle* r12;
    Rectangle* r34;
    Iterator* it;
    
    void SetUp() override {
        r12 = new Rectangle(1, 2);
        r34 = new Rectangle(3, 4);
        it = r12->createIterator();
    }

    void TearDown() override {
        delete r12;
        delete r34;
        delete it;
    }
};

TEST_F(CaseRectangle, RectangleCreation) {
    ASSERT_NO_THROW(Rectangle r12(1, 2));
}

TEST_F(CaseRectangle, RectangleShouldBeShape) {
    Shape* rect = r12;
    ASSERT_TRUE(typeid(rect).name() == typeid(Shape*).name());
}

TEST_F(CaseRectangle, RectangleAreaShouldBeCorrect) {
    ASSERT_NEAR(2, r12->area(), 0.001);
}

TEST_F(CaseRectangle, RectanglePerimeterShouldBeCorrect) {
    ASSERT_NEAR(6, r12->perimeter(), 0.001);
}

TEST_F(CaseRectangle, RectangleInfoDownShouldBeCorrect) {
    Rectangle r(10.234, 20.234);
    ASSERT_EQ("Rectangle (10.23 20.23)", r.info());
}

TEST_F(CaseRectangle, RectangleInfoUpShouldBeCorrect) {
    Rectangle r(10.235, 20.235);
    ASSERT_EQ("Rectangle (10.24 20.24)", r.info());
}

TEST_F(CaseRectangle, LengthIsZeroShouldThrowException) {
     ASSERT_ANY_THROW(Rectangle r(0, 20.235));
}

TEST_F(CaseRectangle, LengthIsNegativeShouldThrowException) {
    ASSERT_ANY_THROW(Rectangle r(-5, 5));
}

TEST_F(CaseRectangle, WidthIsZeroShouldThrowException) {
    ASSERT_ANY_THROW(Rectangle r(5, 0));
}

TEST_F(CaseRectangle, WidthIsNegativeShouldThrowException) {
    ASSERT_ANY_THROW(Rectangle r(5, -5));
}

TEST_F(CaseRectangle, CreateNullIterator) {
    ASSERT_TRUE(it->isDone());
}

TEST_F(CaseRectangle, CurrentItemOfIteratorShouldThrowException) {
    ASSERT_ANY_THROW(it->currentItem());
}

TEST_F(CaseRectangle, FirstOfIteratorShouldThrowException) {
    ASSERT_ANY_THROW(it->first());
}

TEST_F(CaseRectangle, NextOfIteratorShouldThrowException) {
    ASSERT_ANY_THROW(it->next());
}

TEST_F(CaseRectangle, AddShapeShouldThrowException) {
    ASSERT_ANY_THROW(r12->addShape(r34));
}

TEST_F(CaseRectangle, DeleteShapeShouldThrowException) {
    ASSERT_ANY_THROW(r12->deleteShape(r34));
}

TEST_F(CaseRectangle, AcceptShouldNoThrowException) {
    ShapeInfoVisitor visitor;
    ASSERT_NO_THROW(r12->accept(&visitor));
}