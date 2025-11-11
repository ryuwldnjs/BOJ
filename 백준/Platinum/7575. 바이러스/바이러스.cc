#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

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


vector<vector<int>> programs;
vector<vector<int>> patterns;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,k;cin>>n>>k;
    int m;cin>>m;

    deque<int> pattern;
    for(int i=0;i<m;i++){
        int x;cin>>x;

        if(i >= k) pattern.pop_front();
        pattern.push_back(x);

        if(i>=k-1) patterns.push_back(vector<int>(pattern.begin(), pattern.end()));
    }

    for(int i=1;i<n;i++){
        cin>>m;
        vector<int> program(m);
        for(int i=0;i<m;i++){
            cin>>program[i];
        }
        programs.push_back(program);
    }


    for(vector<int>& pattern : patterns){
        bool isAnswer = true;
        for(vector<int>& program : programs){
            vector<int> reversed_pattern = pattern;
            reverse(reversed_pattern.begin(), reversed_pattern.end());

            isAnswer = isAnswer && (KMP(program, pattern) || KMP(program, reversed_pattern));
        }    
        if(isAnswer){
            cout<<"YES";
            return 0;
        }
    }

    cout<<"NO";

    return 0;
}