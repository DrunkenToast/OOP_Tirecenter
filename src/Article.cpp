#include <iostream>
#include "include/Article.h"

Article::Article(std::string name, std::string manufacturer,
    int stock, int diameter, float price, char type) 
    : name(name), manufacturer(manufacturer), stock(stock), diameter(diameter),
    price(price), type(type)
{
    
}

Article::~Article() 
{
    
}

std::string Article::getName() 
{
    return name;
}

void Article::setName(std::string n) 
{
    name = n;
}

std::string Article::getManufacturer() 
{
    return manufacturer;
}

void Article::setManufacturer(std::string m) 
{
    manufacturer = m;
}

int Article::getStock() 
{
    return stock;
}

void Article::setStock(int s) 
{
    stock = s;
}

int Article::getDiameter() 
{
    return diameter;
}

void Article::setDiameter(int d) 
{
    diameter = d;
}

float Article::getPrice() 
{
    return price;
}

void Article::setPrice(float p) 
{
    price = p;
}

char Article::getType() 
{
    return type;
}

void Article::setType(char t) 
{
    type = t;
}

void Article::showArticle()
{
    std::cout << std::endl << "== Article: " << getName() << " ==" << std::endl
        << "Manufacturer: " << getManufacturer() << std::endl
        << "Stock: " << getStock() << std::endl
        << "Diameter:" << getDiameter() << std::endl
        << "Price: " << getPrice() << std::endl
        << "Type: " << getType() << std::endl;
}