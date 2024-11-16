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
    int n, median;
    cin >> n >> median;
    vector<int> v(n + 1);
    for (int i = 1; i < n + 1; i++) {
      v[i] = i;
    }
    if (n == 1 and median == 1) {
      cout << 1 << endl;
      cout << 1 << endl;
      continue;
    }
    if (median == v[n] or median == v[1]) {
      cout << -1 << endl;
      continue;
    } else {
      int idx = median;
      int diff1 = median - 1;
      int diff2 = n - median;
      int ans = 1;
      vector<int> vals;
      vals.push_back(idx);
      if (diff1 % 2 == 1) {
        vals.push_back(1);
        vals.push_back(idx + 1);
      } else {
        vals.push_back(1);
        vals.push_back(2);
        vals.push_back(idx + 1);
        vals.push_back(idx + 2);
      }
      cout << vals.size() << endl;
      sort(vf(vals));
      for (auto i : vals) {
        cout << i << " ";
      }
      cout << endl;
    }
  }
  return 0;
}