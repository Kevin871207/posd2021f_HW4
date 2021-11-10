#pragma once

#include "article_visitor.h"
#include <string>

#include "../list_item.h"
#include "../text.h"
#include "../paragraph.h"


class HtmlVisitor : public ArticleVisitor {
   public:
    void visitListItem(ListItem* li) override{
        _result += "- "+ li->getText() + "\n" ;
    };

    void visitText(Text* t) override{
        _result += t->getText() + "\n" ;
    };

    void visitParagraph(Paragraph* p) override{
        for (int i = p->getLevel(); i>0; i--) {
            _result += "#";
        }
        _result += " " + _result;
        Iterator* it = p->createIterator();
        _result ;
    };

    std::string getResult() const override {
        return _result;
    }

  private:
    std::string _result;
};