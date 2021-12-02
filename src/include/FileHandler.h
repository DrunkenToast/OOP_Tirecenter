#pragma once
#include <string>
#include <vector>
#include <fstream>

#include "TireCenter.h"

class FileHandler 
{
    public:
    FileHandler(TireCenter &tc);

    void saveArticles();
    void loadArticles();

    private:
    TireCenter &tc;
    char pathArticles[256] = "data/articles.dat";

    // Returns a file for writing
    std::ofstream outputFile(char* filePath);
    // Returns a file for reading
    std::ifstream inputFile(char* filePath);
};