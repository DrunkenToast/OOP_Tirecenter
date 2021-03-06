#include <iostream>
#include <sstream>
#include "include/company.h"

Company::Company(std::string name, std::string address,
        //Company specific
        std::string v, int d)
    : Customer(name, address, 'c'), vat(v), volumeDiscount(d)
{
    
}

std::string Company::exportData() const
{
    std::stringstream data;
    data
        << getType() << std::endl

        << getName() << std::endl
        << getAddress() << std::endl
        
        << getVAT() << std::endl
        << getVolumeDiscount() << std::endl;
    return data.str();
}

void Company::importData(std::istream &input)
{
    std::string line;
    setType('c');
    
    getline(input, line);
    setName(line);

    getline(input, line);
    setAddress(line);

    getline(input, line);
    setVAT(line);

    getline(input, line);
    setVolumeDiscount(std::stoi(line));
}

std::string Company::getVAT() const
{
    return vat;
}

void Company::setVAT(std::string v) 
{
    vat = v;
}

int Company::getVolumeDiscount() const
{
    return volumeDiscount;
}

void Company::setVolumeDiscount(int vd) 
{
    volumeDiscount = vd;
}

void Company::print() const
{
    Customer::print();
    std::cout
        << "VAT: " << getVAT() << std::endl
        << "Volume discount: " << getVolumeDiscount() << std::endl;
}