#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        v.push_back(e);
    }

    int longest = 0, small = INT_MAX, count = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            count++;
        } else {
            if (count > 0) {
                small = min(small, count);
                longest = max(longest, count);
                count = 0;
            }
        }
    }

    if (count > 0) {
        small = min(small, count);
        longest = max(longest, count);
    }

    cout << longest << " " << (small == INT_MAX ? 0 : small) << " " << abs(longest - small);
    return 0;
}
