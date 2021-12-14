#pragma once
#include <string>
#include <vector>
#include "Article.h"
#include "Customer.h"
#include "Invoice.h"
#include <map>

class TireCenter
{
public:
    TireCenter();
    TireCenter(std::string name, std::string address);
    ~TireCenter();

    friend std::ostream& operator<<(std::ostream& output, const TireCenter &cust){
        return (output << cust.exportData());
    };

    friend std::istream& operator>>(std::istream& input, TireCenter &cust){
        cust.importData(input);
        return input;
    };

    std::string getName() const;
    void setName(std::string n);

    std::string getAddress() const;
    void setAddress(std::string a);

    std::vector<Article*>& getArticles();
    void setArticles(std::vector<Article*> a);
    void addArticle(Article* a);

    std::vector<Customer*>& getCustomers();
    void setCustomers(std::vector<Customer*> c);
    void addCustomer(Customer* c);

    std::vector<Invoice*>& getInvoices();
    void setInvoices(std::vector<Invoice*> i);
    void addInvoice(Invoice* i);

    void welcome() const;
    void goodbye() const;
private:
    virtual std::string exportData() const;
    virtual void importData(std::istream &input);
    std::string name, address;
    std::vector<Article*> articles;
    std::vector<Customer*> customers;
    std::vector<Invoice*> invoices;
};
