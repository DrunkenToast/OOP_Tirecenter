#include "TireCenter.h"

/*
    This h file mostly defines Use Cases, see Tire-Center-Use-Case.png
*/

Article* searchArticle(TireCenter &tirecenter, bool showMenu = true, std::string needle = "")
{
    int option = -1;
    if (showMenu = true)
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

void addArticle(TireCenter &tirecenter);
void deleteArticle(TireCenter &tirecenter);
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

void checkInvoices(TireCenter &tirecenter);

