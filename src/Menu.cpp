#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <stdexcept>

#include "include/Menu.h"
#include "include/TireCenter.h"
#include "include/util.h"

UserType Menu::loginMenu() 
{
    // int option;
    // std::string buffer;

    // std::cout << "== Login menu ==" << std::endl
    //     << "\t1. Owner" << std::endl
    //     << "\t2. Employee" << std::endl
    //     << "Pick an option: ";

    // getline(std::cin, buffer);
    // option = std::stoi(buffer);

    // while (!(option >= 1 && option <= 2))
    // {
    //     std::cout << "Not a valid option, try again: ";
    //     std::cin >> option;
    // } 

    // option--;
    return static_cast<UserType>(displayMenu("Login menu", {"Owner", "Employee"}));
}

Actions Menu::actionMenu(std::vector<Actions> options)
{
    unsigned int option;
    std::string buffer;

    std::stringstream menuList;
    menuList  << "== Actions menu ==" << std::endl;
    for(unsigned int i = 0; i < options.size(); i++)
    {
        menuList << "\t" << i+1 << ". " << actionDescriptions[(int)options[i]] << std::endl;
    }
    menuList << "Pick an option: ";

    std::cout << menuList.str();

    getline(std::cin, buffer);
    option = std::stoi(buffer);

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
    std::string buffer;

    std::stringstream menuList;
    menuList  << "== " << title << " ==" << std::endl;
    for(unsigned int i = 0; i < options.size(); i++)
    {
        menuList << "\t" << i+1 << ". " << options.at(i) << std::endl;
    }
    menuList << "Pick an option: ";

    std::cout << menuList.str();
    // std::cin >> option;

    getline(std::cin, buffer);
    option = std::stoi(buffer);

    while (!(option >= 1 && option <= options.size()))
    {
        std::cout << "Not a valid option, try again: ";
        std::cin >> option;
    }

    return (unsigned int)option-1;
}

bool Menu::boolMenu(std::string title)
{
    std::string buffer;
    bool option;
    bool picked = false;

    do
    {
        std::cout << title << " (Yes/No): " ;
        getline(std::cin, buffer);
        buffer = Util::asciiToLower(buffer);

        if (
            buffer == "yes" ||
            buffer == "y" ||
            buffer == "1"
        )
        {
            picked = true;
            option = true;
        }
        else if (
            buffer == "no" ||
            buffer == "n" ||
            buffer == "0"
        )
        {
            picked = true;
            option = false;
        }
    } while (!picked);

    return option;
}