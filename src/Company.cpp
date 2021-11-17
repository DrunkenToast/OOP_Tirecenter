#include <iostream>
#include "include/Company.h"

Company::Company() 
{
    
}

Company::~Company() 
{
    
}

std::string Company::getVAT() 
{
    return vat;
}

void Company::setVAT(std::string v) 
{
    vat = v;
}

int Company::getVolumeDiscount() 
{
    return volumeDiscount;
}

void Company::setVolumeDiscount(int vd) 
{
    volumeDiscount = vd;
}

void Company::showCustomer()
{
        std::cout << "== Company: " << this->name << " ==" << std::endl
        << "Address: " << this->address << std::endl
        << "Type: " << this->type << std::endl
        << "VAT: " << this->vat << std::endl
        << "Volume discount: " << this->volumeDiscount << std::endl;
}