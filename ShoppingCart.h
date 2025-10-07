#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <string>
#include <vector>
#include "ItemToPurchase.h"
using namespace std;

class ShoppingCart {
    public:
        ShoppingCart();
        ShoppingCart(string name, string date);

        void setCustomerName(string cname);
        void setDate(string date);

        void AddItem(ItemToPurchase item);
        void RemoveItem(string iName);
        void ModifyItem(ItemToPurchase item);
        void PrintTotal();
        void PrintDescriptions();

        string GetCustomerName();
        string GetDate();
        int GetNumItemsInCart();
        int GetCostOfCart();
        
    private:
        string customerName;
        string currentDate;
        vector<ItemToPurchase> cartItems; 
};

#endif