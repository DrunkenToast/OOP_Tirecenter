#pragma once
#include "Article.h"
#include <string>

class Tire 
    : public Article 
{
    public:
    Tire(std::string name, std::string manufacturer,
        int stock, int diameter, float price, char type,
        //Tire specific
        int width, int height, std::string speedIndex, char season);
    ~Tire();

    int getWidth();
    void setWidth(int w);

    int getHeight();
    void setHeight(int w);

    std::string getSpeedIndex();
    void setSpeedIndex(std::string speed);

    char getSeason();
    void setSeason(char s);

    void showArticle();

    private:
    int width, height;
    std::string speedIndex;
    char season;
};