#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& v, int l, int mid, int h) {
    int n1 = mid - l + 1;
    int n2 = h - mid;
    vector<int> le(n1);
    vector<int> r(n2);

    for (int i = 0; i < n1; i++) {
        le[i] = v[l + i];
    }
    for (int j = 0; j < n2; j++) {
        r[j] = v[mid + j + 1];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (le[i] <= r[j]) {
            v[k++] = le[i++];
        }
        else {                                                      //Time Complexity
                                                                    // Case	Time Complexity
                                                                    // Best Case	O(n*logn)
                                                                    // Average Case	O(n*logn)
                                                                    // Worst Case	O(n*logn)
            v[k++] = r[j++];
        }
    }

    while (i < n1) {
        v[k++] = le[i++];
    }

    while (j < n2) {
        v[k++] = r[j++];
    }
}

void merge_sort(vector<int>& v, int l, int h) {
    if (l < h) {
        int mid = l + (h - l) / 2;
        merge_sort(v, l, mid);
        merge_sort(v, mid + 1, h);
        merge(v, l, mid, h);
    }
}

int main() {
    vector<int> v;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        v.push_back(element);
    }

    merge_sort(v, 0, n - 1);

    cout << "Elements after sorting: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }

    return 0;
}
