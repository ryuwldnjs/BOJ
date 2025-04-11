#include <iostream>
#include <vector>
using namespace std;
using pii=pair<int,int>;
vector<pii> answer;

void solve(int k, int from, int to){
    int by = 6 - from - to;
    if(k == 1){
        answer.push_back({from, to});
        return;
    }
    solve(k-1, from, by);
    solve(1, from, to);
    solve(k-1, by, to);
}
int main(){
    int k; cin>>k;
    solve(k, 1, 3);

    cout<<answer.size()<<'\n';
    for(auto i: answer){
        cout<<i.first<<' '<<i.second<<'\n';
    }
    return 0;
}