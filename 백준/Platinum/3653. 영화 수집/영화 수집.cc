#include <iostream>
#include <vector>
#define SIZE (1<<20)
#define BIAS (1<<19)
using namespace std;

vector<int> position,segTree;
int t,n,m;
int nextPosition;

//중간에 있던 DVD를 맨 위로 올린다해도, 기존위치는 그냥 떠있는걸로 가정
void init(){
    segTree = vector<int>(2*SIZE); // -100만~100만 -> 0~200만 확장
    position = vector<int>(n+1); // position[k]: k번 DVD의 확장된 위치
    nextPosition = BIAS-1;

    for(int i=1;i<=n;i++) position[i] = BIAS + i;
    
    for(int i=1;i<=n;i++){
        segTree[SIZE + BIAS + i] = 1; 
    }
    for(int i=SIZE-1; i>0; i--){
        segTree[i] = segTree[2*i] + segTree[2*i+1];
    }

}
//DVD가 있었던곳은 0처리 후, 새로운 꼭대기층에 1 처리
void update(int idx){
    idx += SIZE;
    segTree[idx] = 0;
    while(idx > 1){
        idx /= 2;
        segTree[idx] = segTree[2*idx] + segTree[2*idx+1];
    }

    idx = SIZE + nextPosition;
    segTree[idx] = 1;
    while(idx > 1){
        idx /= 2;
        segTree[idx] = segTree[2*idx] + segTree[2*idx+1];
    }

}

// [0,position[target]) 구간 합
int query(int target){// target번 영화는 어디에 있을까
    int R = SIZE + position[target];
    int sum = 0;
    while(0 < R){
        if(R % 2 == 1){
            R--;
            sum += segTree[R];
        }
        R /= 2;
    }

    update(position[target]);
    position[target] = nextPosition--;
    return sum;
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>m;
        init();
        for(int i=0;i<m;i++){
            int q; cin>>q;
            cout<<query(q)<<' ';
        }
        cout<<'\n';
    }
    return 0;
}