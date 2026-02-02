#include <bits/stdc++.h>
using namespace std;

vector<int> position;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin>>n>>m;
    position.resize(n+1);
    for(int i=1;i<=n;i++) position[i] = i;

    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        position[a]++; position[b]--;
    }
    set<int> s(position.begin()+1, position.end());

    if(*s.begin() != 1 || *s.rbegin() != n || s.size() != n){
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=n;i++) cout<<position[i]<<' ';
    return 0;
}