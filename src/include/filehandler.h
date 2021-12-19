#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "tirecenter.h"

class FileHandler 
{
    public:
    FileHandler(TireCenter &tc);
    ~FileHandler();

    void saveAll();
    void saveTireCenter();
    void saveArticles();
    void saveCustomers();
    void saveInvoices();

    private:
    /** Reads all objects from files into vectors and places it into tirecenter.
     * If the vector from before isn't cleared then this will cause a leak.
     * You're supposed to run this in the beginning of the program to load the files, not during run time.
     * 
     * I made it private and placed it in the constructor.
    */
    void loadAll();
    void loadTireCenter();
    void loadArticles();
    void loadCustomers();
    void loadInvoices();

    TireCenter &tc;

    const char pathTireCenter[256] = "data/tirecenter.dat";
    const char pathArticles[256] = "data/articles.dat";
    const char pathCustomers[256] = "data/customers.dat";
    const char pathInvoices[256] = "data/invoices.dat";

    // Returns a file for writing
    std::ofstream outputFile(const char* filePath);
    // Returns a file for reading
    std::ifstream inputFile(const char* filePath);
};