#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
#define START_ONE 0
#define START_TWO 1
using namespace std;
int n,w;

vector<pair<int,int>> arr;
vector<vector<int>> dp;
vector<vector<pair<int,int>>> trace;
// dp[i][j]: 1번경찰=i, 2번경찰=j위치일때 최소거리
// dp[i][j] =  dp[i-1][j]+dist(i-1,i), dp[i-1][j-1].., dp[0][j-1]
// dp[i][j] = dp[i][j-1]

int dist(int a, int b){
    return abs(arr[a].first - arr[b].first) + abs(arr[a].second - arr[b].second);
}
int main(){
    cin>>n>>w;
    arr.push_back({1,1}); //START_ONE
    arr.push_back({n,n}); // START_TWO
    dp.resize(w+2,vector<int>(w+2, 1e9));
    trace.resize(w+2,vector<pair<int,int>>(w+2));
    for(int i=0;i<w;i++){
        int a,b; cin>>a>>b;
        arr.push_back({a,b});
    }

    dp[START_ONE][START_TWO] = 0;
    dp[2][START_TWO] = dist(START_ONE, 2);
    dp[START_ONE][2] = dist(START_TWO, 2);
    trace[START_ONE][2] = {START_ONE, START_TWO};
    trace[2][START_TWO] = {START_ONE, START_TWO};

    for(int i=3;i<w+2;i++){

        for(int j=1;j<i;j++){
            //2번차가 i-1, 1번차가 i번째 사건 맡았을때
            int first_idx = j;
            if(j==1) first_idx = START_ONE;
            // dp[i][i-1] = min(dp[i][i-1], dp[first_idx][i-1] + dist(first_idx,i));
            if(dp[i][i-1] > dp[first_idx][i-1] + dist(first_idx,i)){
                dp[i][i-1] = dp[first_idx][i-1] + dist(first_idx,i);
                trace[i][i-1] = {first_idx, i-1};
            }

            //2번차가 i-1, i번째 사건 맡았을때
            // dp[first_idx][i] = min(dp[first_idx][i], dp[first_idx][i-1] + dist(i-1, i));
            if(dp[first_idx][i] > dp[first_idx][i-1] + dist(i-1, i)){
                dp[first_idx][i] = dp[first_idx][i-1] + dist(i-1, i);
                trace[first_idx][i] = {first_idx, i-1};
            }
            //1번차가 i-1, i번째 사건 맡았을때
            // dp[i][j] = min(dp[i][j], dp[i-1][j] + dist(i-1, i));
            if(dp[i][j] > dp[i-1][j] + dist(i-1, i)){
                dp[i][j] = dp[i-1][j] + dist(i-1, i);
                trace[i][j] = {i-1, j};
            }
            
            //1번차가 i-1, 2번차가 i번째 사건 맡았을때
            // dp[i-1][i] = min(dp[i-1][i], dp[i-1][j] + dist(j,i));
            if(dp[i-1][i] > dp[i-1][j] + dist(j,i)){
                dp[i-1][i] = dp[i-1][j] + dist(j,i);
                trace[i-1][i] = {i-1, j};
            }
        }
    }

    int a = 0, b = 0;
    for(int i=0;i<w+2;i++){
        // cout<<dp[w+1][i]<<' '<<dp[i][w+1]<<'\n';
        if(dp[a][b] > dp[w+1][i]){
            a = w+1;
            b = i;
        }
        if(dp[a][b] > dp[i][w+1]){
            a = i;
            b = w+1;
        }
    }
    // cout<<dp[a][b]<<'\n'<<a<<' '<<b<<'\n';
    vector<int> answer;
    // for(int i=0;i<w+2;i++){
    //     for(int j=0;j<w+2;j++){
    //         cout<<trace[i][j].first<<' '<<trace[i][j].second<<'\n';
    //     }
    //     cout<<'\n';
    // }
    cout<<dp[a][b]<<'\n';

    while(a != START_ONE || b != START_TWO){
        // printf("%d %d\n",a,b);  
        if(a > b) answer.push_back(1);
        else answer.push_back(2);
        auto next = trace[a][b];
        a = next.first; b = next.second;
    }
    reverse(answer.begin(), answer.end());
    for(auto i:answer) cout<<i<<'\n';
    return 0;
}