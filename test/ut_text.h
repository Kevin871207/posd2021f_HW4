#include "../src/text.h"

TEST(CaseText, Creation) {
  ASSERT_NO_THROW(Text t("text"));
}
