#include<iostream>
using namespace std;

int arr[100], n = 100, top = -1;

void push(int val) {
    if (top >= n - 1) {
        cout << "Overflow" << endl;
    } else {
        top++;
        arr[top] = val;
    }
}

void pop() {
    if (top < 0) {
        cout << "Empty" << endl;
    } else {
        cout << "Popped element: " << arr[top] << endl;
        top--;
    }
}

void peek() {
    if (top < 0) {
        cout << "Empty" << endl;
    } else {
        cout << "Peek element: " << arr[top] << endl;
    }
}

void display() {
    if (top < 0) {
        cout << "Empty" << endl;
    } else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, val;

    while (1) {
        cout << "Enter your choice:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> val;
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}