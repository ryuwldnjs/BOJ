#include <iostream>
using namespace std;
using ll=long long;
ll n,m;
ll history[100000+5] = {0};
ll now;
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        ll command, val;
        cin>>command>>val;
        
        if(command == 1){ // -1 한뒤 +1 
            now = (now+val) % n;
        }
        else if(command == 2){
            now = (now - val) % n ;
        }
        if(command == 3){
            now = history[val];
        }

        now = (now + n) % n;
        history[i] = now;
    }
    cout<<history[m] + 1;
    return 0;
}