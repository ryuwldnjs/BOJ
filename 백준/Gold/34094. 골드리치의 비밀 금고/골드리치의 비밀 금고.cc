#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    if(arr.front() == 0 && arr.back() == 0){
        cout<<0<<'\n';
        for(int i: arr) cout<<i<<' ';
        
        return 0;
    }
    if(arr.front() > 0){
        cout<<1<<'\n';
        for(int i: arr) cout<<i<<' ';

        return 0;
    }
    int needed = 0;
    for(int i=0;i<n;i++){
        if(needed == arr[i]){
            needed++;
        }
    }


    cout<<needed + 1<<'\n';
    for(int i: arr) cout<<i<<' ';
    return 0;
}