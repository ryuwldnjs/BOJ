#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    deque<int> answer;
    for(int i=n;i>=1;i--){
        if(i%2) answer.push_back(i);
        else answer.push_front(i);
    }

    for(int i: answer) cout<<i<<' ';
    return 0;
}