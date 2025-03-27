#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;
vector<vector<int>> dp;
string a,b;
//dp[i][j]: a의 i번쨰 글자와, b의 j번째 글자까지의 편집거리
int solve(int i, int j){
    if(i<0 || j<0) return max(i,j) + 1;
    int &ret = dp[i][j];
    if(ret != INF) return ret;
    // ret = 0;

    if(a[i] == b[j]) ret = min(ret, solve(i-1, j-1));
    else{
        ret = min(ret, solve(i-1, j) + 1);
        ret = min(ret, solve(i, j-1) + 1);
        ret = min(ret, solve(i-1, j-1) + 1);    
    }
    return ret;
}
int main(){
    cin>>a>>b;
    dp.resize(a.size()+1, vector<int>(b.size()+1, INF));


    cout<<solve(a.size()-1, b.size()-1);
    return 0;
}