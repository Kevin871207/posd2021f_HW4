#pragma once

#include "article_visitor.h"
#include <string>

#include "../list_item.h"
#include "../text.h"
#include "../paragraph.h"


class HtmlVisitor : public ArticleVisitor {
   public:
    void visitListItem(ListItem* li) override{
        _result += "<li>" + li->getText() + "</li>";
    };

    void visitText(Text* t) override{
        _result += "<span>" + t->getText() + "</span>";
    };

    void visitParagraph(Paragraph* p) override{
        _result += "<div><h"+ _count;
        _result += ">"+ _result + "</";
        _result +=  _count;
        _result +=  ">";
        Iterator* it = p->createIterator();
        for (it->first(); !it->isDone(); it->next()) {
            Article* a = it->currentItem();
            a->accept(this);
        }
        _result += "</div>";
    };

    std::string getResult() const override {
        return _result;
    }

  private:
    std::string _result;
    int _count = 0;
};