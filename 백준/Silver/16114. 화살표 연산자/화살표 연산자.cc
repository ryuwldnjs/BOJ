#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int x,n;cin>>x>>n;
    if(n == 1){
        x *= -1;
        n = 0;
    }
    if(n % 2 == 1){
        cout<<"ERROR";
        return 0;
    }


    int answer = 0;
    for(int i=x - n/2;i>0;i -= n/2){
        answer++;
        if(answer > 10000000){
            cout<<"INFINITE";
            return 0;
        }
    }
    cout<<answer;
    return 0;
}