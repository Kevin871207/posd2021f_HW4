#include "../../src/article.h"
#include "../../src/iterator/iterator.h"
#include "../../src/iterator/compound_iterator.h"
#include "../../src/paragraph.h"
#include "../../src/list_item.h"
#include "../../src/text.h"
#include "../../src/visitor/markdown_visitor.h"


TEST(CaseMarkdownVisitor, InfoShouldBeCorrect) {
    Article* p = new Paragraph(1, "title");;
    p->add(new ListItem("list1"));
    p->add(new ListItem("list2"));
    p->add(new Text("text"));
    Paragraph* p2 = new Paragraph(2, "title2");
    p2->add(new ListItem("list3"));
    p2->add(new ListItem("list4"));
    p2->add(new Text("sub text"));
    p->add(p2);
    MarkdownVisitor visitor;
    p->accept(&visitor);
    ASSERT_EQ(visitor.getResult(), "# title\n- list1\n- list2\ntext\n## title2\n- list3\n- list4\nsub text\n");
    // delete cs1;
    // delete cs2;
}
