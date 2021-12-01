#include <string>

#include "../../src/circle.h"
#include "../../src/compound_shape.h"
#include "../../src/rectangle.h"
#include "../../src/two_dimensional_vector.h"
#include "../../src/visitor/shape_info_visitor.h"
#include "../../src/iterator/compound_iterator.h"
#include "../../src/iterator/iterator.h"

TEST(CaseShapeInfoVisitor, VisitCircle) {
    Shape* c10 = new Circle(10);
    
    ShapeInfoVisitor visitor;
    c10->accept(&visitor);
    std::string expected = "Circle (10.00)\n";  
    ASSERT_EQ(visitor.getResult(), expected);
    delete c10;
}

TEST(CaseShapeInfoVisitor, VisitRectangle) {
    Shape* r12 = new Rectangle(1, 2);
    
    ShapeInfoVisitor visitor;
    r12->accept(&visitor);
    std::string expected = "Rectangle (1.00 2.00)\n";  
    ASSERT_EQ(visitor.getResult(), expected);
    delete r12;
}

TEST(CaseShapeInfoVisitor,VisitTriangle) {
    TwoDimensionalVector vec1(3.002, 12.432);
    TwoDimensionalVector vec2(17.574, -4.001);
    Shape* tri = new Triangle(vec1, vec2);
    
    ShapeInfoVisitor visitor;
    tri->accept(&visitor);
    std::string expected = "Triangle ([3.00,12.43] [17.57,-4.00])\n";  
    ASSERT_EQ(visitor.getResult(), expected);
    delete tri;
}

TEST(CaseShapeInfoVisitor, VisitCompoundShape) {
    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(new Circle(1.1));
    cs1->addShape(new Rectangle(3.14 ,4));
   
    ShapeInfoVisitor visitor;
    cs1->accept(&visitor);
    std::string expected = "CompoundShape{\n"
                           "  Circle (1.10)\n" 
                           "  Rectangle (3.14 4.00)\n"
                           "}\n";

    ASSERT_EQ(visitor.getResult(), expected);
    delete cs1;
}

TEST(CaseShapeInfoVisitor, VisitComplexCompoundShape) {
    CompoundShape* cs1 = new CompoundShape();
    cs1->addShape(new Circle(1.1));
    cs1->addShape(new Rectangle(3.14 ,4));
    CompoundShape* cs2 = new CompoundShape();
    cs2->addShape(new Circle(12.34567));
    cs2->addShape(cs1);
    cs2->addShape(new Rectangle(3.14 ,4.20));


    ShapeInfoVisitor visitor;
    cs2->accept(&visitor);
    std::string expected = "CompoundShape{\n"
                           "  Circle (12.35)\n"  
                           "  CompoundShape{\n"   
                           "    Circle (1.10)\n"     
                           "    Rectangle (3.14 4.00)\n"
                           "  }\n"
                           "  Rectangle (3.14 4.20)\n"
                           "}\n";

    ASSERT_EQ(visitor.getResult(), expected);
    delete cs2;
}

TEST(CaseShapeInfoVisitor, getResult) {
    ShapeInfoVisitor* visitor = new ShapeInfoVisitor();
    ASSERT_EQ(visitor->getResult(), "");
    delete visitor;
}