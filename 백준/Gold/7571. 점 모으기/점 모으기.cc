#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<int> y,x;
vector<pii> pos;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        pos.push_back({a,b});
        y.push_back(a);
        x.push_back(b);
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int ay = y[y.size() / 2];
    int ax = x[x.size() / 2];

    int answer = 0;
    for(auto p : pos){
        answer += abs(p.first - ay) + abs(p.second - ax);
    }

    cout<<answer;
    return 0;
}