#include "../src/circle.h"
#include "../src/compound_shape.h"
#include "../src/rectangle.h"
#include "../src/two_dimensional_vector.h"
#include "../src/tostring_visitor.h"
#include "../src/shape_visitor.h"


// TEST_F(VisitorTest, FindFirstVisitor) {
//   ShapeVisitor* sv =
//     new FindFirstVisitor([](Shape* a) { return a->area() == 4; });
//   r22->accept(*sv);
//   Shape* s = (dynamic_cast<FindFirstVisitor*>(sv))->getResult();
//   ASSERT_EQ(r22, s);
// }

// TEST_F(VisitorTest, FindFirstByAreaOnNestedMixedShape) {
//   ShapeVisitor* sv =
//     new FindFirstVisitor([](Shape* a) { return a->area() == 4; });
//   mbox->accept(*sv);
//   Shape* s = (dynamic_cast<FindFirstVisitor*>(sv))->getResult();
//   ASSERT_EQ(r22, s);
// }

TEST(CaseVisitorTest, ToStringVisitor) {
  Shape* r22 = new Rectangle(2, 2);
  ToStringVisitor* tsv = new ToStringVisitor();
  r22->accept(tsv);
  std::string result = tsv->getResult();
  ASSERT_EQ("Rectangle (10.24 20.24)", result);
}

TEST(CaseVisitorTest, CompoundShapeToStringVisitor) {
  CompoundShape* cs1 = new CompoundShape();
  Shape* c1 = new Circle(1.1);
  Shape* c2 = new Circle(12.34567);
  Shape* r1 = new Rectangle(3.14, 4);
  cs1->addShape(c1);
  cs1->addShape(c2);
  cs1->addShape(c1);
  cs1->addShape(c2);
  cs1->addShape(r1);

  ToStringVisitor* tsv = new ToStringVisitor();
  cs1->accept(tsv);
  std::string result = tsv->getResult();
  ASSERT_EQ(
    "CompoundShape\n{\nCircle (1.10)\nCircle (12.35)\nCircle (1.10)\nCircle (12.35)\nRectangle (3.14 4.00)\n}",
    result);
}
