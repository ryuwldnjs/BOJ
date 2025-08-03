#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

stack<int> s;
int answer;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;

    s.push(0);

    
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;

        while(s.top() > y) s.pop();
        if(s.top() == y) continue;
        s.push(y);
        answer++;
    }

    cout<<answer;
    return 0;
}