#pragma once
#include "Article.h"
#include <string>

class Tire 
    : public Article 
{
    public:
    Tire(std::string name, std::string manufacturer,
        int stock, int diameter, float price,
        //Tire specific
        int width, int height, std::string speedIndex, char season);
    virtual ~Tire() = default;

    virtual char getType() const override;

    int getWidth() const;
    void setWidth(int w);

    int getHeight() const;
    void setHeight(int w);

    std::string getSpeedIndex() const;
    void setSpeedIndex(std::string speed);

    char getSeason() const;
    void setSeason(char s);

    virtual void print() const override;

    private:
    int width, height;
    std::string speedIndex;
    char season;
};