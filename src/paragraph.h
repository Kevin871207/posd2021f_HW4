#pragma once

#include <string>
#include <list>
#include <sstream>

#include "./iterator/iterator.h"
#include "./iterator/compound_iterator.h"
#include "./iterator/null_iterator.h"
#include "./visitor/article_visitor.h"
#include "article.h"


class Paragraph : public Article {
   public:
    Paragraph(int level, std::string text) {
        if (level <= 0) {
            throw std::string("Level is negative or zero\n");
        }
        if (level > 6) {
            throw std::string("Level is larger then six\n");
        }
        _level = level;
        _text = text;
    }

    ~Paragraph() {}

    std::string getText() const override {
        return _text;
    }

    int getLevel() const override {
        return _level;
    }

    Iterator* createIterator() override {
        return new CompoundIterator<std::list<Article *>::const_iterator>(_articles.begin(), _articles.end());
    }

    void add(Article* content) override {
        if (content->getLevel() != 0 && content->getLevel() < _level) {
                throw "error on add" + std::to_string(content->getLevel()) +
                      "greater then" + std::to_string(_level);
            }
        _articles.push_back(content);
    }

    void accept(ArticleVisitor* visitor) override {
        visitor->visitParagraph(this);
    }

  private:
        int _level;
        int _count = 0;
        std::string _text;
        std::list<Article *> _articles;
};