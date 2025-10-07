#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
    public:
        ItemToPurchase();
        ItemToPurchase(string name, string desc, int price, int quant);
        void SetName(string name);
        void SetPrice(int price);
        void SetQuantity(int quant);
        void SetDescription(string desc);
        void PrintItemCost();
        void PrintItemDescription();
        int numAdd();
        string GetName();
        int GetPrice();
        int GetQuantity();
        string GetDescription();
    private:
        string itemName;
        int itemPrice;
        int itemQuantity;
        string itemDescription;
};

#endif