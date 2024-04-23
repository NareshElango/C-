#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void insertion_sort(vector<int>&arr){
    int n=arr.size();
    int key;
    for(int i=1;i<n;i++){
        key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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

    insertion_sort(arr);

    cout << "After sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}