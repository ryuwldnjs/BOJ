#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> vec[100000+50]; //각 color를 담을거임 
int n, pos, color, color_cnt;
long long sum;//이게 곧 답 
int main()
{
	scanf("%d", &n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d %d", &pos, &color);
		color_cnt = max(color_cnt, color);// color max값이 곧 color갯수 
		vec[color].push_back(pos);
	}
	
	for(int i=1;i<=color_cnt;i++) //정렬 함 해주고 
		if(!vec[i].empty())
			sort(vec[i].begin(), vec[i].end());
				
	for(int i=1;i<=color_cnt;i++)
	{
	
		if(vec[i].size()==2)
			sum+= 2*(vec[i][1]-vec[i][0]);
			
		
		if(vec[i].size()>=3)
		{
			sum+= vec[i][1]-vec[i][0]; //첫번째 
			sum+= vec[i][vec[i].size()-1] - vec[i][vec[i].size()-2]; //마지막 
		}
		
		if(vec[i].size())
		for(int j=1;j<vec[i].size()-1; j++) 
			{
				int pre = vec[i][j] - vec[i][j-1];
				int next= vec[i][j+1] - vec[i][j];
				sum += min(pre,next);	
			}
	}
	
	printf("%lld", sum); 
	return 0;
}