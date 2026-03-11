#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int n;
int goal[5];
int ingredient[20][10];

int getCost(int bit){
    int now[5]={};

    for(int i=0;i<n;i++){
        if((bit & (1<<i)) == 0) continue;
        for(int j=0;j<5;j++){
            now[j] += ingredient[i][j];
        }
    }

    for(int i=0;i<4;i++){
        if(goal[i] > now[i]) return INF;
    }
    return now[4]; //총 price
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<4;i++) cin>>goal[i];

    for(int i=n-1;i>=0;i--){ //역순으로 하면, bit조합 정답 오름차순 보장
        for(int j=0;j<5;j++){
            cin>>ingredient[i][j];
        }
    }

    int answer = INF;
    vector<vector<int>> answerList;

    for(int bit=0;bit<(1<<n);bit++){
        int cost = getCost(bit);
        if(cost < answer) answerList.clear();

        if(cost <= answer){
            answer = cost;
            vector<int> tmp;
            for(int i=n-1;i>=0;i--){
                if(bit & (1<<i)) tmp.push_back(n-i);
            }
            answerList.push_back(tmp);
        }
    }
    sort(answerList.begin(), answerList.end());

    if(answer == INF) cout<<-1;
    else{
        cout<<answer<<'\n';
        for(int i: answerList[0]) cout<<i<<' ';
    }
    return 0;
}