#pragma once
#include "Article.h"
#include "Customer.h"
#include <vector>

class Invoice
{
public:
    // Invoice();
    ~Invoice();

    std::vector<Article> getArticles();
    void setArticles(std::vector<Article> a);
    void addArticles(Article a);

    Customer getCustomer();
    void setCustomer(Customer c);

    float getPrice();
    void setPrice(float p);

    int getDiscount();
    void setDiscount(int d);

    void showInvoice();
private:
    std::vector<Article> articles;
    Customer customer;
    float price;
    int discount;

    // What do these do??
    // float calculateDiscount();
    // float calculatePrice();
};
