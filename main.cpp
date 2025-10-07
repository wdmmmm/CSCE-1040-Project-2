#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu() {
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl << endl;
   
}

void ExecuteMenu(char option, ShoppingCart& cart) {
    string n, desc;
    int price, quant;
    ItemToPurchase item, rItem;
    
    do {


        
        cout << "Choose an option:" << endl;
        cin >> option;
        
        

        switch (option) {
            case 'a':
                cin.ignore();
                
                cout << endl << "ADD ITEM TO CART" << endl << "Enter the item name:" << endl;
                getline(cin, n);
                item.SetName(n);

                cout << "Enter the item description:" << endl;
                getline(cin, desc);
                item.SetDescription(desc);

                cout << "Enter the item price:" << endl;
                cin >> price;
                item.SetPrice(price);

                cout << "Enter the item quantity:" << endl;
                cin >> quant;
                item.SetQuantity(quant);

                cart.AddItem(item);
                cout << endl;
                PrintMenu();

                break;

            case 'd':
                cin.ignore();
                
                cout << endl << "REMOVE ITEM FROM CART" << endl << "Enter name of item to remove:" << endl;
                getline(cin, n);
                cart.RemoveItem(n);
                cout << endl;
                PrintMenu();
                
                break;
            case 'c':
                cin.ignore();
                
                cout << endl << "CHANGE ITEM QUANTITY" << endl << "Enter the item name:" << endl;
                getline(cin, n);
                cout << "Enter the new quantity:" << endl;
                cin >> quant;

                rItem.SetName(n);
                rItem.SetQuantity(quant);

                cart.ModifyItem(rItem);
                cout << endl;
                PrintMenu();

                break;
            case 'i':
                cin.ignore();
                
                cout << endl << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
                cart.PrintDescriptions();
                cout << endl;
                PrintMenu();

                break;
            case 'o':
                cin.ignore();
                
                cout << "OUTPUT SHOPPING CART" << endl;
                cart.PrintTotal();
                cout << endl;
                PrintMenu();
                break;
            case 'q':
                return;
                break;
            default:
                break;
        }
    }
    while (option != 'q');
    
   
}

int main() {
    ShoppingCart cart;
    
    string name, date;
    char option = 'x';

    cout << "Enter customer's name:" << endl;
    getline(cin, name);
    cart.setCustomerName(name);

    cout << "Enter today's date:" << endl;
    getline(cin, date);
    cart.setDate(date);

    cout << endl << "Customer name: " << cart.GetCustomerName() << endl;
    cout << "Today's date: " << cart.GetDate() << endl << endl;
   
    PrintMenu();
    ExecuteMenu(option, cart);
    //ExecuteMenu('o', cart);

   return 0;
}