#include <iostream>
#include <vector>
#define SIZE (1<<20)
using namespace std;
vector<int> segTree;

int n;
void update(int idx, int cnt){
    idx += SIZE;
    segTree[idx] += cnt;
    // printf("%d %d\n" ,idx,segTree[idx]);
    while(idx > 1){
        idx >>= 1;
        segTree[idx] = segTree[2*idx] + segTree[2*idx + 1];
    }
}

int query(int target){
    int idx = 1;
    while(idx < SIZE){
        if(segTree[idx*2] >= target){
            idx = 2*idx;
        }
        else{
            target -= segTree[idx*2];
            idx = 2*idx + 1;
        }
    }
    update(idx-SIZE, -1);
    return idx - SIZE;
}


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    segTree.resize(2*SIZE);
    for(int i=0;i<n;i++){
        int a,b,c; cin>>a;
        if(a == 1){
            cin>>b;
            cout<<query(b)<<'\n';
        }
        else{
            cin>>b>>c;
            update(b,c);
        }
    }
    return 0;
}