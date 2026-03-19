#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Node{
    int val;
    int left, right;
};

Node node[1005];

int preorder[1005], inorder[1005];
int postorder[1005];
int pos[1005];//pos[val] : inorder[]의 val값의 위치

int idx;

void solve(int l, int r){

    int target = pos[preorder[idx]]; //타겟 인덱스
    int val = preorder[idx];//타겟의 값
    idx++;
    
    if(l == r){ //말단
        return;
    }

    if(l < target){
        node[val].left = preorder[idx];
        solve(l, target-1);
    }
    if(target < r){
        node[val].right = preorder[idx];
        solve(target+1, r);
    }
}

void print(int now){
    if(node[now].left) print(node[now].left);
    if(node[now].right) print(node[now].right);
    cout<<now<<' ';
}

void solve(){
    idx = 0;
    memset(node, 0, sizeof(node));
    int n;cin>>n;
    for(int i=0;i<n;i++) cin>>preorder[i];
    for(int i=0;i<n;i++) {
        cin>>inorder[i];
        pos[inorder[i]] = i;
    }


    solve(0, n-1);

    print(preorder[0]);
    cout<<'\n';

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}