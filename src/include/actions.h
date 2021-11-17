#include "include/TireCenter.h"

Article* searchArticle(TireCenter &tirecenter);
void addArticle(TireCenter &tirecenter);
void deleteArticle(TireCenter &tirecenter);
void changeArticle(TireCenter &tirecenter);

Customer* searchCustomer(TireCenter &tirecenter);
void addCustomer(TireCenter &&tirecenter);
void deleteCustomer(TireCenter &tirecenter);
void changeCustomer(TireCenter &tirecenter);

void placeOrder(TireCenter &tirecenter);

void checkInvoices(TireCenter &tirecenter);