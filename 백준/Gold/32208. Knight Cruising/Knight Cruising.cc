#include <iostream>
using namespace std;

int n;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y,z; cin>>x>>y>>z;
        int even = 0;
        if(x%2 == 0) even++;
        if(y%2 == 0) even++;
        if(z%2 == 0) even++;
        
        if(even == 1 || even == 3) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}