#include <iostream>
#include <string>
#include <algorithm>
#define INF 1234567890

using namespace std;
int t, n;
string str;

int compute(int a, int b){
	int dist = 0;
	int toggle = a^b;
	while(toggle){
		dist += toggle%2;
		toggle >>= 1;
	}
	return dist;
}


int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		int mbti[16]={0,};
		int MIN = INF;
		
		for(int i=0;i<n;i++){
			int bit=0;
			cin>>str;
			// INTJ => 1111(2진수)
			if(str[0] == 'I') bit += 1;
			if(str[1] == 'N') bit += 2;
			if(str[2] == 'T') bit += 4;
			if(str[3] == 'J') bit += 8;
			
			mbti[bit]++; 
		}
		
		for(int i=0;i<16;i++){
			if(!mbti[i]) continue;
			mbti[i]--;
			
			for(int j=i;j<16;j++){
				if(!mbti[j]) continue;
				mbti[j]--;
				
				for(int k=j;k<16;k++){
					if(!mbti[k]) continue;
					int dist = compute(i, j) + compute(i, k) + compute(j, k);
					MIN = min(MIN, dist);
				}
				mbti[j]++;
			}
			mbti[i]++;
		}
		cout<<MIN<<'\n';
	}
	return 0;
}