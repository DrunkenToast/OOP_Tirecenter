#include <iostream>
#include "include/Rim.h"
#include "include/Article.h"

Rim::Rim() 
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
    return this->aluminium;
}

void Rim::setAluminium(bool a) 
{
    this->aluminium = a;
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
    std::cout << "== " << this->name << " ==" << std::endl
        << "Manufacturer: " << this->manufacturer << std::endl
        << "Stock: " << this->stock << std::endl
        << "Diameter:" << this->diameter << std::endl
        << "Width: " << this->width << std::endl
        << "Color: " << this->color << std::endl
        << "Aluminium" << (this->aluminium ? "Yes" : "No") << std::endl
        << "Price: " << this->price << std::endl
        << "Type: " << this->type << std::endl;
}