#pragma once
#include <string>

class Article
{
public:
    Article(std::string name, std::string manufacturer,
        int stock, int diameter, float price /*, char type*/);
    virtual ~Article() = default;

    std::string getName() const;
    void setName(std::string n);

    std::string getManufacturer() const;
    void setManufacturer(std::string m);

    int getStock() const;
    void setStock(int s);

    int getDiameter() const;
    void setDiameter(int d);

    float getPrice() const;
    void setPrice(float p);

    virtual char getType() const = 0; // Abstract class
    // void setType(char t);

    virtual void print() const;

private:
    std::string name, manufacturer;
    int stock, diameter;
    float price;
// protected:
//     char type;
};
