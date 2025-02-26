#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;

bool pass(vector<bool>& line, int bit){//장애물 피해서&& 접한 학생없이 배치 가능한지
    for(int i=0;i<line.size();i++){
        if(line[i]==false && ((1<<i)&bit)) return false;
        if((1<<i)&bit && (1<<(i+1)&bit)) return false;
    }
    return true;
}

//up라인과 비교해서, down라인을 배치할수있는지
bool pass(int size, int bit_down, int bit_up){
    for(int i=0;i<size;i++){
        if((1<<i) & bit_down){
            if(i>0 && 1<<(i-1) & bit_up) return false;
            if(1<<(i+1) & bit_up) return false;    
        }
    }
    return true;
}
int getCnt(int bit){//bit의 1의 개수 = 앉을수있는 학생 수
    int cnt = 0;
    while(bit){
        if(bit%2) cnt++;
        bit /= 2;
    }
    return cnt;
}
void solve(){
    int n,m; cin>>n>>m;
    vector<vector<bool>> seat(n, vector<bool>(m));
    vector<vector<int>> dp(n, vector<int>((1<<m), -INF));
    //dp[i][bit] : i번째 줄에 bit조합으로 놓앗을떄 누적 최댓값

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch; cin>>ch;
            if(ch=='.') seat[i][j] = true;
        }
    }

    int size = (1<<m);
    
    for(int i=0;i<size;i++){
        if(!pass(seat[0], i)) continue;
        dp[0][i] = getCnt(i);
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<size;j++){ //i번째 줄의 j조합
            if(!pass(seat[i], j)) continue; //장애물때메 배치 불가능

            int cnt = getCnt(j);
            for(int k=0;k<size;k++){//i-1번째줄의 k조합
                if(pass(size, j,k)) dp[i][j] = max(dp[i][j], dp[i-1][k] + cnt);
            }
        }
    }
    int answer = 0;
    for(int i=0;i<size;i++){
        answer = max(answer, dp[n-1][i]);
    }
    cout<<answer<<'\n';
}

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}