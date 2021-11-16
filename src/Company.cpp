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
