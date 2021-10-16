#include "../src/text.h"

TEST(CaseText, Creation) {
  ASSERT_NO_THROW(Text t("text"));
}

TEST(CaseText, AddContentShouldThrow) {
  Text t("list1");
  ASSERT_ANY_THROW(t.add(new Text("sub text")));
}
