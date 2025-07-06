#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<char> dir;
int MAX;
int n;
//idx에 가장 키 큰애를 배치했을떄
//좌측은 왼쪽 바라보는 애들중 키큰애들
//우측은 오른쪽 바라보는애들중 키큰애들
int solve(int idx, deque<int> left, deque<int> right){
    vector<int> arr(n);
    for(int i=0;i<idx;i++){
        if(dir[i] == 'R'){
            arr[i] = right.front();
            right.pop_front();
        }
    }
    for(int i=n-1;i>=idx;i--){
        if(dir[i] == 'R'){
            arr[i] = right.front();
            right.pop_front();
        }
        if(dir[i] == 'L'){
            arr[i] = left.front();
            left.pop_front();
        }
    }
    
    for(int i=0;i<idx;i++){
        if(dir[i] == 'L'){
            arr[i] = left.front();
            left.pop_front();
        }
    }

/////////////////////////////////////////////////
    int cnt = 0;

    int prefix = 0;
    for(int i=0;i<n;i++){
        if(dir[i] == 'L' && arr[i] > prefix) cnt++;
        prefix = max(prefix, arr[i]);
    }

    int suffix = 0;
    for(int i=n-1;i>=0;i--){
        if(dir[i] == 'R' && arr[i] > suffix) cnt++;
        suffix = max(suffix, arr[i]);
    }

    return cnt;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    dir.resize(n);
    deque<int> left,right;
    for(int i=0;i<n;i++){
        int a;char b; cin>>a>>b;
        dir[i] = b;
        
        if(b == 'L') left.push_back(a);
        else if(b =='R') right.push_back(a);
    }
    // left.push_back(-1); right.push_back(-1);
    sort(left.begin(), left.end()); sort(right.begin(), right.end());
    

    int answer = 1;
    for(int i=0;i<=n;i++){
        answer = max(answer, solve(i, left, right));
    }
    cout<<answer;
    return 0;
}