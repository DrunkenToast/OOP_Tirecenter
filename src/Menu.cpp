#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <stdexcept>

#include "include/Menu.h"
#include "include/TireCenter.h"

UserType Menu::loginMenu() 
{
    int option;

    std::cout << "== Login menu ==" << std::endl
        << "\t1. Owner" << std::endl
        << "\t2. Employee" << std::endl
        << "Pick an option: ";

    std::cin >> option;

    while (!(option >= 1 && option <= 2))
    {
        std::cout << "Not a valid option, try again: ";
        std::cin >> option;
    } 

    option--;
    return static_cast<UserType>(option);
}

Actions Menu::actionMenu(std::vector<Actions> options)
{
    unsigned int option;

    std::stringstream menuList;
    menuList  << "== Actions menu ==" << std::endl;
    for(unsigned int i = 0; i < options.size(); i++)
    {
        menuList << "\t" << i+1 << ". " << actionDescriptions[(int)options[i]] << std::endl;
    }
    menuList << "Pick an option: ";

    std::cout << menuList.str();

    std::cin >> option;

    while (!(option >= 1 && option <= options.size()))
    {
        std::cout << "Not a valid option, try again: ";
        std::cin >> option;
    }

    return options[option-1];
}

unsigned int Menu::displayMenu(std::string title, std::vector<std::string> options)
{
    unsigned int option;

    std::stringstream menuList;
    menuList  << "== " << title << " ==" << std::endl;
    for(unsigned int i = 0; i < options.size(); i++)
    {
        menuList << "\t" << i+1 << ". " << options.at(i) << std::endl;
    }
    menuList << "Pick an option: ";

    std::cout << menuList.str();

    std::cin >> option;

    while (!(option >= 1 && option <= options.size()))
    {
        std::cout << "Not a valid option, try again: ";
        std::cin >> option;
    }

    return option-1;
}

void Menu::editArticle(Article &art, char type)
{
    std::string name;
    std::string manufacturer;
    int stock, diameter;
    float price;

    // General article settings
    std::cout << "name: ";
    std::cin >> name;

    std::cout << "manufacturer: ";
    std::cin >> manufacturer;

    std::cout << "stock: ";
    std::cin >> stock;

    std::cout << "diameter: ";
    std::cin >> diameter;

    std::cout << "price: ";
    std::cin >> price;

    if (type == 'T')
    {
        
    }
    else if (type == 'R')
    {
        int width;
        bool isAluminium;
        char optionAl;
        std::string color;

        std::cout << "width: ";
        std::cin >> width;

        std::cout << "Is aluminium (Y/n): ";
        std::cin >> optionAl;
        if (optionAl == 'n')
        {
            isAluminium = false;
        }
        else
        {
            isAluminium = true;
        }

        std::cout << "color: ";
        std::cin >> color;


    }
    else
    {
        throw std::invalid_argument("Received something else other than T or R.");
    }
}