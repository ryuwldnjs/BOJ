    #include <bits/stdc++.h>
    using namespace std;
    using ll=long long;

    struct Info{
        ll val;
        ll idx;
        bool operator<(const Info& other)const{
            if(val == other.val) return idx > other.idx;
            return val > other.val;
        }
    };

    vector<ll> init(500000+5), delta(500000+5);
    ll n,X;

    // 모든수가 k이상일때, 총 비용이 X초과 인가?
    bool able(ll k){
        __int128 cost = 0;
        for(ll i=0;i<n;i++){
            ll gap = max(0LL, k - init[i]);
            cost += (gap + delta[i] - 1) / delta[i];
        }
        return cost > X;
    }


    //가장 작은수가 threshold일떄 
    void solve(ll threshold){
        priority_queue<Info> pq;

        for(ll i=0;i<n;i++){
            ll gap = max(0LL, threshold - init[i]);
            ll cost = (gap + delta[i] - 1) / delta[i];
            X -= cost;
            init[i] += cost * delta[i];
            pq.push({init[i], i});
        }
        //여기까지하면, 모든 수가 threshold이상이고, 아직 X비용이 남을수 있음
        

        while(X>0 && !pq.empty()){
            auto [num, idx] = pq.top(); pq.pop();
            
            init[idx] += delta[idx];
            pq.push({init[idx], idx});
            X--;

        }
    }



    //가장 작은수가 threshold일떄  나이브
    void solve_naive(){
        priority_queue<Info> pq;
        vector<ll> a = init;
        ll tmp_X = X;

        for(ll i=0;i<n;i++){
            pq.push({a[i], i});
        }

        while(tmp_X>0 && !pq.empty()){
            auto [num, idx] = pq.top(); pq.pop();
            
            a[idx] += delta[idx];
            pq.push({a[idx], idx});
            tmp_X--;
        }

        for(int i=0;i<n;i++) cout<<a[i]<<' ';
        cout<<'\n';
    }



    int main(){
        cin.tie(0) -> sync_with_stdio(0);

        cin>>n>>X;
        for(ll i=0;i<n;i++) cin>>init[i];
        for(ll i=0;i<n;i++) cin>>delta[i];

        if(X < n){
            solve_naive();
            return 0;
        }



        ll lo = -1, hi = 1e18 + 1e9;

        for(ll i=0;i<100;i++){
            ll mid = (lo + hi) / 2;
            if(able(mid)) hi = mid;
            else lo = mid;
        }   




        // printf("%d %d : %d %d\n", lo, hi, able(lo), able(hi));
        ll start;

        if(able(lo)) start = lo-1;
        else if(able(hi)) start = hi-1;
        else start = hi;
        // printf("%d", start);
        
        // solve_naive();
        
        solve(start);
        // cout<<"파라메 : ";
        for(ll i=0;i<n;i++) cout<<init[i]<<' ';
        return 0;
    }

    /*
    5 4
    0 0 0 0 0
    12 12 12 12 12



    5 4884886
    354 654 654 654 564
    1 321 84 50 4  

    */