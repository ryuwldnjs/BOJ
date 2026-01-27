#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll coefficient[11]; //알파벳별 계수
ll n;
bool banned[11]; //첫자리 0금지인 알파벳들 모음

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(ll i=0;i<n;i++){
        string num;cin>>num;
        ll tens = 1;
        for(ll j=num.size()-1; j>=0; j--){
            ll idx = num[j] - 'A';
            coefficient[idx] += tens;
            tens *= 10LL;
        }

        banned[num[0] - 'A'] = true; // 얘는 0 금지
    }

    ll answer = 0;
    vector<ll> val = {0,1,2,3,4,5,6,7,8,9};
    do{
        ll ret = 0;
        bool isRet = true;
        for(int i=0;i<10;i++){
            if(banned[i] && val[i] == 0) isRet = false; 
            ret += coefficient[i] * val[i];
        }
        if(isRet) answer = max(answer, ret);
    }while(next_permutation(val.begin(), val.end()));
    
    cout<<answer;
    return 0;
}