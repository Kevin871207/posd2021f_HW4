#pragma once

class Circle;
class Rectangle;
class Triangle;
class CompoundShape;

class ShapeVisitor {
 public:
  virtual void visitCircle(Circle* c) = 0;
  virtual void visitRectangle(Rectangle* r) = 0;
  virtual void visitTriangle(Triangle* t) = 0;
  virtual void visitCompoundShape(CompoundShape* cs) = 0;
};
