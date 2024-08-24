#include <iostream>
using namespace std;
int n, arr[7];
int t,p,shirts;
int main(){
    cin>>n;
    for(int i=0;i<6;i++){
        cin>>arr[i];
    }
    cin>>t>>p;
    for(int i=0;i<6;i++){
        shirts += arr[i] / t + !!(arr[i] % t);
    }
    cout<<shirts<<'\n'
        <<n/p<<' '<<n%p;
    return 0;
}