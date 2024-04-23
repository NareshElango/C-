#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int>&arr){
    int n = arr.size();
    bool swapped;
    for(int i=0;i<n-1;i++){
        swapped=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;                       //time complexity -O(n^2)
            }                                       //best-O(n)
        }                                           //avg,worst -O(n^2)
        if(swapped==false)
        break;
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

    bubble_sort(arr);

    cout << "After sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}