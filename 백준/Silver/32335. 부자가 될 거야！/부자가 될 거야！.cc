#include <iostream>
using namespace std;
int n,m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        char x; cin>>x;
        int num = x - '0';
        if(num && 10-num <= m){
            m -= 10-num;
            num = 0;
        }
        if(i == n-1 && m > 0){ //마무리
            num = (num+m) % 10;
        }
        cout<<num;
    }
    return 0;
}