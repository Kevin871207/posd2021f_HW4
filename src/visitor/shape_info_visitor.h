#pragma once

#include <string>

#include "../circle.h"
#include "../compound_shape.h"
#include "../rectangle.h"
#include "../triangle.h"
#include "./shape_visitor.h"

class ShapeInfoVisitor : public ShapeVisitor {
   public:
    void visitCircle(Circle* circle) {
        result.append(depth,' ');
        result += circle->info();
        result += "\n";
    }

    void visitRectangle(Rectangle* rectangle) {
        result.append(depth,' ');
        result += rectangle->info();
        result += "\n";
    }

    void visitTriangle(Triangle* triangle) {
        result.append(depth,' ');
        result += triangle->info();
        result += "\n";
    }

    void visitCompoundShape(CompoundShape* compoundShape) {
        Iterator* it = compoundShape->createIterator();
        result.append(depth,' ');
        result += compoundShape->info();
        result += "{\n";
        depth += 2;
        for (it->first(); !it->isDone(); it->next()) {
            Shape *shape = it->currentItem();
            shape->accept(this);
        }
        depth -= 2;
        result.append(depth,' ');
        result += "}\n";
    }

    std::string getResult() {
        return result;
    }

   private:
    int depth = 0;
    std::string result = "";
};