#include "../../src/article.h"
#include "../../src/iterator/iterator.h"
#include "../../src/iterator/compound_iterator.h"
#include "../../src/paragraph.h"
#include "../../src/list_item.h"

TEST(CaseCompoundIterator, Creation) {
  Article* t = new Paragraph(1, "text");
  ASSERT_NO_THROW(t->createIterator());
}

TEST(CaseCompoundIterator, CompoundIteratorIsAIterator) {
  Article* t = new Paragraph(1, "text");
  Iterator* it = t->createIterator();
  ASSERT_TRUE(typeid(it).name() == typeid(Iterator*).name());
  delete t;
  delete it;
}

TEST(CaseCompoundIterator, FirstNoException) {
  Article* t = new Paragraph(1, "text");
  Iterator* it = t->createIterator();
  ASSERT_NO_THROW(it->first());
  delete t;
  delete it;
}

TEST(CaseCompoundIterator, CurrentItemIsCorrect) {
  Article* t = new Paragraph(1, "text");
  Article* l = new ListItem("text");
  t->add(l);
  Iterator* it = t->createIterator();
  ASSERT_EQ(it->currentItem()->getText(), l->getText());
  delete t;
  delete it;
  delete l;
}

TEST(CaseCompoundIterator, CurrentItem) {
  Article* t = new Paragraph(1, "text");
  Iterator* it = t->createIterator();
  ASSERT_TRUE(it->isDone());
  delete t;
  delete it;
}

TEST(CaseCompoundIterator, CurrentItemShouldThrowExceptionWhenIsDone1) {
  Article* t = new Paragraph(1, "text");
  Iterator* it = t->createIterator();
  ASSERT_TRUE(it->isDone());
  delete t;
  delete it;
}

TEST(CaseCompoundIterator, NextNoException) {
  Article* t = new Paragraph(1, "text");
  Iterator* it = t->createIterator();
  ASSERT_ANY_THROW(it->next());
  delete t;
  delete it;
}

TEST(CaseCompoundIterator, NextShouldThrowExceptionWhenIsDone) {
  Article* t = new Paragraph(1, "text");
  Iterator* it = t->createIterator();
  ASSERT_ANY_THROW(it->next());
  delete t;
  delete it;
}

TEST(CaseCompoundIterator, IsDoneShouldBeCorrect1) {
  Article* t = new Paragraph(1, "text");
  Iterator* it = t->createIterator();
  ASSERT_TRUE(it->isDone());
  delete t;
  delete it;
}

TEST(CaseCompoundIterator, IsDoneShouldBeCorrect2) {
  Article* t = new Paragraph(1, "text");
  Iterator* it = t->createIterator();
  ASSERT_TRUE(it->isDone());
  delete t;
  delete it;
}
