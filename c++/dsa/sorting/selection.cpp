#include<iostream>
#include<vector>
#include<algorithm>  
using namespace std;

void selection_sort(vector<int>& arr) {
    int n = arr.size();
    int min_id;

    for (int i = 0; i < n - 1; i++) {
        min_id = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_id]) {                          //time complexity-O(n^2)
                min_id = j;                                      //avg,worst,best - O(n^2)
            }
        }
        if (min_id != i) {
            swap(arr[i], arr[min_id]);
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n); 

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selection_sort(arr);

    cout << "After sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
