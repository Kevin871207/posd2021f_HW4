#include "../src/list_item.h"

TEST(CaseListItem, Creation) {
  ASSERT_NO_THROW(ListItem l("list1"));
}

TEST(CaseListItem, AddContentShouldThrow) {
  ListItem l("list1");
  ASSERT_ANY_THROW(l.add(new ListItem("list2")));
}

// TEST(CaseCircle, Perimeter) {
//   Circle c(10.0);
//   ASSERT_NEAR(62.831, c.perimeter(), 0.001);
// }

// TEST(CaseCircle, Info1) {
//   Circle c(10.2356);
//   ASSERT_EQ("Circle (10.24)", c.info());
// }

// TEST(CaseCircle, RadiusIsZeroShouldThrowException) {
//   ASSERT_ANY_THROW(Circle c(0));
// }
