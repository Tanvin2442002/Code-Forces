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

int mod = 1000000007;
int inf = 1e18;

int f(vector<int>& a, vector<int>& b, int mid) {
  int cost = 0;
  for (int i = 0; i < a.size(); i++) {  // mid -> 3    cost = 0  a-> 1 2 3
    // dbg(cost, i, mid);
    if (a[i] < mid) {
      cost = cost + (mid - a[i]);
    }
    // dbg(cost, a[i], i);
  }
  for (int i = 0; i < b.size(); i++) {
    if (b[i] > mid) {
      cost = cost + (b[i] - mid);
    }
    // dbg(cost,b[i]);
  }
  return cost;
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  // cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> b[i];
    }
    sort(vf(a));
    sort(vf(b));

    int lo = min(a[0], b[0]);
    int hi = max(a[n - 1], b[m - 1]);
    if (b[m - 1] < a[0]) {
      cout << 0 << endl;
      continue;
    }
    int ans = 0;
    int sum = inf;
    while (lo <= hi) {
      int mid1 = lo + (hi - lo) / 3;  // 1 +
      int mid2 = hi - (hi - lo) / 3;
      int f1 = f(a, b, mid1);
      int f2 = f(a, b, mid2);
      // dbg(f1, f2, mid1, mid2);
      if (f1 < f2)
        hi = mid2 - 1;
      else
        lo = mid1 + 1;
      if (f1 > f2) {
        if (f1 < sum) {
          sum = f1;
          ans = mid1;
        }
      } else {
        if (f2 < sum) {
          sum = f2;
          ans = mid2;
        }
      }
    }
    cout << sum << endl;
  }
  return 0;
}