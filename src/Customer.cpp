#include <iostream>
#include "include/Customer.h"

Customer::Customer(std::string name, std::string address, char type)
    : name(name), address(address), type(type)
{
    
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