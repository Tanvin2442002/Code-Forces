#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

#define ll  long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in  cin.tie(NULL) 
#define out cout.tie(NULL)
//#include <ext/pb_ds/assoc_container.hpp>


int mod  = 1000000007;
ll inf  = 1e18;

struct Node {
    ll seg, pref, suf, sum;
};

vector<Node> segTree;
vector<ll> arr;

Node merge(Node left, Node right) {
    Node result;
    result.sum = left.sum + right.sum;
    result.pref = max(left.pref, left.sum + right.pref);
    result.suf = max(right.suf, right.sum + left.suf);
    result.seg = max({left.seg, right.seg, left.suf + right.pref});
    return result;
}

void build(int idx, int l, int r) {
    if (l == r) {
        segTree[idx] = {max(0LL, arr[l]), max(0LL, arr[l]), max(0LL, arr[l]), arr[l]};
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    segTree[idx] = merge(segTree[2 * idx], segTree[2 * idx + 1]);
}

void update(int idx, int l, int r, int pos, long long value) {
    if (l == r) {
        segTree[idx] = {max(0LL, value), max(0LL, value), max(0LL, value), value};
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(2 * idx, l, mid, pos, value);
    else
        update(2 * idx + 1, mid + 1, r, pos, value);
    segTree[idx] = merge(segTree[2 * idx], segTree[2 * idx + 1]);
}

Node query(int idx, int l, int r, int ql, int qr) {
    if (ql > r || qr < l)
        return {0, 0, 0, 0}; 
    if (ql <= l && r <= qr)
        return segTree[idx];
    int mid = (l + r) / 2;
    Node left = query(2 * idx, l, mid, ql, qr);
    Node right = query(2 * idx + 1, mid + 1, r, ql, qr);
    return merge(left, right);
}

int32_t main()
{
    fastio;in;out;
    int t = 1;
    // cin >> t;
    while(t--){
      int n,q;
      cin >> n >> q;
      segTree.resize(4*n+3);
      arr.resize(n+1);
      for(int i=1;i<=n;i++){
        cin >> arr[i];
      }
      build(1,1,n);
      cout << segTree[1].seg << endl;
      while(q--){
        int i,v;
        cin >> i >> v;
        update(1,1,n,i+1,v);
        cout << segTree[1].seg << endl;
      }
    }
    return 0;
}


