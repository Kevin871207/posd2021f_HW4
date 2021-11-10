#include "../src/article.h"
#include "../src/iterator/iterator.h"
#include "../src/list_item.h"

TEST(CaseListItem, Creation) {
  ASSERT_NO_THROW(ListItem l("list1"));
}

TEST(CaseListItem, ListItemShouldBeAArticle) {
  Article* l = new ListItem("list1");
  ASSERT_TRUE(typeid(l) == typeid(Article*));
  delete l;
}

TEST(CaseListItem, GetText) {
  ListItem l("list1");
  ASSERT_EQ("list1", l.getText());
}

TEST(CaseListItem, GetLevelShouldEq0) {
  ListItem l("list1");
  ASSERT_EQ(0, l.getLevel());
}

TEST(CaseListItem, AddContentShouldThrow) {
  ListItem l("list1");
  ASSERT_ANY_THROW(l.add(new ListItem("list2")));
}

TEST(CaseListItem, CreateNullIterator) {
  ListItem l("list1");
  Iterator* it = l.createIterator();
  ASSERT_TRUE(it->isDone());
  delete it;
}