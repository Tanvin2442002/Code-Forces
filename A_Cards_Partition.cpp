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
    vector<int> v(n);
    map<int, int> mp;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      mp[i + 1] = v[i];
    }
    int mx = 0;
    for (auto i : mp) {
      sum += i.second;
      mx = max(mx, i.second);
    }
    for (int i = n; i > 0; i--) {
      int x = (sum + k) / i;
      if (x >= mx and x * i >= sum) {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}