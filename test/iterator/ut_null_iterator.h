#include <string>

#include "../../src/iterator/iterator.h"
#include "../../src/text.h"
#include "../../src/list_item.h"

TEST(CaseNullIterator, NullIteratorIsAIterator) {
  Iterator* it = new NullIterator();
  ASSERT_TRUE(typeid(it).name() == typeid(Iterator*).name());
  delete it;
}

TEST(CaseNullIterator, TextIsDoneIsTrue) {
  Article* t = new Text("text");
  Iterator* it = t->createIterator();
  ASSERT_TRUE(it->isDone());
  delete it;
  delete t;
}

TEST(CaseNullIterator, ListItemIsDoneIsTrue) {
  Article* l = new ListItem("list1");
  Iterator* it = l->createIterator();
  ASSERT_TRUE(it->isDone());
  delete it;
  delete l;
}

TEST(CaseNullIterator, FirstShouldThrowException) {
  Article* l = new ListItem("list1");
  Iterator* it = l->createIterator();
  ASSERT_ANY_THROW(it->first());
  delete it;
  delete l;
}

TEST(CaseNullIterator, CurrentItemtShouldThrowException) {
  Article* l = new ListItem("list1");
  Iterator* it = l->createIterator();
  ASSERT_ANY_THROW(it->currentItem());
  delete it;
  delete l;
}

TEST(CaseNullIterator, NextShouldThrowException) {
  Article* l = new ListItem("list1");
  Iterator* it = l->createIterator();
  ASSERT_ANY_THROW(it->next());
  delete it;
  delete l;
}