#include "include/actions.h"
#include "include/Tire.h"
#include "include/Rim.h"
#include "include/Company.h"
#include "include/Menu.h"
#include "include/util.h"

#include <iostream>
#include <vector>

Article* searchArticle(std::vector<Article*> &articles)
{
    unsigned int option;
    Article* article = nullptr;
    while (article == nullptr)
    {
        option = Menu::displayMenu("Search article", std::vector<std::string> {
            "Cancel search",
            "Search all by keyword",
            "Filter Tires",
            "Filter Rims",
            "Filter Size"
        });
        switch (option)
        {
        case 0:
            return nullptr;
        case 1:
            article = filterKeyword(articles);
            break;
        case 2:
            article = dynamic_cast<Article*>(filterTires(articles));
            break;
        case 3:
            article = dynamic_cast<Article*>(filterRims(articles));
            break;
        case 4:
            article = filterSize(articles);
            break;
        default:
            break;
        }
    }
    return article;
}

Article* filterKeyword(std::vector<Article*> &articles)
{
    unsigned int option;
    std::vector<Article*> found {};
    std::string needle;

    std::cout << "Keyword to search: ";
    getline(std::cin, needle);

    for (auto art : articles)
    {
        if (Util::asciiToLower(art->getName()).find(Util::asciiToLower(needle)) != std::string::npos)
        {
            found.push_back(art);
        }
    }

    std::vector<std::string> options {"Cancel"};
    for (auto i : found)
    {
        options.push_back(i->getName());
    }

    option = Menu::displayMenu("Pick article. Searched: \"" + needle + '"', options);
    if (option == 0)
    {
        return nullptr;
    }

    return found.at(option-1); // -1 for cancel option
}

Tire* filterTires(std::vector<Article*> &articles)
{
    unsigned int option;
    std::string buffer;
    std::vector<Tire*> tires {};
    std::vector<Tire*> found {};
    int needle;

    std::cout << "Diameter to filter tires: ";
    std::getline(std::cin, buffer);
    needle = stoi(buffer);

    for (auto art : articles)
    {
        if (art->getType() == 't')
        {
            tires.push_back(dynamic_cast<Tire*>(art));
        }
    }

    for (auto tire : tires)
    {
        if (tire->getDiameter() == needle)
        {
            found.push_back(dynamic_cast<Tire*>(tire));
        }
    }

    std::vector<std::string> options {"Cancel"};
    for (auto &i : found)
    {
        options.push_back(i->getName());
    }

    option = Menu::displayMenu("Pick a tire. Searched for diameter: \"" + std::to_string(needle) + '"', options);
    if (option == 0)
    {
        return nullptr;
    }

    return tires.at(option-1); // -1 for cancel option
}

Rim* filterRims(std::vector<Article*> &articles)
{
    unsigned int option;
    std::string buffer;
    std::vector<Rim*> rims {};
    std::vector<Rim*> found {};
    int needle;

    std::cout << "Diameter to filter rims: ";
    std::getline(std::cin, buffer);
    needle = stoi(buffer);

    for (auto art : articles)
    {
        if (art->getType() == 'r')
        {
            rims.push_back(dynamic_cast<Rim*>(art));
        }
    }

    for (auto tire : rims)
    {
        if (tire->getDiameter() == needle)
        {
            found.push_back(dynamic_cast<Rim*>(tire));
        }
    }

    std::vector<std::string> options {"Cancel"};
    for (auto &i : found)
    {
        options.push_back(i->getName());
    }

    option = Menu::displayMenu("Pick a rim. Searched for diameter: \"" + std::to_string(needle) + '"', options);
    if (option == 0)
    {
        return nullptr;
    }

    return rims.at(option-1); // -1 for cancel option
}

Article* filterSize(std::vector<Article*> &articles)
{
    unsigned int option;
    std::string buffer;
    int needle;
    std::vector<Article*> found {};

    std::cout << "Diameter to filter articles: ";
    std::getline(std::cin, buffer);
    needle = stoi(buffer);

    for (auto art : articles)
    {
    
        if (art->getDiameter() == needle)
        {
            found.push_back(art);
        }
    }

    std::vector<std::string> options {"Cancel"};
    for (auto &i : found)
    {
        options.push_back(i->getName());
    }

    option = Menu::displayMenu("Pick a tire. Searched for diameter: \"" + std::to_string(needle) + '"', options);
    if (option == 0)
    {
        return nullptr;
    }

    return articles.at(option-1); // -1 for cancel option
}

