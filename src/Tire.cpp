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
