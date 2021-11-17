#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include <vector>

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
    int option;

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
