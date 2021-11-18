#include "include/TireCenter.h"

TireCenter::TireCenter() 
{
    
}

TireCenter::~TireCenter() 
{
    
}

std::string TireCenter::getName() 
{
    return name;
}

void TireCenter::setName(std::string n) 
{
    name = n;
}

std::string TireCenter::getAddress() 
{
    return address;
}

void TireCenter::setAddress(std::string a) 
{
    address = a;
}

std::vector<Article> TireCenter::getArticles() 
{
    return articles;
}

void TireCenter::setArticles(std::vector<Article> a) 
{
    articles = a;
}

void TireCenter::addArticle(Article a) 
{
    articles.push_back(a); // maybe not good idea :D
}

std::vector<Customer> TireCenter::getCustomers() 
{
    return customers;
}

void TireCenter::setCustomers(std::vector<Customer> c) 
{
    customers = c;
}

void TireCenter::addCustomers(Customer c) 
{
    customers.push_back(c);
}
