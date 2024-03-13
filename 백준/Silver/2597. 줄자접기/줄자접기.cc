#include <iostream>
#include <vector>
using namespace std;
using pii=pair<double,double>;
double l,r;
vector<pii> points(3); 
int main(){
	cin>>r;
	for(auto &i : points){
		cin>>i.first>>i.second;
//		i.first *=2;
//		i.second *=2;
	}
	
	for(int i=0;i<3;i++){
		if(points[i].first == points[i].second) continue;
		double folding = (points[i].first + points[i].second) / 2;
		
		for(int j=i;j<3;j++){
			if(points[j].first < folding) points[j].first = 2*folding-points[j].first;
			if(points[j].second < folding) points[j].second = 2*folding-points[j].second;
			
		}
		
		if(2*folding-l > r) r = 2*folding-l;
		l = folding;
	}
	
//	int num = r-l;
//	cout << num/2 << (num%2 ? ".5" : ".0");
	printf("%.1lf", r-l);
	return 0;
}