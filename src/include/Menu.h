#pragma once
#include "TireCenter.h"

#include <string>
#include <vector>

class Menu {
    public:
    // Menu();

    UserType loginMenu();
    Actions actionMenu(std::vector<Actions> options);
};