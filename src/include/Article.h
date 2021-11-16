#pragma once
#include <string>

class Article
{
public:
    Article();
    ~Article();

    std::string getName();
    void setName(std::string n);
    std::string getManufacturer();
    void setManufacturer(std::string m);
    int getStock();
    void setStock(int s);
    int getDiameter();
    void setDiameter(int d);
    float getPrice();
    void setPrice(float p);
    char getType();
    void setType(char t);
private:
    std::string name, manufacturer;
    int stock, diameter;
    float price;
    char type;
};
