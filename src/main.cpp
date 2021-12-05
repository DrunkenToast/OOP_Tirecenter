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

    fileHandler.loadAll();

    // std::cout << Menu::boolMenu("test");
    UserType user = Menu::loginMenu();


    // Article* art = new Tire("test", "brand", 100, 10, 20, 't', 20, 10, "FWEAFEW", 'w');

    // changeArticle(art);

    switch (Menu::actionMenu(userPermissions[(int)user]))
    {
    //Article options
    case Actions::A_ADD:
    {
        addArticle(tirecenter);
        break;
    }
    case Actions::A_DELETE:
    {
        deleteArticle(tirecenter, searchArticle(tirecenter));
        break;
    }
    case Actions::A_CHANGE:
    {
        changeArticle(searchArticle(tirecenter));
        break;
    }
    case Actions::A_SEARCH:
    {
        searchArticle(tirecenter)->print();
        break;
    }
    //Customer options
    case Actions::C_ADD:
    {
        addArticle(tirecenter);
        break;
    }
    case Actions::C_DELETE:
    {
        addArticle(tirecenter);
        break;
    }
    case Actions::C_CHANGE:
    {
        addArticle(tirecenter);
        break;
    }
    case Actions::C_SEARCH:
    {
        addArticle(tirecenter);
        break;
    }
    // Order options
    case Actions::O_PLACE:
    {
        addArticle(tirecenter);
        break;
    }

    //Invoice options
    case Actions::I_SEARCH:
    {
        addArticle(tirecenter);
        break;
    }

    default:
        break;
    }

    

    // searchArticle(tirecenter);

    return 0;
}
