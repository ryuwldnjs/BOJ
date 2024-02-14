#include <bits/stdc++.h>
using namespace std;

vector<int> parent(105, -1);
int find(int x){
    if(parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}
int merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return 0;
    parent[a] += parent[b];
    parent[b] = a;
    return 1;
}
bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i=0;i<costs.size();i++)
        if(merge(costs[i][0], costs[i][1])) answer += costs[i][2];
    
    return answer;
}