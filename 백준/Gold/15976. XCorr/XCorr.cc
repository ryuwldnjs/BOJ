#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> vec1_idx, vec1_val, vec2_idx, vec2_val;
long long sum;
int main(){
	long long n,m, x,y, a,b;
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	while(n--){
		cin>>x>>y;
		vec1_idx.push_back(x);
		vec1_val.push_back(y);
	}
	cin>>m;
	
	vec2_idx.resize(m+1);
	vec2_val.resize(m+1);
	for(int i=1;i<=m;i++){
		cin>>x>>y;
	
		vec2_idx[i] = x;
		vec2_val[i] = y+ vec2_val[i-1];
//		printf("%d ", vec2_val[i]);
	}
	
	cin>>a>>b; //t의 범위 

	

	long long psum=0;//vec1[i] 범위에 걸리는 값들의 합 
	for(int i=0;i<vec1_idx.size();i++){
		int start = vec1_idx[i] + a;
		int end = vec1_idx[i] + b;
		
		int y2 = lower_bound(vec2_idx.begin()+1, vec2_idx.end(), end) - vec2_idx.begin();
		int y1 = lower_bound(vec2_idx.begin()+1, vec2_idx.end(), start) - vec2_idx.begin();
		if(y2>m) y2 = m;
        if(vec2_idx[y2]>end) y2--;
		psum = vec2_val[y2] - vec2_val[y1-1];
//		printf("%d %d\n", y2, y1);
//	printf("psum=%d\n", psum);
		sum += psum * vec1_val[i];
	}
	
    cout<<sum;
	return 0;
}