#include <iostream>
#include "include/Company.h"

Company::Company(std::string name, std::string address, char type,
        //Company specific
        std::string vat, int valumeDiscount)
    : Customer(name, address, type), vat(vat), volumeDiscount(volumeDiscount)
{
    
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