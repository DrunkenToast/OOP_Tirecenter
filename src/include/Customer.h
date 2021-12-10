#pragma once
#include <string>

class Customer {
    public:
    Customer() = default;
    Customer(std::string name, std::string address, char type);
    virtual ~Customer() = default;

    friend std::ostream& operator<<(std::ostream& output, const Customer &cust){
        return (output << cust.exportData()); //maybe revert
    };

    friend std::istream& operator>>(std::istream& input, Customer &cust){
        cust.importData(input);
    };


    std::string getName() const;
    void setName(std::string n);

    std::string getAddress() const;
    void setAddress(std::string a);

    char getType() const;
    void setType(char t);

    virtual void print() const;

    private:
    virtual std::string exportData() const;
    virtual void importData(std::istream &input);
    std::string name, address;
    char type;
};