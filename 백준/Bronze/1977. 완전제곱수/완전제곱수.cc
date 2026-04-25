#include <iostream>
#include <vector>
using namespace std; 
vector<int> vec;
int m,n;
int sum;
int main(){
	cin>>m>>n;
	for(int i=1;i*i<=n;i++){
		if(i*i>=m){
			vec.push_back(i*i);
			sum+=i*i;
		}	
	}
	if(vec.size()) cout<<sum<<"\n"<<vec.front();
	else cout<<"-1";
	return 0;
}