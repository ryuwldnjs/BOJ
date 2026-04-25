#include <stdio.h>
#include <vector>
using namespace std;
vector<pair<int, int> > vec;
int n,x,y;
int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d %d", &x, &y);
		vec.push_back({x,y});
	}
	
	for(int i=0;i<n;i++){ //i번째사람 등수 확인 
		int cnt=0;
		int x=vec[i].first;
		int y=vec[i].second;
		
		for(int j=0;j<vec.size();j++){
			if(vec[j].first>x && vec[j].second>y) cnt++; //i보다 덩치 큰사람 카운팅 
		}
		
		
		printf("%d ", cnt+1); //등수는 1부터 
	}
	return 0;
}