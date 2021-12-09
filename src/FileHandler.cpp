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
}

void FileHandler::saveAll() 
{
    this->saveArticles();
}

void FileHandler::loadAll() 
{
    this->loadArticles();
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
    
    for (auto &art : tc.getArticles()) {
        // Article properties
        file << art->getName() << std ::endl
            << art->getManufacturer() << std::endl
            << art->getStock() << std::endl
            << art->getDiameter() << std::endl
            << art->getPrice() << std::endl
            << art->getType() << std::endl;

        // Article specific
        switch (art->getType())
        {
        case 't':
           {
               Tire* tire = dynamic_cast<Tire*>(art);

                file << tire->getWidth() << std ::endl
                << tire->getHeight() << std::endl
                << tire->getSpeedIndex() << std::endl
                << tire->getSeason() << std::endl;
            }
            break;
        case 'r':
            {
                Rim* rim = dynamic_cast<Rim*>(art);

                file << rim->getWidth() << std ::endl
                << rim->getAluminium() << std::endl
                << rim->getColor() << std::endl;
                break;
            }
        default:
            break;
        }
    }

    file.close();
    std::cout << "Done." << std::endl;
}

void FileHandler::loadArticles() 
{
    std::cout << "Loading articles... ";

    std::ifstream file = inputFile(this->pathArticles);
    std::vector<Article*> articles;

    std::string line;

    //article params
    std::string name, manufacturer;
    int stock, diameter;
    float price;
    char type;
    //tire params
    int width, height;
    std::string speedIndex;
    char season;
    //rim params
    bool isAluminium;
    std::string color;

    while(!file.eof())
    {
        getline(file, line);
        if (line == "") {break;} // Last line contains nothing
        name = line;
        getline(file, line);
        manufacturer = line;
        getline(file, line);
        stock = std::stoi(line);
        getline(file, line);
        diameter = std::stoi(line);
        getline(file, line);
        price = std::stof(line);
        getline(file, line);
        type = line[0];

        switch (type)
        {
        case 't':
            {
                getline(file, line);
                width = std::stoi(line);
                getline(file, line);
                height = std::stoi(line);
                getline(file, line);
                speedIndex = line;
                getline(file, line);
                season = line[0];

                articles.push_back(new Tire(name, manufacturer, stock, diameter, price,
                    width, height, speedIndex, season));
                break;
            }
        case 'r':
            {
                getline(file, line);
                width = std::stoi(line);
                getline(file, line);
                isAluminium = std::stoi(line);
                getline(file, line);
                color = line;

                articles.push_back(new Rim(name, manufacturer, stock, diameter, price,
                    width, isAluminium, color));
                break;
            }
        // default:
        //     articles.push_back(new Article(name, manufacturer, stock, diameter, price, type));
        //     break;
        }
    }

    tc.setArticles(articles);

    file.close();
    std::cout << "Done." << std::endl;
}

void FileHandler::saveInvoices() 
{
    std::cout << "Saving invoices... ";

    std::ofstream file = outputFile(this->pathInvoices);
    
    for (auto &art : tc.getInvoices()) {
        // Article properties
        file << art->getName() << std ::endl
            << art->getManufacturer() << std::endl
            << art->getStock() << std::endl
            << art->getDiameter() << std::endl
            << art->getPrice() << std::endl
            << art->getType() << std::endl;

        // Article specific
        switch (art->getType())
        {
        case 't':
           {
               Tire* tire = dynamic_cast<Tire*>(art);

                file << tire->getWidth() << std ::endl
                << tire->getHeight() << std::endl
                << tire->getSpeedIndex() << std::endl
                << tire->getSeason() << std::endl;
            }
            break;
        case 'r':
            {
                Rim* rim = dynamic_cast<Rim*>(art);

                file << rim->getWidth() << std ::endl
                << rim->getAluminium() << std::endl
                << rim->getColor() << std::endl;
                break;
            }
        default:
            break;
        }
    }

    file.close();
    std::cout << "Done." << std::endl;
}
