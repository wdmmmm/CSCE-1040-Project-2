#include <iostream>
#include "ShoppingCart.h"

using namespace std;
unsigned int i = 0;



ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string name, string date) {
    customerName = name;
    currentDate = date;
}

void ShoppingCart::setCustomerName(string cname) {
    customerName = cname;
}

void ShoppingCart::setDate(string date) {
    currentDate = date;
}

string ShoppingCart::GetCustomerName() {
    return customerName;
}

string ShoppingCart::GetDate() {
    return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
    cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string iName) {
    for (i = 0; i < cartItems.size(); i++) {
        if (cartItems.at(i).GetName() == iName) {
            cartItems.erase(cartItems.begin() + i);
            return;
        }
    }
    cout << "Item not found in cart. Nothing removed." << endl;
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
    for (i = 0; i < cartItems.size(); i++) {
        if (cartItems.at(i).GetName() == item.GetName()) {
            if ( (cartItems.at(i).GetDescription() != "none") && (cartItems.at(i).GetQuantity() != 0) && (cartItems.at(i).GetPrice() != 0) ) {
                cartItems.at(i).SetQuantity(item.GetQuantity());
                return;
            }
        }
    }
    cout << "Item not found in cart. Nothing modified." << endl;
}

int ShoppingCart::GetNumItemsInCart() {
    int sum = 0;
    
    for (i = 0; i < cartItems.size(); i++) {
        sum = sum + cartItems.at(i).GetQuantity();
    }
    return sum;
}

int ShoppingCart::GetCostOfCart() {
    int sum = 0;
    
    for (i = 0; i < cartItems.size(); i++) {
        sum = sum + (cartItems.at(i).GetPrice() * cartItems.at(i).GetQuantity());
    }
    return sum;
}

void ShoppingCart::PrintTotal() {
    cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl;
    int sum = 0;
    
    for (i = 0; i < cartItems.size(); i++) {
        sum = sum + cartItems.at(i).GetQuantity();
    }

    cout << "Number of Items: " << sum << endl << endl;

    if (cartItems.empty()) {
        cout << "SHOPPING CART IS EMPTY" << endl;
        
    }
    else {
        for (i = 0; i < cartItems.size(); i++) {
            cartItems.at(i).PrintItemCost();
        }
    }
    cout << endl << "Total: $" << GetCostOfCart() << endl;

}

void ShoppingCart::PrintDescriptions() {
    if (cartItems.empty()) {
        cout << "SHOPPING CART IS EMPTY" << endl;
        return;
    }

    cout << GetCustomerName() << "'s Shopping Cart - " << GetDate() << endl << endl;
    cout << "Item Descriptions" << endl;

    for (i = 0; i < cartItems.size(); i++) {
        cartItems.at(i).PrintItemDescription();
    }


}