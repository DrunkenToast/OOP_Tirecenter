#include "include/Article.h"

Article::Article() 
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
