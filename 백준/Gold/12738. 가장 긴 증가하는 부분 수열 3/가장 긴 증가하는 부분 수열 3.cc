#include <bits/stdc++.h> 
using namespace std;vector<int>a;int n,x;main(){cin>>n;while(n--){cin>>x;auto t=lower_bound(a.begin(),a.end(),x);if(t==a.end())a.push_back(x);else*t=x;}cout<<a.size();}