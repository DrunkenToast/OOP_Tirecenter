#pragma once
#include <string>
#include <vector>
#include <fstream>

#include "TireCenter.h"

class FileHandler 
{
    public:
    FileHandler(TireCenter &tc);

    void saveAll();
    /** Reads all objects from files into vectors and places it into tirecenter.
     * If the vector from before isn't cleared then this will cause a leak.
     * You're supposed to run this in the beginning of the program to load the files, not during run time.
    */
    void loadAll();

    private:
    void saveArticles();
    void loadArticles();

    TireCenter &tc;

    char pathArticles[256] = "data/articles.dat";
    // Returns a file for writing
    std::ofstream outputFile(char* filePath);
    // Returns a file for reading
    std::ifstream inputFile(char* filePath);
};