#pragma once
#include "customer.h"
#include <string>

class Company
    : public Customer
{
    public:
    Company() = default;
    Company(std::string name, std::string address,
        //Company specific
        std::string v, int d);
    virtual ~Company() = default;

    Customer* clone(void) const {return new Company(*this);}

    std::string getVAT() const;
    void setVAT(std::string v);

    int getVolumeDiscount() const;
    void setVolumeDiscount(int vd);

    virtual void print() const;

    private:
    std::string exportData() const;
    void importData(std::istream &input);
    std::string vat;
    int volumeDiscount;
};