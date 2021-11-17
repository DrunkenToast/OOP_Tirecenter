#pragma once
#include <string>

class Customer {
    public:
    Customer();
    ~Customer();

    std::string getName();
    void setName(std::string n);

    std::string getAddress();
    void setAddress(std::string a);

    char getType();
    void setType(char t);

    virtual void showCustomer();

    protected:
    std::string name, address;
    char type;
};