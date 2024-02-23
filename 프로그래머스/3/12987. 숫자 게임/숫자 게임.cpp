#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
int find(int x){
    if(parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}
int merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return 0;
    parent[a] = b;
    return 1;
}
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    parent.resize(B.size()+1, -1);
    sort(B.begin(), B.end());
    
    for(int i=0;i<A.size();i++){
        int idx = find(upper_bound(B.begin(), B.end(), A[i]) - B.begin());
        if(idx >= B.size()) continue;
        
        merge(idx, idx + 1);
        answer++;
    }
    return answer;
}