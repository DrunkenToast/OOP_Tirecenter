#include "include/util.h"
#include <iostream>
#include <string>
#include <algorithm>

// https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case
std::string Util::asciiToLower(std::string str) 
{
    std::transform(str.begin(), str.end(), str.begin(),
    [](unsigned char c){ return std::tolower(c); } // Lamba which executes lower on each char
    );

    return str;
}
