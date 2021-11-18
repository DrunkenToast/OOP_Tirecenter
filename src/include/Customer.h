#pragma once
#include <string>

class Customer {
    public:
    Customer(std::string name, std::string address, char type);
    ~Customer();

    std::string getName();
    void setName(std::string n);

    std::string getAddress();
    void setAddress(std::string a);

    char getType();
    void setType(char t);

    virtual void showCustomer();

    private:
    std::string name, address;
    char type;
};