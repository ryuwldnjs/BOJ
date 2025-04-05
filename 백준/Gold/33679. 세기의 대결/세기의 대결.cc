#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void makeArr(vector<int>& arr){

    vector<int> res(arr.begin()+1, arr.end());
    res.push_back(arr[0]);
    arr = res;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    int x=0,y=0;
    for(int i=0;i<n;i++){
        makeArr(a); makeArr(b);
        vector<int> res_a, res_b;
        for(int j=0;j<n;j++){
            int target = lower_bound(res_a.begin(), res_a.end(), a[j]) - res_a.begin();
            if(target == res_a.size()) res_a.push_back(a[j]);
            else res_a[target] = a[j];
    
            target = lower_bound(res_b.begin(), res_b.end(), b[j]) - res_b.begin();
            if(target == res_b.size()) res_b.push_back(b[j]);
            else res_b[target] = b[j];
        }
        x = max(x, (int)res_a.size());
        y = max(y, (int)res_b.size());
    }


    if(x > y) cout<<"YJ Win!";
    else if(x < y) cout<<"HG Win!";
    else cout<<"Both Win!";
    return 0;
}