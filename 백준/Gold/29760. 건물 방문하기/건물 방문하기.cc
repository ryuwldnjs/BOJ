#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

int n,h,w, max_height;
int answer;
int main(){
    cin>>n>>h>>w;
    vector<pair<int,int>> dest(h+1, {INF, -INF});
    vector<vector<int>> dp(h+1, vector<int>(2,INF));

    for(int i=0;i<n;i++){
        int a,b; cin>>a>>b;
        dest[a].first = min(dest[a].first, b);
        dest[a].second = max(dest[a].second, b);
        max_height = max(max_height, a);
    }


    int x1 = 1, x2 = 1;
    int cost1=0, cost2=0;
    for(int i=1;i<=h;i++){
        int l = dest[i].first;
        int r = dest[i].second;
        // int new_cost1=INF, new_cost2=INF;
        if(l==INF) continue;
        int new_cost1 = min(cost1 + abs(x1-r)+abs(r-l), cost2 + abs(x2-r)+abs(r-l));
        int new_cost2 = min(cost1 + abs(x1-l)+abs(r-l), cost2 + abs(x2-l)+abs(r-l));

        cost1 = new_cost1; cost2 = new_cost2;
        x1 = l; x2 = r;
        // printf("%d %d\n", cost1, cost2);
    }
    answer = min(cost1, cost2);
    answer += 100*(max_height-1);
    cout<<answer;
    return 0;
}