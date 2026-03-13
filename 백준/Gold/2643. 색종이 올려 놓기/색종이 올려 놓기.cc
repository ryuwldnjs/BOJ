#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int dp[105]; // i번을 마지막으로 뒀을때의 최댓값
vector<pii> paper;

//paper[a]가 paper[b]를 완전 덮는가
bool isInner(int a, int b){
    return paper[a].first >= paper[b].first && paper[a].second >= paper[b].second;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    paper.resize(n);

    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        if(a < b) swap(a,b);
        paper[i] = {a,b};
    }

    sort(paper.begin(), paper.end());
    
    int answer = 0;
    for(int i=0;i<n;i++){
        dp[i] = 1; // 기본 한장은 보장됨
        for(int j=0;j<i;j++){
            if(isInner(i, j)) dp[i] = max(dp[i], dp[j] + 1);
        }
        answer = max(answer, dp[i]);
    }
    
    cout<<answer;
    
    return 0;
}