void addArticle(std::vector<Article*> &articles)
{
    int option = Menu::displayMenu("Add article", std::vector<std::string> {"Exit", "Add tire", "Add rim"});
    Article* art;
    bool dupe;
    switch (option)
    {
    case 0:
        return;    
    case 1:
    {
        art = new Tire("New tire", "manufacturer", 1, 1, 1, 1, 1, "speed index", 's');
        break;
    }
    case 2:
    {
        art = new Rim("New rim", "manufacturer", 1, 1, 1, 1, true, "color");
        break;
    }
    default:
        return;
    }

    do
    {
        changeArticle(art);
        dupe = false;
        for (auto a : articles)
        {
            if (art->getName() == a->getName())
            {
                std::cout << "An article with this name already exists. Try again." << std::endl;
                dupe = true;
                break;
            }
        }
    } while (dupe);

    articles.push_back(art);
    // tirecenter.addArticle(art);
}

void deleteArticle(std::vector<Article*> &articles, Article* art)
{
    // std::vector<Article*> articles = tirecenter.getArticles();
    art->print();
    if (Menu::boolMenu("Are you sure you want to delete this article?"))
    {
        for (unsigned int i = 0; i < articles.size(); i++)
        {
            if (art == articles.at(i))
            {
                articles.erase(articles.begin() + i);
                delete art;
                std::cout << "Article deleted" << std::endl;
                break;
            }
        }
    }
    return;
}

void changeArticle(Article* art)
{
    // int option = Menu::displayMenu("Add article", std::vector<std::string> {"Exit", "Add tire", "Add rim"});
    art->print();
    std::cout << "== Editing " << (art->getType() == 't' ? "tire" : "rim")
        << " \"" << art->getName() << "\" ==" << std::endl;

    //article params
    std::string name, manufacturer, buffer;
    int stock, diameter;
    float price;
    //tire params
    int width, height;
    std::string speedIndex;
    char season;
    //rim params
    bool isAluminium;
    std::string color;

    std::cout << "Name: ";
    getline(std::cin, name);
    std::cout << "Manufacturer: ";
    getline(std::cin, manufacturer);
    std::cout << "Stock: ";
    getline(std::cin, buffer);
    stock = std::stoi(buffer);
    std::cout << "diameter: ";
    getline(std::cin, buffer);
    diameter = std::stoi(buffer);
    std::cout << "Price: ";
    getline(std::cin, buffer);
    price = std::stof(buffer);

    art->setName(name);
    art->setManufacturer(manufacturer);
    art->setStock(stock);
    art->setDiameter(diameter);
    art->setPrice(price);

    switch (art->getType())
    {
    case 't':
        {
            Tire* tire = dynamic_cast<Tire*>(art);

            std::cout << "Width: ";
            getline(std::cin, buffer);
            width = std::stoi(buffer);
            std::cout << "Height: ";
            getline(std::cin, buffer);
            height = std::stoi(buffer);
            std::cout << "Speed index: ";
            getline(std::cin, speedIndex);
            std::cout << "Season: ";
            getline(std::cin, buffer);
            season = buffer[0];

            tire->setWidth(width);
            tire->setHeight(height);
            tire->setSpeedIndex(speedIndex);
            tire->setSeason(season);

            break;
        }
    case 'r':
        {
            Rim* rim = dynamic_cast<Rim*>(art);

            std::cout << "Width: ";
            getline(std::cin, buffer);
            width = std::stoi(buffer);
            isAluminium = Menu::boolMenu("Is aluminium?");
            std::cout << "Color: ";
            getline(std::cin, color);

            rim->setWidth(width);
            rim->setAluminium(isAluminium);
            rim->setColor(color);

            break;
        }
    }
    art->print();
}

Customer* searchCustomer(std::vector<Customer*> &customers)
{
    unsigned int option;
    Customer* customer = nullptr;
    while (customer == nullptr)
    {
        option = Menu::displayMenu("Search customer", std::vector<std::string> {
            "Cancel search",
            "Search all by keyword"
        });


        switch (option)
        {
        case 0:
            return nullptr;
        case 1:
            customer = filterCustomer(customers);
            break;
        default:
            break;
        }
    }
    return customer;
}

Customer* filterCustomer(std::vector<Customer*> &customers)
{
    unsigned int option;
    std::vector<Customer*> found {};
    std::string needle;

    std::cout << "Keyword to search: ";
    getline(std::cin, needle);

    for (auto cust : customers)
    {
        if (Util::asciiToLower(cust->getName()).find(Util::asciiToLower(needle)) != std::string::npos)
        {
            found.push_back(cust);
        }
    }

    std::vector<std::string> options {"Cancel"};
    for (auto i : found)
    {
        options.push_back(i->getName());
    }

    option = Menu::displayMenu("Pick customer. Searched: \"" + needle + '"', options);
    if (option == 0)
    {
        return nullptr;
    }

    return found.at(option-1); // -1 for cancel option
}

