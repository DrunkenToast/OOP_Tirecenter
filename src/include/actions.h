#pragma once
#include "TireCenter.h"
#include "Tire.h"
#include "Rim.h"

/*
    This h file mostly defines Use Cases, see Tire-Center-Use-Case.png
*/
Article* searchArticle(TireCenter &tirecenter);
Article* FilterKeyword(TireCenter &tc);
Tire* FilterTires(TireCenter &tc);
Rim* FilterRims(TireCenter &tc);
Article* FilterSize(TireCenter &tc);
void addArticle(TireCenter &tirecenter);
void deleteArticle(TireCenter &tirecenter, Article* art);
void changeArticle(Article* art);

Customer* searchCustomer(TireCenter &tirecenter);
Customer* FilterCustomer(TireCenter &tc);
void addCustomer(TireCenter &tirecenter);
void deleteCustomer(TireCenter &tirecenter, Customer *cust);
void changeCustomer(Customer *cust);

void placeOrder(TireCenter &tirecenter);

void checkInvoices(TireCenter &tirecenter);

//////// =======================

