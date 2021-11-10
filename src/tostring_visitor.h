#pragma once

#include "shape_visitor.h"
#include <string>

class Circle;
class Rectangle;
class Triangle;
class CompoundShape;

class ToStringVisitor : public ShapeVisitor {
public:
  void visitCircle(Circle* c);
  void visitRectangle(Rectangle* r);
  void visitTriangle(Triangle* t);
  void visitCompoundShape(CompoundShape* cs);
  std::string getResult();
private:
  std::string _result;
  std::string _indent;
};
