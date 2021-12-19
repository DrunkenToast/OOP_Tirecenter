/*
    This h file mostly defines Use Cases, see Tire-Center-Use-Case.png
*/
#pragma once
#include "TireCenter.h"
#include "Tire.h"
#include "Rim.h"


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
        { // Owner
            Actions::EXIT, Actions::BACK,
            Actions::A_ADD, Actions::A_DELETE, Actions::A_CHANGE, Actions::A_SEARCH,
            Actions::C_ADD, Actions::C_DELETE, Actions::C_CHANGE, Actions::C_SEARCH, 
            Actions::O_PLACE, Actions::I_SEARCH,
        },
        { // Employee
            Actions::EXIT, Actions::BACK,
            Actions::A_CHANGE, Actions::A_SEARCH,
            Actions::C_ADD, Actions::C_CHANGE, Actions::C_SEARCH, 
            Actions::O_PLACE, Actions::I_SEARCH,
        }
};

static_assert(sizeof(actionDescriptions)/sizeof(actionDescriptions[0]) == (unsigned int)Actions::LENGTH,
    "Amount of actions not equal to descriptions");

// Searches for articles and returns article pointer, will return nullptr when nothing selected
Article* searchArticle(std::vector<Article*> &articles);
Article* filterKeyword(std::vector<Article*> &articles);
Tire* filterTires(std::vector<Article*> &articles);
Rim* filterRims(std::vector<Article*> &articles);
Article* filterSize(std::vector<Article*> &articles);
void addArticle(std::vector<Article*> &articles);
void deleteArticle(std::vector<Article*> &articles, Article* art);
void changeArticle(Article* art);

Customer* searchCustomer(std::vector<Customer*> &customers);
Customer* filterCustomer(std::vector<Customer*> &customers);
void addCustomer(std::vector<Customer*> &customers);
void deleteCustomer(std::vector<Customer*> &customers, Customer *cust);
void changeCustomer(Customer *cust);

void placeOrder(TireCenter &tirecenter);

void checkInvoices(std::vector<Invoice*> &invoices, std::vector<Customer*> &customers);
