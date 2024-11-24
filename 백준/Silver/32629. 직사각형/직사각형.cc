#include <iostream>
#include <cmath>
using namespace std;
int t,n;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        int a = (int) sqrt(n);
        int b = (n+a-1) / a ;
        cout<<2*a+2*b<<'\n';
    }
    return 0;
}