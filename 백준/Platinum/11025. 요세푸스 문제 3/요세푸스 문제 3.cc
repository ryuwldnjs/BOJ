#include <bits/stdc++.h>
using namespace std;

// dp[i] = i명[1,2..,i]에서 최후의 1인으로 가정
// dp[i] = (dp[i-1] + k - 1) % n + 1;

/*
n=6일때, 최후의 1인 = x로 가정
 = [0 1 2 3 4 5] 중 x가 최후의 1인이다

n=7일때, iteration 1번 시행
   [0 1 2 3 4 5 6]에서 k번째(값은 k-1) 사람이 죽었다
   [3 4 5 6 0 1 (2)] 6명이 남고 회전되어있을거다. (임의의 k=3, 지금은 2(0-based라서)가 타게팅되었다 가정)
   [3 4 5 6 0 1] : k가 시작인 dp[6]게임을 다시 시작함
    = (x+3) % 7
    = (x+k) % n

    이 문제는 1-based이므로,(x+k-1) % n + 1로 처리
*/

 
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,k;cin>>n>>k;
    int answer = 1;

    for(int i=2;i<=n;i++){
        answer = (answer + k - 1) % i + 1;
    }

    cout<<answer;
    return 0;
}