#include <iostream>
#include <sstream>
#include "include/customer.h"

Customer::Customer(std::string name, std::string address, char type)
    : name(name), address(address), type(type)
{
    
}

std::string Customer::exportData() const
{
    std::stringstream data;
    data
        << getType() << std::endl

        << getName() << std::endl
        << getAddress() << std::endl;
    return data.str();
}

void Customer::importData(std::istream &input)
{
    std::string line;
    setType('p');

    getline(input, line);
    setName(line);

    getline(input, line);
    setAddress(line);
}

std::string Customer::getName() const
{
    return name;
}

void Customer::setName(std::string n) 
{
    name = n;
}

std::string Customer::getAddress() const
{
    return address;
}

void Customer::setAddress(std::string a) 
{
    address = a;
}

char Customer::getType() const
{
    return type;
}

void Customer::setType(char t) 
{
    type = t;
}

void Customer::print() const
{
    std::cout << "== " << getName() << " ==" << std::endl
        << "Address: " << getAddress() << std::endl
        << "Type: " << getType() << std::endl;
}