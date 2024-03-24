#include <iostream>
using namespace std;
struct Info{
	long long x, y;
	bool operator<(const Info &other)const{
		if(x==other.x) return y<other.y;
		return x<other.x;
	}
	bool operator<=(const Info &other)const{
		if(x==other.x) return y<=other.y;
		return x<=other.x;
	}
	
	bool operator>(const Info &other)const{
		if(x==other.x) return y>other.y;
		return x>other.x;
	}
	bool operator>=(const Info &other)const{
		if(x==other.x) return y>=other.y;
		return x>=other.x;
	}
};

//점 a,b,c순으로 회전방향 판단 
int CCW(Info a, Info b, Info c){
	//행렬식으로 판단 (신발끈공식) 
	long long op = a.x*b.y + b.x*c.y + c.x*a.y - (a.y*b.x + b.y*c.x + c.y*a.x);
	if(op > 0) return 1;
	else if(op == 0) return 0;
	return -1;
}

Info P1,P2,P3,P4;
bool isIntersect(){
	int ab = CCW(P1, P2, P3) * CCW(P1, P2, P4);	
	int cd = CCW(P3, P4, P1) * CCW(P3, P4, P2);
	
	//일직선일떄 
	if(ab==0 && cd==0){
		return max(P1, P2) >= min(P3, P4) && min(P1,P2) <= max(P3,P4);
	}	
	return ab<=0 && cd<=0;
}
int main(){
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	P1 = {a,b};
	P2 = {c,d};

	cin>>a>>b>>c>>d;
	P3 = {a,b};
	P4 = {c,d};
	
	if(isIntersect()) cout<<1;
	else cout<<0;
	return 0;
}