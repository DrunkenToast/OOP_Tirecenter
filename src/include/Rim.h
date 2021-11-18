#pragma once
#include "Article.h"
#include <string>

class Rim
    : public Article
{
    public:
    Rim(std::string name, std::string manufacturer,
        int stock, int diameter, float price, char type,
        //Rim specific
        int width, bool isAluminium, std::string color);
    ~Rim();

    int getWidth();
    void setWidth(int w);

    bool getAluminium();
    void setAluminium(bool a);

    std::string getColor();
    void setColor(std::string c);

    void showArticle();

    private:
    std::string color;
    bool isAluminium;
    int width;
};