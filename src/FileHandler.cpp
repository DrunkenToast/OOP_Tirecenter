#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "include/FileHandler.h"
#include "include/Tire.h"
#include "include/Rim.h"

FileHandler::FileHandler(TireCenter &tc) 
    : tc(tc)
{    
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
    while(!file.eof())
    {
        Article* art;
        getline(file, line);
        art->setName(line); //Error here with casting /shrug
        getline(file, line);
        art->setManufacturer(line);
        getline(file, line);
        art->setStock(std::stoi(line));
        getline(file, line);
        art->setDiameter(std::stoi(line));
        getline(file, line);
        art->setPrice(std::stof(line));
        getline(file, line);
        art->setType(line[0]);

        switch (art->getType())
        {
        case 't':
            {
                Tire* tire = dynamic_cast<Tire*>(art);

                getline(file, line);
                tire->setWidth(std::stoi(line));
                getline(file, line);
                tire->setHeight(std::stoi(line));
                getline(file, line);
                tire->setSpeedIndex(line);
                getline(file, line);
                tire->setSeason(line[0]);
                break;
            }
        case 'r':
            {
                Rim* rim = dynamic_cast<Rim*>(art);
                
                getline(file, line);
                rim->setWidth(std::stoi(line));
                getline(file, line);
                rim->setAluminium(std::stoi(line));
                getline(file, line);
                rim->setColor(line);
                break;
            }
        default:
            break;
        }
        articles.push_back(art);
    }

    tc.setArticles(articles);

    file.close();
    std::cout << "Done." << std::endl;
}