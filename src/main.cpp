#include <iostream>
#include "include/TireCenter.h"
#include "include/Menu.h"
#include <vector>
#include "include/actions.h"

int login();

int main()
{
    std::vector<Article*> articles;

    articles.push_back(new Tire("test", "brand", 100, 10, 20, 't', 20, 10, "FWEAFEW", 'w'));
    articles.push_back(new Tire("testers", "brand", 100, 10, 20, 't', 20, 10, "FWEAFEW", 'w'));
    articles.push_back(new Tire("juice", "brand", 100, 10, 20, 't', 20, 10, "FWEAFEW", 'w'));
    articles.push_back(new Tire("Popshow", "brand", 100, 10, 20, 't', 20, 10, "FWEAFEW", 'w'));
    articles.push_back(new Tire("orange", "brand", 100, 10, 20, 't', 20, 10, "FWEAFEW", 'w'));
    articles.push_back(new Tire("popsongs", "brand", 100, 10, 20, 't', 20, 10, "FWEAFEW", 'w'));

    TireCenter tirecenter;
    tirecenter.setArticles(articles);
    Menu::actionMenu(userPermissions[(int)Menu::loginMenu()]);

    searchArticle(tirecenter);

    return 0;
}
