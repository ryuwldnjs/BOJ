#include <string>
#include <vector>
#define INF 1e9
using namespace std;
// dp[i][n][m] :흔적이 각 n,m개남긴상태일때, i까지 훔칠수있는가
bool dp[50][150][150];

int solution(vector<vector<int>> info, int n, int m) {
    int answer = INF;
    info.insert(info.begin(), {0,0});
    dp[0][0][0] = true;
    
    for(int i=1;i<info.size();i++){
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                if(a >= info[i][0] && dp[i-1][a-info[i][0]][b]) dp[i][a][b] = true; 
                if(b >= info[i][1] && dp[i-1][a][b-info[i][1]]) dp[i][a][b] = true; 
                if(i==info.size() - 1 && dp[i][a][b] == true) answer = min(answer, a);
            }
        }
        
    }
    return answer == INF ? -1 : answer;
}