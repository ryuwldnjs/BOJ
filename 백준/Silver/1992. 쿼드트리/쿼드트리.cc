#include <iostream>
#include <string>
using namespace std;
string map[65][65];
int n;
string solve(int y, int x, int size){
	if(size == 1){
		return map[y][x];
	}
	
	int half = size/2;
	string r1 = solve(y, x, half);
	string r2 = solve(y, x + half, half);
	string r3 = solve(y + half, x, half);
	string r4 = solve(y + half, x + half, half);
	
	if(r1==r2 && r2==r3 && r3==r4 && (r1=="0" || r1=="1"))
		return r1;
	return "("+r1+r2+r3+r4+")";
}
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char x;cin>>x;
			map[i][j] = x;
		}
	}
	
	cout<<solve(0,0,n);
	return 0;
}