#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,s;cin>>n>>s;

    int answer;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        int gap = abs(s - a);
        if(i==0) answer = gap;
        answer = gcd(answer, gap);
    }
    cout<<answer;
    return 0;
}