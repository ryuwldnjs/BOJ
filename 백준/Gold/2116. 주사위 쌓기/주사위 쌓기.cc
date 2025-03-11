#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//위치는 0~5
//값은 1~6
vector<vector<int>> arr, pos;
//dice번째 다이스의 바닥면이 val일때
int getOppositeIdx(int idx){
    if(idx==0 || idx==5) return 5-idx;
    if(idx==1 || idx==3) return 4-idx;
    if(idx==2 || idx==4) return 6-idx;
    return -1;
}

int solve(int dice, int val){
    if(dice == arr.size()) return 0;
    int idx = pos[dice][val];
    int MAX=0;

    //옆면중에서 최댓값 찾기
    for(int i=0;i<6;i++){
        if(i==idx || i==getOppositeIdx(idx)) continue;
        MAX = max(MAX, arr[dice][i]);
    }
    // printf("%d %d %d\n", dice, val, MAX);
    return MAX + solve(dice+1, arr[dice][getOppositeIdx(idx)]);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n; cin>>n;
    arr.resize(n, vector<int>(6));
    pos.resize(n, vector<int>(7));
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            cin>>arr[i][j];
            pos[i][arr[i][j]]=j;
        }
    }

    int answer=0;
    //제일 바닥 다이스의 바닥의 숫자가 i일때
    for(int i=1;i<=6;i++){
        answer = max(answer, solve(0, i));
    }
    cout<<answer;
    // cout<<solve(0,6);
    return 0;
}