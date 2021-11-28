#pragma once
#include "Article.h"
#include "Customer.h"
#include <vector>

class Invoice
{
public:
    Invoice(Customer customer, float price, int discount, std::vector<Article> articles);
    ~Invoice();

    std::vector<Article> getArticles();
    void setArticles(std::vector<Article> a);
    void addArticles(Article a);

    Customer getCustomer() const;
    void setCustomer(Customer c);

    float getPrice() const;
    void setPrice(float p);

    int getDiscount() const;
    void setDiscount(int d);

    void print() const;
private:
    std::vector<Article> articles;
    Customer customer;
    float price;
    int discount;

    // What do these do??
    // float calculateDiscount();
    // float calculatePrice();
};
