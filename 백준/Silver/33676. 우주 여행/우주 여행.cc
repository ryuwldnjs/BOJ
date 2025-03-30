#include <iostream>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m,k,l;
    cin>>n>>m>>k>>l;
    for(int i=0;i<k;i++){
        int a,b; cin>>a>>b;
    }
    if(l < n+m-2 || (l -(n+m-2))%2==1 ) cout<<-1;
    else{
        for(int i=0;i<n-1;i++) cout<<"D";
        for(int i=0;i<m-1;i++) cout<<"R";
        int remain = l - (n+m-2);
        for(int i=0;i<remain/2;i++) cout<<"LR";
    }

    return 0;
}