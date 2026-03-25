#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int answer;
int paper[10];

void solve(){
    answer += paper[6];

    answer += paper[5];
    paper[1] = max(0, paper[1] - paper[5] * 11);

    while(paper[4] > 0){
        answer++;
        paper[4]--;
        // 2by2 5개 넣을수있음
        int remain = max(0, 5 - paper[2]);
        paper[2] -= 5-remain;
        paper[1] = max(0, paper[1] - remain * 4);
    }

    
    answer += (paper[3]+3) / 4;
    paper[3] %= 4; //3by3 떨거지
    if(paper[3] == 1){
        int remain = max(0, 5 - paper[2]);
        paper[2] -= 5-remain;
        paper[1] = max(0, paper[1] - remain * 4 - 7);
    }
    else if(paper[3] == 2){
        int remain = max(0, 3 - paper[2]);
        paper[2] -= 3-remain;
        paper[1] = max(0, paper[1] - remain * 4 - 6);
    }
    else if(paper[3] == 3){
        int remain = max(0, 1 - paper[2]);
        paper[2] -= 1-remain;
        paper[1] = max(0, paper[1] - remain * 4 - 5);
    }



    answer += (paper[2] + 8) / 9;
    paper[2] %= 9;
    if(paper[2] != 0){
        int remain = 9 - paper[2]; 
        paper[1] = max(0, paper[1] - remain * 4);
    }


    answer += (paper[1] + 35) / 36;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    for(int i=1;i<=6;i++){
        cin>>paper[i];
    }

    solve();

    cout<<answer;
    return 0;
}