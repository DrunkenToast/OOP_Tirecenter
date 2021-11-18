#include <iostream>
#include "include/Customer.h"

Customer::Customer(std::string name, std::string address, char type) 
{
    
}

Customer::~Customer() 
{
    
}

std::string Customer::getName() 
{
    return name;
}

void Customer::setName(std::string n) 
{
    name = n;
}

std::string Customer::getAddress() 
{
    return address;
}

void Customer::setAddress(std::string a) 
{
    address = a;
}

char Customer::getType() 
{
    return type;
}

void Customer::setType(char t) 
{
    type = t;
}

void Customer::showCustomer()
{
    std::cout << "== " << getName() << " ==" << std::endl
        << "Address: " << getAddress() << std::endl
        << "Type: " << getType() << std::endl;
}