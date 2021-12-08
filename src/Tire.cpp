#include <iostream>
#include "include/Tire.h"

Tire::Tire(std::string name, std::string manufacturer,
        int stock, int diameter, float price,
        //Tire specific
        int width, int height, std::string speedIndex, char season)
    : Article(name, manufacturer, stock, diameter, price),
        width(width), height(height), speedIndex(speedIndex), season(season)
{
}

char Tire::getType() const 
{
    return 'r';
}


int Tire::getWidth() const
{
    return width;
}

void Tire::setWidth(int w) 
{
    width = w;
}

int Tire::getHeight() const
{
    return height;
}

void Tire::setHeight(int w)
{
    height = w;
}

std::string Tire::getSpeedIndex() const
{
    return speedIndex;
}

void Tire::setSpeedIndex(std::string speed)
{
    speedIndex = speed;
}

char Tire::getSeason() const
{
    return season;
}

void Tire::setSeason(char s)
{
    season = s;
}

void Tire::print() const
{
    Article::print();
    std::cout
        << "Width: " << getWidth() << std::endl
        << "Height: " << getHeight() << std::endl
        << "Speed index: " << getSpeedIndex() << std::endl
        << "Season: " << getSeason() << std::endl;
}