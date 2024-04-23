#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int k;
    cin >> k;
    int i = 0, j = n - 1;
    vector<int> ans;
    sort(v.begin(), v.end());
    while(i < j) {
        int sum = v[i] + v[j];
        if(sum == k){
            ans.push_back(sum);
            i++;
            j--;
        }
        else if(sum < k){
            ans.push_back(sum);
            i++;
        }
        else {
            j--;
        }
    }
    
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}
