#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int n;
vector<vector<int>> player;
//타자 순서가 번호가 들어있음

//n루타 진출
int take(vector<bool> &base, int type){
    int score = 0;

    for(int i=3;i>=1;i--){
        if(base[i] && i + type >= 4) score++;//홈 베이스 들어옴
        base[i] = false;
        if(i-type>=1) base[i] = base[i - type];
    }
    if(type == 4) score++;
    else base[type] = true;
    return score;
}
int play(vector<int> &batter){
    int idx = 0;
    int score = 0;
    for(int i=0;i<n;i++){
        vector<int> result = player[i];
        //i이닝의 각 타자별 결과
        vector<bool> base(4);
        int out = 0;
        while(out < 3){
            int now = batter[idx];
            if(result[now] == 0) out++;
            else{
                score += take(base, result[now]);
            }
            idx = (idx+1) % 9;
        }
    }
    return score;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    player.resize(n, vector<int>(9));
    for(int i=0;i<n;i++){
        for(int j=0;j<9;j++){
            cin>>player[i][j];//i이닝의 j플레이어의 결과
        }
    }

    vector<int> idx = {1,2,3,4,5,6,7,8};//0번 선수는 4번타자 고정
    int answer = -1e9;

    do{
        vector<int> batter;
        for(int i=0;i<3;i++) batter.push_back(idx[i]);
        batter.push_back(0);
        for(int i=3;i<8;i++) batter.push_back(idx[i]);

        answer = max(answer, play(batter));
    }while(next_permutation(idx.begin(), idx.end()));

    cout<<answer;
    return 0;
}