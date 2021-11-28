#pragma once
#include <string>

class Customer {
    public:
    Customer(std::string name, std::string address, char type);
    virtual ~Customer() = default;

    std::string getName() const;
    void setName(std::string n);

    std::string getAddress() const;
    void setAddress(std::string a);

    char getType() const;
    void setType(char t);

    virtual void print() const;

    private:
    std::string name, address;
    char type;
};