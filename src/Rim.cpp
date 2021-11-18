#include <iostream>
#include "include/Rim.h"
#include "include/Article.h"

Rim::Rim(std::string name, std::string manufacturer,
        int stock, int diameter, float price, char type,
        //Rim specific
        int width, bool isAluminium, std::string color)
    : Article(name, manufacturer, stock, diameter, price, type),
        width(width), isAluminium(isAluminium), color(color)
{
    
}

Rim::~Rim() 
{
    
}

int Rim::getWidth() 
{
    return this->width;
}

void Rim::setWidth(int w) 
{
    this->width = w;
}

bool Rim::getAluminium() 
{
    return this->isAluminium;
}

void Rim::setAluminium(bool a) 
{
    this->isAluminium = a;
}

std::string Rim::getColor() 
{
    return this->color;
}

void Rim::setColor(std::string c) 
{
    this->color = c;
}

void Rim::showArticle()
{
    Article::showArticle();   
    std::cout
        << "Width: " << getWidth() << std::endl
        << "Color: " << getColor() << std::endl
        << "Aluminium: " << (getAluminium() ? "Yes" : "No") << std::endl;
}