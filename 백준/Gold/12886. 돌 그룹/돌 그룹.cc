#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

bool visited[1500+5][1500+5]; //[a][b], c는 직접 계산
int total;
bool dfs(int a, int b){
    int c = total - a - b;
    if(visited[a][b]) return false;
    visited[a][b] = true;

    if(a == b && b == c) return true;

    if(a<b && dfs(a+a, b-a)) return true; 
    if(a<c && dfs(a+a, b)) return true; 
    if(b<c && dfs(a, b+b)) return true; 

    if(a>b && dfs(a-b, b+b)) return true; 
    if(a>c && dfs(a-c, b)) return true; 
    if(b>c && dfs(a, b-c)) return true; 
    return false;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int a,b,c;cin>>a>>b>>c;
    total = a + b + c;
    if(total % 3 != 0){
        cout<<0;
        return 0;
    }

    cout<<dfs(a,b);
    
    return 0;
}