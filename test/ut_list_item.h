#include "../src/list_item.h"

TEST(CaseListItem, Creation) {
  ASSERT_NO_THROW(ListItem l("list1"));
}
