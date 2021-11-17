#pragma once
#include "Customer.h"
#include <string>

class Company : Customer {
    public:
    Company();
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