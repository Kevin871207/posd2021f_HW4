#include "../src/text.h"
#include "../src/article.h"

TEST(CaseText, Creation) {
  ASSERT_NO_THROW(Text t("text"));
}

TEST(CaseText, ListItemShouldBeAArticle) {
  Article* t = new Text("text");
  ASSERT_TRUE(typeid(t) == typeid(Article*));
}

TEST(CaseText, GetText) {
  Text t("text");
  ASSERT_EQ("text", t.getText());
}

TEST(CaseText, GetLevelShouldEq0) {
  Text t("text");
  ASSERT_EQ(0, t.getLevel());
}

TEST(CaseText, AddContentShouldThrow) {
  Text t("text");
  ASSERT_ANY_THROW(t.add(new Text("sub text")));
}
