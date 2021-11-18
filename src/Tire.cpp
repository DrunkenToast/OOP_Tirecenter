#include <iostream>
#include "include/Tire.h"

Tire::Tire(std::string name, std::string manufacturer,
        int stock, int diameter, float price, char type,
        //Tire specific
        int width, int height, std::string speedIndex, char season)
    : Article(name, manufacturer, stock, diameter, price, type),
        width(width), height(height), speedIndex(speedIndex), season(season)
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
    Article::showArticle();
    std::cout
        << "Width: " << getWidth() << std::endl
        << "Height: " << getHeight() << std::endl
        << "Speed index: " << getSpeedIndex() << std::endl
        << "Season: " << getSeason() << std::endl;
}