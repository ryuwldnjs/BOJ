#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int idx[10005], val[10005];
int a[10005];

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        idx[x] = i;
        val[i] = x;
    }

    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i] = idx[a[i]];
    }

    vector<int> lis, corr(10000+5);
    for(int i=0;i<n;i++){
        int idx = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
        if(idx == lis.size()) lis.push_back(a[i]);
        else lis[idx] = a[i];
        corr[i] = idx;
    }        

    // a[]   = 1 3 6 9 4
	// lis[] = 1 3 4 9
	//corr[] = 0 1 2 3 2 
	//corr를 역순으로 돌면서 큰 숫자부터 작은숫자로 한번씩 회수 
	vector<int> answer;
    int target = lis.size() - 1; //LIS 길이
	for(int i=n-1;i>=0;i--){
		if(target == corr[i]){
			target--;
			answer.push_back(val[a[i]]);
		}
	}

    sort(answer.begin(), answer.end());
    cout<<answer.size()<<'\n';
    for(int i : answer) cout<<i<<' ';
    return 0;
}