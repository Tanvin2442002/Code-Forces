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

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    // vector<int> v(n);
    map<int, vector<int>> m;
    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      m[x].push_back(y);
    }
    dbg(m);
    vector<int> v;
    for (auto i : m) {
      v.push_back(accumulate(vf(i.second), 0));
    }
    sort(vr(v));
    dbg(v);
    int ans = 0;
    if (n >= v.size()) {
      ans = accumulate(vf(v), 0);
    } else {
      for (int i = 0; i < n; i++) {
        ans += v[i];
      }
    }
    cout << ans << endl;
  }
  return 0;
}