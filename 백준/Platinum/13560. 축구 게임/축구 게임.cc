#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n,total;
vector<int> a;

bool solve(){
    if(total != n*(n-1)/2) return false;

    sort(a.begin(), a.end());
    // 승패결과를 임의 조작하면, [0,1,2,3,..,n-1] 의 결과로 나타낼수있어야한다.
    // i팀은 최대한 j팀에 승리를 넘겨줘야한다.
    // 모순이 생기면 답없음

    int j = 1;
    for(int i=0;i<n;i++){
        int diff = a[i] - i;
        if(diff < 0) return false;

        while(diff>0 && j < n){
            int needed = j - a[j];
            int value = min(needed, diff);
            diff -= value;
            a[j] += value;
            if(a[j] >= j) j++;
        }
    }
    return true;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n; a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        total += a[i];
    }
    if(solve()) cout<<1;
    else cout<<-1;
    return 0;
}