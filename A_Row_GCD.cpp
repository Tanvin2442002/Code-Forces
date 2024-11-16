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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(vr(a));
    for (int i = 1; i < n; i++) {
      a[i] = a[0] - a[i];
    }
    int ans = 0;
    for(int i=1;i<n;i++){
      ans = __gcd(ans, a[i]);
    }
    // dbg(a);
    while (m--) {
      int x;
      cin >> x;
      cout << __gcd(ans, a[0] + x) << " ";
    }
    cout << endl;
  }
  return 0;
}