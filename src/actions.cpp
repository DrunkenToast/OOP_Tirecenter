#include "include/actions.h"

#include <string>

Article* searchArticle(TireCenter &tirecenter, std::string needle = "")
{
    if (needle == "")
    {
        //menu
    }

    for (auto &i : tirecenter.getArticles())
    {
        if (i.getName() == needle.)
    }
}
void addArticle(TireCenter &tirecenter)
{

}

void deleteArticle(TireCenter &tirecenter);
void changeArticle(TireCenter &tirecenter);

Customer* searchCustomer(TireCenter &tirecenter);
void addCustomer(TireCenter &tirecenter);
void deleteCustomer(TireCenter &tirecenter);
void changeCustomer(TireCenter &tirecenter);

void placeOrder(TireCenter &tirecenter);

void checkInvoices(TireCenter &tirecenter);