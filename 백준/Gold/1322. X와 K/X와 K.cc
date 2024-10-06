#include <iostream>
using namespace std;
using ll=long long;
ll x,k, answer;
int main(){
    cin>>x>>k;
    for(int i=0;i<64;i++){
        if(x & (1LL<<i)) continue; // 이미 비트 켜진1 자리는 건들면 안됨
        if(k % 2LL) answer |= 1LL<<i; // 비트 꺼진0 자리만 볼때, k를 2진수로 만들어서 넣어줌
        k >>= 1;
    }
    cout<<answer;
    return 0;
}