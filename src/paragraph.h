#pragma once

#include <string>

#include "article.h"

class Paragraph : public Article {
    public:
        Paragraph(int level, std::string text) {
            _level = level;
            while (level--) {
                _text += "#";
            }
            _text += " " + text;
        }

        ~Paragraph() {}
        std::string getText() const override {
            return _text;
        }
        int getLevel() const override {
            return _level;
        }
        void add(Article* content) override {
            if (content->getLevel() != 0 && content->getLevel() <= _level) {
                throw "error on add" + std::to_string(content->getLevel()) +
                      "greater then" + std::to_string(_level);
            }
            _text += "\n" + content->getText();
        }

    private:
        int _level;
        std::string _text;
};
