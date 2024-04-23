#include <iostream>
#include <stack>
#include <cctype> // Include for isdigit function

using namespace std;

int main() {
    string aa;
    cout << "Enter the postfix expression: ";
    getline(cin, aa);

    stack<int> s;

    for (int i = 0; i < aa.size(); i++) {
        if (isdigit(aa[i])) {
            s.push(aa[i] - '0');
        } else if (!isdigit(aa[i])) {
            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();
            switch (aa[i]) {
            case '+':
                s.push(val2 + val1);
                break;
            case '-':
                s.push(val2 - val1);
                break;
            case '*':
                s.push(val2 * val1);
                break;
            case '/':
                s.push(val2 / val1);
                break;
            }
        }
    }

    // Print the result
    if (!s.empty()) {
        cout << "Result: " << s.top() << endl;
    } else {
        cout << "Invalid postfix expression." << endl;
    }

    return 0;
}
