#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin>>n>>m;
    vector<int> a,b;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(x < 0) a.push_back(-x);
        else b.push_back(x);
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    a.push_back(-1e9); b.push_back(-1e9);

    int answer = 0;
    for(int i=0;i<a.size()-1;i+=m) answer += 2*a[i];
    for(int i=0;i<b.size()-1;i+=m) answer += 2*b[i];

    answer -= max(a[0], b[0]);
    cout<<answer;
    return 0;
}