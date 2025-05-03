#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
vector<int> l,r;//이분 그래프
vector<bool> visited;
int n;
vector<int> answer;

bool isPrime(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0) return false;
	return true;
}


bool dfs(int x){
	if(visited[x]) return false;
	visited[x] = true;
	for(int y: graph[x]){
//반대편이 매칭되지 않았거나
//매칭되어 있었지만 원래 매칭되어 있던 정점을 다른 정점과 매칭시킬 수 있으면 성공
		if(r[y]==-1 || dfs(r[y])){
			r[y] = x;
			l[x] = y;
			return true;
		}
	}
	return false;
}

//target이 a그룹에 들어가도록 설정
void solve(vector<int> &a, vector<int> &b, int target){
    graph = vector<vector<int>>(a.size());
    l.resize(a.size() + 1, -1);
    r.resize(b.size(), -1);

    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            if(isPrime(a[i] + b[j])){
                graph[i].push_back(j);
            }
        }
    }

	for(int i=0;i<a.size();i++){
        if(l[i] != -1) continue;
        visited = vector<bool>(a.size());
        dfs(i);
    }


    int target_idx = a.size();
    //target활동 개시
    for(int i=0;i<b.size();i++){
        if(!isPrime(target + b[i])) continue;

        if(l[target_idx] != -1){
            r[l[target_idx]] = -1;
            l[target_idx] = -1;
        }
        graph.push_back({i});//target -> b[i] 연결
        visited = vector<bool>(target_idx+1);
        dfs(target_idx);
        graph.pop_back();


        int match = 0;
        for(int j=0;j<target_idx+1; j++){
            if(l[j] != -1) match++;
        }
        if(match*2 == n) answer.push_back(b[l.back()]);
    }

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
	cin>>n;
	int target;//첫번째 수
    vector<int> odd, even;
    cin>>target;
	for(int i=1;i<n;i++) {
        int x; cin>>x;
        if(x%2 == 0) even.push_back(x);
        else odd.push_back(x);
    }




    if(target % 2 == 1) solve(odd, even, target);
    else solve(even, odd, target);

    sort(answer.begin(), answer.end());
    for(int i: answer) cout<<i<<' ';
    // sort(answer.begin(), answer.end());
    // for(int x: answer){
    //     cout<<x<<' ';
    // }
    if(answer.empty()) cout<<-1;
	return 0;
}