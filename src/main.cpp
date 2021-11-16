#include <iostream>
#include "include/TireCenter.h"
#include "include/Menu.h"
#include <vector>

int login();

int main()
{
    Menu menu;

    std::cout << (int)menu.loginMenu();

    menu.actionMenu(userPermissions[1]);


    return 0;
}

// int login()
// {
//     int option;

//     std::cout << "== Login menu ==" << std::endl
//         << "\t1. Owner" << std::endl
//         << "\t2. Employee" << std::endl
//         << "Pick an option: ";

//     std::cin >> option;

//     while (!(option >= 1 && option <= 2))
//     {
//         std::cout << "Not a valid option, try again: ";
//         std::cin >> option;
//     } 

//     return option;
// }