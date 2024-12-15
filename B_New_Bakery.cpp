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
    int n, a, b;
    cin >> n >> a >> b;
    int l = 0;
    int h = min(n, b);
    int ans = 0;
    int sum1 = 0;
    int sum2 = 0;
    while (l <= h) {
      int mid1 = l + (h - l) / 3;
      int mid2 = h - (h - l) / 3;
      sum1 = (b + 1) * mid1 - ((mid1 * (mid1 + 1)) / 2) + ((n - mid1) * a);
      sum2 = (b + 1) * mid2 - ((mid2 * (mid2 + 1) / 2)) + ((n - mid2) * a);
      // dbg(mid1,mid2,sum1,sum2);
      if (sum1 > sum2) {
        h = mid2 - 1;
      } else if (sum2 > sum1)
        l = mid1 + 1;
      else {
        l = mid1 + 1;
        h = mid2 - 1;
      }
    }
    cout << max(sum1, sum2) << endl;
  }
  return 0;
}