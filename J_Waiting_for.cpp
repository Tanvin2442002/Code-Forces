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
  // cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int cnt = 0;
    int free = 0;
    while (n--) {
      char c;
      int a;
      cin >> c >> a;
      // dbg(cnt, free);
      if (c == 'P') {
        cnt += a;
      } else {
        free += a;
        if (free > cnt) {
          cout << "YES" << endl;
          free = 0;
          cnt = 0;
        } else
          cout << "NO" << endl;
      }
    }
  }
  return 0;
}