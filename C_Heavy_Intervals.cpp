#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "F:\Codeforces\debug.h"
#else
#define dbg(x...)
#define dbgc(x...)
#endif
using namespace std;

#define int long long
#define float long double
#define vf(v) (v).begin(), (v).end()
#define vr(v) (v).rbegin(), (v).rend()
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false)
#define in cin.tie(NULL)
#define out cout.tie(NULL)
// #include <ext/pb_ds/assoc_container.hpp>

class DisjointSet {
  vector<int> parent, sz, mn;

 public:
  DisjointSet(int n) {
    sz.resize(n + 1);
    parent.resize(n + 2);
    mn.resize(n + 2, 1e18);
    for (int i = 1; i <= n; i++) parent[i] = i, sz[i] = 1;
  }
  int findUPar(int u) { return parent[u] == u ? u : parent[u] = findUPar(parent[u]); }
  void unionBySize(int u, int v) {
    int a = findUPar(u);
    int b = findUPar(v);
    if (sz[a] < sz[b]) swap(a, b);
    if (a != b) {
      parent[b] = a;
      sz[a] += sz[b];
      mn[a] = min({mn[a], mn[b], a, b});
    }
  }
  int getMin(int u) { return mn[findUPar(u)]; }
};


int mod = 1000000007;
int inf = 1e18;

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> l(n + 1), r(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> l[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> r[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
    }
    DisjointSet ds(n+1);
    sort(vf(l));
    sort(vf(r));
    vector<int> diff(n+1);
    for(int i=1;i<=n;i++) {
      int low = 1, high = n, ind = high;
      while(low <= high) {
        int mid = (low + high) / 2;
        if(l[mid] <= r[i]) {
          ind = mid;
          low = mid + 1;
        }
        else {
          high = mid - 1;
        }
      }
      int mn = ds.getMin(ind);
      dbg(ind, mn);
      if(mn == 1e18) {
        diff[i] = r[i] - l[ind];
        ds.unionBySize(ind, ind-1);
      }
      else {
        diff[i] = r[i] - l[mn];
        ds.unionBySize(mn, mn-1);
      }
    }
    sort(vf(diff));
    sort(vr(c));
    dbg(c);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += c[i-1] * diff[i];
    }
    cout << ans << endl;
  }
  return 0;
}