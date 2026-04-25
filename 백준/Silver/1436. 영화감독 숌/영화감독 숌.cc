#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec;
int n;
int main(){
	cin>>n;
	
	vec.push_back(666);
	vec.push_back(6660);
	vec.push_back(66600);
	vec.push_back(666000);
	
	for(int i=1;i<3000;i++){
		for(int j=1;j<=1000;j *= 10){
			int front = i / j * j *1000; //666이 이 front뒤에 들어감
			int rear = i % j; //666다음에 rear가 들어감
			
			int num = front + 666*j + rear;
			//i = abc, num = abc666, ab666c, a666bc, 666abc 생성 
			vec.push_back(num); 
		}
	}
	
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	
	cout<<vec[n-1];
	return 0;
}