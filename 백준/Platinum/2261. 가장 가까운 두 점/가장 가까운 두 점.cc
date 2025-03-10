#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;
struct Point{
	int x,y;
	
	//생성자  
	Point(){}
	Point(int x, int y) : x(x), y(y) {}
	
	bool operator < (const Point & b) const{
		if(y == b.y) return x < b.x;
		else return y < b.y;
	}
};

bool cmp(const Point &a, const Point &b){
	return a.x < b.x;
}

int dist(Point p1, Point p2){
	return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

vector<Point> arr;
int n,x,y;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		arr.push_back({x,y});
	}
	sort(arr.begin(), arr.end(), cmp);
	
	set<Point> candidate;
	candidate.insert(arr[0]);
	candidate.insert(arr[1]);
	
	//answer에는 두점사이의 거리의 제곱 저장 
	int answer = dist(arr[0], arr[1]);
	int start = 0;
	for(int i=2;i<n;i++){
		Point now = arr[i];
		while(start < i){
			Point p = arr[start];
			x = now.x - p.x;
			if(x*x > answer){
				candidate.erase(p);
				start++;
			}
			else break;
		}
		
		int dy = (int)sqrt(1.0*answer)+1;
		Point lower_point = (Point){-100000, now.y-dy};
		Point upper_point = (Point){100000, now.y+dy};
		set<Point>::iterator lower = candidate.lower_bound(lower_point);
		set<Point>::iterator upper = candidate.upper_bound(upper_point);
		
		for(set<Point>::iterator it = lower; it != upper; it++){
			answer = min(answer, dist(now, *it));
		}
		candidate.insert(now);
	}
	cout<<answer;
	return 0;
}