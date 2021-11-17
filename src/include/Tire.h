#pragma once
#include "Article.h"
#include <string>

class Tire : Article {
    public:
    Tire();
    ~Tire();

    int getWidth();
    void setWidth(int w);

    int getHeight();
    void setHeight(int w);

    std::string getSpeedIndex();
    void setSpeedIndex(std::string speed);

    char getSeason();
    void setSeason(char s);

    virtual void showArticle() override;

    private:
    int width, height;
    std::string speedIndex;
    char season;
};