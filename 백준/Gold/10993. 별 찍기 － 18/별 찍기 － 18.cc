#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define MAX 3000
char answer[MAX][MAX];
int y,x;
int n;
void drawUp(int idx){
    int size = (1<<idx) - 1;

    for(int i=0;i<size;i++){
        if(i>0) y++,x++;
        answer[y][x] = '*';
        // if(idx == n) answer[y][x+1] = 0;
    }

    for(int i=0;i<size;i++){
        if(i>0) x--;
        answer[y][x] = '*';
    }

    y--;
}

void drawDown(int idx){
    int size = (1<<idx) - 1;

    for(int i=0;i<size;i++){
        if(i>0) y--,x++;
        answer[y][x] = '*';
        // if(idx == n) answer[y][x+1] = 0;
    }

    for(int i=0;i<size;i++){
        if(i>0) x--;
        answer[y][x] = '*';
    }

    y++;
}

//idx번째도형 시작일때
void draw(int idx){
    int size = (1<<idx) - 1;
    if(idx%2==0) y = size-1; //짝수 시작일때만

    
    for(int i=idx;i>=1;i--){
        if(i%2==0) drawDown(i);
        else drawUp(i);
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    fill(&answer[0][0], &answer[MAX-1][MAX-1], ' ');
    draw(n);

    int SIZE = (1<<n) - 1;

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE-1;j++){
            int target = abs(j - SIZE + 1);
            cout<<answer[i][target];
        }

        for(int j=0;j<SIZE;j++){
            int target = j;
            if(n%2==0 && target == SIZE-i || n%2==1 && target == i+1) break;
            cout<<answer[i][target];
        }
        cout<<'\n';
    }

    return 0;
}