#pragma once
#include <string>
#include <vector>
#include "Article.h"
#include "Customer.h"
#include "Invoice.h"
#include <map>

enum class Actions {
    EXIT,
    BACK,

    A_ADD,
    A_DELETE,
    A_CHANGE,
    A_SEARCH,

    C_ADD,
    C_DELETE,
    C_CHANGE,
    C_SEARCH,

    O_PLACE,

    I_SEARCH,

    LENGTH // Other way to check length of enum
};

// Move to cpp
// const std::map <Actions, std::string> actionDescription {
//     {Actions::A_ADD, "Add article"},
//     {Actions::A_DELETE, "Delete article"},
//     {Actions::A_CHANGE, "Change article"},
//     {Actions::A_SEARCH, "Search articles"},

//     {Actions::C_ADD, "Add customer"},
//     {Actions::C_DELETE, "Delete customer"},
//     {Actions::C_CHANGE, "Change customer"},
//     {Actions::C_SEARCH, "Search customers"},

//     {Actions::O_PLACE, "Place Order"},

//     {Actions::I_SEARCH, "Search invoices"},
// };

const std::string actionDescriptions[] {
    "Exit program", "Back to login",
    "Add article", "Delete article", "Change article", "Search articles",
    "Add customer", "Delete customer", "Change customer", "Search customers",
    "Place Order",
    "Search invoices",
};

enum class UserType {
    OWNER,
    EMPLOYEE
};

const std::vector<Actions> userPermissions[] {

        {
            Actions::EXIT, Actions::BACK,
            Actions::A_ADD, Actions::A_DELETE, Actions::A_CHANGE, Actions::A_SEARCH,
            Actions::C_ADD, Actions::C_DELETE, Actions::C_CHANGE, Actions::C_SEARCH, 
            Actions::O_PLACE, Actions::I_SEARCH,
        },

        {
            Actions::EXIT, Actions::BACK,
            Actions::A_CHANGE, Actions::A_SEARCH,
            Actions::C_ADD, Actions::C_CHANGE, Actions::C_SEARCH, 
            Actions::O_PLACE, Actions::I_SEARCH,
        }
};

static_assert(sizeof(actionDescriptions)/sizeof(actionDescriptions[0]) == (unsigned int)Actions::LENGTH,
    "Amount of actions not equal to descriptions");

class TireCenter
{
public:
    TireCenter();
    TireCenter(std::string name, std::string address);
    ~TireCenter();

    friend std::ostream& operator<<(std::ostream& output, const TireCenter &cust){
        return (output << cust.exportData());
    };

    friend std::istream& operator>>(std::istream& input, TireCenter &cust){
        cust.importData(input);
        return input;
    };

    std::string getName() const;
    void setName(std::string n);

    std::string getAddress() const;
    void setAddress(std::string a);

    std::vector<Article*>& getArticles();
    void setArticles(std::vector<Article*> a);
    void addArticle(Article* a);

    std::vector<Customer*>& getCustomers();
    void setCustomers(std::vector<Customer*> c);
    void addCustomer(Customer* c);

    std::vector<Invoice*>& getInvoices();
    void setInvoices(std::vector<Invoice*> i);
    void addInvoice(Invoice* i);

    void welcome() const;
    void goodbye() const;
private:
    virtual std::string exportData() const;
    virtual void importData(std::istream &input);
    std::string name, address;
    std::vector<Article*> articles;
    std::vector<Customer*> customers;
    std::vector<Invoice*> invoices;
};
