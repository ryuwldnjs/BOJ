#include <iostream>
#include <algorithm>
using namespace std;
int n,l,r, arr[100000+5];
int main(){
    cin>>n>>l>>r;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr+l-1, arr+r);
    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1]){
            cout<<0;
            return 0;
        }
    }
    cout<<1;
    return 0;
}