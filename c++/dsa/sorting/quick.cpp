#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&v,int low,int high){
    int pivot=v[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(v[j]<=pivot){
        i++;
        swap(v[i],v[j]);
         }                                                            //Time Complexity
        //                                                                 Case	Time Complexity
        //                                                                 Best Case	O(n*logn)
        //                                                                 Average Case	O(n*logn)
        //                                                                 Worst Case	O(n2)
    }
    swap(v[i+1],v[high]);
    return i+1;
}

void quick_sort(vector<int>&v,int low,int high){
    if(low<high){
        int pivotidx=partition(v,low,high);
        quick_sort(v,low,pivotidx-1);
        quick_sort(v,pivotidx+1,high);
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

    quick_sort(v, 0, n - 1);

    cout << "Elements after sorting: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }

    return 0;
}