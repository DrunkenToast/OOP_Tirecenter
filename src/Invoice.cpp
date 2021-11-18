#include "include/Invoice.h"

// Invoice::Invoice() 
// {
    
// }

Invoice::~Invoice() 
{
    
}

std::vector<Article> Invoice::getArticles() 
{
    return articles;
}

void Invoice::setArticles(std::vector<Article> a) 
{
    articles = a;
}

void Invoice::addArticles(Article a) 
{
    articles.push_back(a);
}

Customer Invoice::getCustomer() 
{
    return customer;
}

void Invoice::setCustomer(Customer c) 
{
    customer = c;
}

int Invoice::getDiscount() 
{
    return discount;
}

void Invoice::setDiscount(int d) 
{
    discount = d;
}

float Invoice::getPrice() 
{
    return price;
}

void Invoice::setPrice(float p) 
{
    price = p;
}
