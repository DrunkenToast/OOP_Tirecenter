#pragma once
#include "Article.h"
#include <string>

class Rim : Article {
    public:
    Rim();
    ~Rim();

    int getWidth();
    void setWidth(int w);

    bool getAluminium();
    void setAluminium(bool a);

    std::string getColor();
    void setColor(std::string c);

    private:
    std::string color;
    bool aluminium;
    int width;
};