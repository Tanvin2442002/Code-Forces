#pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #ifndef ONLINE_JUDGE
// #include "F:\Codeforces\debug.h"
// #else
// #define dbg(x...)
// #define dbgc(x...)
// #endif
using namespace std;

#define ll long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in cin.tie(NULL)
#define out cout.tie(NULL)
// #include <ext/pb_ds/assoc_container.hpp>

int mod = 1000000007;
ll inf = 1e18;

struct node {
  int max1 = 0;
  int max2 = 0;
  int cnt1 = 0;
  int cnt2 = 0;
  node() {
    
  }
  node(int mx1, int mx2, int c1, int c2) {
    max1 = mx1;
    max2 = mx2;
    cnt1 = c1;
    cnt2 = c2;
  }
};

vector<node> secondmax;

node combine(node left, node right) {
    int mx1 = INT_MIN, mx2 = INT_MIN, cnt1 = 0, cnt2 = 0;
    set<int>st;
    st.insert(left.max1);
    st.insert(left.max2);
    st.insert(right.max1);
    st.insert(right.max2);
    map<int, int> mp;
    mp[left.max1] += left.cnt1;
    mp[left.max2] += left.cnt2;
    mp[right.max1] += right.cnt1;
    mp[right.max2] += right.cnt2;

    auto it = --st.end();
    mx1 = *it;
    cnt1 = mp[mx1];
    st.erase(mx1);
    it = --st.end();
    mx2 = *it;
    cnt2 = mp[mx2];
    return node(mx1, mx2, cnt1, cnt2);    
}

void build(vector<int>& a, int x, int lx, int rx) {
  if (lx == rx) {
    secondmax[x].max1 = a[lx];
    secondmax[x].cnt1 = 1;
    secondmax[x].max2 = INT_MIN;
    secondmax[x].cnt2 = 0;
    return;
  }

  int m = (lx + rx) / 2;
  int left = 2 * x;
  int right = 2 * x + 1;
  build(a, left, lx, m);
  build(a, right, m + 1, rx);
  secondmax[x] = combine(secondmax[left], secondmax[right]);
}

void sett(int i, int v, int x, int lx, int rx) {
  if (i < lx || i > rx)
    return;
  if (lx == rx) {
    secondmax[x].max1 = v;
    secondmax[x].cnt1 = 1;
    secondmax[x].max2 = INT_MIN;
    secondmax[x].cnt2 = 0;
    return;
  }
  int m = (lx + rx) / 2;
  int left = 2 * x;
  int right = 2 * x + 1;
  sett(i, v, left, lx, m);
  sett(i, v, right, m + 1, rx);
  secondmax[x] = combine(secondmax[left], secondmax[right]);
}

node query(int l, int r, int x, int lx, int rx) {
  if (lx > r || rx < l) {
    return {INT_MIN, INT_MIN, 0, 0};
  }
  if (lx >= l && rx <= r) {
    return secondmax[x];
  }
  int m = (lx + rx) / 2;
  int left = 2 * x;
  int right = 2 * x + 1;
  node lans = query(l, r, left, lx, m);
  node rans = query(l, r, right, m + 1, rx);
  return combine(lans, rans);
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  // cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    secondmax.resize(4 * n + 3);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    build(a, 1, 1, n);
    // for(auto i:secondmax){
    //   cout<<i.max1<<" "<<i.max2<<" "<<i.cnt1<<" "<<i.cnt2<<endl;
    // }
    while (q--) {
      int x;
      cin >> x;
      if (x == 1) {
        int i, v;
        cin >> i >> v;
        sett(i, v, 1, 1, n);
        // for (auto i : secondmax) {
        //   cerr << i.max1 << " " << i.cnt1 << " " << i.max2 << " " << i.cnt2 << endl;
        // }
      } else {
        int l, r;
        cin >> l >> r;
        node tp = query(l, r, 1, 1, n);
        //dbg(tp.max1, tp.cnt1, tp.max2, tp.cnt2);
        cout << tp.cnt2 << endl;
      }
    }
  }
  return 0;
}