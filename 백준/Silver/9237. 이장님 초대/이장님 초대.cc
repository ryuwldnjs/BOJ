#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,MAX;
vector<int> arr;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end(), greater<int>());
    for(int i=0;i<n;i++){
        MAX = max(MAX, arr[i] + i+1);
    }
    cout<<MAX+1;
    return 0;
}