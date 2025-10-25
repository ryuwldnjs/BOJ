#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;

int value[1000][1000];
void preprocess(){
    fill(&value[0][0], &value[999][999], -INF);
    //두부 조각이 board넘어설경우 -INF처리

    value['A']['A'] = 100;
    value['A']['B'] = value['B']['A'] = 70;
    value['B']['B'] = 50;
    value['A']['C'] = value['C']['A'] = 40;
    value['B']['C'] = value['C']['B'] = 30;
    value['C']['C'] = 20;

    value['F']['A'] = value['F']['B'] = value['F']['C'] = 0;
    value['A']['F'] = value['B']['F'] = value['C']['F'] = 0;
}

int n;
char board[15][15];
int dp[15*15][1<<15];
// dp[idx][bit] : idx-1번째칸까지 전부 방문했고, 현재 포함 다음 n칸의 방문상태가 bit일때 최댓값

//idx값으로 idx1, idx2인 두부의 점수
int getValue(int idx1, int idx2){
    char a = board[idx1/n][idx1%n];
    char b = board[idx2/n][idx2%n];

    return value[a][b];
}

int solve(int idx, int bit){
    if(idx > n*n) return -INF;
    if(idx == n*n){
        if(bit == 0) return 0;
        else return -INF;
    }

    int &ret = dp[idx][bit];
    if(ret != -1) return ret;
    ret = 0;

    //0. 현재 두부가 이미 사용중임
    if(bit&1) return ret = max(ret, solve(idx+1, bit>>1));
    
    //1. idx, idx+1에 가로 두부 배치
    if(idx%n != n-1 && (bit & 3) == 0){
        ret = max(ret, solve(idx+2, bit>>2) + getValue(idx, idx+1));
    }
    //2. idx, idx+n에 세로 두부 배치
    if((bit&1) == 0){
        ret = max(ret, solve(idx+1, (bit>>1)|(1<<n-1)) + getValue(idx, idx+n));
    }
    //3. 현재 두부 폐기
    ret = max(ret, solve(idx+1, bit>>1));
    // printf("%d, %d : %d\n", idx, bit, dp[idx][bit]);
    return ret;
}

int main(){
    preprocess();
    cin.tie(0) -> sync_with_stdio(0);

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    
    cout<<solve(0, 0);
    return 0;
}