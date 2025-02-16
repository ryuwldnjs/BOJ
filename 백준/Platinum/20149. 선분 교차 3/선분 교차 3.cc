#include <iostream>
using namespace std;
using ll=long long;
struct Info{
    ll x,y;
    bool operator<(const Info& other)const{
        if(x==other.x) return y < other.y;
        return x < other.x;
    }

    bool operator>(const Info& other)const{
        if(x==other.x) return y > other.y;
        return x > other.x;
    }
    bool operator<=(const Info& other)const{
        if(x==other.x) return y <= other.y;
        return x <= other.x;
    }

    bool operator>=(const Info& other)const{
        if(x==other.x) return y >= other.y;
        return x >= other.x;
    }
    bool operator==(const Info& other)const{
        return x==other.x && y==other.y;
    }
};
Info p1,p2,p3,p4;

ll CCW(Info a, Info b, Info c){
    long long op = a.x*b.y + b.x*c.y + c.x*a.y - (a.y*b.x + b.y*c.x + c.y*a.x);
    if(op > 0) return 1;
    else if(op==0) return 0;
    else return -1;
}
ll isIntersect(){ // 선분이 완전히 겹치는것도 교차하지 않는걸로 간주
    ll ab = CCW(p1, p2, p3) * CCW(p1, p2, p4);
    ll cd = CCW(p3, p4, p1) * CCW(p3, p4, p2);
    // printf("%d %d %d %d\n",CCW(p1,p2,p3), CCW(p1,p2,p4), CCW(p3,p4,p1),CCW(p3,p4,p2));
    if(ab==0 && cd==0){ //
        //수직선상 끝점에서 만날때
        if(min(p1,p2)==max(p3,p4) || max(p1,p2)==min(p3,p4)){
            return -1;
        }
        //기울기는 다르지만, 한점에서 만날때
        if((CCW(p1,p2,p3)||CCW(p1,p2,p4)) &&(p1==p3||p1==p4 || p2==p3||p2==p4)){
            return -1;
        }
        //겹침
        if(max(p1, p2) > min(p3, p4) && min(p1,p2) < max(p3,p4)){
            
            return -2;
        }
        return 0;
    }
    return ab <= 0 && cd <= 0;
}
int main(){
    cout<<fixed;
    cout.precision(9);
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    p1 = {a,b};
    p2 = {c,d};
    cin>>a>>b>>c>>d;
    p3 = {a,b};
    p4 = {c,d};

    ll intersectNum = isIntersect();
    cout<<!!intersectNum<<'\n';
    if(intersectNum==0 || intersectNum==-2) return 0;

    if(intersectNum == -1){//한직선상에서 한점 교차 or 기울기 다르지만 끝점 교차
        if(p1==p3 || p1==p4) cout<<p1.x<<' '<<p1.y;
        else cout<<p2.x<<' '<<p2.y;
    }
    else{
        double det = (p2.x-p1.x)*(p4.y-p3.y) - (p2.y-p1.y)*(p4.x-p3.x);
        double t = ( (p3.x-p1.x)*(p4.y-p3.y) - (p3.y-p1.y)*(p4.x-p3.x) ) / det;
        double x = p1.x + t*(p2.x - p1.x);
        double y = p1.y + t*(p2.y - p1.y);
        cout<<x<<' '<<y;
    }
    return 0;
}