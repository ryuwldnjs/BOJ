#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int score=-1;
    int number=-1;
    int time=-1;

    bool operator<(const Info&other)const{
        if(score == other.score) return time < other.time;
        return score < other.score;
    };
};

Info pictures[25];
int n,k;
void solve(int num, int t){
    int idx = 0; //지울 타겟
    for(int i=0;i<n;i++){
        if(pictures[i].number == num){
            pictures[i].score++;
            return;
        }

        if(pictures[i] < pictures[idx]) idx = i;
    }
    pictures[idx] = {1, num, t};
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>k;
    for(int i=0;i<k;i++){
        int num;cin>>num;
        solve(num, i);
    }

    vector<int> answer;
    for(int i=0;i<n;i++){
        if(pictures[i].number != -1) answer.push_back(pictures[i].number);
    }

    sort(answer.begin(), answer.end());
    for(int i:answer) cout<<i<<' ';
    return 0;
}