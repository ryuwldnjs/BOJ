#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int pos[1000000+5];
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());
    for(int i=0;i<n;i++){
        pos[sorted[i]] = i;
    }

    int answer = 1;
    for(int i=0;i<n;i++){
        answer = max(answer, i - pos[a[i]] + 1);
    }
    cout<<answer;
    return 0;
}