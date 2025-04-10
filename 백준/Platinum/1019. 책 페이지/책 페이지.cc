#include<iostream>
using namespace std;
using ll=long long;
ll answer[10];
//ten = 10^i값
ll n, ten=1;

void calcMinus(ll num){
    while(num){
        answer[num%10] += ten;
        num /= 10;
    }
}

void solve(){
    while(n){
        //끝자리 9로 맞춰주기
        while(n%10 != 9 && n > 0){
            calcMinus(n);
            n--;
        }
        if(n == 0) break;
        n /= 10;
        //일의 자리를 9로 맞추면, 0~9개수가 매번 일정해짐
        for(int i=0;i<10;i++){
            answer[i] += (n+1) * ten;
        }


        //0이 등장하지 않는 구간 고려
        //0 ~ 19일떄
        //00, 01, 02...09는 십의 자리 0이 존재해서는 안됨
        answer[0] -= ten;
        ten *= 10;
    }
}

//0 ~ n까지 구하는 문제로 바꾸기
//마지막에 0하나 빼기
int main(){
    cin.tie() -> sync_with_stdio(0);
    cin>>n;
    solve();

    // answer[0]--;
    for(int i=0;i<10;i++){
        cout<<answer[i]<<' ';
    }
    return 0;
}