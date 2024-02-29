#include <iostream>
#include <vector>
using namespace std;
int n;
void process(vector<int> &t){
	for(int i=1;i<t.size();i++){
		if(t[i] == t[i-1]){
			t[i-1] += t[i];
			t[i] = 0;
		}
	}
	//중간중간 0 없애기 
	int cnt = 0;
	for(int i=0;i<t.size();i++){
		if(t[i]) t[cnt++] = t[i];
	}
	t.resize(cnt); //찌꺼기 청소 
	t.resize(n,0);//0 채우기 
}

vector<vector<int>> up(vector<vector<int>> tmp){
	for(int i=0;i<n;i++){
		vector<int> t;
		for(int j=0;j<n;j++){
			if(tmp[j][i]) t.push_back(tmp[j][i]);
		}
		process(t);
		for(int j=0;j<n;j++){
			tmp[j][i] = t[j];
		} 

	}
	return tmp;
}

vector<vector<int>> down(vector<vector<int>> tmp){
	for(int i=0;i<n;i++){
		vector<int> t;
		for(int j=n-1;j>=0;j--){
			if(tmp[j][i]) t.push_back(tmp[j][i]);
		}
		process(t);
		for(int j=n-1;j>=0;j--){
			tmp[j][i] = t[n - j - 1];
		} 

	}
	return tmp;
}
vector<vector<int>> left(vector<vector<int>> tmp){
	for(int i=0;i<n;i++){
		vector<int> t;
		for(int j=0;j<n;j++){
			if(tmp[i][j]) t.push_back(tmp[i][j]);
		}
		process(t);
		for(int j=0;j<n;j++){
			tmp[i][j] = t[j];
		} 

	}
	return tmp;
}
vector<vector<int>> right(vector<vector<int>> tmp){
	for(int i=0;i<n;i++){
		vector<int> t;
		for(int j=n-1;j>=0;j--){
			if(tmp[i][j]) t.push_back(tmp[i][j]);
		}
		process(t);
		for(int j=n-1;j>=0;j--){
			tmp[i][j] = t[n - j - 1];
		} 

	}
	return tmp;
}

//
//vector<vector<int>> down(vector<vector<int>> tmp){
//	for(int i=n-2;i>=0;i--){
//		for(int j=0;j<n;j++){
//			int dx = 0;
//			while(i+dx+1<n && tmp[i+dx+1][j]==0) dx++;
//			if(tmp[i][j] == tmp[i+dx][j] || tmp[i+dx][j]==0){
//				tmp[i+dx][j] += tmp[i][j];
//				tmp[i][j] = 0;
//			}
//		}
//	}
//	return tmp;
//}
//vector<vector<int>> left(vector<vector<int>> tmp){
//	for(int i=0;i<n;i++){
//		for(int j=1;j<n;j++){
//			int dy = 0;
//			while(j-dy-1>=0 && tmp[i][j-dy-1]==0) dy++;
//			
//			if(tmp[i][j] == tmp[i][j-dy] || tmp[i][j-dy]==0){
//				tmp[i][j-dy] += tmp[i][j];
//				tmp[i][j] = 0;
//			}
//		}
//	}
//	return tmp;
//}
//vector<vector<int>> right(vector<vector<int>> tmp){
//	for(int i=0;i<n;i++){
//		for(int j=n-2;j>=0;j--){
//			int dy = 0;
//			while(j+dy+1<n && tmp[i][j+dy+1]==0) dy++;
//			
//			if(tmp[i][j] == tmp[i][j+dy] || tmp[i][j+dy]==0){
//				tmp[i][j+dy] += tmp[i][j];
//				tmp[i][j] = 0;
//			}
//		}
//	}
//	return tmp;
//}
int move(int idx, vector<vector<int>> map){
	if(idx == 5){
		int MAX = -1;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++) MAX = max(MAX, map[i][j]);
		return MAX;
	}
	int MAX = -1;
	MAX = max(MAX, move(idx+1, up(map)));
	MAX = max(MAX, move(idx+1, down(map)));
	MAX = max(MAX, move(idx+1, left(map)));
	MAX = max(MAX, move(idx+1, right(map)));
	return MAX;	
}
int main(){
	cin>>n;
	vector<vector<int>> map(n, vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cin>>map[i][j];
	}
	cout<<move(0, map);
	return 0;
}