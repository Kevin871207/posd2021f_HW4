#include "../../src/article.h"
#include "../../src/iterator/iterator.h"
#include "../../src/iterator/compound_iterator.h"
#include "../../src/paragraph.h"
#include "../../src/list_item.h"
#include "../../src/text.h"
#include "../../src/visitor/html_visitor.h"


TEST(CaseCompoundShape, InfoShouldBeCorrect) {
    Article* p = new Paragraph(1, "title");;
    p->add(new ListItem("list1"));
    p->add(new ListItem("list2"));
    p->add(new Text("text"));
    Paragraph* p2 = new Paragraph(2, "title2");
    p2->add(new ListItem("list3"));
    p2->add(new ListItem("list4"));
    p2->add(new Text("sub text"));
    p->add(p2);
    HtmlVisitor visitor;
    p->accept(&visitor);
    ASSERT_EQ(visitor.getResult(), "<div><h1>title</h1><li>list1</li><li>list2</li><span>text</span><div><h2>title2</h2><li>list3</li><li>list4</li><span>sub text</span></div></div>");
    // delete cs1;
    // delete cs2;
}


