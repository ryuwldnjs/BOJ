#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
struct SegmentTree {
    int size; //n이상의 가장 작은 2^k
    vector<ll> tree;

    SegmentTree(int n) {
        size = (1<<(32 - __builtin_clz(n)));
        tree.resize(2 * size);
    }

    void build(vector<ll>& arr) {
        for (int i = 0; i < arr.size(); i++)
            tree[size + i] = arr[i];

        for (int i = size - 1; i > 0; i--)
            tree[i] = tree[2 * i] + tree[2 * i + 1];
    }

    void update(int index, ll value) {
        index += size;  // 리프 노드로 이동
        tree[index] = value;  // 값 변경

        while (index > 1) {
            index /= 2;
            tree[index] = tree[2 * index] + tree[2 * index + 1];
        }
    }

    ll query(int left, int right) {
        ll sum = 0;
        left += size;
        right += size;

        while (left <= right) {
            if (left % 2 == 1) sum += tree[left++];
            if (right % 2 == 0) sum += tree[right--];
            left /= 2, right /= 2;
        }
        return sum;
    }
};


int main(){
    int n,m,k; cin>>n>>m>>k;
    SegmentTree segTree(n);
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    segTree.build(arr);

    for(int i=0;i<m+k;i++){
        ll a,b,c; cin>>a>>b>>c;
        if(a == 1){
            segTree.update(b-1, c);
        }
        else{
            cout<<segTree.query(b-1,c-1)<<'\n';
        }
    }
    return 0;
}