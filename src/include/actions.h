#pragma once
#include "TireCenter.h"
#include "Tire.h"
#include "Rim.h"

#include <vector>

/*
    This h file mostly defines Use Cases, see Tire-Center-Use-Case.png
*/

Article* searchArticle(TireCenter &tirecenter, bool showMenu = true, std::string needle = "")
{
    int option = -1;
    if (showMenu == true)
    {
        option = Menu::displayMenu("Search article", std::vector<std::string> {
            "Search all by keyword",
            "Filter Tires",
            "Filter Rims",
            "Filter Size"
        });

    }
    switch (option)
    {
    case 0:
        
        break;
    
    default:
        break;
    }

    std::cout << "Needle: " << needle << std::endl;

    for (auto &i : tirecenter.getArticles())
    {
        if (i.getName().find(needle) != std::string::npos)
        {
            i.showArticle();
        }
    }
}

void addArticle(TireCenter &tirecenter)
{
    int option = Menu::displayMenu("Add article", std::vector<std::string> {"Exit", "Add tire", "Add rim"});

    if (option == 0) {return;}

    // General article options
    
}

void deleteArticle(TireCenter &tirecenter)
{
    std::vector<Article> articles = tirecenter.getArticles();
    std::vector<std::string> options;
    // List all article options
    for (auto &i : articles)
    {
        options.push_back(i.getName());
    }

    int option = Menu::displayMenu("Choose article to delete", options);

    articles.erase(articles.begin() + option);
    std::cout << "Article removed";

    return;
}

void changeArticle(TireCenter &tirecenter);

Customer* searchCustomer(TireCenter &tirecenter, bool showMenu = true, std::string needle = "")
{
    // int option = -1;
    // if (showMenu = true)
    // {
    //     std::cout << "Enter customer/company name to search:";

    // }
    // switch (option)
    // {
    // case 0:
        
    //     break;
    
    // default:
    //     break;
    // }

    // std::cout << "Needle: " << needle << std::endl;

    // for (auto &i : tirecenter.getArticles())
    // {
    //     if (i.getName().find(needle) != std::string::npos)
    //     {
    //         i.showArticle();
    //     }
    // }
}
void addCustomer(TireCenter &&tirecenter);
void deleteCustomer(TireCenter &tirecenter)
{

}

void changeCustomer(TireCenter &tirecenter);

void placeOrder(TireCenter &tirecenter);

void checkInvoices(TireCenter &tirecenter)
{
    std::vector<Invoice> invoices = tirecenter.getInvoices();
    for (auto&i : invoices)
    {
        i.showInvoice();
    }
}

