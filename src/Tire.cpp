#include <iostream>
#include "include/Tire.h"

Tire::Tire()
{
}

Tire::~Tire()
{
}

int Tire::getWidth()
{
    return width;
}

void Tire::setWidth(int w) 
{
    width = w;
}

int Tire::getHeight()
{
    return height;
}

void Tire::setHeight(int w)
{
    height = w;
}

std::string Tire::getSpeedIndex()
{
    return speedIndex;
}

void Tire::setSpeedIndex(std::string speed)
{
    speedIndex = speed;
}

char Tire::getSeason()
{
    return season;
}

void Tire::setSeason(char s)
{
    season = s;
}

void Tire::showArticle()
{
    std::cout << "== " << this->name << " ==" << std::endl
        << "Manufacturer: " << this->manufacturer << std::endl
        << "Stock: " << this->stock << std::endl
        << "Diameter:" << this->diameter << std::endl
        << "Width: " << this->width << std::endl
        << "Height: " << this->height << std::endl
        << "Speed index: " << this->speedIndex << std::endl
        << "Price: " << this->price << std::endl
        << "Type: " << this->type << std::endl;
}