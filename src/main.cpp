#include <iostream>
#include "include/TireCenter.h"
#include "include/Menu.h"
#include <vector>
#include "include/actions.h"
#include "include/FileHandler.h"

int login();

int main()
{
    std::vector<Article*> articles;

    articles.push_back(new Tire("test", "brand", 100, 10, 20, 't', 20, 10, "FWEAFEW", 'w'));
    articles.push_back(new Tire("testers", "brand", 100, 10, 20, 't', 20, 10, "FWEAFEW", 'w'));
    articles.push_back(new Rim("juice", "brand", 100, 10, 20, 'r', 20, true, "blue"));
    articles.push_back(new Tire("Popshow", "brand", 100, 10, 20, 't', 20, 10, "FWEAFEW", 'w'));
    articles.push_back(new Rim("orange", "brand", 100, 10, 20, 'r', 20, 10, "orange"));
    articles.push_back(new Tire("popsongs", "brand", 100, 10, 20, 't', 20, 10, "FWEAFEW", 'w'));

    TireCenter tirecenter;
    FileHandler fileHandler(tirecenter);

    tirecenter.setArticles(articles);

    fileHandler.loadArticles();

    // Menu::actionMenu(userPermissions[(int)Menu::loginMenu()]);

    // searchArticle(tirecenter);

    return 0;
}
