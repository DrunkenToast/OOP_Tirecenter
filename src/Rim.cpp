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


std::string Rim::exportData() const
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
        << getAluminium() << std::endl
        << getColor() << std::endl;
    return data.str();
}

void Rim::importData(std::istream &input)
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
    setAluminium(std::stoi(line));

    getline(input, line);
    setColor(line);

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