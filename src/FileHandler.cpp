#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "include/FileHandler.h"
#include "include/Tire.h"
#include "include/Rim.h"

FileHandler::FileHandler(TireCenter &tc) 
    : tc(tc)
{    
    this->loadAll();

}

FileHandler::~FileHandler() 
{
    this->saveAll();
}

void FileHandler::saveAll() 
{
    std::cout << std::endl << "Saving to files: " << std::endl;
    this->saveArticles();
    std::cout << "Done saving." << std::endl << std::endl;
}

void FileHandler::loadAll() 
{
    std::cout << std::endl << "Loading from files: " << std::endl;

    this->loadArticles();

    std::cout << "Done loading." << std::endl << std::endl;
}


std::ofstream FileHandler::outputFile(char* filePath) 
{
    std::ofstream outFile{filePath, std::ios::out};
    if (!outFile)
    {
        std::cerr << "File " << filePath << " couldn't be opened for writing!";
        exit(EXIT_FAILURE);
    }
    return outFile;
}

std::ifstream FileHandler::inputFile(char* filePath) 
{
    std::ifstream inFile{filePath, std::ios::in};
    if (!inFile)
    {
        std::cerr << "File " << filePath << " couldn't be opened for reading!";
        exit(EXIT_FAILURE);
    }
    return inFile;
}

void FileHandler::saveArticles() 
{
    std::cout << "Saving articles... ";

    std::ofstream file = outputFile(this->pathArticles);

    // Export amount of articles
    file << tc.getArticles().size() << std::endl;

    // Export articles
    for (auto art : tc.getArticles()) {
        file << *art;
    }

    file.close();
    std::cout << "Done." << std::endl;
}

void FileHandler::loadArticles() 
{
    std::cout << "Loading articles... ";

    std::ifstream file = inputFile(this->pathArticles);
    int amt;
    std::vector<Article*> articles;

    std::string line;

    getline(file, line);
    // TODO if empty, empty articles
    amt = std::stoi(line);

    for (int i = 0; i < amt; i++)
    {
        Article* entry;
        getline(file, line);
        if (line[0] == 't')
        {
            entry = new Tire();
            file >> *entry;
        }
        else
        {
            entry = new Rim();
            file >> *entry;
        }
        articles.push_back(entry);
    }

    tc.setArticles(articles);

    file.close();
    std::cout << "Done." << std::endl;
}

// void FileHandler::saveInvoices() 
// {
//     std::cout << "Saving invoices... ";

//     std::ofstream file = outputFile(this->pathInvoices);
    
//     for (auto &art : tc.getInvoices()) {
//         // Article properties
//         file << art->getName() << std ::endl
//             << art->getManufacturer() << std::endl
//             << art->getStock() << std::endl
//             << art->getDiameter() << std::endl
//             << art->getPrice() << std::endl
//             << art->getType() << std::endl;

//         // Article specific
//         switch (art->getType())
//         {
//         case 't':
//            {
//                Tire* tire = dynamic_cast<Tire*>(art);

//                 file << tire->getWidth() << std ::endl
//                 << tire->getHeight() << std::endl
//                 << tire->getSpeedIndex() << std::endl
//                 << tire->getSeason() << std::endl;
//             }
//             break;
//         case 'r':
//             {
//                 Rim* rim = dynamic_cast<Rim*>(art);

//                 file << rim->getWidth() << std ::endl
//                 << rim->getAluminium() << std::endl
//                 << rim->getColor() << std::endl;
//                 break;
//             }
//         default:
//             break;
//         }
//     }

//     file.close();
//     std::cout << "Done." << std::endl;
// }
