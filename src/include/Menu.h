#pragma once
#include "TireCenter.h"

#include <string>
#include <vector>

class Menu {
    public:
    // Menu();

    static UserType loginMenu();
    static Actions actionMenu(std::vector<Actions> options);
    // Basic preset menu with title and options, will return int the same as index for given options
    static int displayMenu(std::string title, std::vector<std::string> options);
    
    
    static void editArticle(Article &art, char type);
};