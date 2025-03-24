#include <iostream>
#include <vector>
using namespace std;

int d,p;
int LIMIT=1;
// vector<bool> visited;
int solve(int idx, int depth, int val){
    // visited[val] = true;
    // if(val >= LIMIT) return -1;
    if(depth == p){
        // printf("%d\n", val);
        return val;
    }
    int answer = -1;
    for(int i=idx;i<=9;i++){
        int next = val * i;
        if(next < LIMIT) answer = max(answer, solve(i, depth+1, next));
    }
    return answer;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>d>>p;
    for(int i=0;i<d;i++) LIMIT *= 10;
    // visited.resize(LIMIT);

    cout<<solve(2, 0, 1);
    return 0;
}