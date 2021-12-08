#include <iostream>
#include "include/Invoice.h"

Invoice::Invoice()
{
    
}

Invoice::~Invoice() 
{
    
}

std::vector<Article*> Invoice::getArticles() 
{
    return articles;
}

void Invoice::setArticles(std::vector<Article*> a) 
{
    articles = a;
}

void Invoice::addArticles(Article* a) 
{
    
    articles.push_back(a);
}

Customer Invoice::getCustomer() const
{
    return customer;
}

void Invoice::setCustomer(Customer c) 
{
    customer = c;
}

int Invoice::getDiscount() const
{
    return discount;
}

void Invoice::setDiscount(int d) 
{
    discount = d;
}

float Invoice::getPrice() const
{
    return price;
}

void Invoice::setPrice(float p) 
{
    price = p;
}

void Invoice::print() const
{
    std::cout << "== Invoice ==" << std::endl
        << "Customer: " << getCustomer().getName() << std::endl
        << "Price" << getPrice() << std::endl
        << "Discount: " << getDiscount() << std::endl
        << "articles: ..." << std::endl; // TODO, just loop and add to string
}