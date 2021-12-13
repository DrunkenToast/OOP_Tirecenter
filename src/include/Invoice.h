#pragma once
#include "Article.h"
#include "Customer.h"
#include <vector>

class Invoice
{
public:
    Invoice();
    ~Invoice();

    friend std::ostream& operator<<(std::ostream& output, const Invoice &inv){
        return (output << inv.exportData());
    };

    friend std::istream& operator>>(std::istream& input, Invoice &inv){
        inv.importData(input);
        return input;
    };

    std::vector<Article*> getArticles() const;
    void setArticles(std::vector<Article*> a);
    void addArticle(Article* a);

    Customer* getCustomer() const;
    void setCustomer(Customer* c);

    // Returns total price - discount
    float getPrice() const;
    void setPrice(float p);

    int getDiscount() const;
    void setDiscount(int d);

    void print() const;
private:
    virtual std::string exportData() const;
    virtual void importData(std::istream &input);
    std::vector<Article*> articles;
    Customer* customer;
    float price = 0;
    int discount = 10;

    // Calculates the discount
    float calculateDiscount() const;
    // Calculates total price
    float calculatePrice() const;
};
