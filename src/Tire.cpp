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

std::string Tire::exportData() const
{
    std::stringstream data;
    data
        << getType() << std::endl

        << getName() << std::endl
        << getManufacturer() << std::endl
        << getStock() << std::endl
        << getDiameter() << std::endl
        << getPrice() << std::endl

        << getWidth() << std::endl
        << getHeight() << std::endl
        << getSpeedIndex() << std::endl
        << getSeason() << std::endl;
    return data.str();
}

void Tire::importData(std::istream &input)
{
    std::string line;
    getline(input, line);
    setName(line);

    getline(input, line);
    setManufacturer(line);

    getline(input, line);
    setStock(std::stoi(line));

    getline(input, line);
    setDiameter(std::stoi(line));

    getline(input, line);
    setPrice(std::stof(line));


    getline(input, line);
    setWidth(std::stoi(line));

    getline(input, line);
    setHeight(std::stoi(line));

    getline(input, line);
    setSpeedIndex(line);

    getline(input, line);
    setSeason(line[0]);

}

char Tire::getType() const 
{
    return 't';
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