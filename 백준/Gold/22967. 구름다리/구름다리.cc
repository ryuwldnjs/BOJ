#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n;
int graph[305][305];
vector<pii> answer;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    //완전그래프 형성 가능
    if(n <= 4){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(graph[i][j] == 0) answer.push_back({i,j});
            }
        }
    }
    else{
        for(int i=2;i<=n;i++){
            if(graph[1][i] == 0) answer.push_back({1, i});
        }
    }



    cout<<answer.size()<<'\n';
    
    if(n-1 + answer.size() >= n*(n-1)/2) cout<<"1\n";
    else cout<<"2\n";

    for(auto p: answer) cout<<p.first<<' '<<p.second<<'\n';
    return 0;
}