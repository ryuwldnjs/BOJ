#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	
	int L; cin >> L;
	if(L==0){
		cout << 0 << '\n';
		exit(0);
	}
	vector<int>vec;
	while(L--){
		int n; cin >> n;
		vec.push_back(n);
	}	
	sort(vec.begin(),vec.end());
	int size = vec.size();
	size=round(size*0.15);
	double mean = 0;
	for(int i = size; i<vec.size()-size; ++i)
		mean+=vec[i];
		
	cout << round(mean/(vec.size()-2*size)) << '\n';
	
	return 0;
}