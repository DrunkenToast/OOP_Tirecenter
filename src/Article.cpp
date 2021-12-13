#include <iostream>
#include "include/Article.h"

Article::Article(std::string name, std::string manufacturer,
    int stock, int diameter, float price) 
    : name(name), manufacturer(manufacturer), stock(stock), diameter(diameter),
    price(price)
{
    
}

std::string Article::getName() const
{
    return name;
}

void Article::setName(std::string n) 
{
    name = n;
}

std::string Article::getManufacturer() const
{
    return manufacturer;
}

void Article::setManufacturer(std::string m) 
{
    manufacturer = m;
}

int Article::getStock() const
{
    return stock;
}

void Article::setStock(int s) 
{
    stock = s;
}

int Article::getDiameter() const
{
    return diameter;
}

void Article::setDiameter(int d) 
{
    diameter = d;
}

float Article::getPrice() const
{
    return price;
}

void Article::setPrice(float p) 
{
    price = p;
}

// char Article::getType() const
// {
//     return type;
// }

// void Article::setType(char t) 
// {
//     type = t;
// }

void Article::print() const
{
    std::cout
        << std::endl << "== Article: " << getName() << " ==" << std::endl
        << "Manufacturer: " << getManufacturer() << std::endl
        << "Stock: " << getStock() << std::endl
        << "Diameter:" << getDiameter() << std::endl
        << "Price: " << getPrice() << " $"<< std::endl
        << "Type: " << (getType() == 't' ? "Tire" : "Rim") << std::endl;
}