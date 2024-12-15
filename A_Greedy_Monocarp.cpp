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
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    sort(vr(v));
    vector<int> prefix(n);
    prefix[0] = v[0];
    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] + v[i];
    }
    int mn = INT_MAX;
    int f = 0;
    for (int i = 0; i < n; i++) {
      int diff = k - prefix[i];
      if(diff == 0){
        f = 1;
        break;
      }
      dbg(diff);
      if (diff > 0) {
        if (v[i] <= k) {
          mn = min(mn, diff);
        }
      }
    }
    if(!f) cout << mn << endl;
    else cout << 0 << endl;
  }
  return 0;
}