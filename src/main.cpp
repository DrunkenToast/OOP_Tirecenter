#include <iostream>
#include "include/TireCenter.h"
#include "include/Menu.h"
#include <vector>
#include "include/actions.h"
#include "include/FileHandler.h"

int login();

int main()
{
    TireCenter tirecenter;
    FileHandler fileHandler(tirecenter);

    tirecenter.welcome();
    // fileHandler.loadAll();

    // std::vector<Article*> articles {
    //     new Tire("Primacy", "Michelin", 100, 16, 159.99, 215, 118, "V", 'a'),
    //     new Tire("Primacy", "Michelin", 100, 16, 159.99, 215, 118, "V", 'a'),
    //     new Rim("test", "inc", 100, 16, 50.75, 118, true, "blue")
    // };

    // tirecenter.setArticles(articles);
    // fileHandler.saveAll();

    UserType user = Menu::loginMenu();

    std::cout << std::fixed << std::cout.precision(2);

    while(true)
    {
        switch (Menu::actionMenu(userPermissions[(int)user]))
        {
        case Actions::EXIT:
        {
            tirecenter.goodbye();
            return 0;
        }
        case Actions::BACK:
        {
            user = Menu::loginMenu();
            break;
        }
        //Article options
        case Actions::A_ADD:
        {
            addArticle(tirecenter);
            break;
        }
        case Actions::A_DELETE:
        {
            Article* a;
            a = searchArticle(tirecenter);
            if (a != nullptr) {deleteArticle(tirecenter, a);}
            break;
        }
        case Actions::A_CHANGE:
        {
            Article* a;
            a = searchArticle(tirecenter);
            if (a != nullptr) {changeArticle(a);}
            break;
        }
        case Actions::A_SEARCH:
        {
            Article* a;
            a = searchArticle(tirecenter);
            if (a != nullptr) {a->print();}
            break;
        }
        //Customer options
        case Actions::C_ADD:
        {
            addCustomer(tirecenter);
            break;
        }
        case Actions::C_DELETE:
        {
            Customer* c;
            c = searchCustomer(tirecenter);
            if (c != nullptr) {deleteCustomer(tirecenter, c);}
            break;
        }
        case Actions::C_CHANGE:
        {
            Customer* c;
            c = searchCustomer(tirecenter);
            if (c != nullptr) {changeCustomer(c);}
            break;
        }
        case Actions::C_SEARCH:
        {
            Customer* c;
            c = searchCustomer(tirecenter);
            if (c != NULL) {c->print();}
            break;
        }
        // Order options
        case Actions::O_PLACE:
        {
            placeOrder(tirecenter);
            break;
        }

        //Invoice options
        case Actions::I_SEARCH:
        {
            checkInvoices(tirecenter);
            break;
        }

        default:
            break;
        }

        fileHandler.saveAll();
    }

    // searchArticle(tirecenter);

    return 0;
}
