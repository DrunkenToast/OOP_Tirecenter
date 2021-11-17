#pragma once
#include "TireCenter.h"

#include <string>
#include <vector>

class Menu {
    public:
    // Menu();

    static UserType loginMenu();
    static Actions actionMenu(std::vector<Actions> options);
};