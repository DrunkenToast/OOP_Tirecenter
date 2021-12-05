#pragma once
#include "TireCenter.h"
#include <string>
#include <vector>

class Menu {
    public:
    // Menu();

    // Asks for user login
    static UserType loginMenu();
    // Lists actions given
    static Actions actionMenu(std::vector<Actions> options);
    // Basic preset menu with title and options, will return int the same as index for given options
    static unsigned int displayMenu(std::string title, std::vector<std::string> options);
    
    static bool boolMenu(std::string title);

    // static void editArticle(Article &art, char type);
};