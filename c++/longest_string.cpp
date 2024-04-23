#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    vector<string> v;
    int currlen = 0, maxlen = 0;
    string currstr = "", maxstr = "";

    for (char c : s) {
        if (c != ' ') {
            currlen++;
            currstr += c;
        } else {
            if (currlen >= maxlen) {
                maxlen = currlen;
                maxstr = currstr;
                v.push_back(maxstr);
            }
            currlen = 0;
            currstr = "";
        }
    }

    if (currlen >= maxlen) {
        maxlen = currlen;
        maxstr = currstr;
    }

    // if (!maxstr.empty()) {
    //     v.push_back(maxstr);
    // }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}
