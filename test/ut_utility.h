#include "../src/circle.h"
#include "../src/compound_shape.h"
#include "../src/rectangle.h"
#include "../src/two_dimensional_vector.h"
#include "../src/utility.h"

TEST(CaseUtility, SelectShapeByArea) {
  TwoDimensionalVector vec1(1, 2);
  TwoDimensionalVector vec2(3, 4);
  Shape* r1 = new Rectangle(8.0, 3.0);

  Shape* cs = new CompoundShape();
  cs->addShape(new Circle(10.0));
  cs->addShape(r1);
  cs->addShape(new Triangle(vec1, vec2));

  Shape* result = selectShape(cs, [](Shape* shape) {
    return shape->area() > 20.0 && shape->area() <30.0;
  });
  ASSERT_EQ(r1, result);
}

TEST(CaseUtility, SelectShapeByType) {
  TwoDimensionalVector vec1(1, 2);
  TwoDimensionalVector vec2(3, 4);
  Shape* r1 = new Rectangle(8.0, 3.0);

  Shape* cs = new CompoundShape();
  cs->addShape(new Circle(10.0));
  cs->addShape(r1);
  cs->addShape(new Triangle(vec1, vec2));

  Shape* result = selectShape(cs, [](Shape* shape) {
    return typeid(*shape).name() == typeid(Triangle).name();
  });
  ASSERT_EQ(typeid(Triangle).name(), typeid(*result).name());
}
