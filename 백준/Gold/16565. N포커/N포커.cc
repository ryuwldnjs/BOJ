#include <iostream>
#include <vector>
#define MOD 10007
#define SIZE 52
using namespace std;

vector<vector<int>> dp(55, vector<int>(55,-1));
int nCr(int n, int r){
    if(n==r || r==0) return 1;
    int &ret = dp[n][r];
    if(ret != -1) return ret;
    return ret = (nCr(n-1,r-1) + nCr(n-1,r)) % MOD;
}
int getCombi(int n, int i){ //총 n개 고르는 경우에서 4개문양을 i쌍 만족하는 조합 개수
    int ret = nCr(SIZE/4, i); // 13Ci
    return ret * nCr(SIZE - 4*i, n - 4*i) % MOD;////남은 카드 중에서 고르는 조합 수
}
int main(){
    int n; cin>>n;
    int answer = 0;
    
    for(int i=1;4*i<=n;i++){
        if(i%2==1) answer += getCombi(n, i);
        else answer -= getCombi(n, i);
        answer = (answer + MOD) % MOD;
    }
    cout<<answer;
    return 0;
}