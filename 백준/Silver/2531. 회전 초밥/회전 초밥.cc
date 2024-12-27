#include <iostream>
#include <vector>
using namespace std;

int n,d,k,c;
int now, MAX;
vector<int> conveyer, sushi(3000+5);
int main(){
	cin>>n>>d>>k>>c;
	for(int i=0;i<n;i++){
		int yummy; cin>>yummy;
		conveyer.push_back(yummy);
	}
	for(int i=0;i<k;i++){
		if(sushi[conveyer[i]]++ == 0){
			now++;
		}
	}
	
	for(int i=0;i<n;i++){
		int tail = i;
		int head = (i + k) % n;
		if(--sushi[conveyer[tail]] == 0){
			now--;
		}
		if(sushi[conveyer[head]]++ == 0){
			now++;
		}
		MAX = max(MAX, now + !sushi[c]);
	}
	cout<<MAX;
	return 0;
}