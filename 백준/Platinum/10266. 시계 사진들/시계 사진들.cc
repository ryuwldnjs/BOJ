#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define SIZE 360000
vector<int> a,b;

vector<int> makeTable(vector<int> &pattern){
    int n = pattern.size();
    vector<int> pi(n);
    int j=0;
    for(int i=1;i<n;i++){
        while(j>0 && pattern[i] != pattern[j]) j = pi[j-1];
        if(pattern[i] == pattern[j]){
            pi[i] = j+1;
            j++;
        }
    }
    return pi;
}

bool KMP(vector<int> &parent, vector<int> &pattern){
    vector<int> pi = makeTable(pattern);
    int n = parent.size();
    int m = pattern.size();
    int j=0;

    for(int i=0;i<n;i++){
        while(j>0 && parent[i] != pattern[j]) j = pi[j-1];
        if(parent[i] == pattern[j]){
            if(j == m-1) return true;
            else j++;
        }
    }
    return false;
}


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    a.resize(n);
    b.resize(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for(int i=n;i<n*2;i++){
        a.push_back(a[i-n] + SIZE);
        // b.push_back(b[i-n] + SIZE);
    }

    vector<int> diffA(n*2 - 1), diffB(n - 1);
    for(int i=0;i<n*2 - 1;i++) diffA[i] = a[i+1] - a[i];
    for(int i=0;i<n - 1;i++) diffB[i] = b[i+1] - b[i];
    

    // diffA[] = parent
    // diffb[] = pattern

    if(KMP(diffA, diffB)) cout<<"possible";
    else cout<<"impossible";

    return 0;
}