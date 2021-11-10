#pragma once

#include "article_visitor.h"
#include <string>

#include "../list_item.h"
#include "../text.h"
#include "../paragraph.h"
#include "../article.h"

class MarkdownVisitor : public ArticleVisitor {
   public:
    void visitListItem(ListItem* li) override{
        _result += "\n- "+ li->getText();
    };

    void visitText(Text* t) override{
        _result += "\n" + t->getText();
    };

    void visitParagraph(Paragraph* p) override{
        if (_count != 0) {
            _result += "\n";
        }
        for (int i = p->getLevel(); i>0; i--) {
            _result += "#";
        }
        _result += " ";
        _result += p->getText();
        Iterator* it = p->createIterator();

        for (it->first(); !it->isDone(); it->next()) {
            Article* a = it->currentItem();
            a->accept(this);
            _count++;
        }
        _result += "\n";

    };

    std::string getResult() const override {
        return _result;
    }

  private:
    std::string _result;
    int _count = 0;
};