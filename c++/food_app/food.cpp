#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class fooditem {
public:
    int orderid;
    string name;
    float price;

    // Public constructor
    fooditem(int id, string n, float p) : orderid(id), name(n), price(p) {}
};

class foodorder {
private:
    int orderidcount;
    vector<fooditem> menu;
    vector<fooditem> order;

public:
    foodorder() : orderidcount(1) {
        menu = {
            {1, "Pizza", 12.99},
            {2, "Burger", 5.99},
            {3, "Salad", 7.99},
            {4, "Pasta", 9.99},
            {5, "Ice Cream", 3.99}
        };
    }

    void displayorder() {
        float price=0;
        cout << "Order\n";
        cout << setw(20) << "Order ID" << setw(20) << "Name" << setw(20) << "Price" << endl;
        for (auto i : order) {
            price+=i.price;
            cout << setw(20) << i.orderid << setw(20) << i.name << setw(20) << i.price << endl;
        }

        cout<<setw(20)<<"your total cost "<<price;
    }

    void displaymenu() {
        cout << "Menu\n";
        cout << setw(20) << "Name" << setw(20) << "Price" << endl;
        for (auto i : menu) {
            cout << setw(20) << i.name << setw(20) << i.price << endl;
        }
    }

    void placeorder() {
        int choice;
        cout << "Enter the number of the item you want to order (0 to finish): ";
        cin >> choice;

        while (choice != 0) {
            if (choice < 1 || choice > menu.size()) {
                cout << "Enter the correct choice.\n";
            } else {
                cout<<"you ordered "<<menu[choice-1].name<<endl;
                order.push_back({orderidcount, menu[choice - 1].name, menu[choice - 1].price});
                orderidcount++;
            }

            cout << "Enter the number of the item you want to order (0 to finish): ";
            cin >> choice;
        }
    }
};

int main() {
    foodorder foodApp;

    int option;

    do {
        cout << "\n1. Display Menu\n";
        cout << "2. Place Order\n";
        cout << "3. Display Order\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                foodApp.displaymenu();
                break;
            case 2:
                foodApp.placeorder();
                break;
            case 3:
                foodApp.displayorder();
                break;
            case 4:
                cout << "Exiting the application. Thank you!\n";
                break;
            default:
                cout << "Invalid option. Please choose a valid option.\n";
        }

    } while (option != 4);

    return 0;
}
