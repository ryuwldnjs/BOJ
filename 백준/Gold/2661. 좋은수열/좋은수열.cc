#include <bits/stdc++.h>
using namespace std;
int n;
string num = "";
string answer = "";
bool canPlace(int target){
    for(int i=1;i<=num.size()/2;i++){
        int L = num.size()-1-i;
        int R = num.size()-1;
        bool isPlaced = false;
        
        for(int j=0;j<i;j++){
            if(num[L-j] != num[R-j]) isPlaced = true;
        }
        if(isPlaced == false) return false;
    }
    return true;
}
void solve(int depth){
    if(answer != "") return;
    // cout<<num<<'\n';
    if(depth == n){
        // cout<<num<<'\n';
        answer = num;
        return;
    }

    for(int i=1;i<=3;i++){
        num += to_string(i);
        if(canPlace(i)) solve(depth+1);
        num.pop_back();
    }
}
int main(){
    cin>>n;

    solve(0);

    cout<<answer;
    return 0;
}