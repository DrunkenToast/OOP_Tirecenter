#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "include/FileHandler.h"
#include "include/Tire.h"
#include "include/Rim.h"
#include "include/Company.h"

FileHandler::FileHandler(TireCenter &tc) 
    : tc(tc)
{    
    this->loadAll();

}

FileHandler::~FileHandler() 
{
    this->saveAll();
}

void FileHandler::saveAll() 
{
    std::cout << std::endl << "Saving to files: " << std::endl;
    this->saveTireCenter();
    this->saveArticles();
    this->saveCustomers();
    this->saveInvoices();
    std::cout << std::endl;
}

void FileHandler::loadAll() 
{
    std::cout << std::endl << "Loading from files: " << std::endl;
    this->loadTireCenter();
    this->loadArticles();
    this->loadCustomers();
    this->loadInvoices();
    std::cout << std::endl;
}

std::ofstream FileHandler::outputFile(const char* filePath) 
{
    std::ofstream outFile{filePath, std::ios::out};
    if (!outFile)
    {
        std::cerr << "File " << filePath << " couldn't be opened for writing!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return outFile;
}

std::ifstream FileHandler::inputFile(const char* filePath) 
{
    // Make sure file exists. (Open in append and close)
    std::ofstream tmp{filePath, std::ios::out | std::ios::app};
    tmp.close();

    // Open file in read.
    std::ifstream inFile{filePath, std::ios::in};
    if (!inFile)
    {
        std::cerr << "File " << filePath << " couldn't be opened for reading!";
        exit(EXIT_FAILURE);
    }
    return inFile;
}

void FileHandler::saveTireCenter() 
{
    std::cout << "Saving tire center... ";

    std::ofstream file = outputFile(this->pathTireCenter);

    file << tc;

    file.close();
    std::cout << "Done." << std::endl;
}

void FileHandler::loadTireCenter() 
{
    std::cout << "Loading tire center... ";

    std::ifstream file = inputFile(this->pathTireCenter);
    
    file >> tc;

    file.close();
    std::cout << "Done." << std::endl;
}

void FileHandler::saveArticles() 
{
    std::cout << "Saving articles... ";

    std::ofstream file = outputFile(this->pathArticles);

    // Export amount of articles
    file << tc.getArticles().size() << std::endl;

    // Export articles
    for (auto art : tc.getArticles()) {
        file << *art;
    }

    file.close();
    std::cout << "Done." << std::endl;
}

void FileHandler::loadArticles() 
{
    std::cout << "Loading articles... ";

    std::ifstream file = inputFile(this->pathArticles);
    int amt;
    std::vector<Article*> articles {};

    std::string line;

    getline(file, line);
    if (line == "") { amt = 0; } 
    else {amt = std::stoi(line);}

    for (int i = 0; i < amt; i++)
    {
        Article* entry;
        getline(file, line);
        if (line[0] == 't')
        {
            entry = new Tire();
            file >> *entry;
        }
        else
        {
            entry = new Rim();
            file >> *entry;
        }
        articles.push_back(entry);
    }

    tc.setArticles(articles);

    file.close();
    std::cout << "Done." << std::endl;
}

void FileHandler::saveCustomers() 
{
    std::cout << "Saving customers... ";

    std::ofstream file = outputFile(this->pathCustomers);

    // Export amount of customers
    file << tc.getCustomers().size() << std::endl;

    // Export customers
    for (auto cust : tc.getCustomers()) {
        file << *cust;
    }

    file.close();
    std::cout << "Done." << std::endl;
}

void FileHandler::loadCustomers() 
{
    std::cout << "Loading customers... ";

    std::ifstream file = inputFile(this->pathCustomers);
    int amt;
    std::vector<Customer*> customers {};

    std::string line;

    getline(file, line);
    if (line == "") { amt = 0; } 
    else {amt = std::stoi(line);}

    for (int i = 0; i < amt; i++)
    {
        Customer* entry;
        getline(file, line);
        if (line[0] == 'c')
        {
            entry = new Company();
            file >> *entry;
        }
        else
        {
            entry = new Customer();
            file >> *entry;
        }
        customers.push_back(entry);
    }

    tc.setCustomers(customers);

    file.close();
    std::cout << "Done." << std::endl;
}

void FileHandler::saveInvoices() 
{
    std::cout << "Saving invoices... ";

    std::ofstream file = outputFile(this->pathInvoices);

    // Export amount of customers
    file << tc.getInvoices().size() << std::endl;

    // Export invoices
    for (auto inv : tc.getInvoices()) {
        file << *inv;
    }

    file.close();
    std::cout << "Done." << std::endl;
}

void FileHandler::loadInvoices() 
{
    std::cout << "Loading invoices... ";

    std::ifstream file = inputFile(this->pathInvoices);
    int amt;
    std::vector<Invoice*> invoices {};

    std::string line;

    getline(file, line);
    if (line == "") { amt = 0; } 
    else {amt = std::stoi(line);}

    for (int i = 0; i < amt; i++)
    {
        Invoice* entry = new Invoice();
        file >> *entry;
        invoices.push_back(entry);
    }

    tc.setInvoices(invoices);

    file.close();
    std::cout << "Done." << std::endl;
}
