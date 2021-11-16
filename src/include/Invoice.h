#pragma once
#include "Article.h"
#include "Customer.h"
#include <vector>

class Invoice
{
public:
    Invoice();
    ~Invoice();

    std::vector<Article> getArticles();
    void setArticles(std::vector<Article> a);
    void addArticles(Article a);

    std::vector<Customer> getCustomers();
    void setCustomers(std::vector<Customer> c);
    void addCustomers(Customer c);

    int getDiscount();
    void setDiscount(int d);
    
    float getPrice();
    void setPrice(float p);
private:
    std::vector<Article> articles;
    std::vector<Customer> customers;
    float price;
    int discount;

};
