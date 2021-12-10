#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "TireCenter.h"

class FileHandler 
{
    public:
    FileHandler(TireCenter &tc);
    ~FileHandler();

    void saveAll();

    private:
    /** Reads all objects from files into vectors and places it into tirecenter.
     * If the vector from before isn't cleared then this will cause a leak.
     * You're supposed to run this in the beginning of the program to load the files, not during run time.
     * 
     * I made it private and placed it in the constructor.
    */
    void loadAll();

    void saveArticles();
    void loadArticles();
    void inputArticle(std::ifstream, Article*);
    std::stringstream outputArticle(std::ofstream);

    void saveCustomers();
    void loadCustomers();

    void saveInvoices();
    void loadInvoices();


    TireCenter &tc;

    char pathArticles[256] = "data/articles.dat";
    char pathInvoices[256] = "data/invoices.dat";
    // Returns a file for writing
    std::ofstream outputFile(char* filePath);
    // Returns a file for reading
    std::ifstream inputFile(char* filePath);
};