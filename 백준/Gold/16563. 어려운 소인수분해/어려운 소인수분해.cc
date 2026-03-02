#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define MAX 5000000
vector<int> spf;
void sieve(){
    spf.resize(MAX+5);

    for(int i=2;i<=MAX;i++){
        if(spf[i] != 0) continue;

        for(int j=i;j<=MAX;j+=i){
            if(spf[j] == 0) spf[j] = i;
        }
    }
}


void printAnswer(int num){
    vector<int> answer;
    while(num > 1){
        answer.push_back(spf[num]);
        num /= spf[num];
    }
    for(int i:answer) cout<<i<<' ';
    cout<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    sieve();

    int n;cin>>n;
    for(int i=0;i<n;i++){
        int num;cin>>num;
        printAnswer(num);
    }
    return 0;
}