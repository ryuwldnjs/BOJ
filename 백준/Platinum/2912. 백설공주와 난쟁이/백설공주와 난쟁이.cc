#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;
vector<int> arr, color[10000+5], block;
int n,c, sqrtN;

//평방분할
void decomposition(){
    block.resize(sqrtN+1);
    vector<int> tmp(c+1);
    int MAX=0;
    int MAX_color=0;
    for(int i=0;i<n;i++){
        if(MAX < ++tmp[arr[i]]){
            MAX = tmp[arr[i]];
            MAX_color = arr[i];
        }

        if(i%sqrtN == sqrtN-1){
            block[i / sqrtN] = MAX_color;
            tmp = vector<int>(c+1);
            MAX = 0;
            MAX_color = 0;
        }
    }
    //끄트머리
    if(MAX != 0){
        block[(n+sqrtN-1) /sqrtN] = MAX_color;
    }
}
void query(int a, int b){
    unordered_set<int> candidate;
    int l=a, r=b;
    while(l <= r){
        if(l % sqrtN == 0 && l + sqrtN-1 <= r){
            candidate.insert(block[l / sqrtN]);
            l += sqrtN;
        }
        else{
            candidate.insert(arr[l]);
            l++;
        }
    }

    int MAX = 0;
    int MAX_color = 0;
    for(auto it= candidate.begin(); it != candidate.end(); it++){
        vector<int> &target = color[*it];
        int cnt = upper_bound(target.begin(), target.end(), b) - lower_bound(target.begin(), target.end(), a);

        if(MAX < cnt){
            MAX = cnt;
            MAX_color = *it;
        }
    }

    if(MAX > (b-a+1) / 2) cout<<"yes "<<MAX_color<<'\n';
    else cout<<"no\n";
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>c;
    sqrtN = sqrt(n);
    arr.resize(n);
    for(int i=0;i<n;i++){
        int x; cin>>x;
        arr[i] = x;
        color[x].push_back(i);
    }

    decomposition();


    int m; cin>>m;
    while(m--){
        int a,b; cin>>a>>b;
        a--; b--;
        query(a,b);
    }

    return 0;
}