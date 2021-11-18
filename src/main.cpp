#include <iostream>
#include "include/TireCenter.h"
#include "include/Menu.h"
#include <vector>
#include "include/actions.h"

int login();

int main()
{
    std::vector<Article> articles {
        Article("test", "brand", 100, 10, 20, 'r'),
        Article("testers", "brand", 100, 10, 20, 'r'),
        Article("juice", "brand", 100, 10, 20, 'r'),
        Article("Popshow", "brand", 100, 10, 20, 'r'),
        Article("orange", "brand", 100, 10, 20, 'r'),
        Article("popsongs", "brand", 100, 10, 20, 'r'),
    };
    TireCenter tirecenter;
    tirecenter.setArticles(articles);
    Menu::actionMenu(userPermissions[(int)Menu::loginMenu()]);
    searchArticle(tirecenter, "test");
    
}
