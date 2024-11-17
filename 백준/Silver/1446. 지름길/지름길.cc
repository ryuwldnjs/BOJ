#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;
using pii=pair<int,int>;

int n,d;
vector<vector<pii>> from;
vector<int> dp;
int main(){
    cin>>n>>d;
    from.resize(10000+1);
    dp = vector<int>(10000+1, INF);
    for(int i=0;i<n;i++){
        int a,b,c; cin>>a>>b>>c;
        
        from[b].push_back({a,c});
        
    }

    dp[0] = 0;
    for(int i=1;i<=d;i++){
        dp[i] = dp[i-1] + 1;

        for(int j=0;j<from[i].size();j++){
            int a = from[i][j].first;
            int c = from[i][j].second;

            dp[i] = min(dp[i], dp[a] + c);
        }
    }
    cout<<dp[d];
    return 0;
}