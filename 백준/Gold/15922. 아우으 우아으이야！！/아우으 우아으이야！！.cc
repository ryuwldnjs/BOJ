#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9+1;
vector<pii> a;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }

    sort(a.begin(), a.end());

    int answer = 0;
    int start = -INF;
    int end = -INF;
    for(int i=0;i<n;i++){
        if(end < a[i].first){
            answer += end - start;
            start = a[i].first;
        }
        end = max(end, a[i].second);
    }
    answer += end - start;

    cout<<answer;
    return 0;
}