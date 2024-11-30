#include <iostream>
#include <string>
#include <vector>
using namespace std;
string str;
vector<bool> visited(105);
void printString(){
    for(int i=0;i<str.size();i++){
        if(visited[i]) cout<<str[i];
    }
    cout<<'\n';
}
void solve(int idx){
    int min_idx = idx;
    if(visited[idx] || idx >= str.size()) return;
    for(int i=idx;i<str.size();i++){
        if(visited[i]) break;
        if(str[min_idx] > str[i]) min_idx = i;
    }
    visited[min_idx] = true;
    printString();
    solve(min_idx + 1);
    solve(idx);
}
int main(){
    cin>>str;

    solve(0);
    return 0;
}