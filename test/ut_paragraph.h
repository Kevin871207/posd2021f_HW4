#include "../src/paragraph.h"

TEST(CaseParagraph, Creation) {
  ASSERT_NO_THROW(Paragraph p(1, "title"));
}
