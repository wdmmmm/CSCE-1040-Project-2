#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemPrice = 0;
    itemQuantity = 0;
    itemDescription = "none";
}

ItemToPurchase::ItemToPurchase(string name, string desc, int price, int quant) {
    itemName = name;
    itemPrice = price;
    itemQuantity = quant;
    itemDescription = desc;
}

void ItemToPurchase::SetName(string name) {
    itemName = name;
}

void ItemToPurchase::SetPrice(int price) {
    itemPrice =  price;
}

void ItemToPurchase::SetQuantity(int quant) {
    itemQuantity = quant;
}

void ItemToPurchase::SetDescription(string desc) {
    itemDescription = desc;
}

void ItemToPurchase::PrintItemCost() {
    cout << GetName() << " " << GetQuantity() << " @ $" << GetPrice() << " = $" << numAdd() << endl;
}

void ItemToPurchase::PrintItemDescription() {
    cout << GetName() << ": " << GetDescription() << endl;
}

int ItemToPurchase::numAdd() {
    return itemPrice * itemQuantity;
}

string ItemToPurchase::GetName() {
    return itemName;
}

string ItemToPurchase::GetDescription() {
    return itemDescription;
}

int ItemToPurchase::GetPrice() {
    return itemPrice;
}

int ItemToPurchase::GetQuantity() {
    return itemQuantity;
}