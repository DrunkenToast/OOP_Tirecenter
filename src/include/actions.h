#pragma once
#include "TireCenter.h"
#include "Tire.h"
#include "Rim.h"

#include <vector>

/*
    This h file mostly defines Use Cases, see Tire-Center-Use-Case.png
*/
Article* searchArticle(TireCenter &tirecenter, bool showMenu, std::string needle);

Article* FilterKeyword(TireCenter &tc);

Tire* FilterTires(TireCenter &tc);

Rim* FilterRims(TireCenter &tc);

Article* FilterSize(TireCenter &tc);

void addArticle(TireCenter &tirecenter);

void deleteArticle(TireCenter &tirecenter);

void changeArticle(TireCenter &tirecenter);

Customer* searchCustomer(TireCenter &tirecenter, bool showMenu, std::string needle);

void addCustomer(TireCenter &&tirecenter);

void deleteCustomer(TireCenter &tirecenter);

void changeCustomer(TireCenter &tirecenter);

void placeOrder(TireCenter &tirecenter);

void checkInvoices(TireCenter &tirecenter);

//////// =======================

Article* searchArticle(TireCenter &tirecenter, bool showMenu = true, std::string needle = "")
{
    unsigned int option;
    Article* article = NULL;
    if (showMenu == true)
    {
        while (article == NULL)
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
                return NULL;
            case 1:
                article = FilterKeyword(tirecenter);
            case 2:
                article = FilterTires(tirecenter);
            case 3:
                article =  FilterRims(tirecenter);
            case 4:
                article = FilterSize(tirecenter);
            default:
                break;
            }
        }
        return article;
    }

    std::cout << "DEBUG Needle: " << needle << std::endl;

    for (auto &i : tirecenter.getArticles())
    {
        if (i.getName().find(needle) != std::string::npos)
        {
            return &i;
        }
    }
    return NULL;
}

Article* FilterKeyword(TireCenter &tc)
{
    unsigned int option;
    std::vector<Article*> found {};
    std::string needle;

    std::cout << "Keyword to search: ";
    std::cin >> needle;

    for (auto &art : tc.getArticles())
    {
        if (art.getName().find(needle) != std::string::npos)
        {
            found.push_back(&art);
        }
    }

    std::cout << "found stuff";

    std::vector<std::string> options {"Cancel"};
    for (auto i : found)
    {
        options.push_back(i->getName());
    }

    option = Menu::displayMenu("Pick article. Searched: \"" + needle + '"', options);
    if (option == 0)
    {
        return NULL;
    }

    std::cout << "returning!";
    return found.at(option-1); // -1 for cancel option
}

Tire* FilterTires(TireCenter &tc)
{
    // unsigned int option;
    // option = Menu::displayMenu("Filter tire", std::vector<std::string> {
    //     "Filter by name",
    //     "Filter by width",
    //     "Filter by height",
    //     "Filter by speed index",
    //     "Filter by season"
    // });
}

Rim* FilterRims(TireCenter &tc)
{}

Article* FilterSize(TireCenter &tc)
{}

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

Customer* searchCustomer(TireCenter &tirecenter, bool showMenu = true, std::string needle = "");

void addCustomer(TireCenter &&tirecenter);

void deleteCustomer(TireCenter &tirecenter)
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

