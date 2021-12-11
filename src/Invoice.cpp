#include <iostream>
#include "include/Invoice.h"
#include "include/Tire.h"
#include "include/Rim.h"
#include "include/Company.h"

Invoice::Invoice()
{

}

Invoice::~Invoice() 
{
    
}

std::string Invoice::exportData() const
{
    std::stringstream data;
    
    //Articles
    data << this->getArticles().size() << std::endl; //amt
    for (auto art : this->getArticles())
    {
        data << *art;
    }
    //Customer
    data << this->getCustomer() << std::endl;
    //Price and discount
    data << this->getPrice() << std::endl << this->getDiscount() << std::endl;

    return data.str();
}

void Invoice::importData(std::istream &input)
{
    std::string line;
    Customer* cust;
    std::vector<Article*> arts {};
    int artAmt;

    getline(input, line);
    if (line == "") { artAmt = 0; } 
    else {artAmt = std::stoi(line);}

    for (int i = 0; i < artAmt; i++)
    {
        Article* entry;
        getline(input, line);
        if (line[0] == 't')
        {
            entry = new Tire();
            input >> *entry;
        }
        else
        {
            entry = new Rim();
            input >> *entry;
        }
        arts.push_back(entry);
    }
    this->setArticles(arts);

    getline(input, line);
    if (line[0] == 'c')
    {
        cust = new Company();
        input >> *cust;
    }
    else
    {
        cust = new Customer();
        input >> *cust;
    }

    this->setCustomer(*cust);
    delete cust; // cloned

    getline(input, line);
    this->setPrice(std::stof(line));

    getline(input, line);
    this->setDiscount(std::stoi(line));
}

std::vector<Article*> Invoice::getArticles() const 
{
    return articles;
}

void Invoice::setArticles(std::vector<Article*> a) 
{
    articles = a;
}

void Invoice::addArticle(Article* a) 
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
        << "Total price: " << (getPrice() - getDiscount()) << std::endl
        << "articles: " << std::endl;
    for (auto art : this->getArticles())
    {
        std::cout << "\t- " << art->getName() << " x" << art->getStock() << std::endl;
    }
}