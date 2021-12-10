#pragma once
#include <string>
#include <sstream>

class Article
{
public:
    Article() = default;
    Article(std::string name, std::string manufacturer,
        int stock, int diameter, float price /*, char type*/);
    virtual ~Article() = default;

    virtual Article* clone(void) const = 0;

    friend std::ostream& operator<<(std::ostream& output, const Article &art){
        std::string test =art.exportData() ;
        output << test;
        return output;
    };

    friend std::istream& operator>>(std::istream& input, Article &art){
        art.importData(input);
    };

    std::string getName() const;
    void setName(std::string n);

    std::string getManufacturer() const;
    void setManufacturer(std::string m);

    int getStock() const;
    void setStock(int s);

    int getDiameter() const;
    void setDiameter(int d);

    float getPrice() const;
    void setPrice(float p);

    virtual char getType() const = 0; // Abstract class
    // void setType(char t);

    virtual void print() const;

private:
    virtual std::string exportData() const = 0;
    virtual void importData(std::istream &input) = 0;
    std::string name, manufacturer;
    int stock, diameter;
    float price;
// protected:
//     char type;
};
