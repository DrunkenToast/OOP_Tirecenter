#include <iostream>
#include <map>
#include "include/Invoice.h"
#include "include/Tire.h"
#include "include/Rim.h"
#include "include/Company.h"

#define SET 4

Invoice::Invoice()
{
}

Invoice::~Invoice()
{
    // Deconstruct articles
    for (auto art : this->getArticles())
    {
        delete art;
    }

    // Deconstruct customer
    delete getCustomer();
}

std::string Invoice::exportData() const
{
    std::stringstream data;

    // Articles
    data << this->getArticles().size() << std::endl; // amt
    for (auto art : this->getArticles())
    {
        data << *art;
    }
    // Customer
    data << *this->getCustomer();
    // Price and discount
    data 
        // Won't save price because you can calculate afterwards
        // << this->getPrice() << std::endl
        << this->getDiscount() << std::endl;

    return data.str();
}

void Invoice::importData(std::istream &input)
{
    std::string line;
    Customer *cust;
    std::vector<Article *> arts{};
    int artAmt;

    getline(input, line);
    if (line == "")
    {
        artAmt = 0;
    }
    else
    {
        artAmt = std::stoi(line);
    }

    for (int i = 0; i < artAmt; i++)
    {
        Article *entry;
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

    this->setCustomer(cust);

    // getline(input, line);
    // this->setPrice(std::stof(line));

    getline(input, line);
    this->setDiscount(std::stoi(line));
    // Instead of saving the price, I recalculate with the given articles saved in the invoice
    // Articles and customer stay the same so the price will too
    this->calculatePrice();
}

std::vector<Article *> Invoice::getArticles() const
{
    return articles;
}

void Invoice::setArticles(std::vector<Article *> a)
{
    articles = a;
}

void Invoice::addArticle(Article *a)
{

    articles.push_back(a);
}

Customer* Invoice::getCustomer() const
{
    return customer;
}

void Invoice::setCustomer(Customer* c)
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

float Invoice::calculateDiscount() const
{
    float d = 0;

    if (this->getCustomer()->getType() == 'p')
    {
        std::map<int, int> diameter; // diameter tire + amount of sets
        // If customer buys a set they get a discount for that set
        for (auto art : this->getArticles())
        {
            if (art->getType() == 't' && art->getStock() >= SET)
            {
                diameter[art->getDiameter()] = art->getStock() / SET;
                d += (art->getPrice() * art->getStock() / SET * SET * getDiscount() * 0.01); // /set*set is for int rounding, 9/4*4 is 8. Only discount for the sets.
            }
        }
        // They get an extra discount for a fitting rim set
        for (auto art : this->getArticles())
        {
            if (art->getType() == 'r' && art->getStock() >= SET)
            {
                if (diameter.find(art->getDiameter()) != diameter.end())
                {
                    d += (art->getPrice() * std::min(diameter[art->getDiameter()], art->getStock() / SET) * SET * getDiscount() * 0.01);
                }
            }
        }
    }
    else
    {
        Company* cust = dynamic_cast<Company*>(this->getCustomer());
        for (auto art : this->getArticles())
        {
            if ((art->getStock() / SET) >= cust->getVolumeDiscount())
            {
                d += art->getStock() * art->getPrice() * getDiscount() * 0.01;
            }
        }
    }
    return d;
}

float Invoice::calculatePrice()
{
    float p = 0;
    for (auto art : this->getArticles())
    {
        for (int j = 0; j < art->getStock(); j++)
        {
            p += art->getPrice();
        }
    }
    if (this->getCustomer()->getType() == 'p')
    {
        p *= 1.21;
    }

    this->setPrice(p);
    return p;
}

void Invoice::print() const
{

    std::cout << "== Invoice ==" << std::endl
              << "Customer: " << getCustomer()->getName() << std::endl
              << "Total price: " << getPrice() << " $" << std::endl
              << "Discount: " << calculateDiscount() << " $" << std::endl
              << "Price: " << getPrice() - calculateDiscount() << " $" << std::endl
              << "articles: " << std::endl;
    for (auto art : this->getArticles())
    {
        std::cout << "\t- " << "x" << art->getStock() << " "
        << art->getName() << " - " << art->getManufacturer() << " | "
        << (art->getType() == 't' ? "Tire" : "Rim")
        << art->getPrice() << " $"
        << std::endl;
    }
}