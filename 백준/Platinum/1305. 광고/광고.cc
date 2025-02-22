#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> makeTable(string& pattern){
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

int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    string str;
    cin>>n>>str;

    vector<int> pi = makeTable(str);
    cout<<n - pi.back();
    return 0;
}