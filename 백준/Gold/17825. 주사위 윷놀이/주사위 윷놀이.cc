#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int FINAL = 20;
const int DESINATION = 10000;
vector<int> dice(10), selected(10), score(100);
int next_idx[100];

int getNext(int pos, int iter){
    if(pos == 5){
        pos = 21;
        iter--;
    }
    else if(pos == 10){
        pos = 24;
        iter--;
    }
    else if(pos == 15){
        pos = 26;
        iter--;
    }

    while(iter--){
        if(pos == FINAL) return DESINATION; 
        if(next_idx[pos]) pos = next_idx[pos];
        else pos++;
    }
    return pos;
}

int play(){
    int ret = 0;

    vector<int> position(5);
    for(int i=0;i<10;i++){
        int who = selected[i];
        int pos = position[who];
        if(pos == DESINATION) continue;
        int next_pos = getNext(pos, dice[i]);
        if(next_pos == DESINATION){
            position[who] = DESINATION;
            continue;
        }  //골인~

        bool flag = true;
        for(int i=1;i<=4;i++){
            if(i == who) continue;
            if(position[i] == next_pos) flag = false;
        }
        if(!flag) return 0; //이동할칸에 뭔가 존재함
        
        position[who] = next_pos;
        ret += score[next_pos];
        // printf("%d ",ret);
    }
    return ret;
}


int solve(int idx){
    int ret = 0;
    if(idx == 10) return play();
    
    for(int i=1;i<=4;i++){
        selected[idx] = i;
        ret = max(ret, solve(idx+1));
        // printf("%d\n",ret);
    }
    return ret;
}



int main(){
    cin.tie(0) -> sync_with_stdio(0);
    for(int i=0;i<10;i++){
        cin>>dice[i];
    }

    // next_idx[5] = 21;
    next_idx[21] = 22;
    next_idx[22] = 23;
    next_idx[23] = 29;

    // next_idx[10] = 24;
    next_idx[24] = 25;
    next_idx[25] = 29;
    
    // next_idx[15] = 26;
    next_idx[26] = 27;
    next_idx[27] = 28;
    next_idx[28] = 29;
    
    next_idx[29] = 30;
    next_idx[30] = 31;
    next_idx[31] = 20;

    //##############################
    for(int i=0;i<=20;i++) score[i] = i*2;
    score[21] = 13;
    score[22] = 16;
    score[23] = 19;

    score[24] = 22;
    score[25] = 24;

    score[26] = 28;
    score[27] = 27;
    score[28] = 26;

    score[29] = 25;

    score[30] = 30;
    score[31] = 35;
///////////////////////////////////////////////////////

    // int pos = 0;
    // for(int i=0;i<10;i++){
    //     pos = getNext(pos, dice[i]);
    //     printf("%d ",pos);
    // }
    // selected[0] = 1;
    // selected[1] = 1;
    // selected[2] = 1;

    // selected[3] = 2;
    // selected[4] = 2;
    // selected[5] = 2;

    // selected[6] = 3;
    // selected[7] = 3;
    // selected[8] = 3;

    // selected[9] = 4;
    // cout<<play();
    cout<<solve(0);
    return 0;
}