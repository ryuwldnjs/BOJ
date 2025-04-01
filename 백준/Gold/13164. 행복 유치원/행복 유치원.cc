#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,k; cin>>n>>k;
    vector<int> arr(n), diff(n-1);
    for(int &i: arr) cin>>i;

    for(int i=0;i<n-1;i++){
        diff[i] = arr[i+1] - arr[i];
    }

    sort(diff.begin(), diff.end(), greater<int>());

    int answer = arr[n-1] - arr[0];
    for(int i=0; i<k-1;i++){
        answer -= diff[i];
    }
    cout<<answer;
    return 0;
}