#include "tostring_visitor.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
#include "shape.h"
#include "compound_shape.h"

void ToStringVisitor::visitCircle(Circle* c) {
  _result += _indent;
  _result += c->info();
}

void ToStringVisitor::visitRectangle(Rectangle* r) {
  // _result += _indent;
  _result += r->info();
}
void ToStringVisitor::visitTriangle(Triangle* t) {
  // _result += _indent;
  _result += t->info();
}
void ToStringVisitor::visitCompoundShape(CompoundShape* cs) {
  // Iterator* it = cs->createIterator();
  // _result += _indent;
  _result += cs->info();
  // _result += " {\n";
  // _indent += "  ";
  // for (it->first(); !it->isDone(); it->next()) {
  //   Shape* shape = it->currentItem();
  //   shape->accept(this);
  // }
  // _indent.pop_back();
  // _indent.pop_back();
  // _result += _indent;
  // _result += "}\n";
}
std::string ToStringVisitor::getResult() {
  return _result;
}
