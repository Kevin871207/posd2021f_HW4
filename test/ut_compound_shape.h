#include "../src/circle.h"
#include "../src/compound_shape.h"
#include "../src/rectangle.h"

TEST(CaseCompoundShape, Creation) {
  ASSERT_NO_THROW(new CompoundShape());
}

TEST(CaseCompoundShape, CompoundShapeShouldBeShape) {
  Shape* cs1 = new CompoundShape();
  ASSERT_TRUE(typeid(cs1).name() == typeid(Shape*).name());
}

TEST(CaseCompoundShape, AreaOneCompoundShape) {
  CompoundShape* cs1 = new CompoundShape();
  cs1->addShape(new Circle(10.0));
  cs1->addShape(new Circle(10.0));
  ASSERT_NEAR(628.318, cs1->area(), 0.001);
}

TEST(CaseCompoundShape, AreaTwoCompoundShape) {
  CompoundShape* cs1 = new CompoundShape();
  cs1->addShape(new Circle(10.0));
  cs1->addShape(new Circle(10.0));

  CompoundShape* cs2 = new CompoundShape();
  cs2->addShape(new Circle(10.0));
  cs2->addShape(cs1);

  TwoDimensionalVector vec1(1, 2);
  TwoDimensionalVector vec2(3, 4);
  cs2->addShape(new Triangle(vec1, vec2));

  ASSERT_NEAR(943.477, cs2->area(), 0.001);
}

TEST(CaseCompoundShape, PerimeterOneCompoundShape) {
  CompoundShape* cs1 = new CompoundShape();
  cs1->addShape(new Circle(10.0));
  cs1->addShape(new Circle(10.0));
  ASSERT_NEAR(628.318, cs1->area(), 0.001);
}

TEST(CaseCompoundShape, PerimeterTwoCompoundShape) {
  CompoundShape* cs1 = new CompoundShape();
  cs1->addShape(new Circle(10.0));
  cs1->addShape(new Circle(10.0));

  CompoundShape* cs2 = new CompoundShape();
  cs2->addShape(new Rectangle(10.0, 20.0));
  cs2->addShape(cs1);

  TwoDimensionalVector vec1(1, 2);
  TwoDimensionalVector vec2(3, 4);
  cs2->addShape(new Triangle(vec1, vec2));

  ASSERT_NEAR(195.728, cs2->perimeter(), 0.001);
}

TEST(CaseCompoundShape, InfoShouldBeCorrect) {
  CompoundShape* cs1 = new CompoundShape();
  cs1->addShape(new Circle(1.1));
  cs1->addShape(new Rectangle(3.14, 4));

  CompoundShape* cs2 = new CompoundShape();
  cs2->addShape(new Circle(12.34567));
  cs2->addShape(cs1);
  ASSERT_EQ(
    "CompoundShape\n{\nCircle (12.35)\nCompoundShape\n{\nCircle (1.10)\nRectangle (3.14 4.00)\n}\n}",
    cs2->info());
}

TEST(CaseCompoundShape, CreateIteratorShouldNoThrow) {
  CompoundShape* cs1 = new CompoundShape();
  ASSERT_NO_THROW(cs1->createIterator());
}

TEST(CaseCompoundShape, AddShapeOneCompoundShape) {
  CompoundShape* cs1 = new CompoundShape();
  Shape* c1 = new Circle(1.1);
  Shape* c2 = new Circle(12.34567);
  Shape* r1 = new Rectangle(3.14, 4);
  cs1->addShape(c1);
  cs1->addShape(c2);
  cs1->addShape(c1);
  cs1->addShape(c2);
  cs1->addShape(r1);

  ASSERT_EQ(
    "CompoundShape\n{\nCircle (1.10)\nCircle (12.35)\nCircle (1.10)\nCircle (12.35)\nRectangle (3.14 4.00)\n}",
    cs1->info());
}

TEST(CaseCompoundShape, AddShapeTWoCompoundShape) {
  CompoundShape* cs1 = new CompoundShape();
  Shape* c1 = new Circle(1.1);
  Shape* c2 = new Circle(12.34567);
  Shape* r1 = new Rectangle(3.14, 4);
  cs1->addShape(c1);
  cs1->addShape(r1);

  CompoundShape* cs2 = new CompoundShape();
  cs2->addShape(c1);
  cs2->addShape(c2);
  cs2->addShape(c1);
  cs2->addShape(cs1);

  ASSERT_EQ(
    "CompoundShape\n{\nCircle (1.10)\nCircle (12.35)\nCircle (1.10)\nCompoundShape\n{\nCircle (1.10)\nRectangle (3.14 4.00)\n}\n}",
    cs2->info());
}

TEST(CaseCompoundShape, DeleteShapeOneCompoundShape) {
  CompoundShape* cs1 = new CompoundShape();
  Shape* c1 = new Circle(1.1);
  Shape* c2 = new Circle(12.34567);
  Shape* r1 = new Rectangle(3.14, 4);
  cs1->addShape(c1);
  cs1->addShape(c2);
  cs1->addShape(c1);
  cs1->addShape(c2);
  cs1->addShape(r1);
  cs1->deleteShape(c1);

  ASSERT_EQ(
    "CompoundShape\n{\nCircle (12.35)\nCircle (12.35)\nRectangle (3.14 4.00)\n}",
    cs1->info());
}

TEST(CaseCompoundShape, DeleteShapeTWoCompoundShape) {
  CompoundShape* cs1 = new CompoundShape();
  Shape* c1 =new Circle(1.1);
  Shape* c2 = new Circle(12.34567);
  Shape* r1 = new Rectangle(3.14, 4);
  cs1->addShape(c1);
  cs1->addShape(r1);

  CompoundShape* cs2 = new CompoundShape();
  cs2->addShape(c1);
  cs2->addShape(c2);
  cs2->addShape(c1);
  cs2->addShape(cs1);
  cs2->deleteShape(c1);

  ASSERT_EQ(
    "CompoundShape\n{\nCircle (12.35)\nCompoundShape\n{\nCircle (1.10)\nRectangle (3.14 4.00)\n}\n}",
    cs2->info());
}
