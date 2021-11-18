#pragma once
#include "Customer.h"
#include <string>

class Company
    : public Customer
{
    public:
    Company(std::string name, std::string address, char type,
        //Company specific
        std::string vat);
    ~Company();

    std::string getVAT();
    void setVAT(std::string v);

    int getVolumeDiscount();
    void setVolumeDiscount(int vd);

    virtual void showCustomer() override;

    private:
    std::string vat;
    int volumeDiscount;
};