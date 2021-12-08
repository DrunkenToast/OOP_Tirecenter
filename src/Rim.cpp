#include <iostream>
#include "include/Rim.h"
#include "include/Article.h"

Rim::Rim(std::string name, std::string manufacturer,
        int stock, int diameter, float price,
        //Rim specific
        int width, bool isAluminium, std::string color)
    : Article(name, manufacturer, stock, diameter, price),
        width(width), isAluminium(isAluminium), color(color)
{
    
}

char Rim::getType() const 
{
    return 'r';
}

int Rim::getWidth() const
{
    return this->width;
}

void Rim::setWidth(int w)
{
    this->width = w;
}

bool Rim::getAluminium() const
{
    return this->isAluminium;
}

void Rim::setAluminium(bool a) 
{
    this->isAluminium = a;
}

std::string Rim::getColor() const
{
    return this->color;
}

void Rim::setColor(std::string c) 
{
    this->color = c;
}

void Rim::print() const
{
    Article::print();   
    std::cout
        << "Width: " << getWidth() << std::endl
        << "Color: " << getColor() << std::endl
        << "Aluminium: " << (getAluminium() ? "Yes" : "No") << std::endl;
}