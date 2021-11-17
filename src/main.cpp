#include <iostream>
#include "include/TireCenter.h"
#include "include/Menu.h"
#include <vector>

int login();

int main()
{
    Menu menu;

    menu.actionMenu(userPermissions[(int)menu.loginMenu()]);
}
