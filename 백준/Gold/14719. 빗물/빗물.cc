#include <iostream>
using namespace std;
int h,w,map[505];
int answer;
int main(){
	cin>>h>>w;
	for(int i=0;i<w;i++){
		cin>>map[i];
	}
	for(int height=1;height<=500;height++){
		int wall=-1;
		int water=0;
		for(int i=0;i<w;i++){
			if(map[i] >= height){
				answer += water;
				wall = i;
				water = 0;
				continue;
			}
			if(wall != -1) water++;
		}
	}
	cout<<answer;
	return 0;
}