void addCustomer(std::vector<Customer*> &customers)
{
    int option = Menu::displayMenu("Add customer", std::vector<std::string> {"Exit", "Add private person", "Add company"});
    Customer* cust;
    bool dupe;

    switch (option)
    {
    case 0:
        return;    
    case 1:
    {
        cust = new Customer("New customer", "Address", 'p');
        break;
    }
    case 2:
    {
        cust = new Company("New company", "Address", "VAT", 0);
        break;
    }
    }

    do
    {
        changeCustomer(cust);
        dupe = false;
        for (auto c : customers)
        {
            if (cust->getName() == c->getName())
            {
                std::cout << "A customer with this name already exists. Try again." << std::endl;
                dupe = true;
                break;
            }
        }
    } while (dupe);

    customers.push_back(cust);
}

void deleteCustomer(std::vector<Customer*> &customers, Customer *cust)
{
    cust->print();
    if (Menu::boolMenu("Are you sure you want to delete this customer?"))
    {
        for (unsigned int i = 0; i < customers.size(); i++)
        {
            if (cust == customers.at(i))
            {
                customers.erase(customers.begin() + i);
                delete cust;
                std::cout << "Customer deleted" << std::endl;
                break;
            }
        }
    }
    return;
}

void changeCustomer(Customer* cust)
{
    cust->print();
    std::cout << "== Editing " << (cust->getType() == 'c' ? "company" : "private person")
        << " \"" << cust->getName() << "\" ==" << std::endl;

    //article params
    std::string name, address, buffer;
    //company params
    std::string vat;
    int volumeDiscount;

    std::cout << "Name: ";
    getline(std::cin, name);
    std::cout << "Address: ";
    getline(std::cin, address);

    cust->setName(name);
    cust->setAddress(address);

    switch (cust->getType())
    {
    case 'c':
        {
            Company* comp = dynamic_cast<Company*>(cust);

            std::cout << "Volume discount: ";
            getline(std::cin, buffer);
            volumeDiscount = std::stoi(buffer);

            std::cout << "VAT: ";
            getline(std::cin, vat);

            comp->setVolumeDiscount(volumeDiscount);
            comp->setVAT(vat);

            break;
        }
    // case 'p':
    //     {
    //         break;
    //     }
    }
    cust->print();
}

// TODO change stock
void placeOrder(TireCenter &tirecenter)
{
    Invoice *invoice = new Invoice();
    Article* art = nullptr;
    Customer* cust = nullptr;
    int amt;
    
    do
    {
        std::cout << "Select a customer for order:" << std::endl;
        cust = searchCustomer(tirecenter.getCustomers());
    } while (cust == nullptr);
    invoice->setCustomer(cust->clone());

    do
    {
        do
        {
            std::cout << "Select an article for order:" << std::endl;
            art = searchArticle(tirecenter.getArticles());
        } while (art == nullptr);
        
        std::cout << "Amount: ";
        std::cin >> amt;
        std::cin.ignore();

        if (amt > 0 && art->getStock() >= amt)
        {
            // clone article and add to articles
            Article* entry = art->clone();
            entry->setStock(amt); //Stock var in invoice is used for amount
            art->setStock(art->getStock() - amt);
            invoice->addArticle(entry);
        }
        else
        {
            std::cout << "Can't place order, current stock is " << art->getStock() << "." << std::endl;
        }

    } while (Menu::boolMenu("Do you want to add an article to this order?"));

    invoice->calculatePrice();
    tirecenter.addInvoice(invoice);
    std::cout << "Placed order." << std::endl;
    invoice->print();

    return;
}

void checkInvoices(std::vector<Invoice*> &invoices, std::vector<Customer*> &customers)
{
    int option = Menu::displayMenu("Check invoices", {
        "Cancel",
        "Check all invoices",
        "Filter by customer"
    });

    if (option == 0) {return;}

    if(option == 1)
    {
        for (auto i : invoices)
        {
            i->print();
        }
    }
    else
    {
        Customer* cust = nullptr;
        do
        {
            cust = filterCustomer(customers);
        } while (cust == nullptr);
        
        for (auto i : invoices)
        {
            if (i->getCustomer()->getName() == cust->getName())
            {
                i->print();
            }
        }
    }
}
