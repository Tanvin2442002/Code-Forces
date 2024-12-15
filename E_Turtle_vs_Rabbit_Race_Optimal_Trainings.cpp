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

int f(vector<int>& p, int l, int mid, int u) {
  int amount = p[mid]-p[l-1];
  if(l==1)p[mid];
  int sum = 0;
  if (amount > u) {
    int diff = amount - u;  //
    sum += (u * (u + 1) / 2);
    diff--;
    sum -= (diff * (diff + 1) / 2);
  } else {
    int diff = u - amount;  // 9 5    9 8 7 6 5
    sum += (u * (u + 1) / 2);
    sum -= (diff * (diff + 1) / 2);
  }
  return sum;
}

int32_t main() {
  fastio;
  in;
  out;
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    vector<int> presum(n + 1);
    for (int i = 0; i <= n; i++) {
      if (i == 0)
        presum[i] = 0;
      else {
        presum[i] = presum[i - 1] + v[i - 1];
      }
    }
    int q;
    cin >> q;
    vector<int> res;
    while (q--) {
      int l, u;
      cin >> l >> u;
      int lo = l;
      int hi = n;
      int ans = 0;
      int sum = -inf;
      while (lo <= hi) {
        int mid1 = lo + (hi - lo) / 3;  // 1 +
        int mid2 = hi - (hi - lo) / 3;
        int f1 = f(presum, l, mid1, u);
        int f2 = f(presum, l, mid2, u);
        dbg(f1, f2, mid1, mid2);
        if (f1 < f2)
          lo = mid1 + 1;
        else
          hi = mid2 - 1;
        if (f1 > f2) {
          if (f1 > sum) {
            sum = f1;
            ans = mid1;
          } else if (f1 == sum) {
            ans = min(ans, mid1);
          }
        } else {
          if (f2 > sum) {
            sum = f2;
            ans = mid2;
          } else if (f2 == sum) {
            ans = min(ans, mid2);
          }
        }
      }
      dbg(ans);
      cout << ans << " ";
    }
    cout<<endl;
  }
  return 0;
}