#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n, me;
int guilty[20];
int R[20][20];
bool isKilled[20];

//남은 생존자
void kill(int target){
    isKilled[target] = true;
    for(int i=0;i<n;i++){
        guilty[i] += R[target][i];
    }
}
void recover(int target){
    isKilled[target] = false;
    for(int i=0;i<n;i++){
        guilty[i] -= R[target][i];
    }
}

int MIN;
int answer;
void solve(int remain){
    // printf("%d\n", remain);
    answer = max(answer, n/2 - (remain-1)/2);
    if(remain <= 2) return;
    // printf("%d\n", remain);
    if(remain % 2 == 0){//마피아가 죽임
        for(int i=0;i<n;i++){
            if(i != me && !isKilled[i]){
                kill(i);
                solve(remain-1);
                recover(i);
            }
        }
    }
    else{ // 마녀사냥
        int target = -1;
        for(int i=0;i<n;i++){
            if(isKilled[i]) continue;
            if(target == -1 || guilty[target] < guilty[i]) target = i;
        }
        
        if(target == me) return;

        isKilled[target] = true;
        solve(remain-1);
        isKilled[target] = false;
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>guilty[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>R[i][j];
        }
    }
    cin>>me;

    solve(n);
    cout<<answer;
    return 0;
}