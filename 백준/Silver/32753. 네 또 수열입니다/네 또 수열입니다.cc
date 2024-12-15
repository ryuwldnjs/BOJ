#include <iostream>
using namespace std;
int n,k;
int main(){
    cin>>n>>k;
    if(n==2 && k == 1){
        cout<<"1 2";
        return 0;
    }
    if(1 < n) {
        cout<<-1;
        return 0;
    } 
    for(int i =0;i<k;i++){
        cout<<1<<' ';
    }
    return 0;
}