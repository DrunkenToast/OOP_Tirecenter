#include "include/tirecenter.h"
#include <iostream>
#include <sstream>
TireCenter::TireCenter() {}
TireCenter::TireCenter(std::string name, std::string address)
    : name(name), address(address)
{}

TireCenter::~TireCenter() 
{
    // Deconstruct articles
    for (auto art : this->getArticles())
    {
        delete art;
    }

    // Deconstruct customers
    for (auto cust : this->getCustomers())
    {
        delete cust;
    }

    // Deconstruct invoicers
    for (auto inv : this->getInvoices())
    {
        delete inv;
    }

}

std::string TireCenter::exportData() const
{
    std::stringstream data;
    data
        << getName() << std::endl
        << getAddress() << std::endl;
    return data.str();
}

void TireCenter::importData(std::istream &input)
{
    std::string line;
    getline(input, line);
    setName(line);

    getline(input, line);
    setAddress(line);
}

std::string TireCenter::getName() const
{
    return name;
}

void TireCenter::setName(std::string n) 
{
    name = n;
}

std::string TireCenter::getAddress() const
{
    return address;
}

void TireCenter::setAddress(std::string a) 
{
    address = a;
}

std::vector<Article*>& TireCenter::getArticles() 
{
    return articles;
}

void TireCenter::setArticles(std::vector<Article*> a) 
{
    articles = a;
}

void TireCenter::addArticle(Article* a) 
{
    articles.push_back(a);
}

std::vector<Customer*>& TireCenter::getCustomers() 
{
    return customers;
}

void TireCenter::setCustomers(std::vector<Customer*> c) 
{
    customers = c;
}

void TireCenter::addCustomer(Customer* c) 
{
    customers.push_back(c);
}

std::vector<Invoice*>& TireCenter::getInvoices() 
{
    return invoices;
}

void TireCenter::setInvoices(std::vector<Invoice*> i) 
{
    invoices = i;
}

void TireCenter::addInvoice(Invoice* i) 
{
    invoices.push_back(i);
}

void TireCenter::welcome() const
{
    std::cout
    << " ███████████  ███                          █████████                       █████                      " << std::endl
    << "░█░░░███░░░█ ░░░                          ███░░░░░███                     ░░███                       " << std::endl
    << "░   ░███  ░  ████  ████████   ██████     ███     ░░░   ██████  ████████   ███████    ██████  ████████ " << std::endl
    << "    ░███    ░░███ ░░███░░███ ███░░███   ░███          ███░░███░░███░░███ ░░░███░    ███░░███░░███░░███" << std::endl
    << "    ░███     ░███  ░███ ░░░ ░███████    ░███         ░███████  ░███ ░███   ░███    ░███████  ░███ ░░░ " << std::endl
    << "    ░███     ░███  ░███     ░███░░░     ░░███     ███░███░░░   ░███ ░███   ░███ ███░███░░░   ░███     " << std::endl
    << "    █████    █████ █████    ░░██████     ░░█████████ ░░██████  ████ █████  ░░█████ ░░██████  █████    " << std::endl
    << "   ░░░░░    ░░░░░ ░░░░░      ░░░░░░       ░░░░░░░░░   ░░░░░░  ░░░░ ░░░░░    ░░░░░   ░░░░░░  ░░░░░     " << std::endl
    << std::endl << getName() << std::endl
    << "Address: " << getAddress() << std::endl << std::endl;
}

void TireCenter::goodbye() const
{
    std::cout
    << "  ______                 _ _                 "  << std::endl
    << " / _____)               | | |                " << std::endl
    << "| /  ___  ___   ___   _ | | | _  _   _  ____ " << std::endl
    << "| | (___)/ _ \\ / _ \\ / || | || \\| | | |/ _  )" << std::endl
    << "| \\____/| |_| | |_| ( (_| | |_) ) |_| ( (/ / " << std::endl
    << " \\_____/ \\___/ \\___/ \\____|____/ \\__  |\\____)" << std::endl
    << "                                (____/       " << std::endl;
}