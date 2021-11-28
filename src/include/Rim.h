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
    virtual ~Rim() = default;

    int getWidth() const;
    void setWidth(int w);

    bool getAluminium() const;
    void setAluminium(bool a);

    std::string getColor() const;
    void setColor(std::string c);

    virtual void print() const;

    private:
    std::string color;
    bool isAluminium;
    int width;
};