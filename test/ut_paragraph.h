#include "../src/article.h"
#include "../src/list_item.h"
#include "../src/paragraph.h"
#include "../src/text.h"

TEST(CaseParagraph, Creation) {
  ASSERT_NO_THROW(Paragraph p(1, "title"));
}

TEST(CaseParagraph, ParagraphShouldBeAArticle) {
  Article* p = new Paragraph(2, "title2");
  ASSERT_TRUE(typeid(p) == typeid(Article*));
}

TEST(CaseParagraph, LevelIsZero) {
  ASSERT_ANY_THROW(Paragraph p(0, "title"));
}

TEST(CaseParagraph, LevelIsNegative) {
  ASSERT_ANY_THROW(Paragraph p(-5, "title"));
}

TEST(CaseParagraph, LevelIsLargerThenSix) {
  ASSERT_ANY_THROW(Paragraph p(7, "title"));
}

TEST(CaseParagraph, GetText) {
  Paragraph p(1, "title");
  ASSERT_EQ("title", p.getText());
}

TEST(CaseParagraph, GetLevel) {
  Paragraph p(1, "title");
  ASSERT_EQ(1, p.getLevel());
}

TEST(CaseParagraph, AddLowerOrEqualLevelParagraphShouldThrow) {
  Paragraph p(3, "title");
  Paragraph* p2 = new Paragraph(2, "title2");
  ASSERT_ANY_THROW(p.add(p2));
}

TEST(CaseParagraph, AddShouldNoThrow) {
  Paragraph p(1, "title");
  Paragraph* p2 = new Paragraph(2, "title2");
  ASSERT_NO_THROW(p.add(p2));
}
